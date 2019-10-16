#include<bits/stdc++.h>
using namespace std;

#define N 4
#define M 4

class qitem{
public:
  int row,col,dist;
  qitem(int x,int y,int w)
  :row(x),col(y),dist(w)
  {}
};

int mindistance(char a[N][M]){
bool sol[N][M];
qitem source(0,0,0);

for(int i=0;i<N;i++){
  for(int j=0;j<M;j++){
    if(a[i][j]=='0')
      sol[i][j]=true;
    else
      sol[i][j]=false;
    if(a[i][j]=='s'){
      source.row=i;
      source.col=j;
    }
  }
}


queue<qitem> q;
q.push(source);
while(!q.empty()){
  qitem p=q.front();
  q.pop();

  if(a[p.row][p.col]=='d')
    return p.dist;


  if(p.row-1>=0 && sol[p.row-1][p.col]==false )
  {
    q.push(qitem(p.row-1,p.col,p.dist+1));
    sol[p.row-1][p.col]=true;
  }

  if(p.row+1<N && sol[p.row+1][p.col]==false )
  {
    q.push(qitem(p.row+1,p.col,p.dist+1));
    sol[p.row+1][p.col]=true;
  }

  if(p.col-1>=0 && sol[p.row][p.col-1]==false )
  {
    q.push(qitem(p.row,p.col-1,p.dist+1));
    sol[p.row][p.col-1]=true;
  }
  if(p.col+1<M && sol[p.row][p.col+1]==false )
  {
    q.push(qitem(p.row,p.col+1,p.dist+1));
    sol[p.row][p.col-1]=true;
  }


}
return -1;

}

int main(){

  char grid[N][M] = { { '0', '*', '0', 's' },
            { '*', '0', '*', '*' },
            { '0', '*', '*', '*' },
            { 'd', '*', '*', '*' } };
  cout<<mindistance(grid);
  return 0;

}
