//
// Created by peilin on 2021/7/16.
//

#ifndef ALGORITHMCPP_BASICSORTMETHODS_H
#define ALGORITHMCPP_BASICSORTMETHODS_H

#include <iostream>

using namespace std;

//选择排序
template <typename T>
void selectionSort(T arr[], int n){
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i+1; j < n ;j++){
            if (arr[j]<arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}

//插入排序
template <typename T>
void insertionSort(T arr[], int n){
    for(int i = 1; i < n ; i++){
        for(int j = i; j > 0 ;j --){
            if(arr[j]<arr[j-1]) swap(arr[j], arr[j-1]);
            else break;
        }
    }
}

//改进插入排序
template <typename T>
void improvedInsertionSort(T arr[], int n){
    for(int i = 1 ; i < n ; i ++){
        T temp = arr[i];
        int j ;
        for (j = i; j > 0; j --){
            if(arr[j-1] > temp) arr[j] = arr[j-1];
            else break;
        }
        arr[j] = temp;
    }
}

template <typename T>
void BubbleSort(T arr[], int n){
    bool swapped;

    do{
        swapped = false;
        for(int i = 0; i < n - 1  ; i++){
            if(arr[i] > arr[i+1]) swap(arr[i],arr[i+1]);
            swapped = true;
        }

        //每一次循环都会把最大的元素放在最后面，所以下一次循环可以不考虑最后的元素
        n--;
    }while(swapped);

}


#endif //ALGORITHMCPP_BASICSORTMETHODS_H
