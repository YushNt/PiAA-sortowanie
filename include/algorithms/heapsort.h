#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H
#include <vector>
#include <algorithm>
template <typename T>
class Heap
{
private:
    typename std::vector<T>::iterator start;
    typename std::vector<T>::iterator end;
public:
    Heap(typename std::vector<T>::iterator start_, typename std::vector<T>::iterator end_)
    {
        this->start = start_;
        this->end = end_;
        buildHeap();
    }
    void removeMax();
    std::size_t size();
    bool empty();
    T& operator[](size_t index);
    void maxHeapify(size_t index);
    void buildHeap();
};

template <typename T>
void Heap<T>::removeMax()
{
    if (empty()) return;
    std::iter_swap(start, end - 1);
    end--;
    maxHeapify(1);
}

template <typename T>
std::size_t Heap<T>::size()
{
    return end - start;
}

template <typename T>
bool Heap<T>::empty()
{
    if (size() != 0) return false;
    return true;
}

template <typename T>
T& Heap<T>::operator[](size_t index)
{   
    return *(start + index - 1);
}

template <typename T>
void Heap<T>::maxHeapify(size_t index) {
    size_t left = 2 * index;
    size_t right = 2 * index + 1;
    size_t largest = index;
    size_t current_size = size();

    if (left <= current_size && (*this)[left] > (*this)[largest]) {
        largest = left;
    }
    
    if (right <= current_size && (*this)[right] > (*this)[largest]) {
        largest = right;
    }

    if (largest != index) {
        std::swap((*this)[index], (*this)[largest]);
        maxHeapify(largest);
    }
}

template <typename T>
void Heap<T>::buildHeap()
{
    size_t n = size();
    for (size_t i = n / 2; i >= 1; i--) {
        maxHeapify(i);
    }
}


// sortowanie przez kopcowanie

template <typename T>
class HeapSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        Heap<T> heap(start, end);
        while(!heap.empty()) {
            heap.removeMax(); // elementy usuwane (max) są od razu umieszczane na końcu tablicy
        }
    };
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
