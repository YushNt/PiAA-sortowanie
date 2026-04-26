#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H
#include <vector>

template <typename T>
class Heap
{
  public:
    Heap(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {

    }
    void removeMax();
    std::size_t size();
    bool empty();
    T& operator[](int index);
};

template <typename T>
void Heap<T>::removeMax()
{
    
}

template <typename T>
std::size_t Heap<T>::size()
{
    // TODO: zaimplementuj
    return 0;
}

template <typename T>
bool Heap<T>::empty()
{
    if (size() != 0) return false;
    return true;
}

template <typename T>
T& Heap<T>::operator[](int index)
{
    // TODO: zaimplementuj - wyjątkowo indeksowanie jest od 1
    static T t;
    return t;
}


// sortowanie przez kopcowanie

template <typename T>
class HeapSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
    };
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
