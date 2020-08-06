# -*- coding: UTF-8 -*-
'''=================================================
@Project -> File   ：algorithum-learning -> 01-Selection-Sort选择排序.py
@IDE    ：PyCharm
@Author ：Blain Wu
@Date   ：2020/8/6 16:10
@Desc   ：
=================================================='''
'''普通列表排序'''
def selectionSort(list):
    for i in range(len(list)):
        minIndex = i #初始化最小值为最初值
        for j in range(i,len(list)):
            if(list[j]<list[minIndex]):
                minIndex = j
        list[i],list[minIndex] = list[minIndex] ,list[i] #最小值与当前值互换
    return
'''结构体排序'''

def selectionSort_Struct(struct_list):#类似结构的排序方法
    for i in range(len(struct_list)):
        minIndex = i
        for j in range(i,len(struct_list)):
            if(struct_list[j].score > struct_list[minIndex].score):
                minIndex = j
        struct_list[i],struct_list[minIndex] = struct_list[minIndex],struct_list[i]
    return
'''结构体声明'''
class Student:
    def __init__(self,name,score):
        self.name = name
        self.score = score
    def __str__(self):
        return "Student(%s,%.1f)"%(self.name,self.score)

if __name__=="__main__":
    #数字排序测试
    list_num = [10,9,8,7,6,5,4,3,2,1]
    selectionSort(list_num)
    print(list_num)

    #字母排序测试
    list_char = ['D','C', 'B', 'A']
    selectionSort(list_char)
    print(list_char)

    #结构体排序测试
    list_struct =[]
    list_struct.append(Student('B',90))
    list_struct.append(Student('A', 95))
    list_struct.append(Student('C', 60))
    list_struct.append(Student('D', 70))
    selectionSort_Struct(list_struct)

    for i in range(len(list_struct)):
        print(list_struct[i])