#include <iostream>
#include <vector>
using namespace std;

void max_heapify(vector<int> &a, int i){
    int l = i*2+1; //왼쪽자식노드
    int r = i*2+2; //오른쪽자식노드
    int largest;
    if(l<=a.size()-1 && a[l]>a[i]){
        largest = l;
    }
    else{largest = i;}

    if(r<=a.size()-1 && a[r]>a[largest]){
        largest = r;
    }

    if (largest != i) {
        int c = a[i];
        a[i] = a[largest];
        a[largest]= c;
        max_heapify(a,largest);
    }

}
void build_max_heap(vector<int> &a){
    for(int i=(a.size()-1)/2; i>=0; i--){
        max_heapify(a,i);
    }
}

int main(void){
    int n;
    cin >> n;
    vector<int> v;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    build_max_heap(v);

    for(int i=0; i<v.size(); i++){
        cout << v[i] << ' ';
    }
    return 0;

}
