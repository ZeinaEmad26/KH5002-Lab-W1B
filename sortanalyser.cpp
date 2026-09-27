#include <iostream>
#include <algorithm>
using namespace std;

class SortAnalyser {
public:

    // Bubble Sort
    void bubbleSort(int arr[], int n, long long& counter) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {

                counter++; // count comparison

                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }


    // Selection Sort
    void selectionSort(int arr[], int n, long long& counter) {
        for (int i = 0; i < n - 1; i++) {

            int minIndex = i;

            for (int j = i + 1; j < n; j++) {

                counter++; // count comparison

                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }

            if (minIndex != i)
                swap(arr[i], arr[minIndex]);
        }
    }


    // Insertion Sort
    void insertionSort(int arr[], int n, long long& counter) {
        for (int i = 1; i < n; i++) {

            int key = arr[i];
            int j = i - 1;

            while (j >= 0) {

                counter++; // count comparison

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
    }
};