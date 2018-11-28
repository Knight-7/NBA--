#ifndef FIND_H_INCLUDED
#define FIND_H_INCLUDED
#pragma once

#include<stdio.h>
#include"LinkList.h"
#include"head.h"
#include<string.h>
//查找总函数
/*
void find_choose()
{
	int i;
	printf("请选择查找条件");
	printf("1.球员  2.球队  3.得分  4.篮板  5.助攻\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1: find_name(head, head_f); break;
	case 2: find_team(head, head_f); break;
	case 3: find_score(head, head_f); break;
	case 4: find_rebound(head, head_f); break;
	case 5: find_assist(head, head_f); break;
	}
}
*/
//按姓名查找函数
int find_name(LinkList L)
{
	int m = 0;
	char k[30];
	LinkList p;
	p = L->next;
	system("cls");  //清屏
	toxy(35, 19);
	printf("输入要查找的字符：");
	toxy(35, 21);
	scanf("%s", k);
	for (; p; p = p->next)
	{
		if (strstr(p->data.name, k) != 0)
		{
			m++;
		}
	}
	system("cls");  //清屏
	toxy(35, 5);
	int step = 0;
	if (m != 0) {
		p = L->next;
		printf("**********************************************\n");
		toxy(35, 6);
		printf("         查找成功，共找到%d位球员             \n", m);
		toxy(35, 7);
		printf("**********************************************\n");
		toxy(15, 8);
		printf("球员             球队\t\t编号\t身高\t体重\t得分\t篮板\t助攻\t球衣号码\n");
		toxy(15, 10);
		for (; p; p = p->next)
		{
			if (strstr(p->data.name, k) != 0)
			{
				toxy(15, 9 + step);
				step++;
				printf("%-15s\t%-10s\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\t%d\n", p->data.name, p->data.team, p->data.order, p->data.height, p->data.weight, p->data.score, p->data.rebound, p->data.assist, p->data.num);
			}
		}
	}
	else
		printf("很抱歉，没有与您提供的关键字匹配的答案。\n");
	return 9 + step + 2;
}
//按队伍查找函数
int find_team(LinkList L)
{
	int m = 0;
	char k[30];
	LinkList p;

	p = L->next;
	system("cls");  //清屏
	toxy(35, 19);
	printf("输入要查找的字符：");
	scanf("%s", k);
	for (; p; p = p->next)
	{
		if (strstr(p->data.team, k) != 0)
		{
			m++;
		}
	}
	system("cls");  //清屏
	toxy(35, 5);
	int step = 0;
	if (m != 0) {
		p = L->next;
		printf("**********************************************\n");
		toxy(35, 6);
		printf("         查找成功，共找到%d位球员             \n", m);
		toxy(35, 7);
		printf("**********************************************\n");
		toxy(15, 8);
		printf("球员             球队\t\t编号\t身高\t体重\t得分\t篮板\t助攻\t球衣号码\n");
		toxy(15, 10);
		for (; p; p = p->next)
		{
			if (strstr(p->data.team, k) != 0)
			{
				toxy(15, 9 + step);
				step++;
				printf("%-15s\t%-10s\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\t%d\n", p->data.name, p->data.team, p->data.order, p->data.height, p->data.weight, p->data.score, p->data.rebound, p->data.assist, p->data.num);
			}
		}
	}
	else
		printf("查找失败\n");
	return 9 + step + 2;
}
//按球员的得分查找函数
int find_score(LinkList L)
{
	int m = 0;
	float a, b;
	char k[30];
	LinkList p;

	p = L->next;
	system("cls");  //清屏
	toxy(35, 5);
	printf("输入要查找的字符：");
	printf("输入要查找的得分区间（用空格隔开）：");
	scanf("%f %f", &a, &b);

	for (; p; p = p->next)
	{
		if (a <= p->data.score&&p->data.score <= b)
		{
			m++;
		}
	}
	system("cls");  //清屏
	toxy(35, 5);
	int step = 0;
	if (m != 0) {
		p = L->next;
		printf("**********************************************\n");
		toxy(35, 6);
		printf("         查找成功，共找到%d位球员             \n", m);
		toxy(35, 7);
		printf("**********************************************\n");
		toxy(15, 8);
		printf("球员             球队\t\t编号\t身高\t体重\t得分\t篮板\t助攻\t球衣号码\n");
		toxy(15, 10);
		for (; p; p = p->next)
		{
			if (a <= p->data.score&&p->data.score <= b)
			{
				toxy(15, 9 + step);
				step++;
				printf("%-15s\t%-10s\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\t%d\n", p->data.name, p->data.team, p->data.order, p->data.height, p->data.weight, p->data.score, p->data.rebound, p->data.assist, p->data.num);
			}
		}
	}
	else
		printf("查找失败\n");
	return 9 + step + 2;
}
//按球员的篮板查找函数
int find_rebound(LinkList L)
{
	int m = 0;
	float a, b;
	//char k[30];
	LinkList p;

	p = L->next;
	system("cls");  //清屏
	toxy(35, 5);
	printf("输入要查找的字符：");
	printf("输入要查找的篮板数区间（用空格隔开）：");
	scanf("%f %f", &a, &b);

	for (; p; p = p->next)
	{
		if (a <= p->data.rebound&&p->data.rebound <= b)
		{
			m++;
		}
	}
	system("cls");  //清屏
	toxy(35, 5);
	int step = 0;
	if (m != 0) {
		p = L->next;
		printf("**********************************************\n");
		toxy(35, 6);
		printf("         查找成功，共找到%d位球员             \n", m);
		toxy(35, 7);
		printf("**********************************************\n");
		toxy(15, 8);
		printf("球员             球队\t\t编号\t身高\t体重\t得分\t篮板\t助攻\t球衣号码\n");
		toxy(15, 10);
		for (; p; p = p->next)
		{
			if (a <= p->data.rebound&&p->data.rebound <= b)
			{
				toxy(15, 9 + step);
				step++;
				printf("%-15s\t%-10s\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\t%d\n", p->data.name, p->data.team, p->data.order, p->data.height, p->data.weight, p->data.score, p->data.rebound, p->data.assist, p->data.num);
			}
		}
	}
	else
		printf("查找失败\n");
	return 9 + step + 2;
}
//按球员的助攻查找函数
int find_assist(LinkList L)
{
	int m = 0;
	float a, b;
	//char k[30];
	LinkList p;

	p = L->next;
	system("cls");  //清屏
	toxy(35, 5);
	printf("输入要查找的字符：");
	printf("输入要查找的助攻数区间（用空格隔开）：");
	scanf("%f %f", &a, &b);

	for (; p; p = p->next)
	{
		if (a <= p->data.assist&&p->data.assist <= b)
		{
			m++;
		}
	}
	system("cls");  //清屏
	toxy(35, 5);
	int step = 0;
	if (m != 0) {
		p = L->next;
		printf("**********************************************\n");
		toxy(35, 6);
		printf("         查找成功，共找到%d位球员             \n", m);
		toxy(35, 7);
		printf("**********************************************\n");
		toxy(15, 8);
		printf("球员             球队\t\t编号\t身高\t体重\t得分\t篮板\t助攻\t球衣号码\n");
		toxy(15, 10);
		for (; p; p = p->next)
		{
			if (a <= p->data.assist&&p->data.assist <= b)
			{
				toxy(15, 9 + step);
				step++;
				printf("%-15s\t%-10s\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\t%d\n", p->data.name, p->data.team, p->data.order, p->data.height, p->data.weight, p->data.score, p->data.rebound, p->data.assist, p->data.num);
			}
		}
	}
	else
		printf("查找失败\n");
	return 9 + step + 2;
}



#endif // FIND_H_INCLUDED
