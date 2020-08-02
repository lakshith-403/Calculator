#include "solver.h"

#include <bits/stdc++.h>

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

set<char> solver::Set = {'+','/','-','*','(',')',' ','_'};

std::string solver::simpleSolve(string line,char O){
  string cur = "";
  vector<string> vec;
  vector<int> op;
  vector<int> OP;
  int prev = 0;
  FORZ(i,line.length()){
    if(line[i]==' ')continue;
    if((line[i]<='9'&&line[i]>='0')||line[i]=='_'){
      cur+=line[i];
    }else{
      vec.pb(cur);
      cur="";
      op.pb(i);
      if(line[i]==O)OP.pb(op.size()-1);
    }
  }
  if(OP.size()==0)return (line);
  if(OP.at(0)==0)prev=0;
  else prev = op.at(OP.at(0)-1)+1;
   int ans;
  int num1,num2;
  string s1,s2;
  s1 = line.substr(prev,op.at(OP.at(0))-prev);
  if(s1[0]=='_'){
    num1 = stoi(s1.substr(1,s1.length()-1));
    num1 *= -1;
  }else num1 = stoi(s1);

  s2 = line.substr(op.at(OP.at(0))+1,(op.size()>OP.at(0)+1?op.at(OP.at(0)+1):line.length())-OP.at(0)+1);
  if(s2[0]=='_'){
    num2 = stoi(s2.substr(1,s2.length()-1));
    num2 *= -1;
  }else num2 = stoi(s2);

  if(O=='*')
  ans = num1*num2;
  else if(O=='/')
  ans =num1/num2;
  else if(O=='+')
  ans = num1+num2;
  else
  ans = num1-num2;
  string S = to_string(ans);
  if(ans<0){
    S = to_string(ans*-1);
    S = "_"+S;
  }
  line.replace(prev,(op.size()>OP.at(0)+1?op.at(OP.at(0)+1):line.length())-prev,S);
  return simpleSolve(line,O);
}

void solver::solveBrackets(string line){
  vector<char> l;
  vector<string> strList = {""};
  vector<int> pos;
  string cur="";
  FORZ(i,line.length()){
    if(line[i]=='('){
      l.pb('(');
      strList.pb("");
      pos.pb(i);
    }
    else if(line[i]==')'){
      if(l.at(l.size()-1)=='(')l.pop_back();
      else l.pb(')');
      string ans;
      ans = simpleSolve(strList.at(strList.size()-1),'*');
      ans = simpleSolve(ans,'/');
      ans = simpleSolve(ans,'+');
      ans = simpleSolve(ans,'-');
      line.replace(pos.at(pos.size()-1),strList.at(strList.size()-1).length()+2,ans);
      prints(">");
      printl(line);
      solveBrackets(line);
      strList.pop_back();
      pos.pop_back();
      return;
    }else strList.at(strList.size()-1)+=line[i];
  }
  string ans;
  ans = simpleSolve(strList.at(strList.size()-1),'*');
  ans = simpleSolve(ans,'/');
  ans = simpleSolve(ans,'+');
  ans = simpleSolve(ans,'-');
  FORZ(i,ans.length()){
    if(ans[i]=='_')ans[i]='-';
    cout << ans[i];
  }
  cout << endl<<endl;
}