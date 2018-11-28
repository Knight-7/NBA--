#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include "menuu.h"//菜单头文件
#include"find.h"//查找头文件
#include"head.h"//函数命名头文件
#include"LinkList.h"//单链表头文件
#include"sort.h"//排序头文件
#include"file.h"//文件读取和保存头文件
#include"update.h"//更新信息头文件
#include"log.h"//登陆头文件
#include"contrast.h"//对比头文件

int main()
{
	show_load();
	show_menu();//显示操作菜单
	char ope;//储存操作指令
	getchar();
	while (scanf("%c", &ope) != EOF)
	{
		switch (ope)
		{
		case '1': {//显示
			system("cls");  //清屏
			sort_order(head);
			TraverList_L(head, 15, 10);
			printf("请输入任意键返回主菜单。");
			char key1, c;
			while ((c = getchar()) != EOF && c != '\n');
			scanf("%c", &key1);
			break;
		}
		case '2'://查找
			show_search();
			break;
		case '3'://插入
			show_insert();
			break;
		case '4'://删除
			show_delete();
			break;
		case '5'://更新
			show_update();
			break;
		case '6'://排序
			show_sort();
			break;
		case '7'://保存
			file_save(head);
			Sleep(500);
			break;
		case '8'://退出
			show_end();
			goto bb;
			break;
		case '9':
			contrast(head, 2);
			//break;
		default:
			system("cls");  //清屏
			toxy(40, 20);
			printf("没有该序号对应的操作指令，请重新输入!\n");
			Sleep(500);
			break;
		}
		show_menu();//重新打印操作菜单，为下次指令做准备
		char c;
		while ((c = getchar()) != EOF && c != '\n');
	}
	show_end();
	Sleep(100);
bb:return 0;
}
