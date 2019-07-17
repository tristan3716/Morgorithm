#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    
    vector<int> array;
    
    int result=0;
    int size;
    
    cin >> size;
    
    for(int i=0; i<size; i++) { //값 입력하는 부분
        int temp;
        cin >> temp;
        
        array.push_back(temp);
    }
    
    sort(array.begin(), array.end()); //정렬
    
    for(int i=0; i<size; i++) { //정렬하고 나서부터 작은 값부터 누적해나갑니다
        int tTemp;
        if(i==0) { //바보라서 0일때랑 0이 아닐때랑 나눠서 했습니다..
            result += array.at(i);
            tTemp = array.at(i);
        }else {
            int temp = tTemp + array.at(i);
            tTemp = temp;
            result += tTemp;
        }
    }
    
    cout <<result<<endl;
    
    return 0;
}
