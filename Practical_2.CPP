#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Generates a sorted array of 'size' elements starting from 'startVal'
vector<int> generateSortedArray(int size, int startVal = 1)
{
    vector<int> data(size);
    for (int i = 0; i < size; i++)
        data[i] = startVal + i;
    return data;
}

// Sequential (Linear) Search
// Scans the array one element at a time until a match is found
int sequentialSearch(const vector<int> &data, int target)
{
    for (size_t i = 0; i < data.size(); i++)
    {
        if (data[i] == target)
            return static_cast<int>(i);
    }
    return -1;
}

// Binary Search (iterative)
// Repeatedly halves the search range on a sorted array
int binarySearchIterative(const vector<int> &data, int target)
{
    int start = 0;
    int end = static_cast<int>(data.size()) - 1;

    while (start <= end)
    {
        int middle = start + (end - start) / 2;

        if (data[middle] == target)
            return middle;
        else if (data[middle] < target)
            start = middle + 1;
        else
            end = middle - 1;
    }
    return -1;
}

// Utility to run a search function, time it, and print the result
template <typename Func>
void runAndReport(const string &label, Func searchFunc, const vector<int> &data, int target)
{
    auto begin = high_resolution_clock::now();
    int result = searchFunc(data, target);
    auto end = high_resolution_clock::now();

    cout << "\n" << label << endl;
    if (result != -1)
        cout << "Found target at index: " << result << endl;
    else
        cout << "Target not found in array." << endl;

    cout << "Elapsed time: "
         << duration_cast<microseconds>(end - begin).count()
         << " microseconds" << endl;
}

int main()
{
    const int arraySize = 100000;
    vector<int> dataset = generateSortedArray(arraySize);

    int target;
    cout << "Enter a number to search for: ";
    cin >> target;

    runAndReport("Sequential Search", sequentialSearch, dataset, target);
    runAndReport("Binary Search", binarySearchIterative, dataset, target);

    return 0;
}
