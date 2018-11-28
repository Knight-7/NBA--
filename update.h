#ifndef UPDATA_H_INCLUDED
#define UPDATE_H_INCLUDED
#pragma once

#include<stdio.h>
#include"LinkList.h"
//插入函数
void insert_player(LinkList head, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		sum++;
		LinkList p = (LinkList)malloc(sizeof(LNode));
		system("cls");  //清屏
		toxy(25, 15);
		printf("请输入球员的名字、队伍、身高、体重、得分、篮板、助攻、号码\n");
		toxy(30, 19);
		scanf("%s %s %d %d %f %f %f %d", p->data.name, p->data.team, &p->data.height,
			&p->data.weight, &p->data.score, &p->data.rebound, &p->data.assist, &p->data.num);
		p->data.order = sum;
		p->next = head->next;
		head->next = p;
		head = head->next;
	}
}
//删除函数
int delete_player(LinkList head, int n)
{
	LinkList p, q;
	p = head;
	int flag = 1;
	while (p != NULL && p->next != NULL)
	{
		q = p->next;
		if (q->data.order == n)
		{
			p->next = q->next;
			free(q);
			p = p->next;
			system("cls");  //清屏
			toxy(35, 20);
			printf("删除成功！\n");
			flag = 0;
		}
		else
			p = p->next;
	}
	//order_player(head);
	system("cls");  //清屏
	toxy(35, 20);
	if (flag)
		printf("没找到该对应编号的球员！\n");
	Sleep(200);
	return flag;
}
//重新排序
void order_player(LinkList head)//重排序号
{
	LinkList q = head->next;
	int t = 1;
	while (q)
	{
		q->data.order = t;
		t++;
		q = q->next;
	}
	sum = t - 1;
}
//更新函数
void updat_player(LinkList head, int n)//更新序号为n的成员的值；
{
	LinkList p;
	p = head->next;
	while (p != NULL)
	{
		if (p->data.order == n)
		{
			system("cls");  //清屏
			toxy(25, 15);
			printf("请输入球员的名字、队伍、身高、体重、得分、篮板、助攻、号码\n");
			toxy(30, 19);
			scanf("%s %s %d %d %f %f %f %d", p->data.name, p->data.team, &p->data.height,
				&p->data.weight, &p->data.score, &p->data.rebound, &p->data.assist, &p->data.num);
			system("cls");  //清屏
			toxy(52, 21);
			printf("更新成功！\n");
		}
		p = p->next;
	}
}


#endif // UPDATE_H_INCLUDED
