#include <iostream>
#include <vector>

using namespace std;

int main(){
    int input;
    cin >> input;
    
    vector< vector<int> >dp(input, vector<int>(input, -2100000000));
    
    int max = -2100000001;
    
    for(int i=0; i<input; i++){
        int temp;
        cin >> temp;
        dp[i][i] = temp;
    }
    
    int temp = input -1;
    for(int i=0; i<temp; i++){
        for(int j=0; j<temp-i; j++){
            dp[j][j+i+1] = dp[j][j+i] + dp[j+i+1][j+i+1];
        }
    }
    
    for(int i=0; i<input; i++){
        for(int j=0; j<input; j++){
            if(max<dp[i][j]){
                max = dp[i][j];
            }
        }
    }
    cout << max;
    return 0;
}
