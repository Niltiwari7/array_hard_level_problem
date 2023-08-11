#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge_overlapping(vector<vector<int>>& v, int n, int m) {
    vector<vector<int>> ans;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        int start = v[i][0];
        int end = v[i][1];
        
        // Skips all the intervals that are completely contained within the current interval
        while (i + 1 < n && v[i + 1][0] <= end) {
            end = max(end, v[i + 1][1]);
            i++;
        }
        
        ans.push_back({start, end});
    }
    
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    merge_overlapping(v, n, m);
    return 0;
}
