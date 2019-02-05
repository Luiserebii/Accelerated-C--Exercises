/*

1-6. What does the following program do if, when it asks you for input, you type two names (for example, Samuel Beckett)? Predict the behavior before running the program, then try it.

I feel like this should just print "Samuel", and hang on the next one; although, this really depends on whether the computer discards everything after the parsed string or not. It could very well print "Hello, Samuel" and "Hello, Beckett"

*/

#include <iostream>
#include <string>
 
int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name; 
    std::cout << " Hello, " << name
                << std::endl << "And what is yours?";
    std::cin >> name;  
    std::cout << "Hello, " << name
                << "; nice to meet you too!" << std::endl;
    return 0;
 
}


/*

Output:

g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
What is your name? Samuel Beckett
 Hello, Samuel
And what is yours?Hello, Beckett; nice to meet you too!


!!! So it does sort of save the rest as the next input? Even though std::cin are totally seperate? I'd maybe understand if you held onto the value "std::cin >> name" and then called it again, but what, this shouldn't work!

Apparently, it is the case that there is also an input buffer, and all you do on "cin >>" is add to the buffer.

Therefore, when cin parses for whitespace, it removes the "word" and leaves the rest in the buffer. You could say this first word is flushed out. The second remains, meaning it will be used once reading from the buffer through something like cin happens.

In other words, the progression of the buffer is:

[empty]
Samuel Beckett
Beckett
[empty]

Credits to Johnny Chan @ matholope.co.uk for information on this: http://mathalope.co.uk/2014/06/22/accelerated-c-solution-to-exercise-1-6/


*/