#include <iostream>

using namespace std;

long long prinarynumber[91];

int main(){
    prinarynumber[1]=1;
    prinarynumber[2]=1;
    
    for(int i=3; i<91; i++){
        prinarynumber[i] = prinarynumber[i-1] + prinarynumber[i-2];
    }
    
    int input;
    cin >> input;
    
    cout << prinarynumber[input] << endl;
    
    return 0;
}
