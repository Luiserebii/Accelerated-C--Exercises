/*

1-5. Is this program valid? If so, what does it do? If not, say why not, and rewrite it to be valid.


No, this code is not valid, as the value of x is destroyed before it can be used from the outer scope to print. (as it is a local var)

*/
/*
#include <iostream>
#include <string>
 
int main()
{
    {
        std::string s = "a string";
        {
            std::string x = s + ", really";
            std::cout << s << std::endl;
        }
        std::cout << x << std::endl;
    }
    return 0;
}

Yup, a failure: 

g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
exit status 1
main.cpp: In function 'int main()':
main.cpp:21:22: error: 'x' was not declared in this scope
         std::cout << x << std::endl;
                      ^


To revise it, we can extend the second scope a little:

*/

#include <iostream>
#include <string>
 
int main()
{
    {
        std::string s = "a string";
        {
            std::string x = s + ", really";
            std::cout << s << std::endl;
            std::cout << x << std::endl;
        }
    }
    return 0;
}

/*

g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
a string
a string, really

Success!

*/