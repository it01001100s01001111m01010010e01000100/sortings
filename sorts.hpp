#pragma once
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

namespace sortlib {

// O(n^2)  сортировка вставками
template <typename RandomIt, typename Compare = std::less<>>
void insertionSort(RandomIt first, RandomIt last, Compare comp = Compare{}) {
    if (first == last) {
        return;
    }

    for (auto it = first + 1; it != last; ++it) {
        auto value = std::move(*it);
        auto current = it;

        while (current != first && comp(value, *(current - 1))) {
            *current = std::move(*(current - 1));
            --current;
        }

        *current = std::move(value);
    }
}


// O(n log n)- сортировка слиянием
template <typename RandomIt, typename Compare = std::less<>>
void mergeSort(RandomIt first, RandomIt last, Compare comp = Compare{}) {
    auto size = last - first;

    if (size <= 1) {
        return;
    }

    auto middle = first + size / 2;

    mergeSort(first, middle, comp);
    mergeSort(middle, last, comp);

    using ValueType = typename std::iterator_traits<RandomIt>::value_type;
    std::vector<ValueType> buffer;
    buffer.reserve(size);

    auto left = first;
    auto right = middle;

    while (left != middle && right != last) {
        if (comp(*right, *left)) {
            buffer.push_back(*right);
            ++right;
        } else {
            buffer.push_back(*left);
            ++left;
        }
    }


    while (left != middle) {
        buffer.push_back(*left);
        ++left;
    }
    
    while (right != last) {
        buffer.push_back(*right);
        ++right;
    }

    std::move(buffer.begin(), buffer.end(), first);
}
}