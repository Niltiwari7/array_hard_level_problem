#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &i:v)cin>>i;
    unordered_map<int,int>mp;
    for(auto it:v)mp[it]++;
    for(auto it:mp){
        if(it.second>n/3){
            cout<<it.first<<" ";
            return 0;
        }
    }
}