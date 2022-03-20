#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <ctime>
#include <math.h>
#include <conio.h>
#include "myStack.h"
#include "sort.h"
#include <stdio.h>


#define POINT_NUM 100

POINT* pointArr = (POINT*)malloc(sizeof(POINT) * POINT_NUM);
SeqStack stack;

void generateRandomPoints(POINT* pointArr, int n);
void displayPoints(POINT* pointArr, int n);
POINT findPole(POINT* pointArr, int n);
bool isTurnLeft(POINT a, POINT o, POINT b);
void GrahamScan(POINT* pointArr, int n, SeqStack* s);
//void debug(int topNum);


int main()
{
	initgraph(900, 900);//��ʼ��600*600�Ĵ���

	RECT r = { 0, 50, 500, 500};
	drawtext(_T("�й����ʴ�ѧ���人��064181 ������"), &r, DT_CENTER);

	setorigin(0, 900);//��������ԭ��

	setaspectratio(1, -1);//��������Ϊ��

	while(1)
	{ 
		generateRandomPoints(pointArr, POINT_NUM);//����100�������

		displayPoints(pointArr, POINT_NUM);//��ʾ��

		GrahamScan(pointArr, POINT_NUM,&stack);//����͹��

		//Debug
		//debug(topNum);

		setlinecolor(RGB(0, 255, 0));
		polygon(stack.Data, stack.topIdx);//����͹�������
		setlinecolor(RGB(255, 255, 255));

		//_getch();				// �����������
		Sleep(1500);

		cleardevice();
		clear(&stack);
	}

	closegraph();			// �رջ�ͼ����
	free(pointArr);

	return 0;
}

//Grahamɨ�跨���Ĵ���

void GrahamScan(POINT* pointArr, int n, SeqStack* s)
{
	//��p0
	POINT pole = findPole(pointArr, n);

	//������ջ
	Push(s, pole);

	//�����ǴӴ�С����
	selectSort(pointArr, n, pole);

	//p1��ջ
	Push(s, pointArr[1]);
	Sleep(300);
	line(topTwo(s).x, topTwo(s).y, topOne(s).x, topOne(s).y);

	int i = 2;
	while (i < n)
	{
		line(topOne(s).x, topOne(s).y, pointArr[i].x, pointArr[i].y);
		Sleep(300);
		if (isTurnLeft(topTwo(s), topOne(s), pointArr[i]))//�ϱߵ��±����Ϊ��ת
		{
			Push(s, pointArr[i]);//�µ���ջ
			i++;
		}
		else
		{
			setlinecolor(RGB(0, 0, 0));
			line(topOne(s).x, topOne(s).y, pointArr[i].x, pointArr[i].y);
			line(topOne(s).x, topOne(s).y, topTwo(s).x, topTwo(s).y);
			setlinecolor(RGB(255, 255, 255));

			Pop(s);//ջ����ջ
		}

	}
}

void generateRandomPoints(POINT* pointArr, int n)
{
	srand((int)time(0));
	for (int i = 0; i < n; ++i) {
		pointArr[i].x = rand() % 700 + 100;
		pointArr[i].y = rand() % 700 + 100;
	}

	//��BUG�ĵ㼯
	//pointArr[0] = { 153,103 };
	//pointArr[1] = { 104,125 };
	//pointArr[2] = { 101,206 };
	//pointArr[3] = { 104,385 };
	//pointArr[4] = { 114,433 };
	//pointArr[5] = { 147,437 };
	//pointArr[6] = { 161,408 };
	//pointArr[7] = { 166,296 };
	//pointArr[8] = { 166,296 };//�ظ�,���ɵĵ��ظ��ᵼ��BUG
	//pointArr[9] = { 218,495 };
	//pointArr[10] = { 383,486 };
	//pointArr[11] = { 495,455 };
	//pointArr[12] = { 499,318 };
	//pointArr[13] = { 499,272 };
	//pointArr[14] = { 488,191 };
	//pointArr[15] = { 464,147 };
	//pointArr[16] = { 435,111 };
	//pointArr[17] = { 381,108 };
}

void displayPoints(POINT* pointArr, int n)
{
	for (int i = 0; i < n; ++i) {
		solidcircle(pointArr[i].x, pointArr[i].y, 1);
	}
}

//ѡ����������С�ĵ���Ϊ��һ����
POINT findPole(POINT* pointArr, int n)
{
	POINT pole = pointArr[0];
	for (int i = 1; i < n; ++i) {
		if (pointArr[i].y < pole.y)
			pole = pointArr[i];
	}
	return pole;
}

//�ж��Ƿ�Ϊ��ת
bool isTurnLeft(POINT a, POINT o, POINT b)
{
	return ((a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y)) >= 0;
}


//void debug(int topNum)
//{
//	char c;
//	while (1)
//	{
//		if (_kbhit())
//		{
//			c = _getch();
//			break;
//		}
//	}
//	//��¼��bug�ĵ㼯
//	FILE* p = fopen("points.txt", "w");
//	int i;
//
//	if (c == 's')
//	{
//		for (i = 0; i < topNum; i++)
//		{
//			fprintf(p, "(%d,%d)\n", stack.Data[i].x, stack.Data[i].y);
//		}
//		fclose(p);
//	}
//
//}

