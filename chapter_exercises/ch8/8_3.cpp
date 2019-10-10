/**
 *
 * Yes, I think we could rewrite it to operate on iterators. However,
 * we would need random access iterators, I think, to truly find the 
 * midpoint (we need the size.) The current implementation is:
 *
 */

template <class T>
T median(vector<T> v) {
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    if(size == 0) {
        throw domain_error("median of an empty vector");
    }
    //Sort numerically
    sort(v.begin(), v.end());
    //Obtain midpoint index
    vec_sz mid = size/2;

    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

/**
 *
 * If implemented this way, it might look like:
 *
 * Though admittedly enough, I'm not too sure on the sort() here,
 * I fear it might actually break our iterators, darn
 */


template <class RandomAccessIterator>
T median(RandomAccessIterator begin, RandomAccessIterator end) {
    if(size == 0) {
        throw domain_error("median of an empty vector");
    }
    //Sort numerically
    sort(begin, end);
    //Obtain midpoint index
    vec_sz mid = begin + (end - begin) / 2;

    return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

/**
 * I would imagine the performance benefits would have more to do with
 * saving memory
 **/
