#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int bubbleSort(vector<int>& arr) {
    int comparisons = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return comparisons;
}


int insertionSort(vector<int>& arr) {
    int comparisons = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int quickSortHelper(vector<int>& arr, int low, int high) {
    if (low >= high) return 0;

    int comparisons = 0;
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    int partitionIndex = i + 1;
    comparisons += quickSortHelper(arr, low, partitionIndex - 1);
    comparisons += quickSortHelper(arr, partitionIndex + 1, high);

    return comparisons;
}

int quickSort(vector<int>& arr) {
    return quickSortHelper(arr, 0, arr.size() - 1);
}


void generateArray(vector<int>& arr, int size) {
    arr.resize(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 201 - 100;
    }
}


vector<int> copyArray(const vector<int>& arr) {
    return arr;
}

int main() {
    srand(time(nullptr));
    setlocale(LC_ALL, "Russian");

    const int SIZE = 10000;
    vector<int> originalArray;
    generateArray(originalArray, SIZE);

    cout << "Массив из " << SIZE << " случайных чисел от -100 до 100 создан.\n\n";

   
    vector<int> arr1 = copyArray(originalArray);
    cout << "Пузырьковая сортировка...\n";
    int bubbleComparisons = bubbleSort(arr1);
    cout << "Количество сравнений: " << bubbleComparisons << "\n\n";

   
    vector<int> arr2 = copyArray(originalArray);
    cout << "Сортировка вставками...\n";
    int insertionComparisons = insertionSort(arr2);
    cout << "Количество сравнений: " << insertionComparisons << "\n\n";

   
    vector<int> arr3 = copyArray(originalArray);
    cout << "Быстрая сортировка...\n";
    int quickComparisons = quickSort(arr3);
    cout << "Количество сравнений: " << quickComparisons << "\n\n";

    cout << "=== ИТОГИ ===\n";
    cout << "Пузырьковая сортировка: " << bubbleComparisons << " сравнений\n";
    cout << "Сортировка вставками:   " << insertionComparisons << " сравнений\n";
    cout << "Быстрая сортировка:     " << quickComparisons << " сравнений\n";

    return 0;
}
