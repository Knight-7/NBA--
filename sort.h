#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#pragma once

#include<stdio.h>
#include"LinkList.h"
#include"head.h"
//const int maxn = 1e5;
//得分——升序
void qsort_score_up(LinkList head, LinkList end)
{
	if (head == NULL || head == end)
		return;
	LinkList p = head;
	LinkList q = head->next;
	float base = head->data.score;
	while (q != end) {
		if (q->data.score < base) {
			p = p->next;
			player t = p->data;
			p->data = q->data;
			q->data = t;
			q = q->next;
		}
		else
			q = q->next;
	}
	player t = p->data;
	p->data = head->data;
	head->data = t;
	qsort_score_up(head, p);
	qsort_score_up(p->next, end);
}
//得分——降序
void qsort_score_down(LinkList head, LinkList end)
{
	if (head == NULL || head == end)
		return;
	LinkList p = head;
	LinkList q = head->next;
	float base = head->data.score;
	while (q != end) {
		if (q->data.score > base) {
			p = p->next;
			player t = p->data;
			p->data = q->data;
			q->data = t;
			q = q->next;
		}
		else
			q = q->next;
	}
	player t = p->data;
	p->data = head->data;
	head->data = t;
	qsort_score_down(head, p);
	qsort_score_down(p->next, end);
}
//篮板——升序
void qsort_rebound_up(LinkList head, LinkList end)
{
	if (head == NULL || head == end)
		return;
	LinkList p = head;
	LinkList q = head->next;
	float base = head->data.rebound;
	while (q != end) {
		if (q->data.rebound < base) {
			p = p->next;
			player t = p->data;
			p->data = q->data;
			q->data = t;
			q = q->next;
		}
		else
			q = q->next;
	}
	player t = p->data;
	p->data = head->data;
	head->data = t;
	qsort_rebound_up(head, p);
	qsort_rebound_up(p->next, end);
}
//篮板——降序
void qsort_rebound_down(LinkList head, LinkList end)
{
	if (head == NULL || head == end)
		return;
	LinkList p = head;
	LinkList q = head->next;
	float base = head->data.rebound;
	while (q != end) {
		if (q->data.rebound > base) {
			p = p->next;
			player t = p->data;
			p->data = q->data;
			q->data = t;
			q = q->next;
		}
		else
			q = q->next;
	}
	player t = p->data;
	p->data = head->data;
	head->data = t;
	qsort_rebound_down(head, p);
	qsort_rebound_down(p->next, end);
}
//助攻——升序
void qsort_assists_up(LinkList head, LinkList end)
{
	if (head == NULL || head == end)
		return;
	LinkList p = head;
	LinkList q = head->next;
	float base = head->data.assist;
	while (q != end) {
		if (q->data.assist < base) {
			p = p->next;
			player t = p->data;
			p->data = q->data;
			q->data = t;
			q = q->next;
		}
		else
			q = q->next;
	}
	player t = p->data;
	p->data = head->data;
	head->data = t;
	qsort_assists_up(head, p);
	qsort_assists_up(p->next, end);
}
//助攻——降序
void qsort_assists_down(LinkList head, LinkList end)
{
	if (head == NULL || head == end)
		return;
	LinkList p = head;
	LinkList q = head->next;
	float base = head->data.assist;
	while (q != end) {
		if (q->data.assist > base) {
			p = p->next;
			player t = p->data;
			p->data = q->data;
			q->data = t;
			q = q->next;
		}
		else
			q = q->next;
	}
	player t = p->data;
	p->data = head->data;
	head->data = t;
	qsort_assists_down(head, p);
	qsort_assists_down(p->next, end);
}
//根据编号排序
void sort_order(LinkList L)
{
	L = L->next;
	int n = 0, m;
	player p;
	LinkList l;
	l = L;
	while (l != NULL) {
		n++;
		l = l->next;
	}
	while (n > 1) {
		m = n;
		l = L;
		while (m > 1) {
			if (l->data.order > l->next->data.order) {
				p = l->data;
				l->data = l->next->data;
				l->next->data = p;
				l = l->next;
				m--;
			}
			else {
				l = l->next;
				m--;
			}
		}
		n--;
	}
}

#endif // SORT_H_INCLUDED
