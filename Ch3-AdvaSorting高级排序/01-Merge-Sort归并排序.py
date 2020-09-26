# -*- coding: UTF-8 -*-
'''=================================================
@Project -> File   ：algorithum-learning -> 01-Merge-Sort归并排序
@IDE    ：PyCharm
@Author ：Blain Wu
@Date   ：2020/8/7 11:55
@Desc   ：
=================================================='''
from utils import *

@function_timer
def merge_sort(arr):
    __merge_sort(arr, 0, len(arr) - 1)

def __merge_sort(arr, l, r):
    """递归使用归并排序，对arr[l...r]的范围进行排序"""
    if r <= l :
        return
    mid = l + (r - l) // 2
    __merge_sort(arr, l, mid)
    __merge_sort(arr, mid + 1, r)
    __merge(arr, l, mid, r)

def __merge(arr, l, mid, r):
    """将arr[l...mid]和arr[mid+1...r]两部分进行归并"""
    aux = [arr[i] for i in range(l, r + 1)]
    i, j = l, mid + 1
    for k in range(l, r + 1):
        if i > mid:
            arr[k] = aux[j - l]
            j += 1
        elif j > r:
            arr[k] = aux[i - l]
            i += 1
        elif aux[i - l] < aux[j - l]:
            arr[k] = aux[i - l]
            i += 1
        else:
            arr[k] = aux[j - l]
            j += 1

if __name__ == '__main__':
    arr = generateRandomArray(3000,1,100)
    merge_sort(arr)