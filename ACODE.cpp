#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int dp[5000] = {0};
//recursive
// ll solve(string str) {
//     if(str.length() < 1)
//         return 1;
//     if(str.length() == 1) {
//         if(str[0] != '0')
//             return 1;
//         return 0;
//     }
//     ll count = 0;
//     if(str[0] != '0')
//         count += solve(str.substr(1));
//     int num = stoi(str.substr(0, 2));
//     if(num >= 1 && num <= 26)
//         count += solve(str.substr(2));
//     return count;
// }

// top-down(memization)
ll solve(string str, int idx) {
    if(idx == str.length())
        return 1;
    if(dp[idx] != -1)
        return dp[idx];
    int count = 0;
    if(str[idx] != '0')
        count += solve(str, idx+1);
    if(idx < str.length()-1) {
        int num = stoi(str.substr(idx, 2));
        if(num > 9 && num <= 26)
            count += solve(str, idx+2);
    }
    return dp[idx] = count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    while(1) {
        cin >> str;
        if(str[0] == '0')
            break;
        memset(dp, -1, sizeof(dp));
        cout << solve(str, 0) << "\n";
    }
    return 0;
}


