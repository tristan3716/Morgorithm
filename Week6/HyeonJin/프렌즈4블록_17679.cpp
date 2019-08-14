#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	string ch_board[30];
	int num_board[30][30];
	for (int i = 0; i < m; i++)
	{
		ch_board[i] = board[i];
	}
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			num_board[i][j] = 1;
		}
	}
	while (true) {
		bool flag = false;
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				char ch = ch_board[i][j];
				if (ch != ' ' && ch == ch_board[i][j + 1] && ch == ch_board[i + 1][j + 1] && ch == ch_board[i + 1][j])
				{
					num_board[i][j] = 2;
					num_board[i][j+1] = 2;
					num_board[i+1][j] = 2;
					num_board[i+1][j+1] = 2;
					flag = true;
				}
			}
		}
		if (flag == false)
			break;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (num_board[i][j] == 2)
				{
					num_board[i][j] = 0;
					ch_board[i][j] = ' ';
					answer++;
				}
			}
		}
			for (int j = 0; j < n; j++)
			{
				for (int i = m - 2; i >= 0; i--)
				{
					int temp = i;
					while (temp < m - 1)
					{
						if (num_board[temp + 1][j] == 1)
							break;
						temp++;
					}
					if (temp != i)
					{
						
						num_board[temp][j] = num_board[i][j];
						num_board[i][j] = 0;
						ch_board[temp][j] = ch_board[i][j];
						ch_board[i][j] = ' ';
					
					}
				}
			}
	}
	for (int i = 0; i < m; i++)
		cout << ch_board[i] << endl;
	return answer;
}
int main()
{
	vector<string> board;
	string str;
	int answer;
	int m, n;

	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		board.push_back(str);
	}
	answer = solution(m, n, board);
	cout << answer;
	return 0;
}