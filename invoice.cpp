// galuh ramaditya - 1301184505
//

#ifndef INVOICE_CPP_INCLUDED
#define INVOICE_CPP_INCLUDED

#include "invoice.h"

void create(invoice &c)
{
	c.first = NULL;
}

bool empty(invoice c)
{
	return c.first == NULL;
}

invoiceAddress allocation()
{
	time_t now = time(0);
	srand(now);
	dataInvoice c;

	invoiceAddress p = new invoiceList;
	p->info = c;
	p->info.id = rand() % 1000000;
	p->info.time = ctime(&now);
	p->next = NULL;
	return p;
}

invoiceAddress search(invoice c, int id)
{
	invoiceAddress p = c.first;
	if (!empty(c))
	{
		while (p != NULL)
		{
			if (p->info.id == id)
				return p;
			p = p->next;
		}
	}

	return NULL;
}

bool insert(invoice &c, invoiceAddress x)
{
	invoiceAddress p = x;

	p->next = c.first;
	c.first = p;

	return true;
}

bool destroy(invoice &c, int id)
{
	invoiceAddress p = search(c, id);
	if (p != NULL)
	{
		invoiceAddress tmp = c.first;
		if (tmp == p)
		{
			if (tmp->next == NULL)
				create(c);
			else
				c.first = p->next;
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

void print(invoice c)
{
	cout << "========== list Invoice ==========\n";
	if (!empty(c))
	{
		invoiceAddress p = c.first;
		while (p != NULL)
		{
			cout << "id\t\t: " << p->info.id << endl;
			cout << "time\t\t: " << p->info.time;
			cout << "customer\t: " << p->info.customer << endl;
			cout << "total price\t: " << p->info.total_price << endl;
			cout << "-------------------------------\n";
			p = p->next;
		}
	}
	else
		cout << "invoice is empty!\n";
}

#endif