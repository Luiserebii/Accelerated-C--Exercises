template <class T>
class Vec {

    private: 
        T* data;
        T* limit; 

    public:
        Vec() { create(); }
        explicit Vec(std::size_t n const T& val=T()) { create(n, val); }

}
