// galuh ramaditya - 1301184505
// Elqi Ashok - 1301184158

#ifndef APP_CPP_INCLUDED
#define APP_CPP_INCLUDED

#include "itemApp.cpp"
#include "invoiceApp.cpp"

int input;

void blank();

void listItem(item &i, invoice &c, detail &d)
{
    do
    {
        system("clear");
        cout << "<< List of Items\n\n";
        print(i);
        cout << "\nMENU\n";
        cout << "1. buy item\n";
        cout << "2. add item\n";
        cout << "3. delete item\n";
        cout << "0. back\n";
        cout << "input\t: ";
        cin >> input;
        cout << endl;
        switch (input)
        {
        case 1:
            buyItem(i, c, d);
            blank();
            break;
        case 2:
            addItem(i);
            blank();
            break;
        case 3:
            deleteItem(i);
            refresh(d);
            blank();
            break;
        }
        cout << endl;
    } while (input != 0);
}

void listInvoice(item &i, invoice &c, detail &d)
{
    do
    {
        system("clear");
        cout << "<< List of Invoice\n\n";
        print(c);
        cout << "\nMENU\n";
        cout << "1. detail invoice\n";
        cout << "2. delete invoice\n";
        cout << "0. back\n";
        cout << "input\t: ";
        cin >> input;
        cout << endl;
        switch (input)
        {
        case 1:
            detailInvoice(c, d);
            blank();
            break;
        case 2:
            deleteInvoice(c);
            refresh(d);
            blank();
            break;
        }
        cout << endl;
    } while (input != 0);
}

void blank()
{
    string tmp;
    cout << "\n\ntype anything and press <enter>\n";
    cin >> tmp;
}

#endif