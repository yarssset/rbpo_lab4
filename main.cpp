#include <iostream>
#include <iterator>
#include <initializer_list>
using namespace std;

template <typename T>
class DequeBasedOnArray {
private:
    T* arr;
    int size;
public:
    using Iterator = T*;

    DequeBasedOnArray();
    explicit DequeBasedOnArray(unsigned size);
    DequeBasedOnArray(const DequeBasedOnArray& other);
    DequeBasedOnArray(DequeBasedOnArray&& other);
    DequeBasedOnArray(initializer_list<int> list);
    ~DequeBasedOnArray();

    const int& operator[](int index) const;
    int& operator[](int index);

    DequeBasedOnArray& operator=(const DequeBasedOnArray& other);
    DequeBasedOnArray& operator=(DequeBasedOnArray&& other);
    DequeBasedOnArray& operator=(initializer_list<int> ilist);

    DequeBasedOnArray::Iterator begin();
    const DequeBasedOnArray::Iterator begin() const;
    DequeBasedOnArray::Iterator end();
    const DequeBasedOnArray::Iterator end() const;

    int GetSize() const;
    bool PushFront(const T& element);
    bool PopFront(T& element);
    bool PushBack(const T& element);
    bool PopBack(T& element);
    bool PeekFront(T& element) const;
    bool PeekBack(T& element) const;

};

template <typename T>
DequeBasedOnArray<T>::DequeBasedOnArray() : arr(nullptr), size(0) {}

template <typename T>
DequeBasedOnArray<T>::DequeBasedOnArray(unsigned size) : size(size){
    arr = new int[size];
}

template <typename T>
DequeBasedOnArray<T>::DequeBasedOnArray(const DequeBasedOnArray& other){
    arr = new int[other.size];
    size = other.size;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
}

template <typename T>
DequeBasedOnArray<T>::DequeBasedOnArray(DequeBasedOnArray&& other){
    arr = other.arr;
    size = other.size;
    other.arr = nullptr;
}

template <typename T>
DequeBasedOnArray<T>::DequeBasedOnArray(std::initializer_list<int> list){
    delete[] arr;
    size = list.size();
    arr = new T[size];
    int i = 0;
    for (auto iter = list.begin(); iter != list.end(); ++iter) {
        arr[i] = *iter;
        i++;
    }
}

template <typename T>
DequeBasedOnArray<T>::~DequeBasedOnArray() {
    delete[] arr;
}

template <typename T>
DequeBasedOnArray<T>& DequeBasedOnArray<T>::operator=(const DequeBasedOnArray& other){
    if (this == &other)
    {
        return *this;
    }
    delete[] arr;
    arr = new int[other.size];
    size = other.size;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T>
DequeBasedOnArray<T>& DequeBasedOnArray<T>::operator=(DequeBasedOnArray&& other){
    if (this == &other)
    {
        return *this;
    }
    delete[] arr;
    arr = other.arr;
    size = other.size;
    other.arr = nullptr;
}

template<typename T>
DequeBasedOnArray<T>& DequeBasedOnArray<T>::operator=(std::initializer_list<int> list){
    delete[] arr;
    arr = new T[list.size()];
    size = list.size();
    int i = 0;
    for (const auto& element : list)
    {
        arr[i++] = element;
    }
    return *this;

}


template<typename T>
typename DequeBasedOnArray<T>::Iterator DequeBasedOnArray<T>::begin(){
    return Iterator(arr);
}

template<typename T>
const typename DequeBasedOnArray<T>::Iterator DequeBasedOnArray<T>::begin() const{
    return Iterator(arr);
}

template<typename T>
typename DequeBasedOnArray<T>::Iterator DequeBasedOnArray<T>::end(){
    return Iterator(arr + size);
}

template<typename T>
const typename DequeBasedOnArray<T>::Iterator DequeBasedOnArray<T>::end() const{
    return Iterator(arr + size);
}

const int& DequeBasedOnArray<int>::operator[](int index) const{
    return index;
}

int& DequeBasedOnArray<int>::operator[](int index){
    return index;
}

template <typename T>
int DequeBasedOnArray<T>::GetSize() const{
    return size;
}

template<typename T>
bool DequeBasedOnArray<T>::PushFront(const T& element){
    int* arr2 = arr;
    try {
        arr = new int[size + 1];
        arr[0] = element;
        for (int i = 0; i < size; i++)
            arr[i + 1] = arr2[i];
        size++;
        if (size > 1)
            delete[] arr2;
        return true;
    }
    catch (...)
    {
        arr = arr2;
        return false;
    }
}

template<typename T>
bool DequeBasedOnArray<T>::PopFront(T& element){
    if (size == 0)
        return false;
    else {
        int* arr2;
        element = arr[0];
        arr2 = new int[size - 1];
        size--;
        for (int i = 0; i < size; i++)
            arr2[i] = arr[i + 1];
        if (size > 0)
            delete[] arr;
        arr = arr2;
        return true;
    }
}

template<typename T>
bool DequeBasedOnArray<T>::PushBack(const T& element){
    int* arr2 = arr;
    try {
        arr = new int[size + 1];
        for (int i = 0; i < size; i++)
            arr[i] = arr2[i];
        arr[size] = element;
        size++;
        if (size > 1)
            delete[] arr2;
        return true;
    }
    catch (...)
    {
        arr = arr2;
        return false;
    }
}

template<typename T>
bool DequeBasedOnArray<T>::PopBack(T& element){
    if (size == 0)
        return false;
    else {
        int* arr2;
        element = arr[size - 1];
        arr2 = new int[size - 1];
        size--;
        for (int i = 0; i < size; i++)
            arr2[i] = arr[i];
        if (size > 0)
            delete[] arr;
        arr = arr2;
        return true;
    }
}

template<typename T>
bool DequeBasedOnArray<T>::PeekFront(T& element) const{
    if (size > 0)
    {
        element = arr[0];
        return true;
    }
    else
        return false;
}

template<typename T>
bool DequeBasedOnArray<T>::PeekBack(T& element) const{
    if (size > 0)
    {
        element = arr[size - 1];
        return true;
    }
    else
        return false;
}

int main()
{
    return 0;
}