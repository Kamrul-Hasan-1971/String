#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int
//Binary_string_divisibility_rule
void fun2(ll n)
{
    ll y = 0;
    for(ll i = 0 ; i < a ; i++)
    {
        ll x;
        x=s1[i]-'0';
        if (x == 1) y = (y * 2 + 1) % n;
        else if (x == 0) y = (y * 2) % n;
    }
    if (y % n == 0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

