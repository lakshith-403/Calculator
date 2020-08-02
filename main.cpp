#include <bits/stdc++.h>
#include "arts/arts.h"
#include "solvers/solver.h"
#include "util/errorCheck.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<db,db> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORi(i,a,b) for(int i=(a);i>=(b);i--)
#define FORZ(i,a) for(int i=0;i<(a);i++)
#define FORZi(i,a) for(int i=(a)-1;i>=0;i--)
#define trav(a,x) for (auto& a: x)
#define what_is(x) cout << #x << " is " << x << "\n";

#define printl(a) cout << a << "\n";
#define prints(a) cout << a << " ";
#define printall(x) FORZ(i,sz(x))prints(x[i])
#define nextl cout << "\n"

#define in(a) cin >> a;

int main(){
    printl(arts::header);
    string line;
    while(true){
        prints(">>>");
        getline(cin,line);
        if(line=="exit")break;
        printl("");
        if(errorCheck::checkErrors(line)){printl("Syntax Error");continue;}
        solver::solveBrackets(line);
    }
    printl(arts::footer);
    printl("Thank you for using my shitty calculator :) \n\n \t\t\t~LaKsHiTh <3");
}