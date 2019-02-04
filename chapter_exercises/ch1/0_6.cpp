// 
// 
// 
// I think this may be a valid program, for these reasons:
// 
// 1. Curly braces define scope of a block, grouping the statements together. Everything within the innermost braces resolves, the type of "std::cout" is discarded, and the rest of the curly braces simply resolve "whitespace".
// 
//

//
// Test run:
//  



#include <iostream>

int main() {{{{{{ std::cout << "Hello, world!" << std::endl; }}}}}}




// It does seem to run, surprisingly enough... I wonder, what if we had random curly braces without a function strewn about?

//
// Test run:
//

/*
#include <iostream>

int main()
{

    { 0+1+2; }
    { std::cout << "Will my shouts escape this void?" << std::endl; }

    return 0;


}
*/

/*

Wow, it actually does work!!! Huh, I guess they really are just scoping tokens. I wonder what utility this could have...? I suppose if you wanted to use some sort of variable for a small and temporary operation, but isn't that what functions are for? It would be like a weird subfunction I guess... Bad practice probably, but could work

*/

