//
// Created by peilin on 2021/7/16.
//

#ifndef ALGORITHMCPP_ADVANCEDSORTMETHODS_H
#define ALGORITHMCPP_ADVANCEDSORTMETHODS_H

#include <ctime>
#include "BasicSortMethods.h"

template <typename  T>
void __Merge(T arr[],int left, int mid ,int right){
    T aux[right - left + 1];
    for(int i  = 0; i < right - left + 1; i ++)
        aux[i] = arr[left + i];

    int i = left, j = mid + 1;
    for(int k = left; k <= right; k++){
        if(i > mid){
            arr[k] = aux[j - left];
            j++;
        }
        else if (j > right){
            arr[k] = aux[i - left];
            i++;
        }
        else if(aux[i - left] < aux[j - left]){
            arr[k] = aux[i - left];
            i++;
        }
        else{
            arr[k] = aux[j - left];
            j++;
        }
    }
}

template <typename T>
void __MergeSort(T arr[], int left, int right){

    if(left >= right) return;

    int mid = (left + right) / 2;
    __MergeSort(arr, left, mid);
    __MergeSort(arr, mid + 1, right);
    if(arr[mid] > arr[mid+1])
        __Merge(arr, left , mid, right);

}

//为了统一排序算法的输入格式，才分为MergeSort和__MergeSort
template <typename T>
void MergeSort(T arr[], int n){
    __MergeSort(arr, 0, n-1);
}

template <typename T>
void MergeSortBU(T arr[], int n){
    for(int sz = 1; sz <= n ; sz += sz)
        for( int i = 0; i + sz <n; i += sz*2 )
            __Merge(arr,i,i+sz-1,min(i+2*sz-1,n-1));
}


template <typename T>
int __partiton(T arr[], int left, int right){

    //缓解近乎有序带来的问题
    swap(arr[left], arr[rand()%(right - left + 1) + left]);

    T v = arr[left];

    int j = left;
    for(int i = left +1; i <= right; i++){
        if(arr[i] < v){
            swap(arr[j + 1], arr[i]);
            j++;
        }
    }
    swap(arr[left],arr[j]);
    return j;
}

template <typename T>
void __QuickSort(T arr[], int left, int right){
    if(left>= right) return;
    int p = __partiton(arr,left,right);
    __QuickSort(arr, left, p-1);
    __QuickSort(arr, p+1, right);

}

template <typename T>
void QuickSort(T arr[], int n){
    __QuickSort(arr,0, n-1);
}

template <typename T>
int __partiton2(T arr[], int left, int right){

    swap(arr[left], arr[rand()%(right - left + 1) + left]);
    T v = arr[left];

    int i = left + 1, j = right;
    while(true){
        while(arr[i] < v) i++;
        while(arr[j] > v) j--;
        if(i > j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[left],arr[j]);
    return j;
}

template <typename T>
void __QuickSort2(T arr[], int left, int right){
    if(left >= right) return;

    int p = __partiton2(arr, left, right);
    __QuickSort2(arr, left, p-1);
    __QuickSort2(arr, p+1, right);
}

template <typename T>
void QuickSort2(T arr[], int n){
    __QuickSort2(arr, 0 ,n-1);
}


template <typename T>
void __QuickSort3(T arr[], int left, int right){
    // 这里的partition不再单独书写了，因为返回的指针应该有两个
    // 对于C++来说不好返回（Python容易）

    if (left > right)
        return;

    swap(arr[left], arr[rand()%(right - left + 1) + left]);
    T v = arr[left];

    int lt = left; //arr[left+1 : lt] < v
    int gt = right + 1;//arr[gt : right] > v    初始为空
    int i = left + 1;
    while(i < gt){
        if(arr[i] < v){
            swap(arr[i],arr[lt + 1]);
            lt++;
            i++;
        }
        else if(arr[i] > v){
            swap(arr[i],arr[gt - 1]);
            gt -- ;
        }
        else i++;
    }
    swap(arr[left],arr[lt]);

    __QuickSort3(arr, left,lt -1);
    __QuickSort3(arr, gt ,right);
}


template <typename T>
void QuickSort3(T arr[],int n){
    srand(time(NULL));
    __QuickSort3(arr, 0 ,n-1);
}

#endif //ALGORITHMCPP_ADVANCEDSORTMETHODS_H
