#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

int sum;
FILE *fp;
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef struct node
{
	char name[30]; //名字
	char team[20]; //队伍
	int order;     //编号
	int height;    //身高
	int weight;    //体重
	float score;   //得分
	float rebound; //篮板
	float assist;  //助攻
	int num;       //号码
}player;
typedef struct node ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

LinkList head, head_f;
void toxy(int x, int y)      //将光标移动到X,Y坐标处
{
	COORD pos = { x , y };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}
/*static bool Ctrlhit(int x)//
{
	return GetKeyState(x)<0;
}*/
void HideCursor()     //隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
//修改文字的函数（前面的参数字体颜色，后面的是背景的颜色）
void setColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//设置颜色
}

void Init_List()
{
	head = (LinkList)malloc(sizeof(LNode));
	head_f = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	head_f->next = NULL;
}

//创建一个单链表(尾插法)
void CreatList_L(LinkList L, int n)
{
	int i;
	LinkList p, q;
	q = L;
	for (i = 1; i <= n; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%s %s %d %d %f %f %f %d", p->data.name, p->data.team, &p->data.height, &p->data.weight, &p->data.score, &p->data.rebound, &p->data.assist, &p->data.num);
		p->data.order = i;
		p->next = q->next;
		q->next = p;
		q = q->next;//q=p;
	}
	sum = i - 1;
}
//输出线性表(递归与非递归)
void TraverList_L(LinkList head, int x, int y)
{

	LinkList p;
	p = head->next;
	toxy(x, ++y);
	setColor(4, 15);
	printf("球员             球队\t\t编号\t身高\t体重\t得分\t篮板\t助攻\t球衣号码\n");
	y++;
	setColor(9, 15);
	while (p != NULL) {
		y++;
		toxy(x, y);
		printf("%-15s\t%-10s\t%d\t%d\t%d\t%.2f\t%.2f\t%.2f\t%d\n", p->data.name, p->data.team, p->data.order, p->data.height, p->data.weight, p->data.score, p->data.rebound, p->data.assist, p->data.num);
		p = p->next;
	}
	setColor(4, 15);
	toxy(x, y + 2);
}
//排序专用的输出函数
void TraverList_L_sort(LinkList head, int x, int y, int key)
{

	LinkList p;
	p = head->next;
	toxy(x, ++y);
	switch (key) {
	case 1:
		setColor(4, 15);
		printf("球员             球队\t\t编号\t身高\t体重\t");
		setColor(13, 15);
		printf("得分");
		setColor(4, 15);
		printf("\t篮板\t助攻\t球衣号码\n");
		while (p != NULL) {
			y++;
			toxy(x, y);
			printf("%-15s\t%-10s\t%d\t%d\t%d\t", p->data.name, p->data.team, p->data.order, p->data.height, p->data.weight);
			setColor(13, 15);
			printf("%.2f", p->data.score);
			setColor(4, 15);
			printf("\t%.2f\t%.2f\t%d\n", p->data.rebound, p->data.assist, p->data.num);
			p = p->next;
		}
		break;
	case 2:
		setColor(4, 15);
		printf("球员             球队\t\t编号\t身高\t体重\t得分\t");
		setColor(13, 15);
		printf("篮板");
		setColor(9, 15);
		printf("\t助攻\t球衣号码\n");
		while (p != NULL) {
			y++;
			toxy(x, y);
			printf("%-15s\t%-10s\t%d\t%d\t%d\t%.2f\t", p->data.name, p->data.team, p->data.order, p->data.height, p->data.weight, p->data.score);
			setColor(13, 15);
			printf("%.2f", p->data.rebound);
			setColor(4, 15);
			printf("\t%.2f\t%d\n", p->data.assist, p->data.num);
			p = p->next;
		}
		break;
	case 3:
		setColor(4, 15);
		printf("球员             球队\t\t编号\t身高\t体重\t得分\t篮板\t");
		setColor(13, 15);
		printf("助攻");
		setColor(4, 15);
		printf("\t球衣号码\n");
		while (p != NULL) {
			y++;
			toxy(x, y);
			printf("%-15s\t%-10s\t%d\t%d\t%d\t%.2f\t%.2f\t", p->data.name, p->data.team, p->data.order, p->data.height, p->data.weight, p->data.score, p->data.rebound);
			setColor(13, 15);
			printf("%.2f", p->data.assist);
			setColor(4, 15);
			printf("\t%d\n", p->data.num);
			p = p->next;
		}
		break;
	}
	y++;
	toxy(x, y + 2);
}
void TraverList_L_contrast(LinkList head, int x, int y)
{
	LinkList p;
	LinkList q;
	p = head->next;
	q = head->next->next;
	toxy(x, ++y);
	setColor(4, 15);
	printf("球员             球队\t\t编号\t身高\t体重\t得分\t篮板\t助攻\t球衣号码\n");
	y++;
	toxy(x, y); toxy(x, ++y);
	setColor(9, 15);
	/********************************第一位球员得分************************/
	printf("%-15s\t%-10s\t%d\t%d\t%d\t", p->data.name, p->data.team, p->data.order, p->data.height, p->data.weight);

	if (p->data.score > q->data.score)
	{
		setColor(12, 15);
		printf("%.2f", p->data.score);
	}
	else
	{
		printf("%.2f", p->data.score);

	}
	setColor(9, 15);
	/********************************第一位球员篮板************************/

	if (p->data.rebound > q->data.rebound)
	{
		setColor(12, 15);				printf("\t%.2f", p->data.rebound);
	}
	else
	{
		printf("\t%.2f", p->data.rebound);

	}
	setColor(9, 15);
	/********************************第一位球员助攻************************/

	if (p->data.assist > q->data.assist)
	{
		setColor(12, 15);			printf("\t%.2f", p->data.assist);
	}
	else
	{
		printf("\t%.2f", p->data.assist);

	}
	setColor(9, 15);
	printf("\t%d\n", p->data.num);
	y++;
	toxy(x, ++y);
	printf("%-15s\t%-10s\t%d\t%d\t%d\t", q->data.name, q->data.team, q->data.order, q->data.height, q->data.weight);
	/********************************第二位球员得分************************/

	if (p->data.score < q->data.score)
	{
		setColor(12, 15);				printf("%.2f", q->data.score);
	}
	else
	{
		printf("%.2f", q->data.score);

	}
	setColor(9, 15);
	/********************************第二位球员篮板************************/

	if (p->data.rebound < q->data.rebound)
	{
		setColor(12, 15);			printf("\t%.2f", q->data.rebound);
	}
	else
	{
		printf("\t%.2f", q->data.rebound);

	}
	setColor(9, 15);
	/********************************第二位球员助攻************************/
	if (p->data.assist < q->data.assist)
	{
		setColor(12, 15);				printf("\t%.2f", q->data.assist);
	}
	else
	{
		printf("\t%.2f", q->data.assist);

	}
	setColor(9, 15);
	printf("\t%d\n", q->data.num);
	setColor(4, 15);
}
//对比专用 输出函数
int TraverList_L_contrast_2(LinkList head, int x, int y)
{
	int flag1;
	toxy(x, y);
	/***********************************判断是否全面**************************************/

	int a;
	if (head->next->data.score >= 15 && head->next->data.rebound >= 5 && head->next->data.assist >= 5)
		a = 1;
	if (head->next->next->data.score >= 15 && head->next->next->data.rebound >= 5 && head->next->next->data.assist >= 5)
		a = 2;
	if (head->next->next->data.score >= 15 && head->next->next->data.rebound >= 5 && head->next->next->data.assist >= 5 && head->next->next->data.score >= 15 &&
		head->next->next->data.rebound >= 5 && head->next->next->data.assist >= 5)
		a = 3;
	switch (a)
	{
	case 1:
		setColor(9, 15);
		printf("%s", head->next->data.name);
		setColor(4, 15);
		printf("这名球员拥有着很全面的能力，各项数据都领先联盟，能在球场上的所有角落展示自己的能力。\n");
		break;
	case 2:
		setColor(9, 15);
		printf("%s", head->next->next->data.name);
		setColor(4, 15);
		printf("这名球员拥有着很全面的能力，各项数据都领先联盟，能在球场上的所有角落展示自己的能力。\n");
		break;
	case 3:
		setColor(9, 15);
		printf("%s", head->next->next->data.name);
		setColor(4, 15);
		printf("和");
		setColor(9, 15);
		printf("%s", head->next->data.name);
		setColor(4, 15);
		printf("这两名球员都拥有着很全面的能力，各项数据都领先联盟，能在球场上的所有角落展示各自的能力\n。");

	}
	/***********************************得分评论**************************************/
	//得分相差不大
	toxy(x, ++y); toxy(x, ++y);
	if ((abs(head->next->data.score - head->next->next->data.score)) <= 3 || (abs(head->next->next->data.score - head->next->data.score)) <= 3)
	{
		setColor(4, 15);
		if (head->next->data.score > 20 && head->next->next->data.score > 20)
		{
			printf("在得分方面，两位球员都是出色的得分手,得分均超过20分，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的得分水平不相上下\n\n\n");
		}
		else
		{
			printf("在得分方面,");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的得分水平不相上下，得分差距小于3分。\n\n\n");
		}
	}
	//得分相差较大，第一名球员比第二名球员强
	if ((head->next->data.score - head->next->next->data.score) >= 4)
	{
		setColor(4, 15);
		if (head->next->data.score > 20 && head->next->next->data.score > 20)
		{
			printf("在得分方面，两位球员都是出色的得分手，得分均超过20分，但");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("的得分能力略强于");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("，得分相差");
			setColor(9, 15);
			printf("%.2f", head->next->data.score - head->next->next->data.score);
			setColor(4, 15);
			printf("分 \n\n\n");
		}
		else
		{
			printf("在得分方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("的得分能力略强于");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("，得分相差");
			setColor(9, 15);
			printf("%.2f", head->next->data.score - head->next->next->data.score);
			printf("分 \n\n\n");
		}
	}
	//得分相差较大，第一名球员比第二名球员弱
	if ((head->next->data.score - head->next->next->data.score) <= (-4))
	{
		setColor(4, 15);
		if (head->next->data.score > 20 && head->next->next->data.score > 20)
		{
			printf("在得分方面，两位球员都是出色的得分手，但");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("的得分能力略弱于");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("，得分相差");
			setColor(9, 15);
			printf("%.2f", -(head->next->data.score - head->next->next->data.score));
			setColor(4, 15);
			printf("分\n\n\n");
		}
		else
		{
			printf("在得分方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("的得分能力略弱于");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("，得分相差");
			setColor(9, 15);
			printf("%.2f", -(head->next->data.score - head->next->next->data.score));
			setColor(4, 15);
			printf("分\n\n\n");
		}
	}

	/***********************************篮板评论**************************************/
	toxy(x, ++y); toxy(x, ++y);
	//篮板相差不大
	if ((abs(head->next->data.rebound - head->next->next->data.rebound)) <= 2 || (abs(head->next->next->data.rebound - head->next->data.rebound)) <= 2)
	{
		setColor(4, 15);
		if (head->next->data.rebound > 8 && head->next->next->data.rebound > 8)
		{
			printf("在篮板方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的篮板能力都十分出色，不分伯仲,场均篮板均大于八个\n\n\n");
		}
		else
		{
			printf("在篮板方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的篮板能力相差不大，场均差距不到两个\n\n\n");
		}
	}
	//篮板相差较大，第一名球员比第二名球员强
	if ((head->next->data.rebound - head->next->next->data.rebound) >= 3)
	{
		setColor(4, 15);
		if (head->next->data.rebound > 8 && head->next->next->data.rebound > 8)
		{
			printf("在篮板方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的篮板能力都十分出色，其中");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("的场均篮板数更胜一筹，场均篮板差距为");
			setColor(9, 15);
			printf("%.2f", (head->next->data.rebound - head->next->next->data.rebound));
			setColor(4, 15);
			printf("个\n\n\n");
		}
		else
		{
			printf("在篮板方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的篮板能力有着较大的差距，其中");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("的场均篮板数更胜一筹，场均篮板差距为");
			setColor(9, 15);
			printf("%.2f", (head->next->data.rebound - head->next->next->data.rebound));
			setColor(4, 15);
			printf("个\n\n\n");
		}
	}
	//篮板相差较大，第一名球员比第二名球员弱
	if ((head->next->data.rebound - head->next->next->data.rebound) <= (-3))
	{
		setColor(4, 15);
		if (head->next->data.rebound > 8 && head->next->next->data.rebound > 8)
		{
			printf("在篮板方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的篮板能力都十分出色，场均都有八个以上的篮板，其中");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的场均篮板数更胜一筹，场均篮板差距为");
			setColor(9, 15);
			printf("%.2f", -(head->next->data.rebound - head->next->next->data.rebound));
			setColor(4, 15);
			printf("个\n\n\n");
		}
		else
		{
			printf("在篮板方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的篮板能力有着较大的差距，其中");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的场均篮板数更胜一筹，场均篮板差距为");
			setColor(9, 15);
			printf("%.2f", -(head->next->data.rebound - head->next->next->data.rebound));
			setColor(4, 15);
			printf("个\n\n\n");
		}
	}
	/***********************************助攻评论**************************************/
	toxy(x, ++y); toxy(x, ++y);
	//助攻相差不大
	if ((abs(head->next->data.assist - head->next->next->data.assist)) <= 0.5)
	{
		setColor(4, 15);
		if (head->next->data.assist >= 5 && head->next->next->data.assist >= 5)
		{
			printf("在助攻方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("两位球员都是球场上出色的组织者，能频频为队友送出助攻，场均助攻都大于五个\n\n\n");
		}
		else
		{
			printf("在助攻方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的助攻能力相差不大，场均相差不到0.5个助攻\n\n\n");
		}
	}
	//助攻相差较大，第一名球员比第二名球员强
	if ((head->next->data.assist - head->next->next->data.assist) >= 1.5)
	{
		setColor(4, 15);
		if (head->next->data.assist >= 6 && head->next->next->data.assist >= 6)
		{
			printf("在助攻方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("都有着较为出色的助攻能力，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("的组织能力更为突出，场均助攻差距为");
			setColor(9, 15);
			printf("%.2f", (head->next->data.assist - head->next->next->data.assist));
			setColor(4, 15);
			printf("个。\n\n\n");
		}
		else
		{
			printf("在助攻方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的助攻能力有着较大的差距，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("的组织能力更为突出，场均助攻差距为");
			setColor(9, 15);
			printf("%.2f", (head->next->data.assist - head->next->next->data.assist));
			setColor(4, 15);
			printf("个。\n\n\n");
		}
	}
	//助攻相差较大，第一名球员比第二名球员弱
	if ((head->next->data.assist - head->next->next->data.assist) <= (-1.5))
	{
		setColor(4, 15);
		if (head->next->data.assist >= 6 && head->next->next->data.assist >= 6)
		{
			printf("在助攻方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("都有着较为出色的助攻能力，场均都能贡献六次助攻以上，但是");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的组织能力更为突出，比");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("场均多送出");
			setColor(9, 15);
			printf("%.2f", -(head->next->data.assist - head->next->next->data.assist));
			setColor(4, 15);
			printf("个助攻\n\n\n");
		}
		else
		{
			printf("在助攻方面，");
			setColor(9, 15);
			printf("%s", head->next->data.name);
			setColor(4, 15);
			printf("与");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的助攻能力有着较大的差距，");
			setColor(9, 15);
			printf("%s", head->next->next->data.name);
			setColor(4, 15);
			printf("的组织能力更为突出,场均助攻差距为");
			setColor(9, 15);
			printf("%.2f", -(head->next->data.assist - head->next->next->data.assist));
			setColor(4, 15);
			printf("个\n\n\n");
		}
	}

}
#endif // LINKLIST_H_INCLUDED
