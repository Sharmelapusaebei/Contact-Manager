#include <iostream>
#include <cstdlib>
#include "linkedlist.h"

using namespace std;

// Login Function
bool login()
{
    string username, password;

    cout << "=========================================\n";
    cout << "     CONTACT MANAGEMENT SYSTEM\n";
    cout << "=========================================\n\n";

    cout << "Username : ";
    cin >> username;

    cout << "Password : ";
    cin >> password;

    if (username == "admin" && password == "1234")
    {
        cout << "\nLogin Successful!\n";
        return true;
    }

    cout << "\nInvalid Username or Password!\n";
    return false;
}

int main()
{
    LinkedList contacts;

    // Load contacts from file
    contacts.loadFromFile();

    if (!login())
    {
        return 0;
    }

    int choice;

    do
    {
        cout << "\n=========================================\n";
        cout << "      CONTACT MANAGEMENT SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Count Contacts\n";
        cout << "7. Save Contacts\n";
        cout << "8. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            contacts.addContact();
            break;

        case 2:
            contacts.displayContacts();
            break;

        case 3:
            contacts.searchContact();
            break;

        case 4:
            contacts.updateContact();
            break;

        case 5:
            contacts.deleteContact();
            break;

        case 6:
            contacts.countContacts();
            break;

        case 7:
            contacts.saveToFile();
            break;

        case 8:
            contacts.saveToFile();
            cout << "\n=========================================\n";
            cout << "Thank you for using the system!\n";
            cout << "Goodbye!\n";
            cout << "=========================================\n";
            break;

        default:
            cout << "\nInvalid Choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}