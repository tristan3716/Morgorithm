#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string input;

    cin >> input;

    char final;

    int CMajorCount=0, AMinorCount=0;

    for(int i=0; i<input.length(); i++){
        char temp = input.at(i);
        if(i==input.length()-1)
            final = temp;
        if(i==0){
            if(temp=='C' || temp=='F' || temp=='G'){
                CMajorCount++;
            }else if(temp=='A' || temp=='D' || temp=='E'){
                AMinorCount++;
            }
            continue;
        }else if(input.at(i-1)=='|'){
            if(temp=='C' || temp=='F' || temp=='G'){
                CMajorCount++;
            }else if(temp=='A' || temp=='D' || temp=='E'){
                AMinorCount++;
            }
        }
    }

    if(CMajorCount>AMinorCount){
        cout << "C-major";
    }else if(CMajorCount<AMinorCount) {
        cout << "A-minor";
    }else {
        if(final=='C' || final=='F' || final=='G'){
            cout << "C-major";
        }else if(final=='A' || final=='D' || final=='E'){
            cout << "A-minor";
        }
    }
    return 0;
}