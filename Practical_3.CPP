#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

//---------- Max Heap ----------//
void buildMaxHeap(vector<int> &a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        buildMaxHeap(a, n, largest);
    }
}

void heapSortAscending(vector<int> &a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        buildMaxHeap(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        buildMaxHeap(a, i, 0);
    }
}

//---------- Min Heap ----------//
void buildMinHeap(vector<int> &a, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;

    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        buildMinHeap(a, n, smallest);
    }
}

void heapSortDescending(vector<int> &a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        buildMinHeap(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        buildMinHeap(a, i, 0);
    }
}

void display(vector<int> a)
{
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> data(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> data[i];

    vector<int> asc = data;
    vector<int> desc = data;

    auto start1 = high_resolution_clock::now();
    heapSortAscending(asc);
    auto stop1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    heapSortDescending(desc);
    auto stop2 = high_resolution_clock::now();

    cout << "\nOriginal Array:\n";
    display(data);

    cout << "\nAscending Order (Max Heap):\n";
    display(asc);

    cout << "\nDescending Order (Min Heap):\n";
    display(desc);

    cout << "\nExecution Time\n";
    cout << "Ascending Heap Sort : "
         << duration_cast<microseconds>(stop1 - start1).count()
         << " us\n";

    cout << "Descending Heap Sort : "
         << duration_cast<microseconds>(stop2 - start2).count()
         << " us\n";

    return 0;
}
