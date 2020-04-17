#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define mod1 100000000
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
} 

int _upper_bound(pair<int, int> arr[], int low, int high, int key) {
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(arr[mid].second > key)
            high = mid;
        else 
            low = mid + 1;
    }
    return low;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    do {
        pair<int, int> arr[100000];
        int dp[100000] = {1};
        for(int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }    
        sort(arr, arr+n, cmp);
        for(int i = 1; i < n; i++) {
            int idx = _upper_bound(arr, 0, i-1, arr[i].first);
            if(arr[idx].second > arr[i].first)
                idx --;
            dp[i] = dp[i-1] + 1;
            if(idx != -1)
                dp[i] += dp[idx];
            dp[i] = dp[i] % mod1; 
        }
        cout << setw(8) << setfill('0') << dp[n-1] << "\n";
        cin >> n;
    } while(n != -1);
    return 0;
}
