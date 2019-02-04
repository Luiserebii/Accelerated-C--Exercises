//
//
// 0-3. The string literal "\t" represents a tab character; different C++ implementations display
// 	tabs in different ways. Experiment with your implementation to learn how it treats tabs.
//
//


#include <iostream>

int main()
{

    //Regular tab character
    std::cout << "REGTAB | BEGIN:" <<  "	" << ":END" << std::endl;

    //Tab literal
    std::cout << "TABLIT (\\t):" << "\t" << ":END" << std::endl;


    /*

Output is: 

REGTAB | BEGIN:	:END
TABLIT (\t):	:END

Hmmm... Seems to treat tab as a space? Although, there is also some weird vim stuff happening... spacing the beginning expands it

    (\t) is treated as a traditional, regular tab.

    */



    return 0;

}
