#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> v;
    MaxHeap()
    {
    }

    // Complete Binary tree er height Logn so complexity O(logn)
    void upHeapify(int i)
    {
        while (i > 0 and v[i] > v[(i - 1) / 2])
        {
            swap(v[i], v[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    // Insert Function O(logn)
    void insert(int x)
    {
        v.push_back(x);
        upHeapify(v.size() - 1);
    }
    // Print Heap
    void printHeap()
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    void down_heapify(int i)
    {
        while (1)
        {
            int large = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < v.size() and v[l] > v[large])
                large = l;
            if (r < v.size() and v[r] > v[large])
                large = r;
            if (large == i)
                break;
            swap(v[large], v[i]);
            i = large;
        }
    }

    // Delete Function O(logn)
    void Delete(int i)
    {
        if (i >= v.size())
            return;
        swap(v[i], v[v.size() - 1]);
        v.pop_back();
        down_heapify(i);
    }

    int getMax()
    {
        if (v.empty())
        {
            cout << "Heap is empty " << endl;
            return -1;
        }
        return v[0];
    }

    int extract_heap()
    {
        if (v.empty())
        {
            cout << "Heap is empty " << endl;
            return -1;
        }
        int ret = v[0];
        Delete(0);
        return ret;
    }
};

int main()
{
    MaxHeap heap;
    heap.insert(4);
    heap.insert(7);
    heap.insert(9);
    heap.insert(1);
    heap.insert(10);
    heap.insert(20);
    heap.insert(30);
    heap.printHeap();
    // heap.Delete(0);
    // heap.printHeap();

    cout << heap.getMax() << endl;
    heap.extract_heap();
    heap.printHeap();

    return 0;
}