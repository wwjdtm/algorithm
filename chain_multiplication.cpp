#include <vector>
#include <climits>
#include <iostream>

using namespace std;

long matrix_chain_order(vector<int> &p){
    int n = p.size()-1; //행렬개수
    long m[n][n]; //0~n-1
    for(int i=0; i<n; i++){
        m[i][i]=0;
    }
    long q;
    
    for(int l=2; l<=n; l++){
        for(int i=0; i<=n-l; i++){
            int j = i+l-1;
            m[i][j] = LONG_MAX;
            for(int k=i; k<=j-1; k++){
                q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if( q < m[i][j] ){
                    m[i][j] = q;
                }
            }
        }
    }
    return m[0][n-1];
}
int main(void) {
    int n;
    vector<int> v;

    cin >>  n;
    for (int i=0; i<n+1; i++){
        int d;
        cin >> d;
        v.push_back(d);
    }
    long a = matrix_chain_order(v);
    cout << a;
    // solve here and print the result using cout 
    return 0;
}