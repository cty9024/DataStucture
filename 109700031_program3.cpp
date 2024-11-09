#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

const int MAX = 1000;

void PrintArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
}

void InsertionSort(int *arr, int size, int q){

    for (int i = 1; i < size; i++) {
        //PrintArray(arr, size);
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        if(q == 0)cout << i << " : ";
        if(q == 0)PrintArray(arr, size);
    }
}
/*
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int *arr, int front, int end, int size, int q){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        if(q == 0)cout << front << "-" << end << " :" << endl;
        if(q == 0)PrintArray(arr, size);
        QuickSort(arr, front, pivot - 1, size, q);
        QuickSort(arr, pivot + 1, end, size, q);
    }
}
*/

int partition(int *arr, int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void QuickSort(int *arr, int start, int end, int size, int q)
{
 
    if (start >= end)
        return;
 
    int p = partition(arr, start, end);
    if(q == 0)cout << start << "-" << end << " :" << endl;
    if(q == 0)PrintArray(arr, size);
    QuickSort(arr, start, p - 1, size, q);
 
    QuickSort(arr, p + 1, end, size, q);
}
void RadixSortLSD(int *a, int arraySize, int q)
{
    int i, bucket[MAX], maxVal = 0, digitPosition =1 ;
    for(i = 0; i < arraySize; i++) {
        if(a[i] > maxVal) maxVal = a[i];
    }

    int pass = 1;  // used to show the progress
    while(maxVal/digitPosition > 0) {
        int digitCount[10] = {0};

        for(i = 0; i < arraySize; i++)
            digitCount[a[i]/digitPosition%10]++;

        for(i = 1; i < 10; i++)
            digitCount[i] += digitCount[i-1];

        for(i = arraySize - 1; i >= 0; i--)
            bucket[--digitCount[a[i]/digitPosition%10]] = a[i];

        for(i = 0; i < arraySize; i++)
            a[i] = bucket[i];

        if(q == 0){
            if(pass == 1){
                cout << "First-pass:" << endl;
                for(int j = 0; j < 10; j++){
                    cout << j << " | ";
                    for(int k = 0; k < arraySize; k++){
                        if(bucket[k] % 10 == j){
                            cout << " --> " << a[k];
                        }
                    }
                    cout << endl;
                }
            }else if(pass == 2){
                cout << "Second-pass:" << endl;
                for(int j = 0; j < 10; j++){
                    cout << j << " | ";
                    for(int k = 0; k < arraySize; k++){
                        if((bucket[k] / 10) % 10 == j){
                            cout << " --> " << a[k];
                        }
                    }
                    cout << endl;
                }
            }else if(pass == 3){
                cout << "Second-pass:" << endl;
                for(int j = 0; j < 10; j++){
                    cout << j << " | ";
                    for(int k = 0; k < arraySize; k++){
                        if((bucket[k] / 100) % 10 == j){
                            cout << " --> " << a[k];
                        }
                    }
                    cout << endl;
                }
            }else if(pass == 4){
                cout << "Second-pass:" << endl;
                for(int j = 0; j < 10; j++){
                    cout << j << " | ";
                    for(int k = 0; k < arraySize; k++){
                        if((bucket[k] / 1000) % 10 == j){
                            cout << " --> " << a[k];
                        }
                    }
                    cout << endl;
                }
            }


            cout << "resluting chain :" ;
            //print(a,arraySize);
            PrintArray(a, arraySize);
        }
        
        



        

        /* move up the digit position */
        digitPosition *= 10;
        pass++;
    }   
 }

int main() {
    cout << "DS-00 Program3-Demo" << endl;
    int input;
    clock_t time_req;
    time_req = clock();
    cin >> input;
    if(input < 0){
        int n = 11;
        int A[11]= {168,179,208,306,93,859,984,55,9,271,33};
        int B[11];
        int C[11];
        for(int i = 0; i < n; i++){
            B[i] = A[i];
        }
        for(int i = 0; i < n; i++){
            C[i] = A[i];
        }

        cout << "Before : ";
        PrintArray(A, n);
        cout << endl;
        cout << "Insertion sort:" << endl;
        InsertionSort(A, n, 0);
        time_req = clock() - time_req;
        cout << "sorting time : " << (float)time_req * 0.001 << " s" << endl;
        //cout << "----------------------" << endl;
        cout << endl;
        time_req = clock();
        cout << "Quick sort:" << endl;
        cout << "Before : " << endl;
        PrintArray(B, n);
        //cout << endl;
        QuickSort(B, 0, n-1, n, 0); 
        time_req = clock() - time_req;
        cout << "sorting time : " << (float)time_req * 0.001 << " s" << endl;
        int flag = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == B[i]){
                continue;
            }else{
                flag = 1;
            }
        }
        if(flag == 0){
            cout << "Correct!!" << endl;
        }
        //cout << "----------------------" << endl;
        cout << endl;
        cout << "Radix sort :" << endl;
        time_req = clock();
        RadixSortLSD(C, n, 0);
        time_req = clock() - time_req;
        cout << "sorting time : " << (float)time_req * 0.001 << " s" << endl;
    }else{
        int A[input];
        int n = input;
        int q = 0;
        if(input > 100) q = 1;
        for(int i = 0; i < input; i++){
            //srand( time(NULL) );
            A[i] = rand() % 1000;

        }
        int B[input];
        int C[input];
        for(int i = 0; i < input; i++){
            B[i] = A[i];
            //cout << A[i] << endl;
        }
        for(int i = 0; i < input; i++){
            C[i] = A[i];
        }

        cout << "Insertion sort:" << endl;
        InsertionSort(A, input, q);
        time_req = clock() - time_req;
        cout << "sorting time : " << (float)time_req * 0.001 << " s" << endl;
        //cout << "----------------------" << endl;
        cout << endl;
        time_req = clock();
        cout << "Quick sort:" << endl;
        QuickSort(B, 0, n-1, n, q); 
        time_req = clock() - time_req;
        cout << "sorting time : " << (float)time_req * 0.001 << " s" << endl;
        int flag1 = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == B[i]){
                continue;
            }else{
                flag1 = 1;
            }
        }
        if(flag1 == 0){
            cout << "Correct!!" << endl;
        }
        //cout << "----------------------" << endl;
        cout << endl;
        cout << "Radix sort :" << endl;
        time_req = clock();
        RadixSortLSD(C, n, q);
        time_req = clock() - time_req;
        cout << "sorting time : " << (float)time_req * 0.001 << " s" << endl;
        int flag2 = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == B[i]){
                continue;
            }else{
                flag2 = 1;
            }
        }
        if(flag2 == 0){
            cout << "Correct!!" << endl;
        }
    }
    return 0;
}