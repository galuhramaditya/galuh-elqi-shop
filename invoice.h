// galuh ramaditya - 1301184505
// 

#ifndef INVOICE_H_INCLUDED
#define INVOICE_H_INCLUDED

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct dataInvoice
{
	int id;
	string time;
	string customer;
	int total_price;
};

typedef struct invoiceList *invoiceAddress;

struct invoiceList
{
	dataInvoice info;
	invoiceAddress next;
};

struct invoice
{
	invoiceAddress first;
};

void create(invoice &c);
bool empty(invoice c);
invoiceAddress allocation();
invoiceAddress search(invoice c, int id);
bool insert(invoice &c, invoiceAddress x);
bool destroy(invoice &c, int id);
void print(invoice c);

#endif