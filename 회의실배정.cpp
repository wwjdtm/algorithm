#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int solution(vector<vector<int> > arr)
{
    sort(arr.begin(), arr.end()); 

	int answer = 0;
    int time = INT_MAX;
	for (int i = arr.size()-1; i >=0; i—) {
  
        if (time >= arr[i][1]) {
            time = arr[i][0];
            answer++;
        }
    }
    return answer;
}