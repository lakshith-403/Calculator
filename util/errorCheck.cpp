#include <bits/stdc++.h>
#include "errorCheck.h"

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

using namespace std;

bool errorCheck::checkErrors(string line){
    string strReg = "(\\)\\s*[1-9])|((\\*|\\/)\\s*\\))|(\\(\\s*(\\*|\\/))|([1-9]+ \\s*[1-9]+)|([1-9]\\s*\\()|((\\*|\\/)\\s*(\\*|\\/))";
    if(countMatchInRegex(line,strReg) || !checkBrackets(line))
      return true;
    return false;
}

set<char> Set = {'+','/','-','*','(',')',' ','_'};

//also checks the end and unwanted charachters
bool errorCheck::checkBrackets(string line){
  vector<char> l;
  char last='+';
  FORZ(i,line.length()){
    if(line[i]=='(')l.pb('(');
    else if(line[i]==')'){
      if(l.size()==0)return false;
      if(l.at(l.size()-1)=='(')l.pop_back();
      else l.pb(')');
    }
    if(line[i]!=' ')last=line[i];
    if(Set.count(line[i])==0 && !(line[i]>='0'&&line[i]<='9'))return false;
  }
  if(l.size()==0 && ((last>='0'&&last<='9')||last==')'))return true;
  return false;
}

int errorCheck::countMatchInRegex(string s,string re){
    std::regex words_regex(re);
    auto words_begin = std::sregex_iterator(
        s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();
    return std::distance(words_begin, words_end);
}