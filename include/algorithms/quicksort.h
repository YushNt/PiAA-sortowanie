#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H
#include <vector>

// quicksort

template <typename T>
class QuickSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        if (start < end)
        {
            auto pivot_loc = partition(start, end);
            sort(start, pivot_loc);
            sort(pivot_loc + 1, end);
        }
    };
private:
    typename std::vector<T>::iterator partition(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
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
