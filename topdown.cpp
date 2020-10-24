#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int memoized_cut_rod_aux(int p[],int n,int r[]){
    int q;
    if(r[n] >= 0){
        return r[n];
    }
    if(n==0){
        q = 0;
    }
    else{
        q=-1;
        for(int i=1; i<n; i++){
            q = max(q,p[i]+memoized_cut_rod_aux(p,n-i,r));
        }
    }
    r[n] = q;
    return q;
}


int memoized_cut_rod(int p[], int n){
    int r[n];
    for(int i=0; i<n; i++){
        r[n] = -1;
    }
    return memoized_cut_rod_aux(p,n,r);
}



int main(void){
    // int n;
    // cin >> n;
    int p[5] = {0,1,5,8,9};

    int answer = memoized_cut_rod(p , 4);
    cout << answer<<endl;


    return 0;

}