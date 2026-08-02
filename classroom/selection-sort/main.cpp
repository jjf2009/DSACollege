#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int SI = i;  // Smallest Index
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[SI]) {
                SI = j;  // Update smallest element index
            }
            swap(arr[i], arr[SI]);
        }
        // swap(arr[i], arr[SI]);  // Swap only once per iteration
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
