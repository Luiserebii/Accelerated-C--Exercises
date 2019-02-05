/*

1-0. Compile, execute, and test the programs in this chapter.

*/



/*
#include <iostream>
#include <string>

int main() {
  std::cout << "Please enter your first name: ";

  std::string name;
  std::cin >> name;

  std::cout << "Hello, " << name << "!";
  return 0;
}
*/
/*
g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
Please enter your first name: ratatatta
Hello, ratatatta!

*/

// ask for a person's name, and generate a framed greeting

#include <iostream>
#include <string>

int main()
{
  std::cout << "Please enter your first name: ";
  std::string name;
  std::cin >> name;

  // build the message that we intend to write
  const std::string greeting = "Hello, " + name + "!";

  // build the 2nd and 4th lines of the output
  const std::string spaces(greeting.size(), ' ');
  const std::string second = "* " + spaces + " *";

  // build the 1st and 5th lines of the output
  const std::string first(second.size(), '*');

  //write it all
  std::cout << std::endl;
  std::cout << first << std::endl;
  std::cout << second << std::endl;
  std::cout << "* " << greeting << " *" << std::endl;
  std::cout << second << std::endl;
  std::cout << first << std::endl;

  return 0;
}

/*

g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
Please enter your first name: uguu

****************
*              *
* Hello, uguu! *
*              *
****************

*/
