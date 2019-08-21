#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N, K;
	int num;
	long double sum = 0.0;
	long double mean = 0;
	int count = 0;
	int k_count = 0;
	long double variance, deviation, min;
	vector<int> v;
	vector<long double> result;
	cin >> N >> K;
	cout.precision(11);
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < v.size(); i++)
	{
		deviation = 0.0;
		variance = 0.0;
		count++;
		sum += v.at(i);

		if (count == K)
		{
			count = 0;
			i = k_count;
			k_count++;
			mean = sum / K;
			sum = 0;
			for (int j = k_count-1; j < k_count+K-1; j++)
			{
				sum += pow(v.at(j) - mean, 2);
			}
			variance = sum / K;
			deviation = sqrt(variance);
			result.push_back(deviation);
			sum = 0;

			if (k_count > v.size() - K)
			{
				if (K == N)
					break;
				K++;
				i = -1;
				k_count = 0;
				count = 0;
			
			}
				
		}	
	}
	min = result.at(0);
	for (int i = 1; i < result.size(); i++)
	{
		if (min > result.at(i))
			min = result.at(i);
	}
	cout << min << endl;

	return 0;
}