#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_prod(int *arr, int n) {
    int ans = arr[0];  // Initialize ans with the first element, as this can be the max product.
    for (int i = 0; i < n; i++) {
        int mul = arr[i];

        for (int j = i + 1; j < n; j++) {
            mul *= arr[j];
            ans = max(ans, mul);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << max_prod(arr, n);
    return 0;
}
