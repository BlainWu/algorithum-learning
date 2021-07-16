//
// Created by peilin on 2021/7/16.
//

#ifndef ALGORITHMCPP_SORTTESTHELPER_H
#define ALGORITHMCPP_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;



namespace SortTestHelper{
    //生成随机数组
    int* generateRandomArray(int n, int rangeL, int rangeR){
        int *arr = new int[n];
        assert(rangeL<rangeR);

        srand(time(NULL));
        for (int i = 0;i<n;i++)
            arr[i] = rand()%(rangeR - rangeL + 1) + rangeL;

        return arr;
    }

    //生成近似有序的随机数
    int* generateNearlyOrderedArray(int n ,int swapTimes){
        int* arr = new int[n];
        for(int i = 0; i < n ; i++){
            arr[i] = i;
        }
        srand(time(NULL));
        for(int i = 0; i< swapTimes;i++){
            int pos1 = rand() % n;
            int pos2 = rand() % n;
            swap(arr[pos1],arr[pos2]);
        }
        return arr;
    }

    //打印数组
    template<typename T>
    void printArray(T arr[], int n ){
        for (int i =0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }

    //检测结果
    template<typename T>
    bool isSorted(T arr[],int n){
        for(int i = 0;i < n - 1; i ++)
            if (arr[i] > arr[i+1])
                return false;
        return true;
    }

    //测试性能
    template <typename T>
    void testSort(string sortname,void(*sort)(T[],int),T arr[],int n){

        clock_t start = clock();
        sort(arr,n);
        clock_t end = clock();

        assert(isSorted(arr,n));
        cout<<sortname<<"  :"<< double (end - start) / CLOCKS_PER_SEC << "s"<<endl;
        return;
    }

    //复制数组
    int* copyIntArray(int a[],int n){
        int* arr = new int[n];
        copy(a,a+n,arr);
        return arr;
    }

}

#endif //ALGORITHMCPP_SORTTESTHELPER_H
