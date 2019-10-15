#include<bits/stdc++.h>
using namespace std;
void dfs(int v,int visited[],vector<vector<int>> adj,int n){
  cout<<v<<"\t";
  visited[v]=1;
  for(int i=0;i<n;i++){
    if(adj[v][i]==1 && visited[i]==0)
      dfs(i,visited,adj,n);
  }
}

int main(){
  cout<<"enter number of node\n";
  int n;cin>>n;
  vector<vector< int>> adj;
  cout<<"enter maze\n";
  for(int i=0;i<n;i++)
  {
    vector<int> temp;
    for(int j=0;j<n;j++)
    {
     int x;
     cin>>x;
     temp.push_back(x);
    }
    adj.push_back(temp);
  }
  int visited[n];
  for(int i=0;i<n;i++)
    visited[i]=0;
  for(int i=0;i<n;i++){
    if(visited[i]==0)
      {dfs(i,visited,adj,n);cout<<"\n";}
  }
  return 0;

}
