#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int cnt=0;
    int max=-2100000000, asdf;
    
    multimap<string, int> sMap[10001];
    int sum[10001]={0};
    
    
    for(int i=0; i<genres.size(); i++){ //넣는 과정
        bool flag=true;
        string temp = genres.at(i);
        
        for(int j=0; j<10001; j++){
            if(sMap[j].count(temp)) { //있으면
                sMap[j].insert(pair<string, int>(temp, plays.at(i)));//해당 거기에 넣고
                flag=false; //플래그를 변경시킨다
                break;
            }
        }
        
        if(flag){ //플래그가 변경되지 않았다면 해당 key가 없었다는 의미이므로
            sMap[cnt].insert(pair<string, int>(temp, plays.at(i)));
            cnt++;
        }
    }
    
    for(int i=0; i<cnt; i++){ //각자값들을 탐색해서 더해서 sum배열에 넣습니다
        int temp=0;
        for(auto it= sMap[i].begin(); it!=sMap[i].end(); it++){
            temp+= it->second;
        }
        sum[i]=temp;
    }
    
    for(int i=0; i<cnt; i++){ //sum 배열에서 큰 값을 찾습니다 (테스트케이스에 의하면 pop이 나옴)
        if(max<sum[i]){
            max=sum[i];
            asdf=i;
        }
    }
    cout << asdf<<endl;
    
    for(auto it= sMap[asdf].begin(); it!=sMap[asdf].end(); it++){
        //이제 그걸 찾았으니까
    }
    
    
    return answer;
}

int main(){
    vector<string> genres;
    vector<int>plays;
    
    genres.push_back("classic");
    genres.push_back("pop");
    genres.push_back("classic");
    genres.push_back("classic");
    genres.push_back("pop");
    
    plays.push_back(500);
    plays.push_back(600);
    plays.push_back(150);
    plays.push_back(800);
    plays.push_back(2500);
    
    vector<int>answer = solution(genres, plays);
    
    
    
    
    return 0;
    
}

