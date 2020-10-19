
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int main(void) {
    int n;
    vector<int> v;

    cin >> n;

    for (int i=0; i<n; i++){
        int d;
        cin >> d ;
        v.push_back(d);
    }

    // insertion sort
     for (int j=1; j<v.size(); j++){

        int key = v[j];
        int i = j-1;
        while (i>=0 && v[i]>key){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = key;

    }

    for (int i=0; i<n; i++){
        cout << v[i] << endl;
    }
    return 0;
}
