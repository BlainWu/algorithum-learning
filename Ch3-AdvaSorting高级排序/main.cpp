#include <iostream>
#include "Data.h"
#include "BasicSortMethods.h"
#include "AdvancedSortMethods.h"
#include "SortTestHelper.h"

using namespace std;


int main() {
    int n =500000;

    //int *arr = SortTestHelper::generateNearlyOrderedArray(n,10);
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
    int *arr3 = SortTestHelper::copyIntArray(arr,n);
    int *arr4 = SortTestHelper::copyIntArray(arr,n);
    int *arr5 = SortTestHelper::copyIntArray(arr,n);

    SortTestHelper::testSort("MergeSortBU", MergeSortBU,arr,n);
    SortTestHelper::testSort("QuickSort", QuickSort,arr2,n);
    SortTestHelper::testSort("QuickSort2", QuickSort2,arr3,n);
    SortTestHelper::testSort("QuickSort3", QuickSort3,arr4,n);
    SortTestHelper::testSort("MergeSort", MergeSort,arr5,n);


    delete[] arr;//重要！
    delete[] arr2;//重要！
    delete[] arr3;//重要！
    delete[] arr4;//重要！
    delete[] arr5;//重要！

    return 0;
}