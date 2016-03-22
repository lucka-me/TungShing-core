# Tung Shing for Coder

A Tung Shing for Coder, based on [@fake_faith's work on runjs.cn](http://sandbox.runjs.cn/show/ydp3it7b), used to study C and Swift language.

## Description
初学C语言，偶然在推上看到这个“程序员老黄历”，很好玩，又看了一下 JavaScript 代码，发现虽然没学过但很容易懂，看上去也比较简单，于是突发奇想利用现有的一点知识试着做出这个有趣的程序。

这个小程序涵盖了以下个人认为在学习C语言的过程中比较重要但也很难懂的内容：

* 数组的运用
* 函数
* 指针的运用

很适合供和我一样完全没有编程基础的初学编程的同学。

目前只有命令行界面，且代码比较混乱，方法亟待改善，一些功能还未能实现，以后会努力完善代码。

## Supported Features
### C
   | 功能
---|---
✗  | 图形界面
✓  | 显示当前日期
✓  | 根据当前日期和一个种子返回伪随机数
✓  | 随机挑选宜忌事件
✓  | 去除不符合当日的事件
✗  | 查找并替换事件名称字符串中的占位符
✓  | 显示特定日期的事件
✓  | 随机挑选座位朝向
✓  | 随机挑选今日宜饮
✓  | 随机生成女神亲近指数

目前还不会字符串的搜索和编辑，不知道如何查找并替换占位符，故将相关事件删去，也因此最后得到的宜忌事件与原版不同。

### Swift Playground
   | 功能
---|---
✗  | 图形界面
✓  | C 语言版本支持的所有功能
✓  | 查找并替换事件名称字符串中的占位符

Swift 是我2015年下半年在课余时间通过视频自学的，初步掌握了一些基本知识，包括字符串的搜索和编辑（替换），目前还只会在游乐场里玩沙子所以只做了 Playground 版本……  
Swift 感觉比 C 语言更“自由”，功能也更丰富，这使得我能凭借只学了几天的知识实现这个老黄历除图形界面外的全部功能。

## Requirement
### C
* 完全的 C99 标准支持
    * 推荐使用 [Dev-C++](https://sourceforge.net/projects/orwelldevcpp/) 或 [Microsoft Visual Studio Community 2015](https://www.visualstudio.com/zh-cn/dn469161)
    * 不支持 Microsoft Visual C++ 2012 之前的版本，包括 6.0
* 可自行修改代码使其符合 C89 / ANSI C 标准要求

### Swift Playground
* Swift 2
    * Xcode 7 或最新的 Ubuntu 版本