# -*- coding: UTF-8 -*-
'''=================================================
@Project -> File   ：algorithum-learning -> utils
@IDE    ：PyCharm
@Author ：Blain Wu
@Date   ：2020/9/26 20:49
@Desc   ：
=================================================='''
import random
# 1.参生n - -m范围内的一个随机数: random.randint(n, m)
# 2.产生0到1之间的浮点数: random.random()
# 3.产生n - --m之间的浮点数: random.uniform(1.1, 5.4)
# 4.产生从n - --m间隔为k的整数: random.randrange(n, m, k)
# 5.从序列中随机选取一个元素: random.choice([1, 2, 3, 4, 5, 6, 7, 8, 9, 0])
from functools import wraps
import time


'''生成随机数组'''
def generateRandomArray(length,rangeL,rangeR):
    randomarray = []
    for i in range(length):
        randomint = random.randint(rangeL, rangeR)
        randomarray.append(randomint)
    return randomarray

'''计算函数时间'''
def function_timer(func):
    @wraps(func)
    def timer(*args,**kwargs):
        start = time.time()
        func(*args,**kwargs)
        end = time.time()
        print("程序运行：%f s"%(end-start))
    return timer

'''检验排序是否正确'''
def isSort(array):
    for i in range(len(array)-1):
        if(array[i]>array[i+1]):
            return False
    return True