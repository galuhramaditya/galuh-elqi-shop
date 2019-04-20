// galuh ramaditya - 1301184505
// 

#include "item.cpp"
#include "invoice.cpp"
#include "detail.cpp"

void detailInvoice(invoice c, detail d)
{
    int id;
    invoiceAddress _invoice;

    cout << "enter invoice id that you want to see : ";
    cin >> id;
    cout << endl;
    _invoice = search(c, id);
    if (_invoice != NULL)
    {
        system("clear");
        cout << "<< Detail Item\n\n";
        cout << "id\t\t: " << _invoice->info.id << endl;
        cout << "time\t\t: " << _invoice->info.time;
        cout << "customer\t: " << _invoice->info.customer << endl << endl;
        print(d, _invoice);
        cout << "\ntotal price\t: " << _invoice->info.total_price << endl;
    }
    else
        cout << "nothing invoice with id " << id << "!\n";
}

void deleteInvoice(invoice &c)
{
    int id;
    cout << "enter invoice id will be delete : ";
    cin >> id;
    destroy(c, id) ? cout << "\ndelete invoice successfully!\n" : cout << "\nnothing invoice with id " << id << "!\n";
}