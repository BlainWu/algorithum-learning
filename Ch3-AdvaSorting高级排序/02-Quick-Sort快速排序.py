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
    if l>=r :
        return
    p = __partition2(arr,l,r)
    __quickSort2(arr,l,p-1)
    __quickSort2(arr,p+1,r)

def __partition2(arr,l,r):
    random_index = random.randint(l,r)
    arr[l],arr[random_index] = arr[random_index],arr[l]
    i,j,v = l+1,r,arr[l]

    while True:
        while i<=r and arr[i]<v:
            i+=1
        while j>=l+1 and arr[j]>v:
            j-=1
        if j<i:
            break

        arr[i],arr[j] = arr[j],arr[i]
        i+=1
        j-=1

    arr[l],arr[j] = arr[j],arr[l]
    return j

@function_timer
def quickSort3(arr):
    __quickSort3(arr,0,len(arr)-1)

def __quickSort3(arr,l,r):
    if l>=r:
        return
    #patition

    #init
    random_index = random.randint(l, r)
    arr[l], arr[random_index] = arr[random_index], arr[l]
    v = arr[l]
    lt = l
    gt = r+1
    i = l+1
    while i < gt:
        if arr[i]<v:
            arr[lt+1],arr[i] = arr[i],arr[lt+1]
            lt+=1
            i+=1
        elif arr[i]>v:
            arr[i],arr[gt-1] = arr[gt-1],arr[i]
            gt-=1
        else:
            i+=1
    arr[l],arr[lt] = arr[lt],arr[l]
    __quickSort3(arr,l,lt-1)
    __quickSort3(arr,gt,r)



if __name__ == '__main__':
    arr = generateRandomArray(10000,1,100000)
    arr1 = arr.copy()
    arr2 = arr.copy()
    arr3 = arr.copy()
    arr4 = arr.copy()
    #quickSort(arr1)
    #quickSort_rand(arr2)
    quickSort2(arr3)
    quickSort3(arr4)
    #print(arr)