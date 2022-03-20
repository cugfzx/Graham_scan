#pragma once
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�

double distance(POINT a, POINT b)
{
	return sqrt((double)(a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double getpolarAngle(POINT p, POINT o)
{
	return acos((p.x - o.x) / distance(p, o));
}

//�������(�ɴ�С)
void selectSort(POINT* pointArr, int length, POINT pole)
{	
	//ȥ��pointArr�еĵ�ȥ���������pArr
	POINT* pArr = (POINT*)malloc(sizeof(POINT) * length-1);
	int j = 0;
	int skipped = 0;//����Ƿ������˼���

	for (int i = 0; i < length; ++i)
	{
		if (pointArr[i].x == pole.x && pointArr[i].y == pole.y&&!skipped)//����Ǽ����һ�û������
		{
			skipped = 1;//����Ѿ������˼���
			continue;//ֱ�ӽ�����һ��ѭ��
		}
		pArr[j++] = pointArr[i];
	}

	//���ӱ�
	int* link= (int*)malloc(sizeof(int) * (length-1));
	//��ż���
	double* angleArr = (double*)malloc(sizeof(double) * (length-1));
	//��ž���
	double* dist = (double*)malloc(sizeof(double) * (length-1));


	//���㼫�Ǵ�����ʱ����
	for (int i = 0; i < length-1; ++i) {
		double temp= getpolarAngle(pArr[i], pole);
		angleArr[i] = getpolarAngle(pArr[i], pole);
		dist[i] = distance(pArr[i], pole);
	}

	//��ʼ�����ӱ�
	for (int j = 0; j < length - 1; ++j)
	{
		link[j] = j;
	}

	//���ѡ������
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