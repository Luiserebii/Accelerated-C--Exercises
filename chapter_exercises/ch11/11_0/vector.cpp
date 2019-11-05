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

        Vec() { create(); }
        explicit Vec(std::size_t n const T& val=T()) { create(n, val); }

        size_type size() const { return limit - data; }

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
