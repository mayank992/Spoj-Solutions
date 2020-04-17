#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

void insert(multiset<int> &s, multiset<int> &diff_s, int pos) {
    auto upper = s.upper_bound(pos);
    auto lower = upper;
    lower--;
    int diff = (*upper) - (*lower);
    auto itr = diff_s.find(diff);
    diff_s.erase(itr);
    diff_s.insert(pos - (*lower));
    diff_s.insert((*upper) - pos);
    s.insert(pos);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m, q, type, pos, _max;
        multiset<int> x, y, diff_x, diff_y;
        // n -> no. of rows & m -> no. of columns
        cin >> n >> m >> q;
        diff_x.insert(n);
        diff_y.insert(m);
        x.insert(0);
        x.insert(n);
        y.insert(0);
        y.insert(m);
        while(q--) {
            cin >> type >> pos;
            if(pos > 0) {
                if(type == 0) {
                    if(pos < n) insert(x, diff_x, pos);
                }
                else
                    if(pos < m) insert(y, diff_y, pos);
            }
            ll max_x = *(diff_x.rbegin()), max_y = *(diff_y.rbegin());
            cout << max_x * max_y << "\n";
        }
    }    
    return 0;
}


