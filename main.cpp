#include <iostream>
#include "sortanalyser.cpp"

using namespace std;


// Copies the original array so every sorting algorithm
// starts with the same data
void copyArr(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}


// Prints the array
void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i < n - 1 ? " " : "\n");
    }
}


int main() {

    SortAnalyser sa;

    long long c;
    int tmp[10];

    int rand10[] = {64, 34, 25, 12, 22, 11, 90, 45, 7, 80};
    int n = 10;


    // TC1 - Bubble Sort on random array
    c = 0;
    copyArr(rand10, tmp, n);
    sa.bubbleSort(tmp, n, c);

    cout << "TC1 bubble sorted: ";
    printArr(tmp, n);
    cout << "TC1 comparisons: " << c << endl;


    // TC2 - Selection Sort on random array
    c = 0;
    copyArr(rand10, tmp, n);
    sa.selectionSort(tmp, n, c);

    cout << "TC2 selection sorted: ";
    printArr(tmp, n);
    cout << "TC2 comparisons: " << c << endl;


    // TC3 - Insertion Sort on random array
    c = 0;
    copyArr(rand10, tmp, n);
    sa.insertionSort(tmp, n, c);

    cout << "TC3 insertion sorted: ";
    printArr(tmp, n);
    cout << "TC3 comparisons: " << c << endl;


    // Already sorted array
    int sorted10[] = {1,2,3,4,5,6,7,8,9,10};


    // TC4 - Bubble Sort on sorted array
    c = 0;
    copyArr(sorted10, tmp, n);
    sa.bubbleSort(tmp, n, c);

    cout << "TC4 bubble on sorted, comparisons: "
         << c << endl;


    // TC5 - Insertion Sort on sorted array
    c = 0;
    copyArr(sorted10, tmp, n);
    sa.insertionSort(tmp, n, c);

    cout << "TC5 insertion on sorted, comparisons: "
         << c << endl;


    // Reverse sorted array
    int rev10[] = {10,9,8,7,6,5,4,3,2,1};


    // TC6 - Bubble Sort on reverse array
    c = 0;
    copyArr(rev10, tmp, n);
    sa.bubbleSort(tmp, n, c);

    cout << "TC6 bubble on reverse, comparisons: "
         << c << endl;


    // TC7 - Insertion Sort on reverse array
    c = 0;
    copyArr(rev10, tmp, n);
    sa.insertionSort(tmp, n, c);

    cout << "TC7 insertion on reverse, comparisons: "
         << c << endl;


    return 0;
}