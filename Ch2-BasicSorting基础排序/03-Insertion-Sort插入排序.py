# -*- coding: UTF-8 -*-
'''=================================================
@Project -> File   ：algorithum-learning -> 03-Inserting-Sort插入排序
@IDE    ：PyCharm
@Author ：Blain Wu
@Date   ：2020/8/6 20:37
@Desc   ：
=================================================='''
from utils import *

@function_timer
def insertionSort(list):
    for i in range(1,len(list)):#假设第一个已经处于有序列表中
        for j in range(i,0,-1):
            if(list[j]<list[j-1]):
                list[j],list[j-1] = list[j-1],list[j]
            else:
                break
    print("算法：插入排序")

@function_timer
def selectionSort(list):
    for i in range(len(list)):
        minIndex = i #初始化最小值为最初值
        for j in range(i,len(list)):
            if(list[j]<list[minIndex]):
                minIndex = j
        list[i],list[minIndex] = list[minIndex] ,list[i] #最小值与当前值互换
    print("算法：选择排序")
    return

if __name__ == '__main__':
    randomarry = generateRandomArray(1000,0,100)
    insertionSort(randomarry)
    selectionSort(randomarry)
    pass
