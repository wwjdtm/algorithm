#include <iostream>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

void merge(vector<int> & v, int p, int q, int r){
    int a = q-p+1;
    int b = r-q;
    int left[a];
    int right[b];

    for(int i = 0; i<a; i++){ left[i] =  v[p+i]; }
    for(int i = 0; i<b; i++){ right[i] = v[q+i+1]; }

    left[a]=INT_MAX;
    right[b]=INT_MAX;
    int i=0; 
    int j=0;
    for(int k=p; k<=r; k++){
        if(left[i]<=right[j]){v[k]=left[i]; i++;}
        else{v[k]=right[j];j++; }
    }
}

void mergesort(vector<int> & v, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergesort(v,p,q);
        mergesort(v,q+1,r);
        merge(v,p,q,r);
    }
}


int main(void){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int d;
        cin >> d;
        v.push_back(d);
    }
    mergesort(v, 0, v.size()-1);

    for (int i=0; i<n; i++){
        cout << v[i]<<endl;
    }

    return 0;
}
