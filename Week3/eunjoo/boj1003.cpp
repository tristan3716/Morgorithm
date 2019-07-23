#include <iostream>

using namespace std;

int fibonacci[45] = {1, 0, 1, 1};

int main(){
    int input;
    for(int i=3; i<44; i++){
        fibonacci[i+1] = fibonacci[i]+ fibonacci[i-1];
    }
    
    cin >> input;
    
    for(int i=0; i<input; i++){
        int temp;
        cin >> temp;
        cout << fibonacci[temp] << " " << fibonacci[temp+1] << endl;
    }
    return 0;
}
