#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_front(12);

    for (auto i : l)
        cout << i << " ";
    cout << endl;

    cout << "Front : " << l.front() << endl;
    cout << "Back : " << l.back() << endl;

    l.sort();

    for (auto i : l)
        cout << i << " ";
    cout << endl;

    cout << l.empty() << endl; // 0 // Which means lists is not empty

    l.clear(); // Clears the list

    cout << l.empty() << endl; // 1 // Which means lists is not empty

    list<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (std::list<int>::iterator it = c.begin(); it != c.end();)
    {
        if (*it % 2 == 0)
            it = c.erase(it);
        else
            ++it;
    }
    // 1 3 5 7 9

    c.erase(c.begin());

    // 3 5 7 9

    /*---------------------------------------
            Merge
    --------------------------------------------*/
    list<int> list1 = {5, 9, 1, 3, 3};
    list<int> list2 = {8, 7, 2, 3, 4, 4};

    list1.sort();
    list2.sort();

    for (auto i : list1)
        cout << i << " ";
    cout << endl;
    // 1 3 3 5 9

    for (auto i : list2)
        cout << i << " ";
    cout << endl;
    // 2 3 4 4 7 8

    list1.merge(list2);

    for (auto i : list1)
        cout << i << " ";
    cout << endl;
    // 1 2 3 3 3 4 4 5 7 8 9

    list1.reverse();

    for (auto i : list1)
        cout << i << " ";
    cout << endl;
    // 9 8 7 5 4 4 3 3 3 2 1

    cout << endl;

    return 0;
}