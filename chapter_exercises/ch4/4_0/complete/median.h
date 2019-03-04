/*


Header file consists of:

-function declarations
+any names the function declaration relies on

For example: We pass a vector to median, so we must include <vector>.


IMPORTANT NOTE:
----------------
-Qualified name of vector (std::vector) MUST BE USED, as header files
are essentially copied into the files that include them. Since we don't
want to interrupt any potential "using" declarations the use might have
or give them some theym might not want, we use the specific names to 
avoid conflict.


Finally, the last one is simply pre-processor stuff to make sure it's not
included more than once. #ifndef directive: if not defined, don't process
everything following


Technically good practice to make pre-processor stuff 1st line, avoiding
here for commenting convenience

*/


#ifndef GUARD_median_h
#define GUARD_median_h


#include <vector>
double median(std::vector<double>);


#endif
