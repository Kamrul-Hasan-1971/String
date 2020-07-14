#include<bits/stdc++.h>
using namespace std;
#define ll  long long  int

string s1;
bool check(ll &i,ll &li,ll &N)
{
    if((i+li)>=N ||(i-li)<=0) return false;
    if((i+li+1)%2==0) return true;
    if(s1[(i+li+1)/2]==s1[(i-li-1)/2]) return true;
    return false;
}
void lps()
{
	ll N = s1.size(),mx=1,center=1,start=-1,diff=-1;
	if(N == 0)  return;
	N = 2*N + 1;
	ll L[N],C=1,R=2,i,im;
	L[0] = 0,L[1]=1;
	for (i = 2; i < N; i++)
	{
		im = 2*C-i;
		L[i] = 0;
		diff = R - i;
		if(diff > 0) L[i] = min(L[im], diff);

		while(check(i,L[i],N)) L[i]++;

		if(L[i]>mx)
		{
			mx = L[i];
			center = i;
		}
		if (i+L[i]>R)
		{
			C = i;
			R = i+L[i];
		}
	}
	cout<<mx<<endl;
	start = (center-mx)/2;
    cout<<s1.substr(start,mx)<<endl;
}

int main()
{
    ll a;
	cin >> a >>s1 ;
	lps();
	return 0;
}

