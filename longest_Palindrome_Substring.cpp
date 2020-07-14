#include<bits/stdc++.h>
using namespace std;

string text;
int min(int a, int b)
{
	int res = a;
	if(b < a)
		res = b;
	return res;
}

string findLongestPalindromicString()
{
	int N = text.size();
	if(N == 0)  return "";
	N = 2*N + 1;
	int L[N];
	L[0] = L[1]=0;
	int C=1,R=2,i=0,iMirror,mx=0,center=0,start=-1,endd=-1,diff=-1;
	for (i = 2; i < N; i++)
	{
		iMirror = 2*C-i;
		L[i] = 0;
		diff = R - i;
		if(diff > 0) L[i] = min(L[iMirror], diff);

		while(((i+L[i])<N &&(i-L[i])>0)&&(((i+L[i]+1)%2==0)||(text[(i+L[i]+1)/2]==text[(i-L[i]-1)/2]))) L[i]++;

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
	start = (center-mx)/2;
	return text.substr(start,mx);
}

int main(int argc, char *argv[])
{
    int a;
	cin >>a>> text ;
	cout<<findLongestPalindromicString()<<endl;
	return 0;
}
