// stdafx.h: 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 项目特定的包含文件
//

#pragma once
#define flash_speed 40//刷新频率，现为一秒25次
#define datum_line 0//基准线，即忍者初始位置
#define jump_speed 10//跳跃初始速度
#define gravity 9.8//重力加速度
#define run_speed 10//跑步速度
#define time_interval 0.25//时间间隔
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
// Windows 头文件
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include<string>
#include<vector>
#include<deque>
using std::string;
using std::vector;
using std::deque;


// 在此处引用程序需要的其他标头