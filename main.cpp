// 1.2.  Implementation of Quicksort Using Different Pivoting Strategies 

#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <sstream>
#include <utility>

using namespace std;


void insertionSort(std::vector<pair<string,int>>& arr, int low, int high) {
    for (int i = low + 1; i <= high; ++i) {
        pair<string,int> key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j].second > key.second) {
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

int pivotMedianOfThree(vector<pair<string,int>>& arr, int low, int high){
    int randomIndex1 = low + (rand() % (high - low + 1));
    int randomIndex2 = low + (rand() % (high - low + 1));
    int randomIndex3 = low + (rand() % (high - low + 1));
    // finding median of three elements algorithm.
    pair<string,int> median;
    // find median by using median formula with min,max functions. Considered the integer values of data. (not string's median)
    median.second = max(min(arr[randomIndex1].second, arr[randomIndex2].second), min(max(arr[randomIndex1].second, arr[randomIndex2].second), arr[randomIndex3].second));
    if (median == arr[randomIndex1])
        return randomIndex1;
    else if (median == arr[randomIndex2])
        return randomIndex2;
    else
        return randomIndex3;
}


int partition(std::vector<pair<string,int>>& arr, int low, int high) {
    pair<string,int> pivot = arr[high]; // pivot element <-- last element on array
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].second <= pivot.second) {
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


void quickSortHybrid(std::vector<pair<string,int>>& arr, int low, int high, char pivotType, int threshold) {
    
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

pair<string, int> parseline(const string& line) {
    stringstream ss(line);
    string token1, token2;

    getline(ss, token1, ';');
    getline(ss, token2);

    int intValue = stoi(token2);
    //Converting string line to (string,int) pair.
    return make_pair(token1, intValue);
}

void readDataFromCSV(const string& filename, vector<pair<string,int>>& arr) {
    
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            // parsed line 
            arr.push_back(parseline(line));
        }

        file.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }

    // return arr;
}

int main() {
    srand(time(NULL));
    string filename="dummyData.csv";
    // Example usage
    vector<pair<string,int>> data;
    readDataFromCSV(filename,data);
    std::vector<int> arr = {2,1,6,9,7,4,3,8,5};
    int n = data.size();
    //threshold for hybrid quicksort method.
    int k =5;
    char pivotType = 'l';
    std::cout << "Enter pivot strategy (Last Element[l], Random Element[r], Median of 3[m]): ";
    std::cin >> pivotType;
    //example for quicksort function
    quickSortHybrid(data, 0, n - 1, pivotType, k);

    std::cout << "Sorted data: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << "\t"<< data[i].first << "\t\t"<<data[i].second<<endl;
    }
    std::cout << std::endl;
    return 0;
}
