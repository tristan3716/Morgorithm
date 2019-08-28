#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;
	vector<string> command;

	for (int i = 0; i < record.size(); ++i) {
		int index = 0;
		bool flag = false;
		for (int j = 0; j < record[i].size(); ++j) {
			if (record[i].at(j) == ' ')
			{
				if (record[i].at(0) == 'L')
				{

					command.push_back("Leave"+record[i].substr(j+1,20));
					break;
				}
				if (flag == false)
				{
					flag = true;
					index = j + 1;
				}
				else {
					
					if (record[i].at(0) == 'E')
					{
						m[record[i].substr(index, j - index)] = record[i].substr(j + 1, 20);
						command.push_back("Enter"+ record[i].substr(index, j - index ));
					}
					else if (record[i].at(0) == 'C') {
		
						m[record[i].substr(index, j - index)] = record[i].substr(j + 1, 20);
					}
				}
			}
		}
	}
	for (int i = 0; i < command.size(); ++i) {
		if (command.at(i).at(0) == 'E'){
			answer.push_back(m[command.at(i).substr(5, 20)] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		else if(command.at(i).at(0) == 'L')
		{
			answer.push_back(m[command.at(i).substr(5, 20)] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");		
		}	
	}
 	return answer;
}

int main() {
	string str;
	vector<string> record;
	for (int i = 0; i < 5; ++i) {
		getline(cin, str);
		record.push_back(str);
	}
	vector<string> answer = solution(record);
	return 0;
}