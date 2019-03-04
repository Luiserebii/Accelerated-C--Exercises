/*

If the following code is legal, what can we infer about the return type of f?

=========================

   double d = f()[n];

=========================


----------------------------------

The return type of f is likely either an array, a vector, or some other container type/type which has implemented being
able to take the [] square-bracket operators, and returning a double, or other type castable to double.

Most likely, it is an array of vector of type int, double, float, or related type. (But probably double)

*/
