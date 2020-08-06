# -*- coding: UTF-8 -*-
'''=================================================
@Project -> File   ：algorithum-learning -> 02-Selection-Sort-Using-utils选择排序
@IDE    ：PyCharm
@Author ：Blain Wu
@Date   ：2020/8/6 18:04
@Desc   ：
=================================================='''
from utils import *

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

if __name__=='__main__':
    array = generateRandomArray(1000, 1, 20)
    print(array)
    selectionSort(array)
    print(array)