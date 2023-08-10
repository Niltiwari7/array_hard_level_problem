#include<bits/stdc++.h>
using namespace std;

int cnt_xor_k(int *arr,int n,int k){
    int cnt=0;
    for(int i=0;i<n;i++){
        int res=0;
        for(int j=i;j<n;j++){
            res^=arr[j];
            if(res==k)cnt++;
        }
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<cnt_xor_k(arr,n,k);

}