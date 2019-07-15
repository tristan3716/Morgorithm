#include<iostream>
#include<string>

int solution(std::string name);

int main()
{
	std::string name = "";
	std::cin >> name;

	int res = solution(name);

	std::cout << res;

	return 0;
}

int solution(std::string name)
{
	int len = name.length();
	int cnt_up = 0;
	int cnt_col = 0;
	int count = 0;
	int idx = 0;
	int getAll = 0;

	if (len == 0)
	{
		return count;//길이가 0인경우
	}
	int* arr = (int*)calloc(len, sizeof(int));//바꿔야하는곳의 인덱스 확인

	for (int i = 0; i < len; i++)
	{
		if (name[i] != 'A')
		{
			if (name[i] <= 'N')
			{
				cnt_up = cnt_up + (int)(name[i] - 'A');//위로 움직이는 경우
				arr[i]++;
			}
			else
			{
				cnt_up = cnt_up + (int)('Z' - name[i] + 1);//아래로 움직이는 경우
				arr[i]++;
			}
		}
	}
	do
	{
		if (arr[getAll] != 0)
		{
			if (idx == 0)
			{
				if (getAll == idx)
				{
					arr[getAll] = 0;
					getAll++;
				}
				else
				{
					if (getAll - idx < len / 2)
					{
						cnt_col = cnt_col + (getAll - idx);
						idx = getAll;
						arr[getAll] = 0;
						getAll++;
					}
					else
					{
						cnt_col = cnt_col + (len - getAll);
						idx = getAll;
						arr[getAll] = 0;
						getAll++;
					}
				}
			}
			else
			{
				if (getAll-idx < len / 2)
				{
					cnt_col = cnt_col + (getAll - idx);
					idx = getAll;
					arr[getAll] = 0;
					getAll++;
				}
				else
				{
					cnt_col = cnt_col + getAll;
					idx = getAll;
					arr[getAll] = 0;
					getAll++;
				}
			}
		}
		else
		{
			if (arr[len - 1] != 0&&idx==0)
			{
				idx = len - 1;
				int check = 0;
				arr[len - 1] = 0;
				cnt_col++;
				for (int i = 0; i < len; i++)
				{
					if (arr[i] != 0)
					{
						check = 1;
					}
				}
				if (check == 1)
				{
					idx = 0;
					cnt_col++;
				}
				getAll++;
			}
			else
			{ 
				getAll++;
			}
		}
	}while (getAll < len);
	std::cout << cnt_col<<"\n";
	count = cnt_col + cnt_up;
	return count;
}