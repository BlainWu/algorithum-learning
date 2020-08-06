# 算法学习
实现语言Python,C++
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
- 跳表：取代平衡树二分查找，多级索引进行加速查找，lookup复杂度降低为O(log<sub>n</sub>
