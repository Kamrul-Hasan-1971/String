#include <bits/stdc++.h>
using namespace std;
#define           CIN                ios_base::sync_with_stdio(0); cin.tie(0);
string s1 ,s2 ,s3,s4,s5;
#define ll long long int
#define prm1  347
#define Mod1  10000000011
const ll Hash(string str , ll prm , ll mod , ll len)
{
    ll h = 0 , power = 1 , i ;
    for( i = len-1 ; i>=0 ; i-- )
    {
        h = h + (str[i]*power)%mod;
        h = h % mod ;
        power = (power * prm)%mod;
    }
    return h ;
}
const void match( string text ,string pattern)
{
    ll i , power1 = 1 , last = s1.size() , len = pattern.size();
    if(last<len || len == 0 || last == 0) return ;
    for( i = 1 ;i < len ; i++){
        power1 = (power1*prm1)%Mod1;
    }
    ll hash_text1 = Hash(text,prm1,Mod1,len);
    ll hash_pattern = Hash(pattern,prm1,Mod1,len);
    if(hash_text1==hash_pattern) cout<<0<<" ";

    for( i = len ; i<last ; i++)
    {
        hash_text1 = (hash_text1-(power1*s1[i-len]%Mod1))%Mod1;
        hash_text1 = (hash_text1+Mod1)%Mod1;
        hash_text1 = (hash_text1*prm1)%Mod1;
        hash_text1 = (hash_text1+s1[i])%Mod1;
        if(hash_text1==hash_pattern) cout<<i-len+1<<" ";
    }
    cout<<endl;
}
int main()
{
    CIN;
	int a , b , c, d , i , T , j;
	cin >> s1>>b;
	while(b--)
    {
        cin >> s2 ;
        ll len = s2.size();
        match(s1,s2);
    }
	return 0;
}
