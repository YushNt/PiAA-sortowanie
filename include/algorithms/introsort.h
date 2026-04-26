#ifndef SORTING_ALGORITHMS_INTROSORT_H
#define SORTING_ALGORITHMS_INTROSORT_H
#include <vector>
#include <bit>

// sortowanie introspektywne

template <typename T>
class IntroSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        uint maxdepth = 2 * std::bit_width(end - start); //maybe bad typ
        DoIntroSort(start, end, maxdepth);
    };
private:
    void DoIntroSort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end, uint maxdepth){
        auto n = end - start;
        if (n < 16) InsertSort(start, end);
        else if  (maxdepth == 0) InsertSort(start, end); //!!! ZAIMPLEMENTOWAĆ HEAPSORT
        else {
            auto pivot_loc = partition(start, end ); //podział na dwie części + pivot_loc - iterator wskazujący na element, który jest już na swoim miejscu
            DoIntroSort(start, pivot_loc, maxdepth-1);
            DoIntroSort(pivot_loc, end, maxdepth-1);
        }
    };

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
    void InsertSort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        for (auto i = start + 1; i < end; i++) {
            auto x = *i;
            auto j = i;
            
            while (j > start && *(j - 1) > x) {
                *j = *(j - 1);
                --j;
            }
            *j = x;
        }
    }
};
#endif //SORTING_ALGORITHMS_INTROSORT_H
