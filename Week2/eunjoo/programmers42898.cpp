#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector< vector<int> > arr;
vector< vector<int> > visited;
int answer;

void asdfasdf(int m, int n, vector< vector<int> >school){
    if(school[m][n]==0) {//웅덩이일 때
        return;
    }else if(visited[m][n]==1){//이미 방문했을 때
        return;
    }else if(/*이부분을 어떻게 끝을 만났는지 확인을 어떻게 해야될지 모르겠어요 solution 원형을 건드리지않고ㅠㅠㅠ 조금더 고민해볼께요..*/){
        
    }
    else{
        //끝에 만났다는것을 어떻게 표현할수있을지 조금더 고민해봐야될꺼 같습니다 ㅠㅠ
        
    }
}

int solution(int m, int n, vector< vector<int> > puddles) {
    int answer = 0;
    
    return answer;
}

int main(){
    
    int m, n;
    cin >> m >> n;
    
    for(int i=0; i<n; i++){
        vector<int> element(m);
        arr.push_back(element);
    }
    
    vector< vector<int> > puddles;
    
    
    return 0;
}
