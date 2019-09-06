#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mx 2000005
#define mod1 1000000007
#define mod2 1000000009
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define all(a) a.begin(),a.end()


ll prm1 = 103 , prm2 = 1457 ;
char st[3000006], s[mx] ;
ll pw1[mx] , pw2[mx] ;
int main()
{

    pw1[0] = 1 ;
    pw2[0] = 1 ;
    for(ll i = 1 ; i < mx ; i++ )
    {
        pw1[i] = pw1[i-1] * prm1 % mod1 ;
        pw2[i] = pw2[i-1] * prm2 % mod2 ;
    }

    ll input ;
    scanf("%lld",&input ) ;
    scanf("%s",st) ;
    ll m = strlen(st);
    for(ll i = 1 ; i < input ; i++ )
    {
        scanf("%s",s);
        ll n = strlen(s);
        pair<ll , ll > has1(0 , 0), has2(0 , 0);
        ll ans = 0 ;
        for(ll i = m-1 , j = 0 ; i >= 0 && j < n ; i-- , j++  )
        {
            has1.fs = (has1.fs + pw1[j] * s[j]) % mod1;
            has1.sc = (has1.sc + pw2[j] * s[j]) % mod2;

            has2.fs = (has2.fs * prm1 + st[i]) % mod1;
            has2.sc = (has2.sc * prm2 + st[i]) % mod2;

            if( has1 == has2 )
            {
                ans = j+1 ;
            }
        }
        for(ll j = ans ; j < n ; j++)
            st[m++] = s[j] ;
    }
    printf("%s",st);
}
