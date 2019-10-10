/**
 *
 * 8-8. In the binary_search function in §8.2.6/148, why didn't we write 
 * (begin + end) / 2 instead of the more complicated begin + (end - begin) / 2?
 *
 *
 * I suspect this is because we're working with iterators, and doing the former
 * would result in an iterator far beyond range, it sounds like it would simply
 * break right then and there, or might be C++ implementation-specific on
 * whatever happens next; the latter is probably safer.
 *
 **/
