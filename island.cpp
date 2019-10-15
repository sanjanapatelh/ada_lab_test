#include<bits/stdc++.h>
using namespace std;
#define COL 5
#define ROW 5
bool isSafe(int a[][COL],int r,int c,int visited[][COL]){
  if((r>=0 && r<ROW) && (c>=0 && c<COL) && (a[r][c]==1 && visited[r][c]==0) )
    return true;
  return false;
}
void dfs(int a[][COL],int r,int c,int visited[][COL]){
  int static rowbr[]={-1,-1,-1,0,0,1,1,1};
  int static colbr[]={-1,0,1,-1,1,-1,0,1};
  visited[r][c]=1;
  for(int i=0;i<8;i++){
    if(isSafe(a,r+rowbr[i],c+colbr[i],visited))
      dfs(a,r+rowbr[i],c+colbr[i],visited);
  }
}

int count_island(int a[][COL]){
  int count=0;
  int visited[ROW][COL];
  memset(visited,0,sizeof(visited));
  for(int i=0;i<ROW;i++){
    for(int j=0;j<COL;j++){
      if(a[i][j]==1 && visited[i][j]==0)
        {dfs(a,i,j,visited);count++;}
    }
  }
  return count;
}

int main(){
  int a[][COL]= { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };
  cout<<count_island(a);
  return 0;
}
