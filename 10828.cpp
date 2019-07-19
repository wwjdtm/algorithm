#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;

    stack<int> st;
    string str;

   for(int i=0; i<n; i++){
       cin >> str;
       if(str == "push"){
           int num;
           cin >> num;
           st.push(num);
       }else if(str == "pop"){
           if(st.empty()){
               cout << -1 << endl;
           }else{
               cout << st.top() << endl;
               st.pop();
           }
       }else if(str == "size"){
           cout << st.size() << endl;
       }else if(str == "empty"){
           if(st.empty()){
               cout << 1 << endl;
           }else {
               cout << 0 << endl;
           }
       }else if(str == "top"){
           if(st.empty()){
               cout << -1 << endl;
           }else{
               cout << st.top() << endl;
           }
       }

   }
}