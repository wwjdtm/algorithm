#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int a;
    cin >> a;
    stack<int> st;

    int i =1;
    st.push(i);

    string answer;
    int check = 0;
    for(int j=0; j< a; j++){
        int n;
        cin >> n;
        while(check ==0){
            if(st.top() < n){
               answer+='+';
                st.push(i++);
            
            }else if(st.top()==n){
                answer+='-';
                st.pop();
                if(st.empty()){st.push(i++);answer+='+';}
                break;
            }else{ check = 1;break;}
        }
    }
    if(check == 0){
        for(int k=0; k<answer.size(); k++){
                cout << answer[k] << endl;
            }
    }else {
        cout << "NO" << endl;
    }
}

