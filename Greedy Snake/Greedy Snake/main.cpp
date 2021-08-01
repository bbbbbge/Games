#define _CRT_SECURE_NO_WARNINGS 1

#include "state.h"

int main()
{
	srand((unsigned int)time(NULL));
	again:
	menuInit();
	MOUSEMSG m;
	while (true)
	{
		mciSendString(TEXT("open C:\\Users\\bbbbbge\\music\\Schnappi.mp3 alias music1"), NULL, 0, NULL);
		m = GetMouseMsg();
		if (m.x >= 150 && m.x <= 225 && m.y >= 345 && m.y <= 370 && m.uMsg == WM_LBUTTONDOWN)		//打开音乐
			mciSendString(TEXT("play music1 repeat"), NULL, 0, NULL);
		if (m.x >= 390 && m.x <= 465 && m.y >= 345 && m.y <= 370 && m.uMsg == WM_LBUTTONDOWN)		//关闭音乐
			mciSendString(TEXT("close music1"), NULL, 0, NULL);
		if (m.x >= 150 && m.x <= 225 && m.y >= 245 && m.y <= 270 && m.uMsg == WM_LBUTTONDOWN)		//普通模式
		{
			gameInit1();
			while (true)
			{
				gameDraw1();
				if (!snakeMove1()) goto over;
				keyControl();
				Eat();
				Sleep(60);
			}
		}
		else if (m.x >= 270 && m.x <= 345 && m.y >= 245 && m.y <= 270 && m.uMsg == WM_LBUTTONDOWN)	//无尽模式
		{
			gameInit1();
			while (true)
			{
				gameDraw2();
				if (!snakeMove2()) goto over;
				keyControl();
				Eat();
				Sleep(60);
			}
		}
		else if (m.x >= 390 && m.x <= 465 && m.y >= 245 && m.y <= 270 && m.uMsg == WM_LBUTTONDOWN)	//障碍模式
		{
			gameInit2();
			while (true)
			{
				gameDraw3();
				if (!snakeMove2()) goto over;
				keyControl();
				Eat();
				Sleep(60);
			}
		}
		else if (m.x >= 390 && m.x <= 465 && m.y >= 295 && m.y <= 320 && m.uMsg == WM_LBUTTONDOWN)	//退出游戏
		{
			gameExit();
			Sleep(3000);
			return 0;
		}
	}
over:
	gameOver();
	Sleep(3000);
	goto again;

	return 0;
}