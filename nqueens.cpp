#include<bits/stdc++.h>
using namespace std;
 bool place(int k,int i,int x[]){
   for(int j=1;j<k;j++){
     if((x[j]==i) || abs(x[j]-i)==abs(j-k) )
      return false;
   }
   return true;
 }

void nqueens(int k,int n,int x[]){
  for(int i=1;i<=n;i++){
    if(place(k,i,x)){
      x[k]=i;
      if(k==n){
        for(int j=1;j<=n;j++)
          cout<<x[j]<<"\t";
        cout<<"\n";
        int xt=1;
        for(int j=1;j<=n;j++)
        {
          for(int l=1;l<=n;l++)
          {
            if(x[xt]==l)
             cout<<"1\t";
            else
              cout<<"0\t";
          }
          cout<<"\n";
        }
        cout<<"\n";
      }
      else
        nqueens(k+1,n,x);
    }

  }
}

int main(){
  cout<<"enter n\n";
  int n;
  cin>>n;
  int x[n+1];
  nqueens(1,n,x);
}
