// 1.1. Naive Implementation of Quicksort 

#include <iostream>
#include <vector>


template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    
    if (low < high) 
    {
        T pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; ++j) 
        {
        //in Ascending
        if (arr[j] <= pivot) 
            {
            i++;
            //To prevent swapping a value with ştself
            if (i < j)
                {
                std::swap(arr[i], arr[j]);
                }
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pivotIndex = i+1;

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
