# 五子棋（v1.0）

## 1. 棋盘样式

     ┌─0   1   2   3   4   5   6   7   8   9   10  11 x 
     0 ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬── ○ ──┐
       |   |   |   |   |   |   |   |   |   |   |   |   
     1 ├───┼───┼── ● ──┼───┼───┼───┼───┼───┼───┼───┤
       |   |   |   |   |   |   |   |   |   |   |   |   
     2 ├───┼───┼───┼───┼───┼───┼───┼───┼── ○ ──┼───┤
       |   |   |   |   |   |   |   |   |   |   |   |   
     3 ├───┼───┼───┼── ● ──┼───┼───┼───┼── ○ ──┼───┤
       |   |   |   |   |   |   |   |   |   |   |   |   
     4 ├───┼── ● ──┼───┼───┼───┼───┼───┼───┼───┼───┤
       |   |   |   |   |   |   |   |   |   |   |   |   
     5 ├───┼───┼───┼───┼───┼───┼───┼── ● ──┼───┼───┤
       |   |   |   |   |   |   |   |   |   |   |   |   
     6 ├───┼───┼───┼───┼── ○ ──┼── ○ ──┼───┼───┼───┤
       |   |   |   |   |   |   |   |   |   |   |   |   
     7 ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
       |   |   |   |   |   |   |   |   |   |   |   |   
     8 ├── ○ ──┼───┼───┼───┼── ● ──┼───┼───┼───┼───┤
       |   |   |   |   |   |   |   |   |   |   |   |   
     9 ├───┼───┼── ● ──┼───┼───┼───┼───┼───┼───┼───┤
       |   |   |   |   |   |   |   |   |   |   |   |   
    10 ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
       |   |   |   |   |   |   |   |   |   |   |   |   
    11 └───┴───┴───┴───┴───┴───┴───┴── ● ──┴───┴───┘
     y

## 2. 棋盘尺寸

    每次启动程序都可以通过命令行参数的方式确定棋盘尺寸

## 3. 输入方式

    用户从控制台依次输入x和y坐标来下棋

## 4. PVP模式

    两位棋手先后下棋，任何一位棋手完成一次落子操作后都要进行输赢判别

## 5. 悔棋操作（待实现）

    设置一个快捷键，任何一位棋手执行此快捷键后会在终端中要求输入另一位棋手的密钥以表示另一位棋手同意悔棋

## 6. 复盘操作（待实现）

    完成一局完整的棋局后，自动保存该棋局的落子历史记录，并且支持在程序中有复盘模式可以一步步回顾该棋局
    