/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

template <class T>
class minHeap
{
public:
    vector<T> v;

    void up_heapify()
    {
        int i = v.size() - 1;
        while (i > 0)
        {
            int p = (i - 1) / 2;

            if (v[p] > v[i])
            {
                swap(v[p], v[i]);
                i = p;
            }
            else
                break;
        }
    }

    void down_heapify(int i)
    {
        while (i < v.size())
        {
            int max = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < v.size() and v[l] < v[i])
                max = l;
            if (r < v.size() and v[r] < v[max])
                max = r;
            if (max == i)
                break;
            swap(v[i], v[max]);
            i = max;
        }
    }

    void Delete(int idx)
    {
        swap(v[idx], v[v.size() - 1]);
        v.pop_back();
        down_heapify(idx);
    }

    void Insert(T x)
    {
        v.push_back(x);
        up_heapify();
    }

    void build_from_array(vector<T> &a)
    {
        v = a;
        int n = v.size();
        int last_leaf_node = n / 2 - 1;

        for (int i = last_leaf_node; i >= 0; i--)
            down_heapify(i);
    }

    void Print_heap()
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    T getMin()
    {
        return v[0];
    }
    T extractMin()
    {
        T min = v[0];
        Delete(0);
        return min;
    }
};

class PriorityQueue
{
public:
    minHeap<int> h;

    void push(int x)
    {
        h.Insert(-1 * x);
    }
    void pop()
    {
        h.Delete(0);
    }
    int top()
    {
        return h.getMin();
    }
    void print_pq()
    {
        h.Print_heap();
    }
};

vector<int> heapsort(vector<int> &a)
{
    minHeap<int> heap2;
    heap2.build_from_array(a);
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
        ans.push_back(heap2.extractMin() * -1);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    minHeap<int> heap;
    // 5 6 7 14 12 8 10 16 3
    // heap.Insert(5);
    // heap.Insert(6);
    // heap.Insert(7);
    // heap.Insert(14);
    // heap.Insert(12);
    // heap.Insert(8);
    // heap.Insert(10);
    // heap.Insert(16);
    // heap.Insert(3);

    // heap.Print_heap();

    // heap.Delete(0);
    // heap.Print_heap();
    // vector<int> a = {5, 6, 7, 14, 12, 8, 10, 16, 3};
    // vector<int> minus_a;
    // for (auto i : a)
    //     minus_a.push_back(i * -1);
    // // heap.build_from_array(a);
    // // heap.Print_heap();
    // vector<int> ans = heapsort(minus_a);

    // for (auto i : ans)
    //     cout << i << " ";
    // cout << endl;

    PriorityQueue pq;
    pq.push(5);
    pq.push(6);
    pq.push(7);
    pq.push(14);
    pq.push(12);
    pq.push(8);
    pq.push(10);
    pq.push(16);
    pq.push(3);

    pq.print_pq();

    return 0;
}
