#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    vector<int>arr;
    vector<int>selectMax;
    int input;
    cin>>input;
    
    for(int i=0; i<input; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    selectMax.push_back(arr.at(0));
    for(int i=1; i<input; i++)
        selectMax.push_back(max(selectMax.at(i-1)+arr.at(i), arr.at(i)));
    
    cout << *max_element(selectMax.begin(), selectMax.end());
    
    return 0;
}
