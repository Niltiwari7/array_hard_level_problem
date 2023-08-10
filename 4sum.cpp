#include <bits/stdc++.h>
using namespace std;
// //using 4 loop
// vector<vector<int>> quad(int *arr, int n) {
//     set<vector<int>> st;
//     for (int i = 0; i < n - 3; i++) {
//         for (int j = i + 1; j < n - 2; j++) {
//             for (int k = j + 1; k < n - 1; k++) {
//                 for (int l = k + 1; l < n; l++) {
//                     if (arr[i] + arr[j] + arr[k] + arr[l] == 0) {
//                         vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

//using 3 loop and set data structure


vector<vector<int>> quad(int *arr, int n) {
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<int> hashset;
            for (int k = j + 1; k < n ; k++) {  // Change 'j' to 'k'
                int fourth = -(arr[i] + arr[j] + arr[k]);
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> ans = quad(arr, n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
