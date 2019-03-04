/*

We noted in §4.2.3/65 that it is essential that the argument types in a call to max match exactly. Will the following code work? If there is a problem, how would you fix it?


int maxlen;
Student_info s;
max(s.name.size(), maxlen);


============================================


I don't think it should, since s.name.size() likely returns str::size_type, which does not match with int.
max() likely does not handle casting if it is essential for the argument types to match exactly.

If there is a problem, the solution would probably be to convert int to str::size_type, or both to double/some type
that can hold the maximum of their values and perhaps handle negative values?

Or maybe just add a conditional before int to str::size_type conversion; if negative, we already know the maxlen is probably larger,
or at least equal to.

*/
