#include<bits/stdc++.h>
using namespace std;
int binarySearch(int a[],int low,int high,int k){
  if(low>high)
    return -1;
  int  mid=(low+high)/2;
  if(a[mid]==k)
    return mid;
  else if(k>a[mid]){
    return binarySearch(a,mid+1,high,k);
  }
  else{
    return binarySearch(a,low,mid-1,k);
  }

}

void find(int a[],int first,int last,int count,int k,int n){
  int x=binarySearch(a,0,n-1,k);

  if (x!=-1){
    int i=x;
    while (a[i]==k){
      count++;
      i--;
    }
    first=i+1;
    i=x;
    while (a[i+1]==k){
      count++;
      i++;
    }
    last=i;
  }
  cout<<first<<" "<<last<<" "<<count<<"\n";


}

int main(){
  cout<<"enter th number of elements in array\n";
  int n;
  cin>>n;
  int a[n];
  cout<<"elements\n";
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int k;
  cout<<"enter element\n";
  cin>>k;
  int first=-1,last=-1,count=0;
  find(a,first,last,count,k,n);
  return 0;
}
