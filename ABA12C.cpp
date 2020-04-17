#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()
// no any boundation of number of packets of apples
// recursive
// int solve(int price[], int k, int n) {
//     if(n == 0) {  
//         if(k == 0)
//             return 0;
//         return INT_MAX;
//     }
//     if(price[n-1] != -1) {
//         if(n < k) {
//             int res1 = solve(price, k-n, n);
//             int res2 = solve(price, k, n-1);
//             return ((res1 == INT_MAX)? res2: min(res1 + price[n-1], res2));
//         }
//         else if(n == k)
//             return min(price[n-1], solve(price, k, n-1));
//     }
//     return solve(price, k, n-1);
// }
//top-down (Memoization) DP
// int dp[101][101];
// int solve(int price[], int k, int n) {
//     if(n == 0) {  
//         if(k == 0)
//             return 0;
//         return INT_MAX;
//     }
//     if(dp[n][k] != -1)
//         return dp[n][k];
//     if(price[n-1] != -1) {
//         if(n <= k) {
//             int res1 = solve(price, k-n, n);
//             int res2 = solve(price, k, n-1);
//             return dp[n][k] = ((res1 == INT_MAX)? res2: min(res1 + price[n-1], res2));
//         }
//     }
//     return dp[n][k] = solve(price, k, n-1);
// }

// with boundation of number of packets picked
//int dp[101][101];
// int solve(int price[], int k, int n, int count) {
//     if(n == 0 || count == 0) {  
//         if(k == 0)
//             return 0;
//         return INT_MAX;
//     }
//     if(dp[n][k] != -1)
//         return dp[n][k];
//     if(price[n-1] != -1) {
//         if(n <= k) {
//             int res1 = solve(price, k-n, n, n-1);
//             int res2 = solve(price, k, n-1, n);
//             return dp[n][k] = ((res1 == INT_MAX)? res2: min(res1 + price[n-1], res2));
//         }
//     }
//     return dp[n][k] = solve(price, k, n-1, n);
// }
//Bottom-up DP
int solve(int price[], int k) {
    int dp[k+1] = {0};
    for(int i = 0; i < k; i++)
        dp[i+1] = price[i];
    for(int i = 2; i <= k; i++) {
        for(int j = 1; j < i; j++) {
            if(price[i-j-1] == -1 || dp[j] == -1)
                continue;
            if(dp[i] == -1)
                dp[i] = dp[j] + price[i-j-1];
            else 
                dp[i] = min(dp[i], dp[j] + price[i-j-1]);
        }
    }
    return dp[k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k, price[100];
        cin >> n >> k;
        for(int i = 0; i < k; i++) {
            cin >> price[i];
        }
        //memset(dp, -1, sizeof(dp));
        int result = solve(price, k);
        cout << result << "\n";
        // if(result == INT_MAX)
        //     cout << -1 << "\n";
        // else 
        //     cout << result << "\n";
    }    
    return 0;
}


