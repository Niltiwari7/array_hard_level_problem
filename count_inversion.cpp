#include<iostream>
#include<vector>
using namespace std;

int merge(int *arr,int l,int mid,int hi){
     vector<int>temp;
     int cnt=0;
     int left=l;
     int right=mid+1;
     
     while(left<=mid && right<=hi){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
     }
     while(left<=mid){
        temp.push_back(arr[left]);
        left++;
     }
     while(right<=hi){
        temp.push_back(arr[right]);
        right++;
     }
     for(int i=l;i<=hi;i++){
        arr[i]=temp[i-l];
     }
     return cnt;
}

int merge(int *arr,int l,int hi){
    int cnt=0;
    if(l>=hi)return cnt;
    int mid=(l+hi)/2;
    cnt+=merge(arr,l,mid);
    cnt+=merge(arr,mid+1,hi);
    cnt+=merge(arr,l,mid,hi);
    return cnt;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
   cout<< merge(arr,0,n-1);
}