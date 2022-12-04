#if localdb
    #include "include/debug.h"
    #define TASK "test"
#else
    #pragma GCC optimize("Ofast,unroll-loops,inline")
    #pragma GCC target("sse4")
    #include <bits/stdc++.h>
    #define db(...)
    #define TASK "discovery"
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define str string
#define nl '\n'
#define sp ' '
#define mask(BI) (1LL << (BI))
#define bitcnt(BM) __builtin_popcountll(BM)
#define getbit(BM, BI) ((BM >> BI) & 1)
#define all(A) (A).begin(), (A).end()
#define point(N) fixed << showpoint << setprecision(N)
const int MAXN = 1e6;
const ull MOD = 1e9 + 7;

// https://oj.vnoi.info/problem/chvpt_discovery
// graph

// struct pair_hash {
//     template <class T1, class T2>
//     size_t operator() (const pair<T1, T2> &pair) const {
//         return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
//     };
// };
map<pii, set<pii>> mp;
char dir[4] = {'E', 'W', 'N', 'S'};
char rev[4] = {'W', 'E', 'S', 'N'};
map<pii, pii> par;
///////////////////////////////////////
pii go(pii s, char a) {
    if (a == 'E') {
        s.se++;
    };
    if (a == 'W') {
        s.se--;
    };
    if (a == 'N') {
        s.fi++;
    };
    if (a == 'S') {
        s.fi--;
    };
    return s;
};

str res;
void trace(pii s) {
    if (par[s] == s) {
        return;
    };
    for (auto &it : dir) {
        if (par[s] == go(s, it)) {
            res += it;
            break;
        };
    };
    
    trace(par[s]);
};
///////////////////////////////////////
void bfs(pii s, pii e) {
    deque<pii> q = {s};
    par[s] = s;
    
    while (q.size()) {
        pii cur = q.back();
        q.pop_back();
        
        if (cur == e) {
            trace(e);
            return;
        };
        
        for (auto &it : mp[cur]) {
            if (!par.count(it)) {
                q.push_front(it);
                par[it] = cur;
            };
        };
    };
};
///////////////////////////////////////
int main() {
    if (fopen(TASK".inp", "r")) freopen(TASK".inp", "r", stdin);
    if (fopen(TASK".out", "r")) freopen(TASK".out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    /////////////////
    str a;
    cin >> a;
    
    // a = "";
    // for (int i = 0; i < MAXN; i++) {
    //     a += 'W';
    // };
    // for (auto &it : dir) {
    //     for (int i = 0; i < MAXN / 4; i++) {
    //         a += it;
    //     };
    // };
    
    pii cur = {0, 0}, nxt, tmp;
    for (auto &it : a) {
        nxt = go(cur, it);
        mp[cur].insert(nxt);
        mp[nxt].insert(cur);
        cur = nxt;
    };
    
    // for (auto &it : mp) {
    //     for (auto &jt : it.se) {
    //         cout << it.fi << sp << jt << nl;
    //     };
    //     cout << nl;
    // };
    
    bfs({0, 0}, cur);
    
    cout << res;
    /////////////////
    return 0;
};
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