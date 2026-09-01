#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
LinkedList::LinkedList()
{
    head = NULL;
}

// Add Contact
void LinkedList::addContact()
{
    string name, phone, email;

    cin.ignore();

    cout << "\n========== ADD NEW CONTACT ==========\n";

    cout << "Enter Name  : ";
    getline(cin, name);

    cout << "Enter Phone : ";
    getline(cin, phone);

    cout << "Enter Email : ";
    getline(cin, email);

    Contact *newContact = new Contact(name, phone, email);

    // If list is empty
    if (head == NULL)
    {
        head = newContact;
    }
    else
    {
        Contact *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newContact;
    }

    cout << "\nContact Added Successfully!\n";
}

// Display Contacts
void LinkedList::displayContacts()
{
    if (head == NULL)
    {
        cout << "\nNo contacts available.\n";
        return;
    }

    Contact *temp = head;

    cout << "\n============================================================\n";
    cout << left << setw(20) << "Name"
         << setw(18) << "Phone"
         << setw(30) << "Email" << endl;
    cout << "============================================================\n";

    while (temp != NULL)
    {
        cout << left << setw(20) << temp->name
             << setw(18) << temp->phone
             << setw(30) << temp->email << endl;

        temp = temp->next;
    }

    cout << "============================================================\n";
}
// Search Contact
void LinkedList::searchContact()
{
    if (head == NULL)
    {
        cout << "\nNo contacts available.\n";
        return;
    }

    string searchName;
    cin.ignore();

    cout << "\nEnter Name to Search: ";
    getline(cin, searchName);

    Contact *temp = head;

    while (temp != NULL)
    {
        if (temp->name == searchName)
        {
            cout << "\n===== CONTACT FOUND =====\n";
            cout << "Name  : " << temp->name << endl;
            cout << "Phone : " << temp->phone << endl;
            cout << "Email : " << temp->email << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nContact not found.\n";
}

// Update Contact
void LinkedList::updateContact()
{
    if (head == NULL)
    {
        cout << "\nNo contacts available.\n";
        return;
    }

    string searchName;
    cin.ignore();

    cout << "\nEnter Name to Update: ";
    getline(cin, searchName);

    Contact *temp = head;

    while (temp != NULL)
    {
        if (temp->name == searchName)
        {
            cout << "\nEnter New Phone : ";
            getline(cin, temp->phone);

            cout << "Enter New Email : ";
            getline(cin, temp->email);

            cout << "\nContact Updated Successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nContact not found.\n";
}

// Delete Contact
void LinkedList::deleteContact()
{
    if (head == NULL)
    {
        cout << "\nNo contacts available.\n";
        return;
    }

    string searchName;
    cin.ignore();

    cout << "\nEnter Name to Delete: ";
    getline(cin, searchName);

    Contact *temp = head;
    Contact *prev = NULL;

    while (temp != NULL)
    {
        if (temp->name == searchName)
        {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            delete temp;

            cout << "\nContact Deleted Successfully!\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "\nContact not found.\n";
}

// Count Contacts
void LinkedList::countContacts()
{
    int count = 0;
    Contact *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "\nTotal Contacts : " << count << endl;
}
// Save Contacts to File
void LinkedList::saveToFile()
{
    ofstream file("contacts.txt");

    if (!file)
    {
        cout << "\nError saving contacts!\n";
        return;
    }

    Contact *temp = head;

    while (temp != NULL)
    {
        file << temp->name << "|"
             << temp->phone << "|"
             << temp->email << endl;

        temp = temp->next;
    }

    file.close();

    cout << "\nContacts saved successfully.\n";
}

// Load Contacts from File
void LinkedList::loadFromFile()
{
    ifstream file("contacts.txt");

    if (!file)
        return;

    string name, phone, email, line;

    while (getline(file, line))
    {
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);

        if (p1 == string::npos || p2 == string::npos)
            continue;

        name = line.substr(0, p1);
        phone = line.substr(p1 + 1, p2 - p1 - 1);
        email = line.substr(p2 + 1);

        Contact *newContact = new Contact(name, phone, email);

        if (head == NULL)
        {
            head = newContact;
        }
        else
        {
            Contact *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newContact;
        }
    }

    file.close();
}

// Destructor
LinkedList::~LinkedList()
{
    Contact *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}