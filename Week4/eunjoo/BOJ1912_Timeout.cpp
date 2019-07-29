#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int input;
    cin >> input;
    
    vector<int> selectMax(input);
    vector<int> inputNumber(input);
    for(int i=0; i<input; i++){
        int temp;
        cin >> temp;
        inputNumber.at(i) = temp;
    }
    
    for(int i=0; i<input; i++) {
        int sum = 0;
        vector<int> tempNumber;
        for (int j = i; j < input; j++) {
            sum += inputNumber.at(j);
            tempNumber.push_back(sum);
        }
        selectMax.at(i) = *max_element(tempNumber.begin(), tempNumber.end());
    }
    
    cout << *max_element(selectMax.begin(), selectMax.end());    
    
    return 0;
}
