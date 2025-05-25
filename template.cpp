#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//==============================================DEFINES=============================================
#define int   long long 
#define M 1000000007 //1e9+7
#define pi 3.1415926535897932384626
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define vi vector<int>
#define input(v) for(int &c:v)cin>>c;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define endl "\n"
#define fastio  cin.tie(0), cout.tie(0),ios_base::sync_with_stdio(false);

// pbds find_by_order, order_of_key
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; 


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


//===============================================Functions=============================================

//Modular subtraction
int modsub(int a,int b,int c){ return ((a%c) - (b%c) + c)%c;}
//Modular Power
int modpow(int x,int n,int c){int result=1;while(n>0) {if(n & 1) result=(result * x)%c ; x=(x*x) % c ; n>>=1;}return result;}   //LCM
int lcm(int a, int b){return (a / __gcd(a, b)) * b;}
//Modular Inverse (x is  inverse of b under modulo m)
int modInverse(int b, int m) {return modpow(b,m-2,m);} //Fermat's little theorem if(M = prime) else extended_gcd 
//MOdular Division
int modDivide(int a, int b, int m){a = a % m;int inv = modInverse(b, m);if (inv == -1)return -1;else return (inv * a) % m;} 

const int N = 1e5+10;
const int INF=1e9+10;
const int LOG = 20;
unordered_map<int,vector<int>>G;
int up[N][LOG];
int depth[N];

vector<int>fact(N, 1), inv(N,1);
void factorize(){
    
    for(int i = 1;i<N;i++){
        fact[i] = (fact[i-1]*i)%M;
    }
    inv[N-1] = modInverse(fact[N-1], M);
    for(int i = N-2;i>=1;i--){
        inv[i] = (inv[i+1]* (i+1) )%M;
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true; 
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

auto dfs = [&](auto&& dfs, int node, int par) -> void{
    up[node][0] = par;
    for (int i = 1; i < LOG; ++i) {
        if (up[node][i - 1] != -1)
            up[node][i] = up[up[node][i - 1]][i - 1];
        else
            up[node][i] = -1;
    }

    for (int it : G[node]) {
        if (it != par) {
            depth[it] = depth[node] + 1;
            dfs(dfs, it, node);
        }
    }
};

auto lift = [&](int u, int k) -> int {
    for (int i = 0; i < LOG; ++i) {
        if (k & (1 << i)) {
            u = up[u][i];
            if (u == -1) break;
        }
    }
    return u;
};

auto lca = [&](int u, int v) -> int {
    if (depth[u] < depth[v]) swap(u, v);
    u = lift(u, depth[u] - depth[v]);
    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != -1 && up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
};


//===================================================Code Here=========================================


void sol(){   


    
}

 

//===================================================Main==============================================
signed main() {
  
     fastio;
    int T=1;
    cin>>T;
   
    while(T--)
     sol();

}
