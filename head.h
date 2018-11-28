#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#pragma once

#include"LinkList.h"
void qsort_score_up(LinkList head, LinkList end);
void qsort_score_down(LinkList head, LinkList end);
void qsort_rebound_up(LinkList head, LinkList end);
void qsort_rebound_down(LinkList head, LinkList end);
void qsort_assists_up(LinkList head, LinkList end);
void qsort_assists_down(LinkList head, LinkList end);
int find_name(LinkList L);
int find_team(LinkList L);
int find_score(LinkList L);
int find_rebound(LinkList L);
int find_assist(LinkList L);
void find_choose();
void insert_player(LinkList head, int n);
int delete_player(LinkList head, int n);
void order_player(LinkList head);
void updat_player(LinkList head, int n);
void file_save(LinkList L);
void HideCursor();    //隐藏光标
void TraverList_L_sort(LinkList head, int x, int y, int key);
void setColor(unsigned short ForeColor, unsigned short BackGroundColor);
#endif // HEAD_H_INCLUDED
