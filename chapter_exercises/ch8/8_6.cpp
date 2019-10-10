/**
 *
 * 8-6. Suppose that m has type map<int, string>, and that we encounter a call to
 * copy (m.begin(), m.end(), back_inserter(x)). 
 * 
 * What can we say about the type of x? 
 * What if the call were copy(x.begin(), x.end(), back_inserter(m))
 * instead?
 *
 *
 * We could say that the type of x is something which has operations to receive
 * the Pair data structure, as each iterator for map yields one. If it were the
 * other way around, probably x would be a type which contains a sequence/set
 * of maps.
 *
 */


