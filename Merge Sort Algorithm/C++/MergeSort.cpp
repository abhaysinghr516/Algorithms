#include <bits/stdc++.h>
using namespace std;

void conqurer(int *a, int s, int e, int mid)
{
    int *merged = new int[e - s + 1];
    int index1 = s;
    int index2 = mid + 1;
    int mainindex = 0;

    while (index1 <= mid && index2 <= e)
    {
        if (a[index1] <= a[index2])
        {
            merged[mainindex++] = a[index1++];
        }
        else
        {
            merged[mainindex++] = a[index2++];
        }
    }
    while (index1 <= mid)
    {
        merged[mainindex++] = a[index1++];
    }
    while (index2 <= e)
    {
        merged[mainindex++] = a[index2++];
    }

    for (int i = 0, j = s; i < (e - s) + 1; i++, j++)
    {
        a[j] = merged[i];
    }

    delete[] merged;
}

void divide(int *a, int s, int e)
{
    while (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    divide(a, s, mid);
    divide(a, mid + 1, e);

    conqurer(a, s, e, mid);
}
int main()
{
    int a[20] = {4, 5, 6, 3, 12};
    int size = 5;
    divide(a, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
