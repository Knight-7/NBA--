#ifndef MENUU_H_INCLUDED
#define MENUU_H_INCLUDED

#include"LinkList.h"
#include"head.h"
void show_load()
{
	char str[] = "Loading... ...\n";
	system("color f9");
	system("mode con cols=120 lines=60");
	toxy(52, 20);
	int i;
	for (i = 0; i < 14; i++) {
		Sleep(200);
		printf("%c", str[i]);
	}
	Init_List();
	Sleep(200);
	system("cls");  //清屏
	toxy(52, 20);
	data_read();
	printf("读取成功！\n");
	Sleep(1500);
	system("cls");  //清屏
	show_log();
	file_read(head);

}

void show_title()
{
	setColor(4, 15);
	toxy(35, 10);
	printf("**********************************************\n");
	toxy(35, 11);
	printf("*           NBA球员信息管理系统              *\n");
	toxy(35, 12);
	printf("*      制作者：欧宇建、刘家豪、刘思凡        *\n");
	toxy(35, 13);
	printf("**********************************************\n");
}
int show_log()
{
	setColor(4, 15);
	system("cls");  //清屏
	toxy(30, 20);
	printf("如若第一次使用本系统，还请注册！");
	toxy(30, 22);
	setColor(9, 15);
	printf("若已有账号，直接登陆即可。");
	toxy(30, 24);
	setColor(4, 15);
	printf("是否需要注册？是请输入1，否则将进入登录界面！");
	char c, cc;
	setColor(9, 15);
	scanf("%c", &c);
	while ((cc = getchar()) != EOF && cc != '\n');
	setColor(4, 15);
	if (c == '1')
	{
		//注册
		register_l();
		system("cls");  //清屏
		toxy(30, 20);
		printf("注册成功！\n");
		Sleep(2000);
	}
	data_read();
	log_l();
}
void show_menu()
{
	system("cls");  //清屏
	show_title();
	toxy(35, 14);
	printf("**********************************************\n");
	toxy(35, 15);
	printf("*                操作指令如下：              *\n");
	toxy(35, 16);
	printf("*--------------------------------------------*\n");
	toxy(35, 17);
	printf("*");
	setColor(9, 15);
	printf("  1、显示数据               2、查找数据     ");
	setColor(4, 15);
	printf("*\n");
	toxy(35, 18);
	printf("*                                            *\n");
	toxy(35, 19);
	printf("*");
	setColor(9, 15);
	printf("  3、插入数据               4、删除数据     ");
	setColor(4, 15);
	printf("*\n");
	toxy(35, 20);
	printf("*                                            *\n");
	toxy(35, 21);
	printf("*");
	setColor(9, 15);
	printf("  5、更新数据               6、数据排序     ");
	setColor(4, 15);
	printf("*\n");
	toxy(35, 22);
	printf("*                                            *\n");
	toxy(35, 23);
	printf("*");
	setColor(9, 15);
	printf("  7、保存数据               8、退出系统     ");
	setColor(4, 15);
	printf("*\n");
	toxy(35, 24);
	setColor(4, 15);
	printf("*                                            *\n");
	toxy(35, 25);
	printf("*");
	setColor(9, 15);
	printf("  9、球员对比                               ");
	setColor(4, 15);
	printf("*\n");
	toxy(35, 26);
	printf("*--------------------------------------------*\n");
	toxy(35, 27);
	printf("*  >请通过输入对应操作序号来调用操作指令！<  *\n");
	toxy(35, 28);
	printf("**********************************************\n");
	toxy(35, 30);
}
void show_end()
{
	HideCursor();
	system("cls");  //清屏
	toxy(52, 20);
	printf("正在保存……\n");
	file_save(head);
	system("cls");  //清屏
	toxy(35, 18);
	printf("**********************************************\n");
	toxy(35, 19);
	printf("*               感谢您的使用！               *\n");
	toxy(35, 20);
	printf("**********************************************\n");
}
void show_sort()
{
aa: system("cls");  //清屏
	toxy(35, 10);
	printf("**********************************************\n");
	toxy(35, 11);
	printf("*           请输入你的排序关键词！           *\n");
	toxy(35, 12);
	printf("*--------------------------------------------*\n");
	toxy(35, 13);
	printf("*");
	setColor(9, 15);
	printf("     1.得分        2.篮板        3.助攻     ");
	setColor(4, 15);
	printf("*\n");
	toxy(35, 14);
	printf("*--------------------------------------------*\n");
	toxy(35, 15);
	printf("*");
	setColor(9, 15);
	printf("            A.升序         B.降序           ");
	setColor(4, 15);
	printf("*\n");
	toxy(35, 16);
	printf("*--------------------------------------------*\n");
	toxy(35, 17);
	printf("* 请输入关键词与排序方式的对应数字或字母序号 *\n");
	toxy(35, 18);
	printf("**********************************************\n");
	toxy(35, 19);
	int key1, step = 0;
	char key2;
	setColor(9, 15);
	while (scanf("%d %c", &key1, &key2))
	{
		setColor(4, 15);
		if ((key1 == 1 || key1 == 2 || key1 == 3) && (key2 == 'A' || key2 == 'B'))
			break;
		step++;
		toxy(35, 19 + step);
		printf("输入有误，请重新选择排序条件！\n");
		step++;
		toxy(35, 19 + step);
		setColor(9, 15);
	}
	setColor(4, 15);
	switch (key1)
	{
	case 1://得分
		key2 == 'A' ? qsort_score_up(head->next, NULL) : qsort_score_down(head->next, NULL);//1：按得分升序排序，2：按得分降序排序
		break;
	case 2://篮板
		key2 == 'A' ? qsort_rebound_up(head->next, NULL) : qsort_rebound_down(head->next, NULL);//1：按篮板升序排序，2：按篮板降序排序
		break;
	case 3://助攻
		key2 == 'A' ? qsort_assists_up(head->next, NULL) : qsort_assists_down(head->next, NULL);//1：按助攻升序排序，2：按助攻降序排序
		break;
	}
	system("cls");  //清屏
	toxy(35, 5);
	printf("**********************************************\n");
	toxy(35, 6);
	printf("*                  排序成功！                *\n");
	toxy(35, 7);
	printf("**********************************************\n");
	toxy(35, 8);
	TraverList_L_sort(head, 15, 8, key1);
	setColor(4, 15);
	printf("是否要留在排序菜单？如果要，请输入1，否则都将返回主菜单。");
	char c, cc;
	while ((cc = getchar()) != EOF && cc != '\n');
	setColor(9, 15);
	scanf("%c", &c);
	setColor(4, 15);
	if (c == '1')
		goto aa;
}

void show_search()
{
aa:system("cls");  //清屏
	toxy(35, 10);
	printf("**********************************************\n");
	toxy(35, 11);
	printf("*           请输入你的查找关键词！           *\n");
	toxy(35, 12);
	printf("*--------------------------------------------*\n");
	toxy(35, 13);
	printf("*");
	setColor(9, 15);
	printf("      1.球员                  2.球队        ");
	setColor(4, 15);
	printf("*\n");
	toxy(35, 14);
	printf("*");
	setColor(9, 15);
	printf("      3.得分                  4.助攻        ");
	setColor(4, 15);
	printf("*\n");
	toxy(35, 15);
	printf("*");
	setColor(9, 15);
	printf("      5.篮板                                ");
	setColor(4, 15);
	printf("*\n");
	toxy(35, 16);
	printf("*--------------------------------------------*\n");
	toxy(35, 17);
	printf("*         请输入与关键词相对应的序号         *\n");
	toxy(35, 18);
	printf("**********************************************\n");
	toxy(35, 20);
	int key, step = 0;
	setColor(9, 15);
	while (scanf("%d", &key))
	{
		setColor(4, 15);
		if (key == 1 || key == 2 || key == 3 || key == 4 || key == 5)
			break;
		step++;
		toxy(35, 20 + step);
		printf("输入有误，请重新选择查询关键词！\n");
		char cc;
		while ((cc = getchar()) != EOF && cc != '\n');
		step++;
		toxy(35, 20 + step);
		setColor(9, 15);
	}
	setColor(4, 15);
	int stepp;
	switch (key)
	{
	case 1:
		stepp = find_name(head);
		break;
	case 2:
		stepp = find_team(head);
		break;
	case 3:
		stepp = find_score(head);
		break;
	case 4:
		stepp = find_assist(head);
		break;
	case 5:
		stepp = find_rebound(head);
		break;
	}
	toxy(35, stepp);
	printf("是否要留在查询菜单？如果要，请输入1，否则都将返回主菜单。");
	char c, cc;
	while ((cc = getchar()) != EOF && cc != '\n');
	setColor(9, 15);
	scanf("%c", &c);
	setColor(4, 15);
	if (c == '1')
		goto aa;
}
void show_insert()
{
aa:system("cls");  //清屏
	toxy(35, 18);
	printf("**********************************************\n");
	toxy(35, 19);
	printf("*          请输入你要插入的球员个数          *\n");
	toxy(35, 20);
	printf("**********************************************\n");
	toxy(35, 21);
	int n, step = 0;
	setColor(9, 15);
	while (scanf("%d", &n))
	{
		setColor(4, 15);
		if (n >= 0)
			break;
		step++;
		toxy(35, 21 + step);
		printf("输入的个数有误，请重新输入！\n");
		step++;
		toxy(35, 21 + step);
		setColor(9, 15);
	}
	insert_player(head, n);
	system("cls");  //清屏
	toxy(35, 18);
	printf("**********************************************\n");
	toxy(35, 19);
	printf("*                  插入成功！                *\n");
	toxy(35, 20);
	printf("**********************************************\n");
	toxy(30, 21);
	printf("是否要留在插入菜单？如果要，请输入1，否则都将返回主菜单。");
	char c, cc;
	while ((cc = getchar()) != EOF && cc != '\n');
	setColor(9, 15);
	scanf("%c", &c);
	setColor(4, 15);
	if (c == '1')
		goto aa;
}
void show_delete()
{
aa:system("cls");  //清屏
	toxy(35, 18);
	printf("**********************************************\n");
	toxy(35, 19);
	printf("*         请输入你要删除的球员序号           *\n");
	toxy(35, 20);
	printf("**********************************************\n");
	toxy(35, 21);
	int n, step = 0;
	setColor(9, 15);
	while (scanf("%d", &n))
	{
		setColor(4, 15);
		if (n >= 0)
			break;
		step++;
		toxy(35, 21 + step);
		printf("输入的序号有误，请重新输入！\n");
		step++;
		toxy(35, 21 + step);
		setColor(9, 15);
	}
	int flag = delete_player(head, n);
	order_player(head);
	system("cls");  //清屏
	toxy(35, 18);
	printf("**********************************************\n");
	toxy(35, 19);
	if (flag)
		printf("*                  删除失败！                *\n");
	else
		printf("*                  删除成功！                *\n");
	toxy(35, 20);
	printf("**********************************************\n");
	toxy(30, 21);
	printf("是否要留在删除菜单？如果要，请输入1，否则都将返回主菜单。");
	char c, cc;
	while ((cc = getchar()) != EOF && cc != '\n');
	setColor(9, 15);
	scanf("%c", &c);
	setColor(4, 15);
	if (c == '1')
		goto aa;
}
void show_update()
{
aa:system("cls");  //清屏
	toxy(35, 15);
	printf("**********************************************\n");
	toxy(35, 16);
	printf("*          请输入你要更新的球员序号          *\n");
	toxy(35, 17);
	printf("**********************************************\n");
	toxy(35, 20);
	int n, step = 0;
	setColor(9, 15);
	while (scanf("%d", &n))
	{
		setColor(4, 15);
		if (n >= 0)
			break;
		step++;
		toxy(35, 20 + step);
		printf("输入的序号有误，请重新输入！\n");
		step++;
		toxy(35, 21 + step);
		setColor(9, 15);
	}
	updat_player(head, n);
	system("cls");  //清屏
	toxy(35, 18);
	printf("**********************************************\n");
	toxy(35, 19);
	printf("*                  更新成功！                *\n");
	toxy(35, 20);
	printf("**********************************************\n");
	toxy(30, 21);
	printf("是否要留在更新菜单？如果要，请输入1，否则都将返回主菜单。");
	char c, cc;
	while ((cc = getchar()) != EOF && cc != '\n');
	setColor(9, 15);
	scanf("%c", &c);
	setColor(4, 15);
	if (c == '1')
		goto aa;
}
#endif // MENUU_H_INCLUDED
