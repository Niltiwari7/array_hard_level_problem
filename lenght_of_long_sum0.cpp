#include<bits/stdc++.h>
using namespace std;

int longest_subarray(int *arr, int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        int sum = arr[i];  // Initialize sum with the current element
        for (int j = i + 1; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = longest_subarray(a, n);
    cout << ans;
    return 0;
}
