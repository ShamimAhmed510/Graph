//https://codeforces.com/contest/727/problem/A
#include <bits/stdc++.h>
using namespace std;
#define optimize() ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long 

int main() {
    optimize();

       ll a,b; cin>>a>>b;
       vector<int>v;
       v.push_back(b);
       while( b > a)
       {
        if(b % 2 == 0)
        {
            b/=2;
        }
        else if(b%10 == 1)
        {
            b/=10;
        }
        else 
        {
            break;
        }
        v.push_back(b);
       }

if(v.back() == a)
{
    cout <<"YES"<<endl;
    cout << v.size()<<endl;
       for(int i=v.size()-1; i>=0; i--) cout << v[i] <<" ";
       cout << endl;

}
else 
{
    cout << "NO"<<endl;
}
    return 0 ;
}
