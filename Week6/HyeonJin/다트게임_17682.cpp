#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int score[3] = { 0, };
	int sum[3] = { 0, };
	int index = 0;
	int n_count = 0;

	for (int i = 0; i < dartResult.size(); i++)
	{
		n_count++;
		if (dartResult.at(i) == '*')
		{
			if (index == 1)
				sum[index - 1] *= 2;
			else
			{
				sum[index - 2] *= 2;
				sum[index - 1] *= 2;
			}
			n_count--;
				
		}
		if (dartResult.at(i) == '#')
		{
			sum[index - 1] *= -1;
			n_count--;
		}
		if (dartResult.at(i) == 'S' || dartResult.at(i) == 'D' || dartResult.at(i) == 'T')
		{
			char ch = dartResult.at(i);
			string a;
			if(n_count==2)
				a = dartResult.substr(i-1,1);
			else
				a = dartResult.substr(i - 2, 2);
			score[index] = stoi(a);

			if (ch == 'D')
				sum[index] = score[index] * score[index];
			else if (ch == 'T')
				sum[index] = score[index] * score[index] * score[index];
			else if (ch == 'S')
				sum[index] = score[index];

			index++;
			n_count = 0;
		}
		if (i == dartResult.size() - 1)
		{
			for (int i = 0; i < 3; i++)
			{
				answer += sum[i];
			}
		}
	}
	
	return answer;
}
int main()
{
	string str;
	cin >> str;
	int answer = solution(str);
	cout << answer << endl;
	return 0;
}