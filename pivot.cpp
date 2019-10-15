#include<bits/stdc++.h>
using namespace std;

int pivot(int a[],int low,int high){
  if(high<low)
    return -1;
  if(low==high)
    return low;
  int mid=(low+high)/2;
  if(mid<high && a[mid]>a[mid+1])
    return mid;
  if(mid>low && a[mid]<a[mid-1])
    return mid-1;
  if(a[low]>=a[mid])
    return pivot(a,low,mid-1);
  return pivot(a,mid+1,high);
}

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
int main(){
  int a[]={5,6,7,8,9,10,1,3};
  int k=10;
  int x=pivot(a,0,7);
  cout<<x<<"\n";
  int r=binarySearch(a,0,x,k);
  if( r==-1)
    r=binarySearch(a,x+1,7,k);
  cout<<r;
  return 0;
}
