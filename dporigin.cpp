#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int cutrod(int p[], int n){
    if(n == 0){
        return 0;
    }
    int q = INT_MIN;
    for(int i=1; i<=n; i++){
        q = max(q , p[i]+cutrod(p,n-i));
    }
    return q;
}

int main(void){
    // int n;
    // cin >> n;
    int p[5] = {0,1,5,8,9};

    int answer = cutrod(p , 4);
    cout << answer <<endl;


    return 0;

}