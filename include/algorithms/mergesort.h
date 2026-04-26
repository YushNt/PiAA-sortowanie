#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H
#include <vector>

// sortowanie przez scalanie

template <typename T>
class MergeSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        auto n = end - start;
        if (n <= 1) { //jeśli jest 1 element to nie ma co sortować
            return;
        }
        if (n == 2) { //jeśli są 2 elementy to wystarczy porównać i ewentualnie zamienić
            if (*start > *(start + 1)) {
                std::iter_swap(start, start + 1);
            }
            return;
        }

        auto mid = start + n/2;
        //rekurencja 
        sort(start, mid);
        sort(mid, end);

        merge(start, mid, end);  
    };
private:
    void merge(typename std::vector<T>::iterator start, typename std::vector<T>::iterator mid, typename std::vector<T>::iterator end) {
        std::vector<T> buffer;
        buffer.reserve(end - start);

        auto left = start; //iteratory do porównywania elementów do wstawienia
        auto right = mid;

        //wstawianie elementów od najmniejszych, aż sie skończą w jednej z połówek
        while (left < mid && right < end) {
            if (*left <= *right) {
                buffer.push_back(*left);
                ++left;
            } else {
                buffer.push_back(*right);
                ++right;
            }
        }

        //zrzucamy resztki z lewej połówki
        while (left < mid) {
            buffer.push_back(*left);
            ++left;
        }

        //zrzucamy resztki z prawej połówki
        while (right < end) {
            buffer.push_back(*right);
            ++right;
        }

        //kopiowanie posortowanych wartości spowrotem do tablicy
        auto it = start;
        for (const auto& val : buffer) {
            *it = val;
            ++it;
        }
    }
};
#endif //SORTING_ALGORITHMS_MERGESORT_H
