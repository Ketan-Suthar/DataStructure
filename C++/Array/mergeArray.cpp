#include <iostream>
using namespace std;

void Merge(int *a, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100];

    while (i <= e && j <= e)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= e)
        temp[k++] = a[j++];

    //copy the element
    for (int i = s; i <= e; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int s, int e)
{
    //Base case = 1 or 0
    if (s >= e)
        return;

    //Need To Follow 3 Steps.
    //1. Divide
    int mid = (s + e) / 2;

    //2. Recursively Sort two arrays = 1(s,mid) & 2(mid+1,e)
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);

    //3. Merge The Array
    Merge(a, s, e);
}

int main()
{
    int n;
    int arr[100];
    cout << "Enter Size: ";
    cin >> n;
    cout << "Enter Elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    //Display The Result
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
