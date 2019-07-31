#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string input;
    cin >> input;
    
    vector<int> number;
    
    for(int i=0; i<input.length(); i++){
        number.push_back(input.at(i)-'0');
    }
    
    sort(number.begin(), number.end(), greater<int>());
    
    int sum=0;
    for(int i=0; i<number.size(); i++){
        sum += number.at(i);
    }
    
    int lastNumber = number.at(number.size()-1);
    if(lastNumber != 0 || sum%3){
        cout << -1;
    }else{
        for(int i=0; i<number.size(); i++){
            cout<<number.at(i);
        }
    }
    
    return 0;
}
