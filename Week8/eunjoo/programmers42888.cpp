#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<string> queue; //들어오고 나가는 command를 저장하는 벡터

    map<string, string>openChat; //id에 해당하는 nickname을 저장하는 맵

    for(int i=0; i<record.size(); ++i)
    {
        string id;
        string nickname;
        int temp;

        if(!record.at(i).find("Enter"))
        {
           id = record.at(i).substr(6, string::npos);
           temp = id.find(" ");
           nickname = id.substr(temp+1, string::npos);
           id = id.substr(0, temp);


           openChat[id]=nickname; //id와 nickname을 잘라내고,
           queue.push_back(id+" Enter"); //Enter했다는 커멘드를 아이디와 기록해둔다.

        }
        else if(!record.at(i).find("Leave"))
        {
            id = record.at(i).substr(6, string::npos);
            temp = id.find(" ");
            id = id.substr(0, temp);

            queue.push_back(id+" Leave"); //id를 기록해둔다
            // 한 번 나간 아이디가 평생 안 들어올수도 있는데 그럴때도 history에는 남아야 하기 때문에 map에서 삭제는 ㄴㄴ
        }
        else if(!record.at(i).find("Change"))
        {
            id = record.at(i).substr(7, string::npos);
            temp = id.find(" ");
            nickname = id.substr(temp+1, string::npos);
            id = id.substr(0, temp);

            openChat[id]=nickname; //id에 해당하는 닉네임을 바꿔준다
        }
    }

    for(int i=0; i<queue.size(); ++i)
    {
        int temp = queue.at(i).find(" "); //queue에서 하나씩 빼내어 미리 준비해놨던 띄어쓰기로 구분한다
        string id = queue.at(i).substr(0, temp);
        string command = queue.at(i).substr(temp+1, string::npos);
        //id와 command를 구분해낸다

        //command에 따라서, id에 해당하는 Nickname을 찾은 뒤 answer에 맞는 형식으로 push_back한다.
        if(command=="Enter")
        {
            answer.push_back(openChat[id]+"님이 들어왔습니다.");
        }
        else if(command=="Leave")
        {
            answer.push_back(openChat[id]+"님이 나갔습니다.");
        }
    }

    return answer;
}

int main()
{
    //테스트 케이스
    vector<string> record;
    string a = "Enter uid1234 Muzi";
    string b = "Enter uid4567 Prodo";
    string c = "Leave uid1234";
    string d = "Enter uid1234 Prodo";
    string e = "Change uid4567 Ryan";

    record.push_back(a);
    record.push_back(b);
    record.push_back(c);
    record.push_back(d);
    record.push_back(e);

    solution(record);
}