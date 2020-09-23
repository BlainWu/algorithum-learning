# -*- coding: UTF-8 -*-
'''=================================================
@Project -> File   ：algorithum-learning -> 04-ShellSort希尔排序
@IDE    ：PyCharm
@Author ：Blain Wu
@Date   ：2020/8/7 11:10
@Desc   ：
=================================================='''
from utils import *
@function_timer
def insertionSortProProPro(array):
    for i in range(len(array)):
        for j in range(i):
            if array[i] < array[j]:
                array.insert(j, array.pop(i))
                break
    print("算法：优化后插入排序")

@function_timer
def shellSort(arr):
    n = len(arr)
    gap = int(n / 2)

    while gap > 0:

        for i in range(gap, n):

            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap = int(gap / 2)
    print("算法：希尔排序")

@function_timer
def pythonSort(arr):
    arr.sort()
    print("算法：python自带")

if __name__ == '__main__':
    randomarry = generateRandomArray(10000,0,100)
    randomarry1 = randomarry.copy()
    randomarry2 = randomarry.copy()
    randomarry3 = randomarry.copy()
    insertionSortProProPro(randomarry1)
    shellSort(randomarry2)
    pythonSort(randomarry3)
