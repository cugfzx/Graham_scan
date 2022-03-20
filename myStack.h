#pragma once
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#define MaxSize 1024


typedef struct
{
    POINT Data[MaxSize];   // �洢Ԫ�ص�����
    int topIdx;       //ջ��ָ��
}SeqStack;

//return 0 Ϊfalse,1Ϊtrue(��ͬ)
// ��Ԫ������ջ��
void Push(SeqStack* L, POINT e)
{ // ջ����
    if (L->topIdx == MaxSize - 1)
    {
        return;
    }
    // ����ջ��
    L->Data[L->topIdx++] = e;
}
// �Ƴ�ջ��Ԫ��
void Pop(SeqStack* L)
{	// ջ��
    if (L->topIdx == 0)
    {
        //����ʧ��
        return;
    }
    L->topIdx--;
}
//�ж�ջs�Ƿ�Ϊ��
bool isEmpty(SeqStack* s)
{
    // ����±���0��˵��ջ����Ԫ��
    if (s->topIdx != 0)
    {
        return 1;
    }
    return 0;
}
// �ж�ջ�Ƿ�����.
bool isFull(SeqStack s)
{
    // ��������true(1)
    if (s.topIdx != MaxSize - 1)//֮ǰ�Ķ�����������ֵ���±�
    {
        return 1;
    }
    return 0;
}

POINT topOne(SeqStack* L)
{
    return L->Data[L->topIdx - 1];
}

POINT topTwo(SeqStack* L)
{
    return L->Data[L->topIdx - 2];
}

void clear(SeqStack* L)
{
    L->topIdx = 0;
}