#include<iostream>
#include<string>

int solution(std::string name);

int main()
{
	std::string name="";
	std::cin >> name;

	int res = solution(name);

	std::cout << res;

	return 0;
}

int solution(std::string name)
{
	int len = name.length();
	int count = 0;
	int pos = 0;
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
				count = count + (int)(name[i] - 'A');//위로 움직이는 경우
				arr[i]++;
			}
			else
			{
				count = count + (int)('Z' - name[i] + 1);//아래로 움직이는 경우
				arr[i]++;
			}
		}
	}
	do
	{
		if (arr[getAll] != 0)//바꿔야하는 알파벳 위치
		{
			if (pos == 0)
			{
				if (getAll == pos)
				{
					getAll++;
				}
				else
				{
					if (getAll-pos<len/2)//최초위치에서 가까울경우
					{
						pos = pos+getAll - pos;
						getAll++;
					}
					else//최초위치에서 멀경우
					{
						pos = pos + (len - 1 - getAll + 1);
						getAll++;
					}
				}
			}
			else
			{
				if (getAll - pos < len / 2)//이동후 재이동시 거리확인. 가까울경우
				{
					pos = pos + getAll - pos;
					getAll++;
				}
				else//멀경우
				{
					pos = pos + (len - getAll);
					getAll++;
				}
			}
		}
		else
		{
			getAll++;
		}
	} while (getAll < len);

	count = count + pos;
	return count;
}