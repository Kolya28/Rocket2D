﻿// pch.h: это предварительно скомпилированный заголовочный файл.
// Перечисленные ниже файлы компилируются только один раз, что ускоряет последующие сборки.
// Это также влияет на работу IntelliSense, включая многие функции просмотра и завершения кода.
// Однако изменение любого из приведенных здесь файлов между операциями сборки приведет к повторной компиляции всех(!) этих файлов.
// Не добавляйте сюда файлы, которые планируете часто изменять, так как в этом случае выигрыша в производительности не будет.

#ifndef PCH_H
#define PCH_H


#include<iostream>
#include<thread>
#include<chrono>

#include <locale>
#include <codecvt>
#include <string>
#include<vector>

#include<algorithm>
#include<cmath>
#include<deque>
#include<sstream>
#include<functional>

#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>

#include<Windows.h>

namespace chrono = std::chrono;

#endif //PCH_H
