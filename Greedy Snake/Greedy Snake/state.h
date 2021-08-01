#pragma once

#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<mmstream.h>
#pragma comment(lib ,"winmm.lib")	// 多媒体设备接口

void Eat();

void gameInit1();

void gameInit2();

void wallDraw();

void gameDraw1();

void gameDraw2();

void gameDraw3();

void keyControl();

bool snakeMove1();

bool snakeMove2();

void menuInit();

void gameExit();

void gameOver();
