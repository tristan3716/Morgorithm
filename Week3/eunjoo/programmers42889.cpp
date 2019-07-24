#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b){
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
        int mother=0;
        int son=0;
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
    }
    
    sort(temp.begin(), temp.end(), compare);
    
    
    for(int i=0; i<temp.size(); i++){
        answer.push_back(temp.at(i).second);
    }
    /*
     for(int i=0; i<answer.size(); i++){
     cout << answer.at(i) << endl;
     }
     */
    return answer;
}
/*
int main(){
    
    vector<int> stages;
    
    stages.push_back(4);
    stages.push_back(4);
    stages.push_back(4);
    stages.push_back(4);
    stages.push_back(4);
    
    solution(4, stages);
    return 0;
}
*/
