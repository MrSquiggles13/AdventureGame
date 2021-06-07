#pragma once
#include <array>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <conio.h>
#include <random>
#include <stdlib.h>
#include <string>
#include <string_view>
#include <thread>
#include <vector>
#include <iostream>

extern inline std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

struct slowPrint { std::string data; long int delay{ 28 }; };
std::ostream& operator<< (std::ostream& out, const slowPrint& str);

int errorHandle(const int& input);

char errorHandle(const char& input);