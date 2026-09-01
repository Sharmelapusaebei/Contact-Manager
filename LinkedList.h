// TEST123
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Contact.h"

class LinkedList
{
private:
    Contact *head;

public:
    // Constructor
    LinkedList();

    // Core Operations
    void addContact();
    void displayContacts();
    void searchContact();
    void updateContact();
    void deleteContact();
    void countContacts();

    // File Handling
    void saveToFile();
    void loadFromFile();

    // Destructor
    ~LinkedList();
};

#endif