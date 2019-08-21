#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int score_a[6] = { 5000000,3000000,2000000,500000,300000,100000 };
	int score_b[5] = { 5120000,2560000,1280000,640000,320000 };
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a = 0, b = 0, sum = 0;
		cin >> a >> b;

		if (a != 0) {
			for (int j = 0; j < 6; j++)
			{
				if (a > j * (j + 1) / 2 && a <= (j + 1)*(j + 2) / 2)
					sum += score_a[j];

			}
		}
		else
			sum += 0;
		if (b != 0) {
			for (int j = 0; j < 5; j++)
			{
				if (b >= pow(2, j) && b < pow(2, j + 1))
					sum += score_b[j];
			}
		}
		else
			sum += 0;
		cout << sum << endl;
	}
	return 0;
}