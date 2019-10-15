#include<bits/stdc++.h>
using namespace std;
void print(int a[],int size){
  for(int i=0;i<size;i++)
    cout<<a[i]<<"\t";
  cout<<"\n";
}

void subset(int s[],int t[],int s_size,int t_size,int sum,int ite,int const target_sum){
    if(target_sum==sum){
      print(t,t_size);
      subset(s,t,s_size,t_size-1,sum-s[ite],ite+1,target_sum);
      return;
    }
    else{
      for(int i=ite;i<s_size;i++){
        t[t_size]=s[i];
        subset(s,t,s_size,t_size+1,sum+s[i],i+1,target_sum);
      }
    }
}

void generateSubsets(int s[],int size,int target_sum){
  int *t=(int*)malloc(size*sizeof(int));
  subset(s,t,size,0,0,0,target_sum);
  free(t);
}
int main(){
  cout<<"enter size\n";
  int n;
  cin>>n;
  int a[n];
  cout<<"elements\n";
  for(int i=0;i<n;i++)
   cin>>a[i];
  cout<<"enter sum\n";
  int sum;
  cin>>sum;
  generateSubsets(a,n,sum);
  return 0;
}
