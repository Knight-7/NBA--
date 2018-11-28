#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#pragma once

#include"LinkList.h"
#include<stdio.h>
#include<Windows.h>
//数据的读取函数
int file_read(LinkList L)
{
	LinkList p, q;
	q = L;
	if ((fp = fopen("player_list", "rb")) == NULL) {
		printf("Can't open file!\n");
		exit(0);
	}
	p = (LinkList)malloc(sizeof(LNode));
	while (fscanf(fp, "%s %s %d %d %d %f %f %f %d\r\n", p->data.name, p->data.team, &p->data.order, &p->data.height, &p->data.weight, &p->data.score, &p->data.rebound, &p->data.assist, &p->data.num) != EOF) {
		p->next = q->next;
		q->next = p;
		q = q->next;
		p = (LinkList)malloc(sizeof(LNode));
		sum++;
	}
	fclose(fp);
	fp = NULL;
}
//数据保存函数
void file_save(LinkList L)
{
	LinkList p;
	p = L->next;
	if ((fp = fopen("player_list", "wb")) == NULL) {
		printf("Save failed!\n");
		exit(0);
	}
	while (p != NULL) {
		fprintf(fp, "%s %s %d %d %d %f %f %f %d\r\n", p->data.name, p->data.team, p->data.order, p->data.height, p->data.weight, p->data.score, p->data.rebound, p->data.assist, p->data.num);
		p = p->next;
	}
	system("cls");  //清屏
	toxy(52, 20);
	printf("保存成功！\n");
	fclose(fp);
	fp = NULL;
}



#endif // FILE_H_INCLUDED

