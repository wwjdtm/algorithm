#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

//answer1
int recursive(int s[], int f[]){
    // int n = 3;
    int a = 1;
    int k = 0;
    for (int i=1; i<11; i++){
        // cout << s[i] << ' '<<f[k]<<endl;
        if (s[i] >= f[k]){
            cout << s[i] << ' '<<f[i]<<endl;
            
            a ++;
            k = i;

        }
    }
    cout << a;
    return a;
}

//answer2
// int ans(int arr[][2]){
//     // sort(arr[0]); 

// 	int answer = 0;
//     int time = INT_MAX;
// 	for (int i = 10; i >=0; i--) {
  
//         if (time >= arr[i][1]) {
//             time = arr[i][0];
//             cout << arr[i][0] <<' '<<arr[i][1] <<endl;;
//             answer++;
        
//         }
//     }
//     cout << answer;
//     return answer;
// }
int main(void)
{
    // int arr[11][2]={
    //     {0,6},
    //     {1,4},
    //     {2,14},
    //     {3,5},
    //     {3,9},
    //     {5,7},
    //     {5,9},
    //     {6,10},
    //     {8,11},
    //     {8,12},
    //     {12,16}
    // }; //answer2

    int s[11]={1,3,0,5,3,5,6,8,8,2,12};//answer1
    int f[11]={4,5,6,7,9,9,10,11,12,14,16};//answer1
    

    // int answer = ans(arr); //answer2
    int answer2 = recursive(s,f); //answer1
}