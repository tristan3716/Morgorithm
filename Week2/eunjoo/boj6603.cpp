#include <iostream>
#include <vector>

using namespace std;

int lotto[14]; //입력받을 로또 받을 변수
int print_lotto[6]; //출력하는 로또 변수

void asdfasdf(int lotto[], int count, int input, int init){ //너무 쓸데없이 인수가 많은데 정리를 할걸그랬습니다..
    if(count==6){ //print_lotto 6개 되었을때 첨부터 출력해주고 끝냄
        for(int i=0; i<6; i++)
            cout << print_lotto[i] << " ";
        cout << endl;
        return;
    }else{
        for(int i=init; i<input; i++){ //그게 아니면 i의 값을 프린트로또에 담고 바로 다음 호출 .. 디버깅 해본 결과 위에 return을 만나면서 이 i값이 1개씩 줄어들면서 모든 값을 다 탐색하는 역할을 수행하게 된다
            print_lotto[count]=lotto[i];
            asdfasdf(lotto, count+1, input, i+1);
        }
        
    }
    
}

int main(){
    
    while(1){
        int input;
        cin >> input;
        if(input==0){ //0이면 종료
            break;
        }
        
        
        for(int i=0; i<input; i++){ //입력 받는 구문
            int temp;
            cin >> temp;
            
            lotto[i] = temp;
        }
        
        asdfasdf(lotto, 0, input, 0);
        
        cout<<endl; //이거 안쓰면 출력 형식 오류남..-_-
    }
    
    return 0;
}
