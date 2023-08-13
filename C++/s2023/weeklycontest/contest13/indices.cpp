#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #include <bits/stdc++.h>
    #define TASK "indices"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define b_mask(POS) (1ULL << (POS))
#define b_get(MASK, POS) ((MASK >> (POS)) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
const int N = 1e6;
const ull MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;
// directions = left, up, right, down, upper_l, upper_r, lower_r, lower_l
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
template<typename tVar, typename tVal>
void mnmz(tVar &var, tVal val) { if (val < var) var = val; }
template<typename tVar, typename tVal>
void mxmz(tVar &var, tVal val) { if (val > var) var = val; }

// indeces
// <tags>

////////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    };
    cin.tie(0) -> sync_with_stdio(0);
    ////////////////
    int n;
    cin >> n;
    vector<int> a(n);
    
    int mx = 0;
    unordered_map<int, ll> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        mxmz(mx, a[i]);
    } 
    
    vector<ll> mul(mx + 1);
    for (int i = 1; i <= mx; i++) {
        for (int j = i; j <= mx; j += i) {
            mul[i] += cnt[j];
        }
    }
    
    vector<ll> dp(mx + 1);
    for (int i = mx; i >= 1; i--) {
        dp[i] = mul[i] * (mul[i] - 1) / 2;
        for (int j = i * 2; j <= mx; j += i) {
            dp[i] -= dp[j];
        }
    }
    
    cout << dp[1];
    ////////////////
    return 0;
}