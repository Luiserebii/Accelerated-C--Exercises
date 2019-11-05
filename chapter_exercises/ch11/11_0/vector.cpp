template <class T>
class Vec {

    private: 
        T* data; //Pointer to the head of the array
        T* limit; //Pointer to +1 after the end of the array

    public:

        //Iterator Types
        typedef T* iterator; 
        typedef const T* const_iterator;

        typedef size_t size_type;

        //Types needed to round out implementation; required for back_inserter usage
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T& reference;
        typedef const T& const_reference;

        //Constructors
        Vec() { create(); }
        explicit Vec(std::size_t n const T& val=T()) { create(n, val); }

        //Copy, assignment, destructor
        Vec(const Vec& v) { create(v.begin(), v.end()); }
        Vec& operator=(const Vec&);
        ~Vec() { uncreate(); }

        size_type size() const { return limit - data; }

        //Operators
        //Set of functions for the overloaded operator [].
        //Note that "const" functions can be overloaded
        T& operator[](size_type i) { return data[i]; }
        const T& operator[](size_type i) const { return data[i]; } 

        //Iterator functions
        iterator begin() { return data; }
        const_iterator begin() const { return data; }

        iterator end() { return limit; }
        const_iterator end() const { return limit; }

}

template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
    //Check that value being assigned to isn't the same as the one
    //already existing in this var
    if(&rhs != this) {
        //Free the array
        uncreate();

        //Create and copy in elements from the right-hand side via iterators
        create(rhs.begin(), rhs.end());
    }
    return *this;
}


