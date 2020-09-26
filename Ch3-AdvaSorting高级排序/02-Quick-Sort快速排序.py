# -*- coding: UTF-8 -*-
'''=================================================
@Project -> File   ：algorithum-learning -> 02-Quick-Sort快速排序
@IDE    ：PyCharm
@Author ：Blain Wu
@Date   ：2020/9/24 0:06
@Desc   ：
=================================================='''
import random
from utils import generateRandomArray,function_timer


'''使用递归，所以用两个不同的函数'''
@function_timer
def quickSort(arr):
    __quickSort(arr,0,len(arr)-1)

def __quickSort(arr,l,r):
    if l>=r:
        return
    p = __partition(arr,l,r)
    __quickSort(arr,l,p-1)
    __quickSort(arr,p+1,r)

def __partition(arr,l,r):
    #random_index = random.randint(l,r)
    #arr[l],arr[random_index] = arr[random_index],arr[l]
    v,j = arr[l],l
    for  i in range(l+1,len(arr)-1):
        if arr[i] < v:
            arr[i],arr[j+1] = arr[j+1],arr[i]
            j+=1
    arr[l],arr[j] = arr[j],arr[l]
    return j

@function_timer
def quickSort_rand(arr):
    __quickSort_rand(arr,0,len(arr)-1)

def __quickSort_rand(arr,l,r):
    if l>=r:
        return
    p = __partition_rand(arr,l,r)
    __quickSort_rand(arr,l,p-1)
    __quickSort_rand(arr,p+1,r)

def __partition_rand(arr,l,r):
    random_index = random.randint(l,r)
    arr[l],arr[random_index] = arr[random_index],arr[l]
    v = arr[l]
    j=l
    for  i in range(l+1,len(arr)-1):
        if arr[i] < v:
            arr[i],arr[j+1] = arr[j+1],arr[i]
            j+=1
    arr[l],arr[j] = arr[j],arr[l]
    return j

'''双路快排'''
@function_timer
def quickSort2(arr):
    __quickSort2(arr,0,len(arr)-1)

def __quickSort2(arr,l,r):
    if l>=r:
        return
    p = __partition2(arr,l,r)
    __quickSort2(arr,l,p-1)
    __quickSort2(arr,p+1,r)

def __partition2(arr,l,r):
    pass


if __name__ == '__main__':
    arr = generateRandomArray(3000,1,100)
    arr1 = arr.copy()
    arr2 = arr.copy()
    quickSort(arr1)
    quickSort_rand(arr2)
    #print(arr)