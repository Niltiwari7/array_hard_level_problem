#include<bits/stdc++.h>
using namespace std;

int ncr(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return (int)(res);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>ans;
    for(int i=1;i<=n;i++){
     vector<int>temp;
        for(int j=1;j<=i;j++){
            temp.push_back(ncr(i-1,j-1));
        }
        ans.push_back(temp);
    }
    for(auto it:ans){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}