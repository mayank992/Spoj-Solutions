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
    int arr[1000000], brr[1000000], crr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> crr[i];
    }
    int size_a = 0, size_b = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                arr[size_a++] = (crr[i] * crr[j]) + crr[k];
                if(crr[i] != 0)
                    brr[size_b++] = crr[i] * (crr[j] + crr[k]);
            }
        }
    }
    sort(arr, arr+size_a);
    sort(brr, brr+size_b);
    int result = 0;
    for(int i = 0; i < size_a; i++) {
        result += (upper_bound(brr, brr+size_b, arr[i]) - brr) - (lower_bound(brr, brr+size_b, arr[i]) - brr);
    }
    cout << result;
    return 0;
}


