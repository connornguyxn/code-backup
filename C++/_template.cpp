// #pragma GCC optimize("trapv") // abort() on integer overflow
                                // increase runtime by ~10%(?)
// note: include headers *after* compile options
#ifdef local_debug // if local debug flag is set
#include "include/debugging.h" // include local debugging header
#define init_ifs() ifstream cin("_input.inp")
#define init_ofs() ofstream cout("_output.out")
#else // if not on local machine
// GCC optimization flags
// #pragma GCC optimize("O3,unroll-loops,inline")
// SIMD optimization
// #pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4,sse4.1,sse4.2")
#include <bits/stdc++.h> // include everything
// undefine debug functions
#define init_ifs()
#define init_ofs()
#define vdb(...)
#define db(...)
#endif // end
using namespace std; // use standard namespace for faster access
// aliases
#define ll long long // -(2^63) to (2^63)-1 (approx -1e18 to 1e18)
#define ull unsigned long long // 0 to approx 1e19
#define ld long double // approx -1e308 to 1e308
#define str string // python :D
#define nl '\n' // saving time by not flushing buffer
#define sp ' ' // writing this is faster
#define all(a) a.begin(), a.end() // iterator macro
// macro for functions
// set decimal precision
#define dec_point(n) fixed << showpoint << setprecision(n)
// dynamic container optimization, eg: map, vector
#define mp_optimize(mp) mp.reserve(4096); mp.max_load_factor(0.1);
#define for_in(i, a) for (auto& i : a) // python :D
const int LIM = 1e6; // array limit
const ull MOD = 1e9 + 7; // common modular

// <problem link>
// <tags>

///////////////////////////////////////
int main() {
    // file stream objects
    init_ifs();
    // i/o optimization
    // ios_base::sync_with_stdio(false); // desyncronize standard c and c++ streams
    // cin.tie(nullptr); // turn off automatic output flushing
    cin.tie(0) -> sync_with_stdio(0); // new and shorter version
    /////////////////
    // // test case handler
    // int tc = 1;
    // //cin >> tc;
    // while (tc--) {
    //     // code goes here
        
        
    //     /////////////////
    //     cout << nl;
    // };
    /////////////////
    return 0; // for good measure :)
};
// nice
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