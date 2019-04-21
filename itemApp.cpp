// galuh ramaditya - 1301184505
// Elqi Ashok - 1301184158

#include "general.cpp"

void buyItem(item &i, invoice &c, detail &d)
{
    int id;
    char add;
    bool valid = false;
    itemAddress _item;
    dataDetail _detail;
    invoiceAddress _invoice = allocation();

    _invoice->info.total_price = 0;
    do
    {
        cout << "enter item id that you want to buy\t: ";
        cin >> id;
        _item = search(i, id);
        if (_item != NULL)
        {
            valid = true;
            cout << "many items those you want to buy\t: ";
            cin >> _detail.quantity;
            _invoice->info.total_price += _item->info.price * _detail.quantity;
            cout << "write your note\t\t\t\t: ";
            getline(cin >> ws, _detail.note);
            insert(d, _detail, _item, _invoice);
        }
        else
            cout << "nothing item with id " << id << "!\n";
        cout << endl;
        do
        {
            cout << "do you want to add more item [y/n]? ";
            cin >> add;
        } while (add != 'y' && add != 'n');
    } while (add != 'n');

    cout << endl;
    if (valid)
    {
        cout << "total price\t\t\t\t: " << _invoice->info.total_price << endl;
        cout << "enter the customer's name\t\t: ";
        getline(cin >> ws, _invoice->info.customer);
        insert(c, _invoice);
        cout << "\npurchase successfully!\n";
    }
    else
        cout << "\nnothing items those will be buy!\n";
}

void addItem(item &i)
{
    dataItem x;
    clear();
    cout << "<< Add Item\n\n";
    cout << "item name\t: ";
    cin >> x.name;
    cout << "item price\t: ";
    cin >> x.price;
    insert(i, x) ? cout << "\nadd item successfully!\n" : cout << "\nadd item failed!\n";
}

void deleteItem(item &i)
{
    int id;
    cout << "enter item id will be delete : ";
    cin >> id;
    destroy(i, id) ? cout << "\ndelete item successfully!\n" : cout << "\nnothing item with id " << id << "!\n";
}