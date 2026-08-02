#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Sort{
    public:
    static void SelectionSort(vector<int>&arr);
    static void BubbleSort(vector<int>&arr);
    static void Insertionsort(vector<int>&arr);
    static void display(const vector<int>&arr);
};

void Sort::BubbleSort( vector<int> &arr){
    int n = arr.size();
   for(int i =0 ; i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
   }
}

void Sort:: SelectionSort(vector<int> &arr){
    int n = arr.size();
    for(int i =0; i<n-1;i++){
        int minIndex=i;
    for(int j=i+1;j<n;i++){
        if(arr[j]<arr[minIndex]){
              minIndex=j;
        }
    }
           swap(arr[i],arr[minIndex]);
}
}

void Sort:: Insertionsort(vector<int> &arr){
    int n = arr.size();
for(int i =1; i<n;i++){
        int key = arr[i];
        int j = i-1;
while(j>=0&& arr[j]>key){
    arr[j+1] = arr[j];
    j--;
}
arr[j+1] = key;
}
}

void Sort::display(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}