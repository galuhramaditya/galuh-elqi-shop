// galuh ramaditya - 1301184505
// 

#include "app.cpp"

item i;
invoice c;
detail d;

void menu();

int main()
{
	create(i);
	create(c);
	create(d);

	menu();

	return 0;
}


void menu()
{
	int input;

	do
	{
		system("clear");
		cout << "===========================\n";
		cout << "||   Galuh & Elqi Shop   ||\n";
		cout << "===========================\n";
		cout << "\nMENU\n";
		cout << "1. list of items\n";
		cout << "2. check invoices\n";
		cout << "0. exit\n";
		cout << "input\t: ";
		cin >> input;
		cout << endl;
		switch (input)
		{
		case 1:
			listItem(i, c, d);
			break;

		case 2:
			listInvoice(i, c, d);
			break;
		}
		cout << endl;
	} while (input != 0);
}