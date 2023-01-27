#if DEBUG
    #include "lib/include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("O3,unroll-loops,inline")
    #pragma GCC target("avx2")
    #include <bits/stdc++.h>
    #define db(...)
    #define TASK "lehoi"
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
#define mask(POS) (1ULL << (POS))
#define bitcnt(MASK) __builtin_popcountull(MASK)
#define getbit(MASK, POS) ((MASK >> POS) & 1)
#define all(VAR) (VAR).begin(), (VAR).end()
#define point(CNT) fixed << showpoint << setprecision(CNT)
const int MAXN = 1e6;
const ull MOD = 1e9 + 7;

// https://oj.vnoi.info/problem/chvpt_dtqg_lehoi
// <tags>

int n;
vector<int> a, b;
// vector<int> res;
///////////////////////////////////////
namespace sub1 {
    int mn = INFINITY;
    
    void solve(int i, int j, int mx, int prev) {
        if (i > n && j > n) {
            mn = min(mn, mx);
            // db(res, mx);
            return;
        };
        
        if (i <= n) {
            // res.push_back(a[i]);
            solve(i + 1, j, max(mx, abs(a[i] - prev)), a[i]);
            // res.pop_back();
        };
        if (j <= n) {
            // res.push_back(b[j]);
            solve(i, j + 1, max(mx, abs(b[j] - prev)), b[j]);
            // res.pop_back();
        };
    }
    
    int main() {
        // res.push_back(a[1]);
        solve(2, 1, 0, a[1]);
        // res.pop_back();
        
        // res.push_back(b[1]);
        solve(1, 2, 0, b[1]);
        // res.pop_back();
        
        cout << mn;
        /////////////////
        return 0;
    }
}

namespace sub2 {
    int main() {
        vector<int> res;
        int i = 1, j = 1;
        while (i <= n && j <= n) {
            if (a[i] < b[j]) {
                res.push_back(a[i]);
                i++;
            } else {
                res.push_back(b[j]);
                j++;
            };
        };
        for (; i <= n; i++) res.push_back(a[i]);
        for (; j <= n; j++) res.push_back(b[j]);
        
        int mx = 0;
        for (int i = 1; i < n * 2; i++) {
            mx = max(mx, abs(res[i] - res[i - 1]));
        };
        
        cout << mx;
        /////////////////
        return 0;
    }
}
///////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) freopen(TASK".inp", "r", stdin);
    if (fopen(TASK".out", "r")) freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    /////////////////
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    if (n <= 10) {
        sub1::main();
    } else {
        sub2::main();
    }
    
    /////////////////
    return 0;
}
/*
000000000000000000000000000000000000000000011111111100000000000000000000000000000000000000
0000000000000000000000000000000000001111.............1111111000000000000000000000000000000
00000000000000000000000000000000011.. .....11111111.........111000000000000000000000000000
000000000000000000000000000000011.  .1111111111111111111111.. .110000000000000000000000000
0000000000000000000000000000001. ..111111111111111111111111111. .1100000000000000000000000
000000000000000000000000000001. .111111111111111111111111111111. .110000000000000000000000
00000000000000000000000000001. .111111.............11111111111111. .1000000000000000000000
00000000000000000000000000001  111.   ..............   ...11111111. .100000000000000000000
0000000000000000000000000001. .11.  ..11111111111111111..  .1111111. .10000000000000000000
0000000000000000000000000001  111. ..11111111111111111111.  .1111111. .1000000000000000000
000000000000000000000000001. .111.  ..1111111111111111111.. .11111111. .100000000000000000
000000000000000000000000001. 11111.   ...11111111111111...  .11111111. .100000000000000000
000000000000000000000000011 .1111111..   ..............   .11111111111. 110000000000000000
00000000000000000000000001. .1111111111.................11111111111111. .10000000000000000
00000000000000000000000001 .1111111111111111111111111111111111111111111  10000000000000000
0000000000000000000000001. .1111111111111111111111111111111111111111111. .1000000000000000
0000000000000000000000001. 11111111111111111111111111111111111111111111. .1000000000000000
000000000000000000000001. .11111111111111111111111111111111111111111111. .1000000000000000
000000000000000000000001. .111111111111111111111111111111111111111111111 .1000000000000000
000000000000000000000011 .1111111111111111111111111111111111111111111111 .1000000000000000
00000000000000000000001. .1111111111111111111111111111111111111111111111. 1000000000000000
00000000000000000000001. 11111111111111111111111111111111111111111111111. 1000000000000000
0000000000000000000001. .11111111111111111111111111111111111111111111111. 1100000000000000
0000000000000000000001. .11111111111111111111111111111111111111111111111. 1100000000000000
0000000000000000000011 .111111111111111111111111111111111111111111111111. 1100000000000000
000000000000000000001. .111111111111111111111111111111111111111111111111. 1100000000000000
000000000000000000001 .1111111111111111111111111111111111111111111111111  1000000000000000
00000000000000000001. .1111111111111111111111111111111111111111111111111 .1000000000000000
00000000000000000001. 11111111111111111111.........11111111111111111111. .1000000000000000
0000000000000000001. .111111111111................... .1111111111111111. .1000000000000000
0000000000000000001. .111111111....111111111111111111. .111111111111111. .1000000000000000
0000000000000000011 .111111111. .100000000000000000001  111111111111111. .1000000000000000
000000111111111111. .111111111. .100000000000000000001  111111111111111. .1000000000000000
00111...............11111111111 .100000000000000000001 .111111111111111. .1000000000000000
001. ..111111111111111111111111. 110000000000000000001  111111111111111. .1000000000000000
001. 11111111111111111111111111. .10000000000000000001  111111111111111. .1000000000000000
001. .1111111111111111111111111. .10000000000000000001 .111111111111111. .1000000000000000
00011. ..11111111111111111111..  .1000000000111111111. .111111111111111 .10000000000000000
0000011.. ................. ...11100000111........... ..11111111111111. .10000000000000000
0000000111111...........111111000000011. ...11111111111111111111111111  110000000000000000
00000000000000000000000000000000000001. .111111111111111111111111111.  .100000000000000000
000000000000000000000000000000000000011. .11111111111111111111111.. ..11000000000000000000
00000000000000000000000000000000000000111.. ......111111111.... ...11000000000000000000000
00000000000000000000000000000000000000000111111...............1111000000000000000000000000
000000000000000000000000000000000000000000000000011111111111100000000000000000000000000000
*/