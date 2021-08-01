#define _CRT_SECURE_NO_WARNINGS 1

#include "state.h"

#define width 640
#define heigth 400
#define SNAKE_MAX 400
#define WALL_MAX 10

IMAGE img1, img2, img3, img4, img5;

struct Snake
{
	int size;					//�ߵĳ���
	int speed;					//�ߵ��ٶ�
	int dir;					//�ߵķ���
	POINT coor[SNAKE_MAX];		//�ߵ���󳤶�
}snake;

struct Food
{
	int x;
	int y;
	int r;
	bool flag;					//1 û�гԵ� 0 �Ե���
	DWORD color;
}food;

struct Wall
{
	int x1, y1, x2, y2;
	DWORD color;
}wall[10];

enum Dir
{
	UP, DOWN, LEFT, RIGHT
};

void Eat()
{
	if (food.flag && snake.coor[0].x >= food.x - food.r && snake.coor[0].x <= food.x + food.r && snake.coor[0].y >= food.y - food.r && snake.coor[0].y <= food.y + food.r)
	{
		food.flag = false;
		switch (food.r / 5)
		{
		case 1:
			snake.size += 1;
			break;
		case 2:
			snake.size += 2;
			break;
		case 3:
			snake.size += 3;
			break;
		default:
			break;
		}
	}
	if (!food.flag)
	{
		food.x = rand() % width;		//��ʼ��x
		food.y = rand() % heigth;		//��ʼ��y
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = rand() % 15 + 5;
		food.flag = true;
	}
}

void gameInit1()
{
	initgraph(width, heigth);
	//С�߳�ʼ��
	snake.size = 3;
	snake.speed = 10;
	snake.dir = LEFT;
	for (int i = snake.size - 1; i >= 0; i--)
	{
		snake.coor[i].x = 10 * i + 400;
		snake.coor[i].y = 30;
	}
	food.r = rand() % 16 + 5;
	food.x = rand() % width;		//��ʼ��x
	food.y = rand() % heigth;		//��ʼ��y
	
	if (food.x < food.r) food.x += food.r;
	if (width - food.x < food.r) food.x -= food.r;
	if (food.y < food.r) food.y += food.r;
	if (heigth - food.y < food.r) food.y -= food.r;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.flag = true;

}

void gameInit2()
{
	initgraph(width, heigth);
	//С�߳�ʼ��
	snake.size = 3;
	snake.speed = 10;
	snake.dir = LEFT;
	for (int i = snake.size - 1; i >= 0; i--)
	{
		snake.coor[i].x = 10 * i + 400;
		snake.coor[i].y = 30;
	}

	wall[0] = { 60,0,80,100 };
	wall[1] = { 80,80,200,100 };
	wall[2] = { 180,100,200,200 };
	wall[3] = { 200,180,320,200 };
	wall[4] = { 0,180,80,200 };
	wall[5] = { 60,280,400,300 };
	wall[6] = { 280,80,480,100 };
	wall[7] = { 460,100,480,200 };
	wall[8] = { 540,0,560,200 };
	wall[9] = { 540,200,560,400 };
	food.r = rand() % 16 + 5;
	food.x = rand() % width;		//��ʼ��x
	food.y = rand() % heigth;		//��ʼ��y

	if (food.x < food.r) food.x += food.r;
	if (width - food.x < food.r) food.x -= food.r;
	if (food.y < food.r) food.y += food.r;
	if (heigth - food.y < food.r) food.y -= food.r;
	food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
	food.flag = true;

}

void gameDraw1()
{
	loadimage(&img4, "ͼ4.png", width, heigth);
	putimage(0, 0, &img4);
	setfillcolor(RGB(61, 89, 171));
	for (int i = 0; i < snake.size; i++)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	setfillcolor(food.color);
	if (food.flag)
		solidcircle(food.x, food.y, food.r);
	EndBatchDraw();					//������������
}

void gameDraw2()
{
	loadimage(&img5, "ͼ5.jpg", width, heigth);
	putimage(0, 0, &img5);
	setfillcolor(RGB(61, 89, 171));
	for (int i = 0; i < snake.size; i++)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	setfillcolor(food.color);
	if (food.flag)
		solidcircle(food.x, food.y, food.r);
	EndBatchDraw();					//������������
}

void gameDraw3()
{
	loadimage(&img4, "ͼ4.png", width, heigth);
	putimage(0, 0, &img4);
	wallDraw();
	setfillcolor(RGB(61, 89, 171));
	for (int i = 0; i < snake.size; i++)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	setfillcolor(food.color);
	if (food.flag)
		solidcircle(food.x, food.y, food.r);
	EndBatchDraw();					//������������
}

void keyControl()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'W':
		case 'w':
		case 72:
			if (snake.dir != DOWN)
				snake.dir = UP;
			break;
		case 'S':
		case 's':
		case 80:
			if (snake.dir != UP)
				snake.dir = DOWN;
			break;
		case 'A':
		case 'a':
		case 75:
			if (snake.dir != RIGHT)
				snake.dir = LEFT;
			break;
		case 'D':
		case 'd':
		case 77:
			if (snake.dir != LEFT)
				snake.dir = RIGHT;
			break;
		case ' ':
			while (_getch() != ' ');
			break;
		}
	}
}

bool snakeMove1()
{
	for (int i = snake.size - 1; i > 0; i--)
	{
		snake.coor[i] = snake.coor[i - 1];
	}
	switch (snake.dir)
	{
	case UP:
		snake.coor[0].y -= snake.speed;
		if (snake.coor[0].y <= 0)
			return false;
		break;
	case DOWN:
		snake.coor[0].y += snake.speed;
		if (snake.coor[0].y >= heigth)
			return false;
		break;
	case LEFT:
		snake.coor[0].x -= snake.speed;
		if (snake.coor[0].x <= 0)
			return false;
		break;
	case RIGHT:
		snake.coor[0].x += snake.speed;
		if (snake.coor[0].x >= width)
			return false;
		break;
	}
	for (int i = snake.size - 1; i > 0; i--)
	{
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y)
			return false;
	}
	return true;
}

bool snakeMove2()
{
	for (int i = snake.size - 1; i > 0; i--)
	{
		snake.coor[i] = snake.coor[i - 1];
	}
	switch (snake.dir)
	{
	case UP:
		snake.coor[0].y -= snake.speed;
		if (snake.coor[0].y <= 0)
			snake.coor[0].y = heigth;
		break;
	case DOWN:
		snake.coor[0].y += snake.speed;
		if (snake.coor[0].y >= heigth)
			snake.coor[0].y = 0;
		break;
	case LEFT:
		snake.coor[0].x -= snake.speed;
		if (snake.coor[0].x <= 0)
			snake.coor[0].x = width;
		break;
	case RIGHT:
		snake.coor[0].x += snake.speed;
		if (snake.coor[0].x >= width)
			snake.coor[0].x = 0;
		break;
	}
	for (int i = snake.size - 1; i > 0; i--)
	{
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y)
			return false;
	}
	for (int i = 0; i < WALL_MAX; i++)
	{
		if (snake.coor[0].x >= wall[i].x1 && snake.coor[0].x <= wall[i].x2 && snake.coor[0].y >= wall[i].y1 && snake.coor[0].y <= wall[i].y2)
			return false;
	}
	return true;
}

void menuInit()
{
	initgraph(width, heigth);
	loadimage(&img1, "ͼ1.png", width, heigth);
	putimage(0, 0, &img1);
	setbkmode(TRANSPARENT);
	outtextxy(260, 50, "̰���ߴ���ս");
	outtextxy(155, 250, "��ͨģʽ");
	outtextxy(395, 250, "�ϰ�ģʽ");
	outtextxy(275, 250, "�޾�ģʽ");
	outtextxy(155, 300, "������Ϸ");
	outtextxy(395, 300, "�˳���Ϸ");
	outtextxy(155, 350, "������");
	outtextxy(395, 350, "�ر�����");

	rectangle(150, 245, 225, 270);
	rectangle(270, 245, 345, 270);
	rectangle(390, 245, 465, 270);
	rectangle(150, 295, 225, 320);
	rectangle(390, 295, 465, 320);
	rectangle(150, 345, 225, 370);
	rectangle(390, 345, 465, 370);
}

void wallDraw()
{
	setfillcolor(RGB(95, 158, 160));
	for (int i = 0; i < WALL_MAX; i++)
	{
		solidrectangle(wall[i].x1, wall[i].y1, wall[i].x2, wall[i].y2);
	}
}

void gameExit()
{
	initgraph(width, heigth);
	loadimage(&img2, "ͼ2.jpg", width, heigth);
	putimage(0, 0, &img2);
}

void gameOver()
{
	initgraph(width, heigth);
	loadimage(&img3, "ͼ3.jpg", width, heigth);
	putimage(0, 0, &img3);
}