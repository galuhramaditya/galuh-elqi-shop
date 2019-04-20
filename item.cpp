// galuh ramaditya - 1301184505
//

#ifndef ITEM_CPP_INCLUDED
#define ITEM_CPP_INCLUDED

#include "item.h"

void create(item &i)
{
	i.first = NULL;
}

bool empty(item i)
{
	return i.first == NULL;
}

itemAddress allocation(dataItem x)
{
	srand(time(0));
	x.id = rand() % 10000;

	itemAddress p = new itemList;
	p->info = x;
	p->next = NULL;

	return p;
}

itemAddress search(item i, int id)
{
	itemAddress p = i.first;
	while (p != NULL)
	{
		if (p->info.id == id)
			return p;
		p = p->next;
	}

	return NULL;
}

bool insert(item &i, dataItem x)
{
	itemAddress p = allocation(x);

	p->next = i.first;
	i.first = p;

	return true;
}

bool destroy(item &i, int id)
{
	itemAddress p = search(i, id);
	if (p != NULL)
	{
		itemAddress tmp = i.first;
		if (tmp == p)
		{
			if (tmp->next == NULL)
				create(i);
			else
				i.first = p->next;
		}
		else
		{
			while (tmp->next != p)
			{
				tmp = tmp->next;
			}
			tmp->next = p->next;
		}
		return true;
	}
	return false;
}

void print(item i)
{
	cout << "========== list item ==========\n";
	if (!empty(i))
	{
		itemAddress p = i.first;
		while (p != NULL)
		{
			cout << "id\t: " << p->info.id << endl;
			cout << "name\t: " << p->info.name << endl;
			cout << "price\t: " << p->info.price << endl;
			cout << "-------------------------------\n";
			p = p->next;
		}
	}
	else
		cout << "item is empty!\n";
}

#endif