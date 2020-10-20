#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &a, int p, int r){
    int x = a[r]; //pivot
    int i = p-1;
    for(int j=p; j<=r-1; j++){
        if(a[j]<=x){
            i++;
            int c = a[i];
            a[i] = a[j];
            a[j] = c;
        }
    }
    int d = a[i+1];
    a[i+1] = a[r];
    a[r] = d;

    return i+1;
}

void quicksort(vector<int> &a, int p, int r){
    if(p<r){
        int q = partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

int main(void){
    int n;
    cin >> n;
    vector<int> a;
    for (int i=0; i<n; i++){
        int d;
        cin >> d;
        a.push_back(d);
     }
    // quicksort
    quicksort(a, 0, a.size()-1);

    for (int i=0; i<n; i++){
        cout << a[i];
    }

    return 0;
}