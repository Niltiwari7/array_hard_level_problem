#include<iostream>
#include<algorithm>
using namespace std;

void merge(int *arr1,int *arr2,int n,int m){
    int left=n-1;
    int right=0;
    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left],arr2[right]);
            left--;right++;
        }
        else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}
int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int j=0;j<m;j++)cin>>b[j];
    merge(a,b,n,m);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    for(int j=0;j<m;j++)cout<<b[j]<<" ";
}