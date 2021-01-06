#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <random>
#include <chrono>
#include <numeric>
#include <list>


#ifndef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif


using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::rand;
using std::setfill;
using std::ifstream;
using std::ofstream;
using std::get;
using std::sort;
using std::accumulate;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::list;
using std::wcout;
using std::wstring;


extern "C"
DLL_API void dllmain();

extern "C"
DLL_API void rasom();

extern "C"
DLL_API class duomenys;



#endif