***实现语言Python,C++***
#学习资料
- [算法可视化](https://visualgo.net/zh)
# 第一章：基础知识
## 1.1时间复杂度和空间复杂度
**（一）常见七种复杂度**  
- O(1) : Constant Complexity
- O(n) :Linear Complexity
- O(n<sup>2</sup>) : N square Complexity
- O(n<sup>3</sup>) : N cubic Complexity
- O(2<sup>n</sup>) : Exponential Complexity
- O(log<sub>n</sub>) : Logarithmic Complexity
- O(n!) :Factorial

<img src="https://tva1.sinaimg.cn/large/00831rSTly1gcbed227xkj317s0qy77v.jpg" width = 600>

**（二）支配定理**  
对于递归方法的复杂度分析，可使用**master theorem**定理来分析  
参考：[wiki百科-支配定理](https://zh.wikipedia.org/wiki/%E4%B8%BB%E5%AE%9A%E7%90%86)

**（三）数据结构的操作复杂度**  
- 普通链表：lookup的复杂度为O(n)，append、insert、delet为O（1）
- 列表：insert、delete的复杂度为O(n),append、lookup为O（1）
- 跳表：取代平衡树二分查找，多级索引进行加速查找，lookup复杂度降低为O(log<sub>n</sub>;但是维护成本高，空间换时间

**（四）刻意训练方法**
- 5~10分钟思考，有思路可以实现，没有思路直接看题解
- 看题解，背诵熟练（有的解法不好 可以不看）  
- 闭卷测试  
- 练习结果主要看**时间**，空间暂不考虑  
- 同一题要多练几遍！！！，看看网友的优秀方法

## 1.2树、二叉树、二叉搜索树
**（1）二叉树遍历方式**  
树的循环比较麻烦，常用**递归**的方式  
1.前序pre-order : 根-左-右  
2.中序in-order : 左-根-右  
3.后序post-order : 左-右-根  

**（2）二叉搜索树**  
- 特征：左子树上**所有节点**均大于根节点的值；右子树上**所有节点**的值均大于根节点的树。  
- 搜索树的搜索时间复杂度为：O(log<sub>n</sub>)
- [二叉搜索树demo](https://visualgo.net/zh/bst)
.

# 第二章：基础排序  
##2.0工具包utils.py
- 函数计时器：function_timer(func)  
```
使用Python修饰器实现
在定义的函数前面一行 插入一行 @function_timer
即可查看此函数运行时间
```
- 随机数组生成器：generateRandomArray(length,rangeL,rangeR)
```
返回length长度，且在（rangeL,rangeR)范围内的整数数组
```
- 检验排序是否正确：isSort(array)
##2.1 & 2.2选择排序  
**基本思路**：遍历列表中的值，搜寻该值以后所有值中的最小值，与之替换。  
**时间复杂度**：O（n<sup>2</sup>）
```
Python实现结构体：使用Class做定义，手动初始化和排序
```
##2.3插入排序
**基本思路**：遍历列表中的值，选中以后插入有序列表中的应有的位置，理论上通常比选择排序快一点。  
**时间复杂度**：O（n<sup>2</sup>）  
**算法改进**：实际操作时，发现插入排序反而比选择排序耗时。因为虽然判断的少，但是交换次数多，耗时反而比较长。
因此优化方法为：先把遍历位置的值取出保存，再与前一个比较大小，如果前一个大于当前值，则直接将前一个值后移。
如果小于则将缓存放在此处，减少交换产生的赋值次数。
```buildoutcfg
算法：插入排序
程序运行：0.083029 s

算法：选择排序
程序运行：0.046010 s
```
