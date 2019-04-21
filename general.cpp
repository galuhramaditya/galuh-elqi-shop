#ifndef GENERAL_CPP_INCLUDED
#define GENERAL_CPP_INCLUDED

#include "item.cpp"
#include "invoice.cpp"
#include "detail.cpp"

void blank()
{
#ifdef __unix
    string tmp;
    cout << "\n\ntype anything and press <enter>\n";
    cin >> tmp;
#else
#include <conio.h>
    cout << "\n\npress <enter>\n";
    getch();
#endif
}

void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

#endif