#ifndef SYM_DYNAMIC_ARRAY
#define SYM_DYNAMIC_ARRAY

template <class T>
class DynArray
{
    int length;
    int capacity;
    T*  array;

    public :
    DynArray(size_t _length)
    {
        length   = 0;
        capacity = _length;
        array    = (T*)calloc(length, sizeof(T));
    };

    T operator[](int index);

    void PushBack(T elem);
};

#endif  //SYM_DYNAMIC_ARRAY