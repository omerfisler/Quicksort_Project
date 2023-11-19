// 1.1. Naive Implementation of Quicksort 

#include <iostream>
#include <vector>

template <typename T>
int quickSortPartition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        //in Ascending
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = quickSortPartition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1); //Sorting the subarrays
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Example usage
    std::vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
    int n = arr.size();

    //example for quicksort function
    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
