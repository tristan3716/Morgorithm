#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>
using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	vector<string> s1,s2;
	multiset<string> set1, set2;

	for (int i = 0; i < str1.size(); i++)
		str1[i] = toupper(str1[i]);
	for (int i = 0; i < str2.size(); i++)
		str2[i] = toupper(str2[i]);
	int num1 = 0, num2 = 0;
	int count = 0;
	double res;
	for (int i = 0; i < str1.size(); i++)
	{
		count++;
		if (!(str1.at(i) >= 'A' && str1.at(i) <= 'Z'))
		{
			str1.erase(i, 1);
			i--;
			count = 0;
		}	
		if (count == 2)
		{
			set1.insert(str1.substr(i - 1, 2));
			count = 1;
		}
	}
	count = 0;
	for (int i = 0; i < str2.size(); i++)
	{
		count++;
		if (!(str2.at(i) >= 'A' && str2.at(i) <= 'Z'))
		{
			str2.erase(i, 1);
			i--;
			count = 0;
		}	
		if (count == 2)
		{
			set2.insert(str2.substr(i - 1, 2));
			count = 1;
		}		
	}
	multiset<string> new_set1,new_set2;
	set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(new_set1,new_set1.begin()));
	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(new_set2, new_set2.begin()));
	for (multiset<string>::iterator it = new_set1.begin(); it != new_set1.end(); it++)
	{
		//cout << *it<<" ";
		num1++;
	}
	cout << endl;
	for (multiset<string>::iterator it = new_set2.begin(); it != new_set2.end(); it++)
	{
		//cout << *it << " ";
		num2++;
	}
	if (num1 == 0 && num2 == 0)
	{
		num1 = 1;
		num2 = 1;
	}
	res = num2 / (double)num1;
	answer = (int)(res * 65536);
	return answer;
}
int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	int answer = solution(str1, str2);
	cout << answer;
	return 0;
}