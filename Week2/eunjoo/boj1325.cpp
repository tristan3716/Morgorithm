#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10001]; //인접 리스트를 담을 벡터 생성
vector<int> visited(10001, 0); //방문하는 것을 담을 벡터 0으로 초기화


void func(vector<int> adj[], int i){
    visited.at(i)++; //일단 카운트 하고나서
    if(adj[i].empty()){ //말단이면 멈춘다
        return;
    }else{
        for(int j=0; j<adj[i].size(); j++){ //말단이 아니면 모든 노드를 다 방문해본다(재귀로)
            int temp = adj[i].at(j);
            
            func(adj, temp);
        }
    }
}

int main(){
    
    int computer, M;
    int max=-2100000000;
    
    cin >> computer >> M;
    
    for(int i=0; i<M; i++){ //입력 받는 for문
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }
    
    for(int i=1; i<computer+1; i++){ //재귀로 탐색을 시작하게 되는 구문
        func(adj,i);
    }
    
    for(int i=1; i<computer+1; i++){ //최댓값을 찾아내는 구문
        if(max<visited[i])
            max=visited[i];
    }
    for(int i=1; i<computer+1; i++) {//최댓값이 여러개일수 있으므로 다 찾아냅니다
        if(max==visited[i]){
            cout << i << " ";
        }
    }
    
    return 0;
}
