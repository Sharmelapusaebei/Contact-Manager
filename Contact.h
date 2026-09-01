#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

using namespace std;

class Contact
{
public:
    string name;
    string phone;
    string email;
    Contact *next;

    Contact(string n, string p, string e)
    {
        name = n;
        phone = p;
        email = e;
        next = NULL;
    }
};

#endif