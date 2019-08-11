#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int map[25][25];
int numofhome[323];
int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int cnt;
int n,a;

bool isInside(int a,int b){
  return (a>=0 && a<n) && (b>=0 && b<n);
}

void dfs(int a, int b, int key){
  map[a][b] = key;
  for(int i=0; i<4; i++){
    int dy = a+direction[i][0];
    int dx = b+ direction[i][1];

    if(isInside(dy,dx) && map[dy][dx] == 1){
      dfs(dy,dx,key);
    }
  }
}

void Sol(int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if (map[i][j] == 1){
        cnt++;
        dfs(i, j, cnt+1);
      }
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(map[i][j] > 1){
        numofhome[map[i][j] -2] ++;
      }
    }
  }
}

int main(void){

  cin >> n;
  for(int i=0; i<n; i++){

    for(int j=0; j<n; j++){

      scanf("%1d",&map[i][j]);
    }
  }
  Sol(n);
  sort(numofhome,numofhome+cnt);


  cout << cnt << endl;
  for(int i=0; i<cnt; i++){
    cout << numofhome[i] << endl;
  }
  return 0;
}
