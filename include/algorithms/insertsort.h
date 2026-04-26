#ifndef SORTING_ALGORITHMS_INSERTSORT_H
#define SORTING_ALGORITHMS_INSERTSORT_H
#include <vector>

// sortowanie przez wstawianie

template <typename T>
class InsertSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        for (auto i = start + 1; i < end; i++) {
            auto x = *i;
            auto j = i;
            
            while (j > start && *(j - 1) > x) {
                *j = *(j - 1);
                --j;
            }
            *j = x;
        }
    };
};

#endif //SORTING_ALGORITHMS_INSERTSORT_H
