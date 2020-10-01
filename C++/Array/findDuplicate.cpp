#include <iostream>
#include <vector>
using namespace std;

void findDuplicate(vector<int> v, int num)
{
    int l = 1, h = 12;
    int *H = new int[h]{0};
    for (int i = 0; i < num; i++)
        H[v[i]]++;
    for (int i = l; i <= h; i++)
        if (H[i] == 0)
            cout << "Missing Element is " << i << endl;
}

int main()
{
    int num;
    cout << "Enter Size: ";
    cin >> num;
    vector<int> v(num);

    cout << "Enter Elements in Array: " << endl;
    for (int i = 0; i < num; i++)
        cin >> v[i];

    findDuplicate(v, num);
    return 0;
}
