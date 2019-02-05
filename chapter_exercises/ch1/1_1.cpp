/*

1-1. Are the following definitions valid? Why or why not?

Yes, they should be valid; the first line is defining a "hello" variable as type std::string, creating an object "Hello" and setting it to the variable. The scond is the same, with + working as a concatenator.

*/
#include <string>

int main(){

  const std::string hello = "Hello";
  const std::string message = hello + ", world" + "!";
  //compiles fine!

}