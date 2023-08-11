#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int reverse_pair(int *arr,int n){
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>2*arr[j])cnt++;
        }
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<reverse_pair(arr,n);
}