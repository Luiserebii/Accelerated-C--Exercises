/*

Is the following program valid? What if we change }} to };} in the third line from the end?

No, it is not valid; since the innermost local scope also has access to the outer variables, there is now a naming conflict, even though const s becomes destroyed once the first-level local scope is exited.

*/

#include <iostream>
#include <string>
 
int main()
{
    {
      const std::string s = "a string";
      std::cout << s << std::endl;
    {     
      const std::string s = "another string";
      std::cout << s << std::endl; }}
  return 0;
}

/*

!!! It runs!?!?!?!?

I wanted to test something, to see how the variable might change under the same name within a local scope.

#include <iostream>

int main() {

  int x = 5;
  std::cout << x << std::endl;

  {
    std::cout << x << std::endl;
    int x = 7;
    std::cout << x << std::endl;    
  }

  std::cout << x << std::endl;    
}

Output:

g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
5
5
7
5

!!! Ahhh, so it seems that within the local scope; 
1. It was able to refer to the global scope-named variable.
2. It was able to set the value of a variable x within its own scope to another value (7).
3. The local scope only changed (or rather, set?) the value of its own variable, so the variable x is still the same as before!

My best guess is that when a variable with the same name under a different scope is defined, the computer chooses to "shadow" the name, and simply treat it as an entirely new variable.

Thus, the distinction comes between x defined in scope 1, and x defined in scope 2. Since there was no naming conflict before, it just yielded the value of scope 1's x. Probably, shadowing is C++'s method of resolving naming conflicts within layered scopes.


In this case };} should also work, as ; would just signal the end of the statement; although, 

Q: Are blocks almost like statements, or is it the specific meaning of ; that has to do with it?

; alone is a null statement which is valid, so even if the {} resolves and "disappears", it wouldn't change much.

After a quick test, yes, this is valid:

#include <iostream>
#include <string>
 
int main()
{
    {
      const std::string s = "a string";
      std::cout << s << std::endl;
    {     
      const std::string s = "another string";
      std::cout << s << std::endl; };}
  return 0;
}

*/