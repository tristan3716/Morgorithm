#include <iostream>

using namespace std;

int arr[12];

int main(){

    int input;

    arr[1]=1;
    arr[2]=2;
    arr[3]=4;

    for(int i=4; i<13; i++){
        arr[i] = arr[i-1]+ arr[i-2] + arr[i-3];
    }

    cin >> input;

    for(int i=0; i<input; i++){
        int temp;
        cin >> temp;

        cout << arr[temp] << endl;
    }

    return 0;
}