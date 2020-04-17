#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1) {
        int n1, n2, arr[10000], brr[10000], cum_sum1[10000] = {0}, cum_sum2[10000] = {0};
        cin >> n1;   if(n1 == 0)  break;
        for(int i = 0; i < n1; i++) {
            cin >> arr[i];
            if(i == 0)   cum_sum1[i] = arr[i];
            else    cum_sum1[i] = cum_sum1[i-1] + arr[i];
        }
        cin >> n2;
        for(int i = 0; i < n2; i++) {
            cin >> brr[i];
            if(i == 0)   cum_sum2[i] = brr[i];
            else    cum_sum2[i] = cum_sum2[i-1] + brr[i];
        }
        int idx1 = -1, idx2 = -1, result = 0;
        for(int i = 0; i < n1; i++) {
            int idx = lower_bound(brr, brr + n2, arr[i]) - brr;
            if(brr[idx] != arr[i])
                continue;
            int a = cum_sum1[i] - ((idx1 == -1)? 0: cum_sum1[idx1]);
            int b = cum_sum2[idx] - ((idx2 == -1)? 0: cum_sum2[idx2]);
            if(a > b)
                result += a;
            else 
                result += b;
            idx1 = i;
            idx2 = idx;
        }
        result += max(cum_sum1[n1-1] - ((idx1 == -1)? 0: cum_sum1[idx1]), cum_sum2[n2-1] - ((idx2 == -1)? 0: cum_sum2[idx2]));
        cout << result << "\n";
    }
    return 0;
}


