// galuh ramaditya - 1301184505
// 

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct dataItem
{
	int id;
	string name;
	int price;
};

typedef struct itemList *itemAddress;

struct itemList
{
	dataItem info;
	itemAddress next;
};

struct item
{
	itemAddress first;
};

void create(item &i);
bool empty(item i);
itemAddress allocation(dataItem x);
itemAddress search(item i, int id);
bool insert(item &i, dataItem x);
bool destroy(item &i, int id);
void print(item i);

#endif