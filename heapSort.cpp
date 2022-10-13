#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;

class HeapSort
{
public:
    int heap_size = 10;
    int sorting_array[10];
    HeapSort();
    int parent(int i);
    int left(int i);
    int right(int i);

    void max_heapify(int i);

    void build_maax_heap(int n);

    void heap_sort();
};
HeapSort::HeapSort(){
    int j=0;
    for (int i =10; i > 0; i--)
    {
        sorting_array[j]=i;
        j++;
    }
// sorting_array= { 1, 3, 5, 2, 5, 7, 4, 0, 55, 67 };
}
int HeapSort::parent(int i)
{
    return int(floor(i / 2));
}

int HeapSort::left(int i)
{
    return (2 * i + 1);
}
int HeapSort::right(int i)
{
    return 2 * i + 2;
}
void HeapSort::max_heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = 0;

    if (l <= heap_size and sorting_array[l] > sorting_array[i])
        largest = l;
    else
        largest = i;

    if (r <= heap_size and sorting_array[r] > sorting_array[largest])
        largest = r;

    if (largest != i)
    {
        int temp = sorting_array[i];
        sorting_array[i] = sorting_array[largest];
        sorting_array[largest] = temp;
        max_heapify(largest);
    }
    return;
}

void HeapSort::build_maax_heap(int n)
{
    heap_size = n;
    for (int i = int(floor(n / 2)); i > -1; i--)
    {
        max_heapify(i);
    }
    return;
}

void HeapSort::heap_sort()
{
    int n = 10;//sorting_array.size();
    build_maax_heap(n - 1);
    for (int i = n - 1; i > 0; i--)
    {
        int temp = sorting_array[i];
        sorting_array[i] = sorting_array[0];
        sorting_array[0] = temp;
        heap_size = heap_size - 1;
        max_heapify(0);
    }
}
int main()
{
    HeapSort s;
    s.heap_sort();
    cout << s.sorting_array << endl;
    return 0;
}