// 1.2.  Implementation of Quicksort Using Different Pivoting Strategies 

#include <iostream>
#include <vector>
#include <time.h>

template <typename T>
int pivotLast(std::vector<T>& arr, int low, int high){
    int LastIndex = high;
    return LastIndex;
}

template <typename T>
int pivotRandom(std::vector<T>& arr, int low, int high){
    int randomIndex = low + (rand() % (high - low + 1)); 
    return randomIndex;
}

template <typename T>
int pivotMedianOfThree(std::vector<T>& arr, int low, int high){
    int randomIndex1 = low + (rand() % (high - low + 1));
    int randomIndex2 = low + (rand() % (high - low + 1));
    int randomIndex3 = low + (rand() % (high - low + 1));
    T median = std::max(std::min(arr[randomIndex1], arr[randomIndex2]), std::min(std::max(arr[randomIndex1], arr[randomIndex2]), arr[randomIndex3]));
    if (median == arr[randomIndex1])
        return randomIndex1;
    else if (median == arr[randomIndex2])
        return randomIndex2;
    else
        return randomIndex3;
}

template <typename T>
void quickSort(std::vector<T>& arr, int low, int high, char pivotType) {
    
    if (low < high) 
    {
        int pivotIndex;
        switch (pivotType) 
        {
            case 'l':
                pivotIndex = pivotLast(arr, low, high);break;
            case 'r':
                pivotIndex = pivotRandom(arr, low, high);break;
            case 'm':
                pivotIndex = pivotMedianOfThree(arr, low, high);break;
            default:
                std::cout << "Invalid pivot type" << std::endl; break;       
        }
        std::swap(arr[pivotIndex],arr[high]);
        T pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) 
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
        pivotIndex = i+1;

        quickSort(arr, low, pivotIndex - 1, pivotType); //Sorting the subarrays
        quickSort(arr, pivotIndex + 1, high, pivotType);
    }
}

int main() {
    srand(time(NULL));
    // Example usage
    std::vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
    int n = arr.size();

    char pivotType = 'l';
    std::cout << "Enter pivot strategy (Last Element[l], Random Element[r], Median of 3[m]): ";
    std::cin >> pivotType;
    //example for quicksort function
    quickSort(arr, 0, n - 1, pivotType);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
