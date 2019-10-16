#include<bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<int>> adj,vector<vector<bool>> visited,int r,int c,int x,int y)
{
  if(r>=0 && r<x &&c>=0 && c<y && adj[r][c]==1 && visited[r][c]==false)
    return true;
  return false;
}

void dfs(vector<vector<int>> adj,vector<vector<bool>> &visited,int r,int c,int x,int y){
  int static rowbr[]={-1,-1,-1,0,0,1,1,1};
  int static colbr[]={-1,0,1,-1,1,-1,0,1};
  visited[r][c]=true;
  for(int i=0;i<8;i++){
      if(issafe(adj,visited,r+rowbr[i],c+colbr[i],x,y))
        dfs(adj,visited,r+rowbr[i],c+colbr[i],x,y);
    }

}

int main(){
  cout<<"enter col and row\n";
  int x,y;
  cin>>x>>y;
  cout<<"enter matrix\n";
  vector<vector<int>>adj;
  for(int i=0;i<x;i++){
    vector<int>temp;
    for(int j=0;j<y;j++){
      int ele;
      cin>>ele;
      temp.push_back(ele);
    }
    adj.push_back(temp);
  }

vector<vector<bool>> visited;
for(int i=0;i<x;i++){
  vector<bool>temp;
  for(int j=0;j<y;j++){
    temp.push_back(false);
  }
  visited.push_back(temp);
}
  int count=0;
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
      if(adj[i][j]==1 && visited[i][j]==false)
      {
        dfs(adj,visited,i,j,x,y);count++;
      }
    }
  }
  cout<<count;
  return 0;
}
