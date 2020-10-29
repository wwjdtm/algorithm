#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> arr){
    int memo[200][200] = {0};
    int dp_max[200][200] = {0}; 
    int dp_min[200][200] = {0};
    //string to int
    for (int i = 0; i < arr.size(); i+=2) {
        dp_max[i][i] = stoi(arr[i]);
        dp_min[i][i] = stoi(arr[i]);
    }
    //비교
    for (int a=2; a < arr.size(); a+=2) {
        for (int i=0; i < arr.size(); i+=2) {
            for (int j=i+1; j < i+a; j+=2) {
                if (j == arr.size()){break;}
                if (arr[j] == "+") {
                    if (memo[i][i+a] == 0) {
                        memo[i][i+a] = 1;
                        dp_max[i][i+a] = dp_max[i][j-1] + dp_max[j+1][i+a];
                        dp_min[i][i+a] = dp_min[i][j-1] + dp_min[j+1][i+a];
                    }else {
                        dp_max[i][i+a] = max(dp_max[i][i+a], dp_max[i][j-1] + dp_max[j+1][i+a]);
                        dp_min[i][i+a] = min(dp_min[i][i+a], dp_min[i][j-1] + dp_min[j+1][i+a]);
                    }
                }else {
                    if (memo[i][i+a] == 0) {
                        memo[i][i+a] = 1;
                        dp_max[i][i+a] = dp_max[i][j-1] - dp_min[j+1][i+a];
                        dp_min[i][i+a] = dp_min[i][j-1] - dp_max[j+1][i+a];
                    }else{
                        dp_max[i][i+a] = max(dp_max[i][i+a], dp_max[i][j-1] - dp_min[j+1][i+a]);
                        dp_min[i][i+a] = min(dp_min[i][i+a], dp_min[i][j-1] - dp_max[j+1][i+a]);
                    }
                }
            }
        }
    }
    int answer = 1;
    answer = dp_max[0][arr.size()-1];

    return answer;

}