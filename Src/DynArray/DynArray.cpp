#include <stdlib.h>

#include "DynArray.h"

template<class T>
void DynArray<T>::PushBack(T new_elem)
{
    if (capacity <= length)
    {
        capacity *= 2;
        realloc(array, capacity * sizeof(T));
    }

    array[length] = new_elem;
    length++;
}

template<class T>
T  DynArray<T>::operator[](int index)
{
    if (index >= length)
        length = index + 1;
    return array[index];
};