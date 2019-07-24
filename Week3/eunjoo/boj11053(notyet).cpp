#include <iostream>
#include <vector>

using namespace std;

int main(){
    int input;
    int top_one = 0;
    int top_two = 0;
    
    int temp_one = 0;
    int temp_two = 0;
    cin >> input;
    
    vector<int> vec;
    
    for(int i=0; i<input; i++){
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    
    for(int i=0; i<input; i++){
        if(i==0){
            temp_one = vec.at(i);
            top_one++;
            continue;
        }
        if(temp_one<vec.at(i)){
            temp_one = vec.at(i);
            top_one++;
        }else if(temp_one>vec.at(i)) {
            if (temp_two < vec.at(i)) {
                temp_two = vec.at(i);
                top_two++;
            }
        }else if(temp_one == vec.at(i)){
            if(temp_two == vec.at(i)){
                if(top_one > top_two){
                    top_one++;
                }else if(top_two < top_one){
                    top_two++;
                }else{
                    top_one++;
                    top_two++;
                }
            }
        }
        
        
        
        
        /*else{
         if(temp_one<vec.at(i)) {
         temp_one = vec.at(i);
         top_one++;
         }else(temp_one>vec.at(i)){
         if
         }
         
         
         
         
         
         
         
         
         
         else if(temp_one>temp_two){
         top_one++;
         }else if(temp_one<temp_two){
         top_two++;
         }else if(temp_one==temp_two){
         if(top_one>top_two){
         top_one++;
         }else if(top_one<top_two){
         top_two++;
         }
         }
         }
         */
    }
    
    if(top_one<top_two){
        cout << top_two << endl;
    }else {
        cout << top_one << endl;
    }
    return 0;
}
