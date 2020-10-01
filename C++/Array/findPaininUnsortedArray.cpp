#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findPair(vector<int> v, int sum)
{
    //time complexity is O(n)
    int i, j;
    i = 0;            //i is pointing to first element of array/list
    j = v.size() - 1; //j is pointing to last element of array/list

    //we stop the loop when i and j becomes equal
    while (i < j)
    {
        if (v[i] + v[j] == sum)
        {
            cout << "Pair is ( " << v[i] << "," << v[j] << " ) " << endl;
            i++;
            j--;
        }
        else if (v[i] + v[j] > sum)
            j--;
        else if (v[i] + v[j] < sum)
            i++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    vector<int> v(num);

    for (int i = 0; i < num; i++)
        cin >> v[i];

    int sum;
    cin >> sum;

    findPair(v, sum);

    return 0;
}
