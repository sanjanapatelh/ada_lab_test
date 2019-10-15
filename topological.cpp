#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cout<<"enter number of nodes\n";
  cin>>n;
  int a[n][n],indeg[10],flag[10],count=0;
  cout<<"enter matrix\n";
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
}
for(int i=0;i<n;i++){
      indeg[i]=0;
      flag[i]=0;
  }
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
      indeg[i]+=a[j][i];
  }
}

cout<<"topological order is\n";

while(count<n){
  for(int k=0;k<n;k++){
    if(indeg[k]==0 && flag[k]==0){
      cout<<(k+1)<<" ";
      flag[k]=1;
    }

    for(int i=0;i<n;i++){
      if(a[i][k]==1)
        indeg[k]--;
    }
  }
  count++;
}
return 0;
}
