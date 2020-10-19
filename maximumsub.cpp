#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int find_crossing_subarray(vector<int> &a, int low, int mid, int high){
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;
    for(int i=mid; i>=low; i--){
        sum = sum+a[i];
        if(sum>left_sum){
            left_sum = sum;
        }
    }
    sum = 0;
    for(int i=mid+1; i<=high; i++){
        sum = sum+a[i];
        if(sum > right_sum){
            right_sum = sum;
        }
    }
    return right_sum+left_sum;
}

int find_maximum_subarray(vector<int> &a, int low, int high){
    if(high==low){return a[low];}
    else{
        int mid = (low+high)/2;

        int left_sum = find_maximum_subarray(a,low,mid);
        int right_sum = find_maximum_subarray(a,mid+1,high);
        int cross_sum = find_crossing_subarray(a,low,mid,high);


        if(left_sum>=right_sum && left_sum>=cross_sum){
            return left_sum;
        }else if(right_sum>=left_sum && right_sum>=cross_sum){
            return right_sum;
        }else { return cross_sum;}
    }
}

int main(void){
    int answer = 0;
    int d;
    vector<int> a;
    cin >> d; 
    for(int i=0; i<d; i++){
        int b;
        cin >> b;
        a.push_back(b);
    }
    answer = find_maximum_subarray(a,0,a.size()-1);
    cout << answer;
    return answer;
}