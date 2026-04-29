#include <vector>
#include <random>

template <typename T>
std::vector<T> createArray(size_t size){
    static std::random_device rd; //losowe ziarno
    static std::mt19937 gen(rd()); //inicjalizacja silnika losowym ziarnem
    std::uniform_int_distribution<T> dis(0, size*2);    //zakres wartości w tablicy

    std::vector<T> array;
    array.reserve(size); //rezerwacja miejsca na tablice 
    for (size_t i = 0; i < size; i++)
    {
        array.push_back(dis(gen)); //wypełnienie losowymi wartościami
    }
    return array;
}