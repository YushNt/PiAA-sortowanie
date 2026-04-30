#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <algorithm>
#include "algorithms/insertsort.h"
#include "algorithms/heapsort.h"
#include "algorithms/mergesort.h"
#include "algorithms/quicksort.h"
#include "algorithms/introsort.h"
#include "algorithms/create_array.h"

const int num_of_measurements = 1;
size_t arr_sizes[5] = {10000, 50000, 100000, 500000, 1000000};
double percentiles[6] = {0.25, 0.5, 0.75, 0.95, 0.99, 0.997};

int main(int argc, char* argv[])
{   
    std::fstream plik;
    // ===== MERGE SORT ===== 
    plik.open( "C:/Users/korne/Desktop/PiAASortowanie/Pomiary/MergeSort.csv", std::ios::trunc | std::ios::out );
    std::cout << "===== Rozpoczeto pomiary dla MergeSort =====" << std::endl;
    plik << "Rozmiar; Random; 25%; 50%; 75%; 95%; 99%; 99,7%; odwrotnie\n";

    for (int s = 0; s < 5; s++){
        std::cout << " --- Start " << arr_sizes[s] << " elements ---" << std::endl;
        long long pomiary[8][num_of_measurements];

        for (int w = 0; w < num_of_measurements; w++){
            std::vector<int> arr = createArray<int>(arr_sizes[s]);
            auto start = std::chrono::high_resolution_clock::now();
            MergeSort<int>().sort(arr.begin(), arr.end());
            auto end = std::chrono::high_resolution_clock::now();
            pomiary[0][w] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
        std::cout << "Sorted " << std::endl;
        
        for (int p = 0; p < 6; p++){
            size_t k = static_cast<size_t>(arr_sizes[s] * percentiles[p]);
            for (int w = 0; w < num_of_measurements; w++){
                std::vector<int> arr = createArray<int>(arr_sizes[s]);
                std::sort(arr.begin(), arr.begin()+k);

                auto start = std::chrono::high_resolution_clock::now();
                MergeSort<int>().sort(arr.begin(), arr.end());
                auto end = std::chrono::high_resolution_clock::now();
                pomiary[p+1][w] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            }
            std::cout << "Sorted with " << percentiles[p] * 100 << "% sorted:" << std::endl;
        }

        for (int w = 0; w < num_of_measurements; w++){
            std::vector<int> arr = createArray<int>(arr_sizes[s]);
            std::sort(arr.rbegin(), arr.rend());

            auto start = std::chrono::high_resolution_clock::now();
            MergeSort<int>().sort(arr.begin(), arr.end());
            auto end = std::chrono::high_resolution_clock::now();
            pomiary[7][w] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
        std::cout << "Sorted with reverse order" << std::endl;

        for (int w = 0; w < num_of_measurements; w++){
            plik << arr_sizes[s];
            for (int i = 0; i < 8; i++){
                plik << "; " << pomiary[i][w];
            }
            plik << "\n";
        }
    }
    std::cout << "===== Ukonczono pomiary dla MergeSort =====\n" << std::endl;
    plik.close();
    
    // ===== QUICK SORT =====
    plik.open( "C:/Users/korne/Desktop/PiAASortowanie/Pomiary/QuickSort.csv", std::ios::trunc | std::ios::out );
    std::cout << "===== Rozpoczeto pomiary dla QuickSort =====" << std::endl;
    plik << "Rozmiar; Random; 25%; 50%; 75%; 95%; 99%; 99,7%; odwrotnie\n";
    for (int s = 0; s < 5; s++){
        std::cout << " --- Start " << arr_sizes[s] << " elements ---" << std::endl;
        long long pomiary[8][num_of_measurements];

        for (int w = 0; w < num_of_measurements; w++){
            std::vector<int> arr = createArray<int>(arr_sizes[s]);
            auto start = std::chrono::high_resolution_clock::now();
            QuickSort<int>().sort(arr.begin(), arr.end());
            auto end = std::chrono::high_resolution_clock::now();
            pomiary[0][w] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
        std::cout << "Sorted " << std::endl;
        
        for (int p = 0; p < 6; p++){
            size_t k = static_cast<size_t>(arr_sizes[s] * percentiles[p]);
            for (int w = 0; w < num_of_measurements; w++){
                std::vector<int> arr = createArray<int>(arr_sizes[s]);
                std::sort(arr.begin(), arr.begin()+k);

                auto start = std::chrono::high_resolution_clock::now();
                QuickSort<int>().sort(arr.begin(), arr.end());
                auto end = std::chrono::high_resolution_clock::now();
                pomiary[p+1][w] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            }
            std::cout << "Sorted with " << percentiles[p] * 100 << "% sorted:" << std::endl;
        }

        for (int w = 0; w < num_of_measurements; w++){
            std::vector<int> arr = createArray<int>(arr_sizes[s]);
            std::sort(arr.rbegin(), arr.rend());

            auto start = std::chrono::high_resolution_clock::now();
            QuickSort<int>().sort(arr.begin(), arr.end());
            auto end = std::chrono::high_resolution_clock::now();
            pomiary[7][w] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
        std::cout << "Sorted with reverse order" << std::endl;

        for (int w = 0; w < num_of_measurements; w++){
            plik << arr_sizes[s];
            for (int i = 0; i < 8; i++){
                plik << "; " << pomiary[i][w];
            }
            plik << "\n";
        }
    }
    std::cout << "===== Ukonczono pomiary dla QuickSort =====\n" << std::endl;
    plik.close();

    // ===== INTRO SORT =====
    plik.open( "C:/Users/korne/Desktop/PiAASortowanie/Pomiary/IntroSort.csv", std::ios::trunc | std::ios::out );
    std::cout << "===== Rozpoczeto pomiary dla IntroSort =====" << std::endl;
    plik << "Rozmiar; Random; 25%; 50%; 75%; 95%; 99%; 99,7%; odwrotnie\n";
    for (int s = 0; s < 5; s++){
        std::cout << " --- Start " << arr_sizes[s] << " elements ---" << std::endl;
        long long pomiary[8][num_of_measurements];

        for (int w = 0; w < num_of_measurements; w++){
            std::vector<int> arr = createArray<int>(arr_sizes[s]);
            auto start = std::chrono::high_resolution_clock::now();
            IntroSort<int>().sort(arr.begin(), arr.end());
            auto end = std::chrono::high_resolution_clock::now();
            pomiary[0][w] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
        std::cout << "Sorted " << std::endl;
        
        for (int p = 0; p < 6; p++){
            size_t k = static_cast<size_t>(arr_sizes[s] * percentiles[p]);
            for (int w = 0; w < num_of_measurements; w++){
                std::vector<int> arr = createArray<int>(arr_sizes[s]);
                std::sort(arr.begin(), arr.begin()+k);

                auto start = std::chrono::high_resolution_clock::now();
                IntroSort<int>().sort(arr.begin(), arr.end());
                auto end = std::chrono::high_resolution_clock::now();
                pomiary[p+1][w] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            }
            std::cout << "Sorted with " << percentiles[p] * 100 << "% sorted:" << std::endl;
        }

        for (int w = 0; w < num_of_measurements; w++){
            std::vector<int> arr = createArray<int>(arr_sizes[s]);
            std::sort(arr.rbegin(), arr.rend());

            auto start = std::chrono::high_resolution_clock::now();
            IntroSort<int>().sort(arr.begin(), arr.end());
            auto end = std::chrono::high_resolution_clock::now();
            pomiary[7][w] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
        std::cout << "Sorted with reverse order" << std::endl;

        for (int w = 0; w < num_of_measurements; w++){
            plik << arr_sizes[s];
            for (int i = 0; i < 8; i++){
                plik << "; " << pomiary[i][w];
            }
            plik << "\n";
        }
    }
    std::cout << "===== Ukonczono pomiary dla IntroSort =====" << std::endl;
    plik.close();
    


    return 0;
}
