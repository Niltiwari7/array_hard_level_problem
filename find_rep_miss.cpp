#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int find_rep(int *arr,int n){
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1])
            return arr[i];
      }
}

int find_miss(int *arr,int n){
    set<int>st;
    int sum=0;
    for(int i=0;i<n;i++)st.insert(arr[i]);
    for(auto it:st)sum+=it;
    int ans=n*(n+1)/2-sum;
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<find_rep(arr,n)<<endl;
    cout<<find_miss(arr,n)<<endl;
}