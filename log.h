#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<conio.h>
#include"LinkList.h"
#pragma once

typedef struct Data
{
	char account[30];
	char password[20];
}data;
data d[30];
int k = 0;
//登陆信息的读取
int data_read()
{
	if ((fp = fopen("password_list", "rb")) == NULL) {
		printf("Can't open file!\n");
		exit(0);
	}
	while (fscanf(fp, "%s %s\r\n", d[k].account, d[k].password) != EOF) {
		k++;
	}
	Sleep(1000);
	fclose(fp);
	fp = NULL;
}
//登陆信息的保存
void data_save(char s1[30], char s2[20])
{
	if ((fp = fopen("password_list", "a")) == NULL) {
		printf("Save failed\n");
		exit(0);
	}
	fprintf(fp, "%s %s\r\n", s1, s2);
	fclose(fp);
	fp = NULL;
}
int register_l()
{
aa: system("cls");  //清屏
	toxy(30, 20);
	data client;
	printf("请输入用户名：");
	toxy(30, 22);
	scanf("%s", client.account);
	char c;
	while ((c = getchar()) != EOF && c != '\n');
	int i, flag = 0;
	for (i = 0; i < k; i++)
	{
		if (strcmp(client.account, d[i].account) == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		system("cls");
		toxy(30, 24);		
		printf("该用户名已被占用，请重新输入！\n");
		Sleep(1000);
		goto aa;
	}
	toxy(30, 24);
	printf("请输入密码：");
	toxy(30, 26);
	scanf("%s", client.password);
	/*int a = 0;
	while (1) {
		if (_kbhit()) {
			char ch = _getwch();
			if (ch == '\r') {
				client.password[a] = '\0';
				break;
			}
			printf("*");
			client.password[a] = ch;
			a++;
		}
	}*/
	data_save(client.account, client.password);
}
int log_l() {
	char ac[30], pa[20];
a:
	system("cls");
	toxy(30, 20);
	printf("请输入账号：");
	scanf("%s", ac);
	printf("\n\n");
	toxy(30, 25);
	printf("请输入密码：");
	int a = 0;
	while (1) {
		if (_kbhit) {
			char c = _getwch();
			if (c == '\r') {
				pa[a] = '\0';
				break;
			}
			printf("*");
			pa[a] = c;
			a++;
		}
	}
	int i;
	for (i = 0; i < k; i++) {
		if (!strcmp(ac, d[i].account) && !strcmp(pa, d[i].password)) {
			system("cls");
			toxy(52, 20);
			printf("登陆成功！");
			Sleep(2000);
			break;
		}
	}
	if (i >= k) {
		system("cls");
		toxy(30, 20);
		printf("抱歉，没有该账号或密码输入错误。按任意键重试，退出请按1。\n");
		char c;
		getchar();
		toxy(30, 21);
		scanf("%c", &c);
		if (c != '1')
			goto a;
		else
			exit(0);
	}
}



#endif // LOG_H_INCLUDED
