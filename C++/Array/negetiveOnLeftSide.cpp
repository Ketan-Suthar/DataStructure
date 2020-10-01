#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int length;
    cout << "Enter Length: ";
    cin >> length;
    int arr[100];

    cout << "Enter Elements in Array: " << endl;
    for (int a = 0; a < length; a++)
        cin >> arr[a];

    int i = 0;
    int j = length - 1;

    while (i < j)
    {
        while (arr[i] < 0)
            i++;
        while (arr[j] >= 0)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    cout << "Array is: " << endl;
    for (int a = 0; a < length; a++)
        cout << arr[a] << " ";

    return 0;
}
