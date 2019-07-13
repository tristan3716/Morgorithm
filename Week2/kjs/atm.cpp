#include<iostream>
#include<vector>
#include<algorithm>

int get_sum(std::vector<int> v, int len);

int main()
{
	int n;
	std::cin >> n;//인원수
	std::vector<int> v(n);

	for (auto i = v.begin(); i < v.end(); i++)
		std::cin >> *i;//인원당 필요시간

	sort(v.begin(), v.end());//최소 시간순으로 정렬
	int *arr = (int*)calloc(v.size(), sizeof(int));//대기시간 포함 총 필요시간 저장할 배열
	int res = 0;

	for (int i=0;i<v.size();i++)
	{
		if (i == 0)
		{
			arr[i] = v[i];
		}
		else
		{
			arr[i] = get_sum(v, i);//총 필요시간 저장
		}
	}
	for (int i = 0; i < n; i++)
		res = res + arr[i];//합산

	std::cout << res;

	return 0;
}

int get_sum(std::vector<int> v, int len)
{
	int count = 0;
	int res = 0;
	for (; count < len+1; count++)
	{
		res = res + v[count];//해당 인원까지의 소요시간+본인 사용시간
	}

	return res;//반환
}