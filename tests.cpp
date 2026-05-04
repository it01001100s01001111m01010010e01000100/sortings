#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include "sorts.hpp"


template <typename SortFunction>
void testAscendingSort(SortFunction sortFunction) {
    std::vector<std::vector<int>> testCases = {
        {},
        {1},
        {2, 1},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {3, 1, 2, 3, 1, 2},
        {-5, 10, 0, -1, 7},
        {100, -100, 50, 0, 50, -100}
    };

    for (auto values : testCases) {
        auto expected = values;

        std::sort(expected.begin(), expected.end());
        sortFunction(values);

        assert(values == expected);
    }
}


int main() {
    testAscendingSort([](std::vector<int>& values) {
        sortlib::insertionSort(values.begin(), values.end());
    });

    testAscendingSort([](std::vector<int>& values) {
        sortlib::mergeSort(values.begin(), values.end());
    });

    std::cout << "Все тесты пройдены!\n";

    return 0;
}