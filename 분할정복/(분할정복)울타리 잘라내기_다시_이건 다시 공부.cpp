//https://www.algospot.com/judge/submission/recent/
#include <iostream>
using namespace std;

int arr[20005] = { 0, };

int Max(int a, int b) { return a > b ? a : b; }
int Min(int a, int b) { return a > b ? b : a; }

int solve(int left, int right)
{
	if (left == right) return arr[left];
	int mid = (left + right) / 2;
	int ret = Max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, hi = mid + 1;
	int height = Min(arr[lo], arr[hi]);

	ret = Max(ret, height * 2);

	while (left < lo || hi < right)
	{
		if (hi < right && (lo == left || arr[lo - 1] < arr[hi + 1]))
		{
			++hi;
			height = Min(height, arr[hi]);
		}
		else
		{
			--lo;
			height = Min(height, arr[lo]);
		}

		ret = Max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main(void)
{
	int testcase;
	cin >> testcase;
	for (int itr = 0; itr < testcase; itr++)
	{
		int num;
		cin >> num;
		
		for (int i = 0; i < num; i++)
		{
			cin >> arr[i];
		}

		cout << solve(0, num - 1) << endl;

		for (int i = 0; i < num; i++) arr[i] = 0;

	}

	return 0;
}