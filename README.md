# 编程实战练习

这是我练习编写`C++`代码的文件，所有注释都是AI生成的。以下是各个项目与项目里我记忆深刻的地方

### [整数方阵求行列式](https://github.com/A2U4F/CppPracticeFiles/blob/main/intDeterminantSolver.cpp)

0. 使用行列式的递归定义直接求解
1. 练习了一下二维`vector`的用法

### [多种计算π的算法](https://github.com/A2U4F/CppPracticeFiles/blob/main/WaysToCalculatePI.cpp)

0. 莱布尼兹公式: π/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + ...
1. `Piece_of_cycle`: 计算落在圆内的点数
2. `Line_of_cycle`: 也是计算落在圆内的点数，但优化了确定在圆内的点不再计算
3. 蒙特卡罗方法: 随机取点，算点落在圆内的概率
4. `Slid_the_cycle`: 几何迭代法，将圆近似成正多边形，计算多边形周长和半径的比值，多边形边数以指数形式增长
5. `Infinite`: 不是我自己写的，但也是公式法

### [模拟手机计算器算法](https://github.com/A2U4F/CppPracticeFiles/blob/main/PhoneCalculatorSimulation.cpp)

0. 手机计算器计算`%`符号时不是数学意义上的*0.01，所以写了这么一个东西
1. 非常感谢[这个博客](https://leetcode.cn/problems/basic-calculator-ii/solutions/91271/chai-jie-fu-za-wen-ti-shi-xian-yi-ge-wan-zheng-ji-)，思路讲解的十分清晰
2. 练习栈的用法和递归

### [枚举求解日历拼图](https://github.com/A2U4F/CppPracticeFiles/blob/main/DatePuzzleSolver.cpp)

0. 日历拼图太难了，所以写了这个算法
1. 其中最关键的`SOLVE()`方法是用的经过`Check()`方法剪枝的回溯算法，但效率极低，实测计算3月6日周四的解法用了55min(在我的电脑配置下)
2. `Check()`方法是用BFS算法(广度优先算法)检查是否有4格连通的小区域，因为没有拼图块是4格大的
3. 练习面向对象编程

### [合并日记文件](https://github.com/A2U4F/CppPracticeFiles/blob/main/DiaryIntegration.cpp)

0. 为了把我每天的日记合并成一个总文件, 写了这样一个小脚本
1. 练习了文件的读取和写入流
