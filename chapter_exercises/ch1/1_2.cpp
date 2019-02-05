/*

1-2. Are the following definitions valid? Why or why not?

Yes, they should be valid; everything is basically the same as 1-1.

*/
#include <string>

int main(){

  const std::string exclam = "!";
  const std::string message = "Hello" + ", world" + exclam;

}

/*

TESTING: FAILURE

"g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
exit status 1
main.cpp: In function 'int main()':
main.cpp:13:39: error: invalid operands of types 'const char[6]' and 'const char [8]' to binary 'operator+'
   const std::string message = "Hello" + ", world" + exclam;
                               ~~~~~~~~^~~~~~~~~~~

Explanation: Ahhh, a line I missed. Two string literals cannot be concatenated. Why? Because string literals are essentially const char arrays. I guess?

Why not just implement it in a way where the arrays are fused together into a larger array? Is it just something that isn't written, that + is reserved for strings/string literal + string?



*/