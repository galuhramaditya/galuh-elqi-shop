// galuh ramaditya - 1301184505
// 

#ifndef DETAIL_H_INCLUDED
#define DETAIL_H_INCLUDED

#include <iostream>
#include <string>
#include "item.h"
#include "invoice.h"
using namespace std;

struct dataDetail
{
	string note;
	int quantity;
};

typedef struct detailList *detailAddress;

struct detailList
{
	dataDetail info;
	detailAddress next;
	itemAddress item;
	invoiceAddress invoice;
};

struct detail
{
	detailAddress first;
};

void create(detail &d);
bool empty(detail d);
detailAddress allocation(dataDetail x, itemAddress i, invoiceAddress c);
bool insert(detail &d, dataDetail x, itemAddress i, invoiceAddress c);
bool refresh(detail &d);
void print(detail d, invoiceAddress c);

#endif