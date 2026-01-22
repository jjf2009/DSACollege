#include<iostream>
#include "10.hpp"
using namespace std;

int main(){
    vector<int> arr;
    int n,choice ;
    cout<<"Enter Number of Elements:";
    cin>>n;
    arr.resize(n);
    cout<<"Enter Elements";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"1.Selection Sort";
    cout<<"2.Bubble Sort";
    cout<<"3.Insertion Sort";
    do{
       cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Sort::SelectionSort(arr);
            cout<<"Arry  after Selection Sort:\n";
            Sort::display(arr);
            break;
        case 2:
            Sort::BubbleSort(arr);
            cout<<"Arry  after Selection Sort:\n";
            Sort::display(arr);
            break;
        case 3:
            Sort::Insertionsort(arr);
            cout<<"Arry  after Selection Sort:\n";
            Sort::display(arr);
            break;
        default:
            break;
        }
    }while(choice!=4);

    return 0;
}