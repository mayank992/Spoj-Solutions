#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

bool is_palindrome(string str) {
    string rev = str;
    reverse(rev.begin(), rev.end());
    if(str == rev)
        return 1;
    else 
        return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int t;
    cin >> t;
    while(t--) {
        int i, j;
        string result;
        cin >> str;
        if(str.length() & 1) 
            i = j = str.length() / 2;
        else {
            i = str.length()/2-1;
            j = str.length()/2;
        }
        while(i >= 0 && j < str.length()) {
             
            i--;
            j++;
        }
        string res2 = result;
        reverse(res2.begin(), res2.end());
        if (i == j)
            cout << result << res2.substr(1) << "\n";
        else
            cout << result << res2 << "\n";
    }
    return 0;
}
