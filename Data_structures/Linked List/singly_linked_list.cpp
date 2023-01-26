/*

LINKED LIST FUNCTIONS

01 : Creating New Node with a Null Pointer
02 : Insert at head
03 : Insert at any Index
04 : Print the linked list
05 : Search First Index of a value
06 : Search All Indices of a value
07 : Get Size
08 : Get Value at an Index
09 : Delete at the beginning
10 : Delete at any Index
11 : Print Reverse Order
12 : Swap First Two
13 : Insert after a value
14 : Bubble Sort on Linked List
15 : Delete all Zeros
16 : Get Odd Index Sum
17 : LL has Duplicate Values ?

*/

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
    /*------------------------------------------------------------
            01 : Creating New Node with a Null Pointer
        ---------------------------------------------------------------*/
    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    /*------------------------------------------------------------
                02 : Insert at head
       ---------------------------------------------------------------*/

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
    /*------------------------------------------------------------
                03 : Insert at any Index
   ---------------------------------------------------------------*/
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

    /*------------------------------------------------------------
                04 : Print the linked list
   ---------------------------------------------------------------*/
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

    /*------------------------------------------------------------
                05 : Search First Index of a value
   ---------------------------------------------------------------*/
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
    /*------------------------------------------------------------
                06 : Search All Indices of a value
   ---------------------------------------------------------------*/
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

    /*------------------------------------------------------------
                        07 : Get Size
       ---------------------------------------------------------------*/
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

    /*------------------------------------------------------------
        08 : Get Value at an Index
   ---------------------------------------------------------------*/
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

    /*------------------------------------------------------------
                09 : Delete at the beginning
   ---------------------------------------------------------------*/
    void DeleteAtHead()
    {
        if (head == NULL)
            return;
        sz--;

        node *a = head;
        head = a->nxt;

        delete a;
    }

    /*------------------------------------------------------------
                10 : Delete at any Index
   ---------------------------------------------------------------*/
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

    /*------------------------------------------------------------
            11 : Print Reverse Order
   ---------------------------------------------------------------*/
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

    /*------------------------------------------------------------
            12 : Swap First Two
   ---------------------------------------------------------------*/
    void swapFirst()
    {
        node *a = head;
        node *b = a->nxt;

        swap(a->data, b->data);
    }

    /*------------------------------------------------------------
                    13 : Insert after a value
   ---------------------------------------------------------------*/
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

    /*------------------------------------------------------------
            14 : Bubble Sort on Linked List
   ---------------------------------------------------------------*/
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

    /*------------------------------------------------------------
                15 : Delete all Zeros
   ---------------------------------------------------------------*/
    void deleteAllZeroes()
    {
        node *cur = head;
        node *pre = NULL;
        node *next = NULL;

        while (cur != NULL)
        {
            next = cur->nxt;
            node *temp = cur;
            if (cur->data == 0)
            {
                if (pre != NULL)
                    pre->nxt = cur->nxt;

                if (cur == head)
                    head = cur->nxt;

                delete cur;
                sz--;
            }
            pre = temp;
            cur = next;
        }
    }

    /*------------------------------------------------------------
                16 : Get Odd Index Sum
   ---------------------------------------------------------------*/
    int getOddIndexSum()
    {
        node *a = head;
        int i = 0, sum = 0;
        while (a != NULL)
        {
            if (i % 2 == 1)
            {
                sum += a->data;
            }
            a = a->nxt;
            i++;
        }
        return sum;
    }

    /*------------------------------------------------------------
            17 : LL has Duplicate Values ?
   ---------------------------------------------------------------*/
    bool hasDuplicate()
    {
        node *a = head;
        map<int, int> m;
        while (a != NULL) // Time Complexity of Nlogn
        {
            m[a->data]++;
            a = a->nxt;
        }

        for (auto i : m)
        {
            if (i.second > 1)
                return true;
        }
        return false;
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

    cout << l.getValue(2) << "\n";

    cout << l.getValue(6) << "\n";

    l.printReverse();
    l.Traverse();
    l.swapFirst();
    l.InsertAtAnyIndex(4, 0);
    l.InsertAtAnyIndex(0, 0);
    l.InsertAtAnyIndex(7, 0);
    l.deleteAllZeroes();
    l.Traverse();
    cout << l.getOddIndexSum() << endl;

    if (l.hasDuplicate())
        cout << "Has Duplicate" << endl;
    else
        cout << "No Duplicate" << endl;

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
