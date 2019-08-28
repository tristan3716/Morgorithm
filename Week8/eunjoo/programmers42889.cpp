#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b){ //stable 정렬 하려고 만든 함수
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first > b.first;
    }
}


vector<int> solution(int N, vector<int>stages){
    vector<int> answer;
    vector< pair<double, int> >temp;
    
    for(int i=0; i<N; i++){
        int mother=0; //실패율을 계산하기 위한 분모
        int son=0; //실패율을 계산하기 위한 분자
        for(int j=0; j<stages.size(); j++){
            if(i+1<=stages.at(j)){
                mother++;
            }
            if(i+1==stages.at(j)){
                son++;
            }
        }
        if(mother==0){
            temp.push_back(make_pair(double(0), i+1));
        }else{
            temp.push_back(make_pair((double)son/mother, i+1));
        }
        ///실패율 계산
    }
    
    sort(temp.begin(), temp.end(), compare); //sorting하는데 compare함수를 이용하여 stable정렬한다.
    
    for(int i=0; i<temp.size(); i++){
        answer.push_back(temp.at(i).second); //answer에 원하는 값을 push_back한다.
    }
    /*
     for(int i=0; i<answer.size(); i++){
     cout << answer.at(i) << endl;
     }
     */
    return answer;
}
