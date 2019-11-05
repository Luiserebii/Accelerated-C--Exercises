#include <memory>

template <class T>
class Vec {

    private: 
        T* data; //Pointer to the head of the array
        T* avail; //Pointer to +1 after the end of the initialized elements
        T* limit; //Pointer to +1 after the end of the allocated elements

        //Class offering facilities for memory allocation
        allocator<T> alloc;

        void create();
        //Allocate memory, and set this one value x times throughout
        void create(size_type n, const T& val);
        //Allocate memory, and copy the values of this iterator into memory
        void create(const_iterator i, const_iterator j);

        void uncreate();

        //Grow the vector by allocating memory, pushing limit forward
        void grow();
        //Simply append a value to a pointer (such as the one at avail)
        void unchecked_append(const T&);

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

        size_type size() const { return avail - data; }

        //Operators
        //Set of functions for the overloaded operator [].
        //Note that "const" functions can be overloaded
        T& operator[](size_type i) { return data[i]; }
        const T& operator[](size_type i) const { return data[i]; } 

        //Iterator functions
        iterator begin() { return data; }
        const_iterator begin() const { return data; }

        iterator end() { return avail; }
        const_iterator end() const { return avail; }
    
        //Functions
        void push_back(const T& val) {
            if(avail == limit) {
                grow();
            }
            unchecked_append(val);
        }

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

template <class T>
void Vec<T>::create() {
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i);
    limit = avail = uninitialized_copy(i, j, data);
}
