#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *nxt;
};

class LinkedList
{
public:
    node *head;
    int sz;

    LinkedList()
    {
        head = NULL;
        sz = 0;
    }

    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    void InsertAtHead(int value)
    {
        sz++;
        node *a = CreateNewNode(value);

        if (head == NULL)
        {
            head = a;
            return;
        }

        a->nxt = head;
        head = a;
    }

    void InsertAtAnyIndex(int index, int value)
    {

        if (index < 0 || index > sz)
        {
            return;
        }

        if (index == 0)
        {
            InsertAtHead(value);
            return;
        }

        sz++;
        node *a = head;
        int cur_index = 0;

        while (cur_index != index - 1)
        {
            a = a->nxt;
            cur_index++;
        }

        node *newnode = CreateNewNode(value);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }

    void Traverse()
    {
        node *a = head;

        while (a != NULL)
        {
            cout << a->data << " ";
            a = a->nxt;
        }

        cout << endl;
    }

    int SearchDistinctValue(int value)
    {
        node *a = head;
        int index = 0;

        while (a != NULL)
        {
            if (a->data == value)
                return index;
            a = a->nxt;
            index++;
        }

        return -1;
    }

    void SearchAllvalue(int value)
    {
        node *a = head;
        int index = 0;

        while (a != NULL)
        {
            if (a->data == value)
            {
                cout << value << " Found at : " << index << endl;
            }

            a = a->nxt;
            index++;
        }
    }

    int getSize()
    {
        return sz;
        // int count = 0;
        // node *a = head;
        // while (a != NULL)
        // {
        //     count++;
        //     a = a->nxt;
        // }
        // return count;
    }

    int getValue(int index)
    {
        node *a = head;
        int i = 1;

        if (index >= getSize())
        {
            return -1;
        }

        while (a != NULL)
        {
            if (i == index)
            {
                return a->data;
            }
            a = a->nxt;
            i++;
        }
    }

    void DeleteAtHead()
    {
        if (head == NULL)
            return;
        sz--;

        node *a = head;
        head = a->nxt;

        delete a;
    }

    void DeleteAtAnyIndex(int index)
    {
        if (index < 0 || index > sz - 1)
            return;

        if (index == 0)
        {
            DeleteAtHead();
            return;
        }

        sz--;
        node *a = head;
        int cur_index = 0;

        while (cur_index != index - 1)
        {
            a = a->nxt;
            cur_index++;
        }

        node *b = a->nxt;
        a->nxt = b->nxt;
        delete b;
    }

    void printReverse2(node *a)
    {
        if (a == NULL)
            return;

        printReverse2(a->nxt);
        cout << a->data << " ";
    }
    void printReverse()
    {
        printReverse2(head);
        cout << endl;
    }
    void swapFirst()
    {
        node *a = head;
        node *b = a->nxt;

        swap(a->data, b->data);
    }
    void InsertAfterValue(int value, int data)
    {

        node *a = head;

        while (a != NULL)
        {
            if (a->data == value)
            {
                break;
            }
            a = a->nxt;
        }

        sz++;

        if (a == NULL)
            cout << value << " Does not exists ! " << endl;

        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        a->nxt = newnode;
    }
    void BubbleSort()
    {

        for (node *i = head; i != NULL; i = i->nxt)
        {
            for (node *j = i->nxt; j != NULL; j = j->nxt)
            {
                if (i->data > j->data)
                    swap(i->data, j->data);
            }
        }
    }
};

int main()
{

    LinkedList l;
    node *head = NULL;

    cout << l.getSize() << "\n";
    l.InsertAtHead(5);
    cout << l.getSize() << "\n";
    l.InsertAtHead(6);
    l.InsertAtHead(30);
    cout << l.getSize() << "\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);

    cout << l.getValue(2) << "\n";

    cout << l.getValue(6) << "\n";

    l.printReverse();
    l.Traverse();
    l.swapFirst();
    l.InsertAtAnyIndex(4, 200);
    l.InsertAtAnyIndex(1, 200);
    l.Traverse();
    l.printReverse();
    // l.DeleteAtHead();
    // l.Traverse();
    // l.DeleteAtAnyIndex(1);
    // l.Traverse();
    // l.InsertAfterValue(30, 100);
    // l.Traverse();
    // cout << endl;
    // cout << l.getSize() << endl;

    return 0;
}
