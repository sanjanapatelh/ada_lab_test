#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> a){
  for(int i=0;i<a.size();i++)
  {
    for(int j=0;j<a[i].size();j++)
      cout<<a[i][j]<<"\t";
    cout<<"\n";
  }
}
bool isSafe(vector<vector<int>> maze,int x,int y,int n){
  if(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1)
    return true;
  return false;
}

bool solveMaze(vector<vector<int>> maze,int x,int y,int n,vector<vector<int>> &sol)
{
  if(x==n-1 && y==n-1){
    sol[x][y]=1;
    return true;
  }
  if(isSafe(maze,x,y,n)==true){
    sol[x][y]=1;
    if(solveMaze(maze,(x+1),y,n,sol)==true)
     return true;
   if(solveMaze(maze,x,(y+1),n,sol)==true)
      return true;
    sol[x][y]=0;
    return false;
  }
  return false;
}

bool solve(vector<vector<int>> maze,int n){
  vector<vector<int>> sol;
  for(int i=0;i<n;i++)
  {
    vector<int> temp;
    for(int j=0;j<n;j++)
      temp.push_back(0);
    sol.push_back(temp);
  }
  if(solveMaze(maze,0,0,n,sol)==false)
      {  cout<<"doesnot exit\n";return false;}
  else
  print(sol);
  return true;
}


int main(){
  cout<<"enter size of maze\n";
  int n;
  cin>>n;
  vector<vector< int>> maze;
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
    maze.push_back(temp);
    //print(maze);
  }
 solve(maze,n);

  return 0;
}
