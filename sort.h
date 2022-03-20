#pragma once
#include <graphics.h>		// 引用图形库头文件

double distance(POINT a, POINT b)
{
	return sqrt((double)(a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double getpolarAngle(POINT p, POINT o)
{
	return acos((p.x - o.x) / distance(p, o));
}

//间接排序(由大到小)
void selectSort(POINT* pointArr, int length, POINT pole)
{	
	//去将pointArr中的点去掉极点存入pArr
	POINT* pArr = (POINT*)malloc(sizeof(POINT) * length-1);
	int j = 0;
	int skipped = 0;//标记是否跳过了极点

	for (int i = 0; i < length; ++i)
	{
		if (pointArr[i].x == pole.x && pointArr[i].y == pole.y&&!skipped)//如果是极点且还没有跳过
		{
			skipped = 1;//标记已经跳过了极点
			continue;//直接进入下一趟循环
		}
		pArr[j++] = pointArr[i];
	}

	//链接表
	int* link= (int*)malloc(sizeof(int) * (length-1));
	//存放极角
	double* angleArr = (double*)malloc(sizeof(double) * (length-1));
	//存放距离
	double* dist = (double*)malloc(sizeof(double) * (length-1));


	//计算极角存入临时数组
	for (int i = 0; i < length-1; ++i) {
		double temp= getpolarAngle(pArr[i], pole);
		angleArr[i] = getpolarAngle(pArr[i], pole);
		dist[i] = distance(pArr[i], pole);
	}

	//初始化链接表
	for (int j = 0; j < length - 1; ++j)
	{
		link[j] = j;
	}

	//间接选择排序
	for (int i = 0; i < length - 2; ++i)
	{
		int maxInd = i,temp;
		bool flag = 0;
		for (int j = i+1; j < length - 1; ++j)
		{
			if (angleArr[link[j]] > angleArr[link[maxInd]] || (angleArr[link[j]] == angleArr[link[maxInd]]&&dist[link[j]] < dist[link[maxInd]]))
			{
				maxInd = j;
				flag = 1;
			}
		}
		if (flag)
		{
			temp = link[i];
			link[i] = link[maxInd];
			link[maxInd] = temp;
		}
	}
	pointArr[0] = pole;
	for (int i = 1; i < length; ++i)
	{
		pointArr[i] = pArr[link[i-1]];
	}

	free(pArr);
	free(angleArr);
	free(link);
	free(dist);
}