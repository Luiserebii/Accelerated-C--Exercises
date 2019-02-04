

//
//This should work, I think, since regular // comments will extend to the end of the line, I think...? The compiler probably just stops reading there and moves to the next line
//

//Test run:

#include <iostream>
int main()

{
    // This is a comment that extends over several lines
    // by using // at the beginning of each line instead of using /*
    // or */ to delimit comments.

    std::cout << "Does this work?" << std::endl;
    return 0;
}

//Output:
//
//Does this work?
//


//Huh, it really does. I wasn't sure honestly, but thinking about it the way the compiler is probably coded, it makes sense to just imagine that "//" comments simply have the compiler skip a line, but /* */ forces it to look for the first "end comment" it can find
