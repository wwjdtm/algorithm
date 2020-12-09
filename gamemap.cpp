// #include<vector>
// #include<iostream>
// using namespace std;

// int main(void)
// {   
//     int maps[5][5] = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
//     int answer = 1;
//     int up = 0;
//     int c1 = 0;
//     int c2 = 0;
//     // int check=0;
//     // cout << maps[0][0];
    
//     //캐릭터(0,0) = c1,c2
    
//     while(answer<20){
        
//         if(maps[c1+1][c2] == 1 && up == 0){
//             if(c1+1<=4){
//                 c1++;
//                 answer++;
//                 up=0;
//                 cout << c1 <<' '<<c2 << endl;
//             }else{
//                 up=1;
//             }
//         }else{up=1;}
//         cout << up <<endl;
        
//         if(maps[c1][c2+1]==1 && up==1){
//             if(c2+1<=4){
//                 c2++;
//                 up = 0;
//                 answer++;
//                 cout << c1 <<' '<<c2 << endl;
//             }else{
//                 up=2;
//             }
//         }else if(up!=0){up=2;}
//         cout << up <<endl;
        
//         if(up==2){
//             c1--;
//             up = 1;
//             answer++;
//             cout << c1 <<' '<<c2 << endl;
//         }
//         cout << up <<endl;
        
//         if(c1 ==4 && c2 == 4){
//             // cout << answer;
//             // return answer;
//             break;
//         }
//         // else if(answer>4){
//         //     return 0;
//         //     break;
//         // }else{continue;}
//     }
//     cout << answer;
//     return answer;
// }


#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int dx[] = {0,0,-1,1}, dy[]={-1,1,0,0};
int dist[101][101];
int main(void){
    int maps[5][5] = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
    dist[0][0]= 1;
    int n = 4;
    int m = 4;
    queue<pair<int, int> > q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        // for(int j=0; j<101; j++){
        //         for(int k=0; j<101; j++){
        //             cout << dist[j][k] << ' ';
        //         }
        //         cout << endl;
        //     }
        //     cout << "end"<< endl;
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        cout << dist[x][y]<<endl;
        if (x == n && y ==m){
            return dist[x][y];
        }
        for(int i=0;i<4;i++){
            int nx = x+dx[i], ny = y+dy[i];
            if (nx <0 || nx >n || ny <0 || ny > m) continue;
            if (maps[nx][ny]==0 || dist[nx][ny]!=0) continue;
            dist[nx][ny]= dist[x][y]+1;

            cout << nx << ' '<< ny << endl;
            
            
            q.push(make_pair(nx,ny));
        }
        cout << "end"<<endl;
    }
    return -1;
}