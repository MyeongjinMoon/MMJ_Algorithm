using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int x;
	cin >> x;
	sort(arr.begin(), arr.end());

	int result = 0;
	int i = 0; int j = n - 1;

	while (1)
	{
		
		if (i >= j)
		{
			break;
		}
		int temp = (arr[i] + arr[j]);
		if (temp == x)
		{
			result++;
			j--;
		}
		else if (temp > x)
		{
			j--;
		}
		else
		{
			i++;
		}
	}

	cout << result;
}