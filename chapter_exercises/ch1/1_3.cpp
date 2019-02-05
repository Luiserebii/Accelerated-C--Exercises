/*

Is the following program valid? If so, what does it do? If not, why not?

Yes, it is valid. Once on the opening bracket, a new scope is created, s is initialized, and is printed onto the console. On the ending bracket, the computer destroys the local scope variables (Is this the garbage collector?) to free up memory.

Same for the second scope.

*/

#include <iostream>
#include <string>
 
int main()
{
    {
      const std::string s = "a string";
      std::cout << s << std::endl;
    }
    {     
      const std::string s = "another string";
      std::cout << s << std::endl;
    }
 
}