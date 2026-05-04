#include <iostream>
#include <vector>
#include "sorts.hpp"


void printVector(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }
    
    std::cout << '\n';
}


int main() {
    std::vector<int> data = {9, 4, 1, 7, 3, 8, 2, 6, 5};

    std::cout << "Оригинал: ";
    printVector(data);

    auto insertionData = data;
    sortlib::insertionSort(insertionData.begin(), insertionData.end());

    std::cout << "Сортировка вставками O(N^2): ";
    printVector(insertionData);

    auto mergeData = data;
    sortlib::mergeSort(mergeData.begin(), mergeData.end());

    std::cout << "Сортировка слиянием O(N log N): ";
    printVector(mergeData);
    return 0;
}