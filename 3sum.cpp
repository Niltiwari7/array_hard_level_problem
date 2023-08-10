#include <bits/stdc++.h>
using namespace std;


//brute force
// vector<vector<int>> triplet(vector<int> &arr, int n) {
//     set<vector<int>> st;
//     for (int i = 0; i < n - 2; i++) {  // Change loop condition to 'n - 2'
//         for (int j = i + 1; j < n - 1; j++) {  // Change loop condition to 'n - 1'
//             for (int k = j + 1; k < n; k++) {
//                 if (arr[i] + arr[j] + arr[k] == 0) {
//                     vector<int> temp = {arr[i], arr[j], arr[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// better approach
// vector<vector<int>>triplet(vector<int>&arr,int n){
//     set<vector<int>>st;
//     for(int i=0;i<n-2;i++){
//         set<int>hashset;
//         for(int j=i+1;j<n-1;j++){
//             if(hashset.find(-(arr[i]+arr[j]))!=hashset.end()){
//                 vector<int>temp={arr[i],arr[j],-(arr[i]+arr[j])};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(arr[j]);
//         }
//     }
//      vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// optimal approach

vector<vector<int>>triplet(vector<int>&arr,int n){
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i!=0 && arr[i]==arr[i-1])continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum<0) j++;
            else if(sum>0)k--;
            else{
                vector<int>temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicate
                while(j<k && arr[j]==arr[j-1])j++;
                while(j<k && arr[k]==arr[k-1])k++;
            }
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> ans = triplet(arr, n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
