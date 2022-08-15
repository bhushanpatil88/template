#include <bits/stdc++.h>
using namespace std;
//==============================================DEFINES=============================================
#define int   long long 
#define M 1000000007 //1e9+7
#define pi 3.1415926535897932384626
#define ff first
#define ss second
#define vi vector<int>
#define input(v) for(int &c:v)cin>>c;
#define vpi vector<pair<int,int>>
#define inputvpi(v)  for (int i = 0; i < n; i++){int x,y; cin>>x>>y; v.push_back({x,y}); }
#define all(v) v.begin(),v.end()
#define endl "\n"
#define fastio  cin.tie(0), cout.tie(0),ios_base::sync_with_stdio(false);
#define debug(...) __f(#__VA_ARGS__,__VA__ARGS)
//===============================================Functions=============================================

template <typename Arg1>
void __f(const char* name,Arg1&& arg1){cout<<name<<" : "<<arg1<<endl;}
template <typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args)
{
  const char* comma = strchr(names+1,',');
  cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}



//Modular subtraction
  int modsub(int a,int b,int c)
   { return ((a%c) - (b%c) + c)%c;}
 
 
 //Modular Power
  int modpow(int x,int n,int c)
  {
    int result=1;
    while(n>0) {if(n & 1) result=(result * x)%c ; x=(x*x) % c ; n>>=1;}
 
    return result;
  }


   //LCM
  int lcm(int a, int b)
  {
    return (a / __gcd(a, b)) * b;
  }


 //Modular Inverse (x is  inverse of b under modulo m)
 int modInverse(int b, int m) 
 { 
     return modpow(b,m-2,m); //Fermat's little theorem if(M = prime) else extended_gcd
 } 
  
  
 //MOdular Division
 int modDivide(int a, int b, int m) 
 { 
     a = a % m; 
     int inv = modInverse(b, m); 
     if (inv == -1) 
        return -1; 
     else
        return (inv * a) % m; 
 } 

const int N = 1e5+10;
const int INF=1e9+10;


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


