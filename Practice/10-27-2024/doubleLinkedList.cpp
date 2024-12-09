#include <iostream>
using namespace std;

// Doubly Linked List Node
struct DLink
{
    int data;       // Data stored in the node
    DLink *lnkNext; // Pointer to the next node
    DLink *lnkPrev; // Pointer to the previous node
    DLink(int value) : data(value), lnkNext(nullptr), lnkPrev(nullptr) {}
};

// Doubly Linked List Base Class
class DoublyLinkedList
{
protected:
    DLink *head; // Head pointer
    DLink *tail; // Tail pointer

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the end of the list
    void insert_back(int value)
    {
        DLink *newLink = new DLink(value);
        if (!head)
        { // If list is empty
            head = tail = newLink;
        }
        else
        {
            tail->lnkNext = newLink;
            newLink->lnkPrev = tail;
            tail = newLink;
        }
    }

    // Print list from head to tail
    void print_list() const
    {
        DLink *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->lnkNext;
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~DoublyLinkedList()
    {
        DLink *current = head;
        while (current)
        {
            DLink *next = current->lnkNext;
            delete current;
            current = next;
        }
    }
};

// Sorted Doubly Linked List that inherits DoublyLinkedList
class SortedDoublyLinkedList : public DoublyLinkedList
{
public:
    // Insert in sorted order
    void insert_sorted(int value)
    {
        DLink *newLink = new DLink(value);

        // Case 1: Insert at the front if list is empty or new value is smallest
        if (!head || head->data >= value)
        {
            newLink->lnkNext = head;
            if (head)
                head->lnkPrev = newLink;
            head = newLink;
            if (!tail)
                tail = head;
            return;
        }

        // Case 2: Find correct position in the list
        DLink *current = head;
        while (current->lnkNext && current->lnkNext->data < value)
        {
            current = current->lnkNext;
        }

        // Insert in the middle or end
        newLink->lnkNext = current->lnkNext;
        if (current->lnkNext)
            current->lnkNext->lnkPrev = newLink;
        newLink->lnkPrev = current;
        current->lnkNext = newLink;
        if (!newLink->lnkNext)
            tail = newLink; // Update tail if added at end
    }
};

// Prioritized List by recent use, inheriting from SortedDoublyLinkedList
class PrioritizedList : public SortedDoublyLinkedList
{
public:
    // Move a recently accessed node to the front of the list
    void prioritize(int value)
    {
        DLink *current = head;

        // Locate the node with the given value
        while (current && current->data != value)
        {
            current = current->lnkNext;
        }

        // Node not found or already at front
        if (!current || current == head)
            return;

        // Detach the node from its current position
        if (current->lnkNext)
            current->lnkNext->lnkPrev = current->lnkPrev;
        if (current->lnkPrev)
            current->lnkPrev->lnkNext = current->lnkNext;

        // If this node was the tail, update the tail
        if (current == tail)
            tail = current->lnkPrev;

        // Move node to front
        current->lnkNext = head;
        current->lnkPrev = nullptr;
        if (head)
            head->lnkPrev = current;
        head = current;
    }
};

// Main function to test the list functionalities
int main()
{
    cout << "Doubly Linked List:" << endl;
    DoublyLinkedList dll;
    dll.insert_back(1);
    dll.insert_back(2);
    dll.insert_back(3);
    dll.print_list();

    cout << "\nSorted Doubly Linked List:" << endl;
    SortedDoublyLinkedList sll;
    sll.insert_sorted(5);
    sll.insert_sorted(3);
    sll.insert_sorted(7);
    sll.insert_sorted(1);
    sll.print_list();

    cout << "\nPrioritized List before query:" << endl;
    PrioritizedList pl;
    pl.insert_sorted(3);
    pl.insert_sorted(5);
    pl.insert_sorted(7);
    pl.insert_sorted(10);
    pl.print_list();

    // Query node to bring it to front
    cout << "\nAfter prioritizing 7:" << endl;
    pl.prioritize(7);
    pl.print_list();

    cout << "\nAfter prioritizing 10:" << endl;
    pl.prioritize(10);
    pl.print_list();

    return 0;
}
