#include <iostream>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);
	
	for (int i = 0; i < n; i++)
	{
		char binary[16] = { 0, };
		int a = arr1[i] | arr2[i];
		for (int j = n-1; j >= 0; j--)
		{
			if (a % 2 == 1)
				binary[j] = '#';
			else
				binary[j] = ' ';
			a /= 2;
		}
		for (int j = 0; j < n; j++)
			cout << binary[j];
		cout << endl;
		answer.push_back(binary);
	}

	return answer;
}

int main()
{
	vector<int> arr1, arr2;
	vector<string> answer;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr1.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr2.push_back(num);
	}
	answer = solution(n, arr1, arr2);
	//for (int i = 0; i < n; i++)
	//	cout << answer.pop_back << " ";
	return 0;
}