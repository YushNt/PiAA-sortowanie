#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H
#include <vector>
#include <algorithm>

// quicksort

template <typename T>
class QuickSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        if (end - start > 1)
        {
            auto pivot_loc = partition(start, end); //podział na dwie części + pivot_loc - iterator wskazujący na element, który jest już na swoim miejscu
            sort(start, pivot_loc); //rekurnecja 
            sort(pivot_loc + 1, end);
        }
    };
private:
    typename std::vector<T>::iterator partition(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        auto mid = start + (end - start) / 2;
        auto last = end - 1;
        //optymalizacja pivota - mediana z początku, środka i końca
        if (*mid < *start) std::iter_swap(mid, start);
        if (*last < *start) std::iter_swap(last, start);
        if (*last < *mid) std::iter_swap(last, mid);
        std::iter_swap(start, mid);

        auto pivot = *start;
        auto leftwall = start;
        for (auto i = start + 1; i < end; ++i){
            if (*i < pivot){
                ++leftwall;
                std::iter_swap(leftwall, i);
            }
        }
        std::iter_swap(start, leftwall);
        return leftwall;
    }
};
#endif //SORTING_ALGORITHMS_QUICKSORT_H
