#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int dp[6101][6101];

int lcs(string &str, string &rev) {
    int n = str.length();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(str[i-1] == rev[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string str, rev;
        cin >> str;
        rev = str;
        memset(dp, 0, sizeof(dp));
        reverse(rev.begin(), rev.end());
        cout << str.length() - lcs(str, rev) << "\n";
    }
    return 0;
}


