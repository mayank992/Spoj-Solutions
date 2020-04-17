#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int 
#define mod 1000000007
#define pb push_back
#define pop pop_back
#define mp make_pair
#define ALL(v)  v.begin(), v.end()

int search(int arr[], int low, int high, int key) {
    int idx = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) {
            idx = mid;
            //high = mid-1; // for first occurance
            low = mid + 1; // for last occurance
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, arr[100000];
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    while(q--) {
        cin >> key;
        cout << search(arr, 0, n-1, key) << "\n";
    }
    return 0;
}


