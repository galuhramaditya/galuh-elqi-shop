// galuh ramaditya - 1301184505
// Elqi Ashok - 1301184158

#ifndef DETAIL_CPP_INCLUDED
#define DETAIL_CPP_INCLUDED

#include "detail.h"

void create(detail &d)
{
	d.first = NULL;
}

bool empty(detail d)
{
	return d.first == NULL;
}

detailAddress allocation(dataDetail x, itemAddress i, invoiceAddress c)
{
	detailAddress p = new detailList;
	p->info = x;
	p->next = NULL;
	p->item = i;
	p->invoice = c;

	return p;
}

bool insert(detail &d, dataDetail x, itemAddress i, invoiceAddress c)
{
	detailAddress p = allocation(x, i, c);

	p->next = d.first;
	d.first = p;

	return true;
}

bool refresh(detail &d)
{
	if (!empty(d))
	{
		detailAddress p = d.first;
		while (p != NULL)
		{
			if (p->invoice == NULL || p->item == NULL)
			{
				detailAddress tmp = d.first;
				if (tmp == p)
				{
					if (tmp->next == NULL)
						create(d);
					else
						d.first = p->next;
				}
				else
				{
					while (tmp->next != p)
					{
						tmp = tmp->next;
					}
					tmp->next = p->next;
				}
			}
			p = p->next;
		}
	}
	return true;
}

void print(detail d, invoiceAddress c)
{
	cout << "========== list Detail ==========\n";
	detailAddress p = d.first;
	while (p != NULL)
	{
		if (c == p->invoice)
		{
			cout << "item\t\t: " << p->item->info.name << endl;
			cout << "price/pcs\t: " << p->item->info.price << endl;
			cout << "note\t\t: " << p->info.note << endl;
			cout << "quantity\t: " << p->info.quantity << endl;
			cout << "total price\t: " << p->item->info.price * p->info.quantity << endl;
			cout << "-------------------------------\n";
		}
		p = p->next;
	}
}

#endif