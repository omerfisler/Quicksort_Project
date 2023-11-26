// 1.2.  Implementation of Quicksort Using Different Pivoting Strategies 

#include <iostream>
#include <vector>
#include <time.h>

template <typename T>
void insertionSort(std::vector<T>& arr, int low, int high) {
    for (int i = low + 1; i <= high; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
    std::cout<<"insertionSort evoked"<<std::endl;
}


int pivotLast(int low, int high){
    return high;        //Last Index = high 
}


int pivotRandom(int low, int high){
    int randomIndex = low + (rand() % (high - low + 1)); 
    return randomIndex;
}

template <typename T>
int pivotMedianOfThree(std::vector<T>& arr, int low, int high){
    int randomIndex1 = low + (rand() % (high - low + 1));
    int randomIndex2 = low + (rand() % (high - low + 1));
    int randomIndex3 = low + (rand() % (high - low + 1));
    // finding median of three elements algorithm.
    T median = std::max(std::min(arr[randomIndex1], arr[randomIndex2]), std::min(std::max(arr[randomIndex1], arr[randomIndex2]), arr[randomIndex3]));
    if (median == arr[randomIndex1])
        return randomIndex1;
    else if (median == arr[randomIndex2])
        return randomIndex2;
    else
        return randomIndex3;
}

template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high]; // pivot element <-- last element on array
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            if (i<j) // to avoid swapping same elements (when i=j ==> a[i]=a[j]). and also i can't be greater than j due to algorithm.
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSortHybrid(std::vector<T>& arr, int low, int high, char pivotType, int threshold) {
    
    if (low < high) 
    {
        if (high-low+1 <= threshold)
        {
            insertionSort(arr,low,high);
        }
        else
        {
            /* code */
            int pivotIndex;
            switch (pivotType) 
            {
                case 'l':
                    pivotIndex = pivotLast(low, high);break;
                case 'r':
                    pivotIndex = pivotRandom(low, high);break;
                case 'm':
                    pivotIndex = pivotMedianOfThree(arr, low, high);break;
                default:
                    std::cout << "Invalid pivot type" << std::endl; break;       
            }
            std::swap(arr[pivotIndex],arr[high]);
            
            pivotIndex = partition(arr, low, high);

            quickSortHybrid(arr, low, pivotIndex - 1, pivotType, threshold); //Sorting the subarrays
            quickSortHybrid(arr, pivotIndex + 1, high, pivotType, threshold);
        }
    }
}

int main() {
    srand(time(NULL));
    // Example usage
    std::vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
    int n = arr.size();
    //threshold for hybrid quicksort method.
    int k =5;
    char pivotType = 'l';
    std::cout << "Enter pivot strategy (Last Element[l], Random Element[r], Median of 3[m]): ";
    std::cin >> pivotType;
    //example for quicksort function
    quickSortHybrid(arr, 0, n - 1, pivotType, k);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
