#include<bits/stdc++.h>
using namespace std;

#define  CIN            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define  ll             long long int

string s1;
string convertString(const string &s)
{
    string newString;
    for(ll i=0; i<s.size(); i++)
    {
        newString+="#"+s.substr(i,1);
    }
    newString+="#";
    return newString;
}

string lps(const string &s)
{
    string str = convertString(s);
    ll c=0,r=0;
    ll len = str.size();
    ll LPS[len+2]= {0};
    for(ll i=0; i<len; i++)
    {
        ll mirror =2*c-1;
        if(r>i)
        {
            LPS[i]=min(r-i,LPS[mirror]);
        }
        ll a=i+(1+LPS[i]);
        ll b=i-(1+LPS[i]);
        while(a<len&&b>=0&&str[a]==str[b])
        {
            LPS[i]++;
            a++;
            b--;
        }
        if(i+LPS[i]>r)
        {
            c=i;
            r=i+LPS[i];
        }
    }

    ll maxlen=0,indx=0;
    for (ll i = 0; i < str.size() ; i++)
    {
        if (LPS[i] > maxlen)
        {
            maxlen = LPS[i];
            indx = i;
        }
    }
    return s.substr((indx-maxlen)/2,maxlen);
}

int main()
{
    CIN;
    ll  a,b,c,d,e,f,i,j,k,cnt1=0,cnt2=0,sum1=0,sum2=0,chk1=0,chk2=0,T;
    cin>> T ;
    while(T--)
    {
        cin >> s1 ;
        cout<<lps(s1)<<endl;
    }
    return 0 ;
}
//https://medium.com/প্রোগ্রামিং-পাতা/লংগেস্ট-প্যালিনড্রোমিক-সাবস্ট্রিং-manachers-algorithm-3c4d6880c905
