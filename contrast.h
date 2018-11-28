#ifndef CONTRAST_H_INCLUDE
#define CONTRAST_H_INCLUDE
#pragma once

#include<stdio.h>
#include<string.h>
#include"LinkList.h"
int contrast(LinkList L, int n)
{
	system("cls");
	LinkList p, q, r;
	p = L->next;
	LinkList o = (LinkList)malloc(sizeof(LNode));
	o->next = NULL;
	r = o;
	toxy(35, 10);
	printf("*******对比两位球员的数据*******\n");
	int m = 0;
	int i = 0;
	int step = 11;
	for (; i < n; i++)
	{
		toxy(35, step++);
		printf("输入第%d名球员姓名: ", i + 1);
		char k[100];
		toxy(54, step++);
		scanf("%s", k);
		for (p = L->next; p; p = p->next)
		{
			if (strstr(p->data.name, k) != 0)
			{
				LinkList q = (LinkList)malloc(sizeof(LNode));
				q->data = p->data;
				q->next = o->next;
				o->next = q;
				o = q;
				m++;
			}
		}
		printf("\n");
	}

	if (m == 2) {
		system("cls");
		toxy(15, 18);
		printf("查找成功，共找到%d位球员\n", m);
		setColor(13, 15);
		TraverList_L_contrast(r, 15, 20);
		TraverList_L_contrast_2(r, 15, 30);

	}
	else {
		system("cls");
		toxy(50, 20);
		printf("查找失败\n\n\n");
	}
	toxy(35, 50);
	printf("是否需要继续查找，若需要，则输入1.输入其他数字则返回主菜单\n");
	int t;
	scanf_s("%d", &t);
	if (t == 1)
		contrast(L, 2);
}



#endif // !CONTRAST_H_INCLUDE
