#ifndef GENERAL_CPP_INCLUDED
#define GENERAL_CPP_INCLUDED

#include "item.cpp"
#include "invoice.cpp"
#include "detail.cpp"
#include <cstdlib>

void blank()
{
    string tmp;
    cout << "\n\ntype anything and press <enter>\n";
    getline(cin >> ws, tmp);
}

void clear()
{
#ifdef __unix
    system("clear");
#else
    system("cls");
#endif
}

#endif