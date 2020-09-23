# -*- coding: UTF-8 -*-
'''=================================================
@Project -> File   ：algorithum-learning -> 01-Merge-Sort归并排序
@IDE    ：PyCharm
@Author ：Blain Wu
@Date   ：2020/8/7 11:55
@Desc   ：
=================================================='''
from utils import *

def merge_sort(arr):
    __merge_sort(arr,0,len(arr)-1)

def __merge_sort(arr,l,r):
    if l>=r :
        return
    mid = l + (r-l) // 2
    __merge_sort(arr,l,mid)
    __merge_sort(arr,mid+1,r)
    if(arr[mid]>arr[mid+1]):
        __merge(arr,l,mid,r)

def __merge(arr,l,mid,r):
    aux = [arr[i] for i in range(l,r+1)]
    i , j = 1 , mid+1
    for k in range(l,r+1):
        if aux[i-1] < aux[j-1]:
            arr[k] = aux[i-1]
            i+=1
        elif aux[i-1] >=aux[j-1]:
            arr[l] = aux[j-1]
            j+=1
        elif i>mid:
            arr[k] = aux[j-l]
            j+=1
        elif j>r:
            arr[k] = aux[i-1]
            i+=1


if __name__ == '__main__':
    pass