#include<bits\stdc++.h>
using namespace std;

int numberOfStepsZero(int num)
{
	return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num;
	cin >> num;

	cout << numberOfStepsZero(num) << endl;

	return 0;
}
