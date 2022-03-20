#pragma once
#include <graphics.h>		// 引用图形库头文件
#define MaxSize 1024


typedef struct
{
    POINT Data[MaxSize];   // 存储元素的数组
    int topIdx;       //栈顶指针
}SeqStack;

//return 0 为false,1为true(下同)
// 将元素推入栈中
void Push(SeqStack* L, POINT e)
{ // 栈已满
    if (L->topIdx == MaxSize - 1)
    {
        return;
    }
    // 加入栈中
    L->Data[L->topIdx++] = e;
}
// 移除栈顶元素
void Pop(SeqStack* L)
{	// 栈空
    if (L->topIdx == 0)
    {
        //返回失败
        return;
    }
    L->topIdx--;
}
//判断栈s是否为空
bool isEmpty(SeqStack* s)
{
    // 如果下标在0，说明栈中无元素
    if (s->topIdx != 0)
    {
        return 1;
    }
    return 0;
}
// 判断栈是否已满.
bool isFull(SeqStack s)
{
    // 已满返回true(1)
    if (s.topIdx != MaxSize - 1)//之前的定义数组的最大值的下标
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