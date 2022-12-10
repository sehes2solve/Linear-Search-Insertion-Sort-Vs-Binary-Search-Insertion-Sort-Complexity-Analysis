#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include <ctime>
#include <iomanip>
using namespace std;

void insertionSort(int arr[], int n);
int binarySearch(int a[], int item, int low, int high);
void insertionSort_binary(int a[], int n);
void  generating_numbers(int arr[], int SIZE);
double calc_Normal_time(int arr[], int SIZE);
double calc_Binary_time(int arr[], int SIZE);
void copy_arr(int arr1[] , int arr2[] ,int n);


int main()
{

    int arr1[1000];               generating_numbers(arr1,1000);
    int arr11[1000];                copy_arr(arr1 , arr11,1000);
    int arr2[2000];               generating_numbers(arr2, 2000);
    int arr22[2000];                copy_arr(arr2 , arr22,2000);
    int arr3[3000];               generating_numbers(arr3, 3000);
    int arr33[3000];                copy_arr(arr3 , arr33,3000);
    int arr4[4000];               generating_numbers(arr4, 4000);
    int arr44[4000];                copy_arr(arr4 , arr44,4000);
    int arr5[5000];               generating_numbers(arr5, 5000);
    int arr55[5000];                copy_arr(arr5 , arr55,5000);
    int arr6[6000];               generating_numbers(arr6, 6000);
    int arr66[6000];                copy_arr(arr6, arr66,6000);
    int arr7[7000];              generating_numbers(arr7, 7000);
    int arr77[7000];                copy_arr(arr7 , arr77,7000);
    int arr8[8000];               generating_numbers(arr8, 8000);
    int arr88[8000];                copy_arr(arr8 , arr88,8000);
    int arr9[9000];               generating_numbers(arr9, 9000);
    int arr99[9000];                copy_arr(arr9 , arr99,9000);
    int arr10[10000];              generating_numbers(arr10, 10000);
    int arr1010[10000];             copy_arr(arr10 , arr1010,10000);


    cout << "Time For Normal sort" << "    "<< "Time For Binary Sort" << endl;
    cout <<"1- " << calc_Normal_time(arr1, 1000) << setw(20) << calc_Binary_time(arr11,1000)<< endl;
    cout <<"2- "<< calc_Normal_time(arr2, 2000) << setw(20) << calc_Binary_time(arr22,2000)<< endl;
    cout<<"3- " << calc_Normal_time(arr3, 3000) << setw(20) << calc_Binary_time(arr33,3000)<< endl;
    cout <<"4- "<< calc_Normal_time(arr4, 4000) << setw(20) << calc_Binary_time(arr44,4000)<< endl;
    cout <<"5- "<< calc_Normal_time(arr5, 5000) << setw(20) << calc_Binary_time(arr55,5000)<< endl;
    cout <<"6- "<< calc_Normal_time(arr6, 6000) << setw(20) << calc_Binary_time(arr66,6000)<< endl;
    cout <<"7- "<< calc_Normal_time(arr7, 7000) << setw(20) << calc_Binary_time(arr77,7000)<< endl;
    cout <<"8- "<< calc_Normal_time(arr8, 8000) << setw(20) << calc_Binary_time(arr88,8000)<< endl;
    cout <<"9- "<< calc_Normal_time(arr9, 9000) << setw(20) << calc_Binary_time(arr99,9000)<< endl;
    cout <<"10- "<< calc_Normal_time(arr10, 10000) << setw(20) << calc_Binary_time(arr1010,10000)<< endl;


    return 0;
    }

void copy_arr(int arr1[] , int arr2[] ,int n)
{
    for(int i=0; i < n; i++)
        arr2[i] = arr1[i];
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low;

    int mid = (low + high)/2;

    if(item == a[mid])
        return mid+1;

    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}

// Function to sort an array a[] of size 'n'
void insertionSort_binary(int a[], int n)
{
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

        // find location where selected sould be inseretd
        loc = binarySearch(a, selected, 0, j);

        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}

void  generating_numbers(int arr[], int SIZE)
{
    for(int i =0; i <SIZE ; i++)
    {
        arr[i] = (rand()%10000);
        //cout << arr[i] << "  ";
    }
}
double calc_Normal_time(int arr[], int SIZE)
{
    int ticks = clock();
    insertionSort(arr, SIZE);
    return ((double)ticks / CLOCKS_PER_SEC);
}

double calc_Binary_time(int arr[], int SIZE)
{
    int ticks = clock();
    insertionSort_binary(arr, SIZE);
    return ((double)ticks / CLOCKS_PER_SEC);
}
