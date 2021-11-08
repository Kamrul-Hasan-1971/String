/*

https://leetcode.com/problems/longest-valid-parentheses/solution/

*/

#include<bits/stdc++.h>
using namespace std;

int longestValidParenthesesNoExtraSpaces(string s)
{
    if( s.size() == 0)
        return 0;
    int left = 0, right = 0, longestValidParentheses = 0 ;

    for( int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == '(')
            left++;
        else
            right ++;
        if(left<right)
            left = right = 0;
        else if( left == right )
            longestValidParentheses = max(longestValidParentheses,left+right);
    }
    left = right = 0 ;
    for( int i = s.size()-1 ; i >= 0 ; i--)
    {
        if(s[i] == '(')
            left++;
        else
            right ++;
        if(left>right)
            left = right = 0;
        else if( left == right )
            longestValidParentheses = max(longestValidParentheses,left+right);
    }
    return longestValidParentheses;
}


int longestValidParentheses(string &s)
{
    s = ")"+s;
    int maxValidParenthesis = 0, sz = s.size();
    vector<int>dp(sz,0);
    for( int i = 1 ; i < s.size() ; i++)
    {
        if( s[i-1] == '(' && s[i] == ')') //here is a valid substring of length 2
        {
            dp[i] = dp[i-2] + 2;
        }
        else if( s[i] == s[i-1] && s[i] == ')' && s[i-dp[i-1]-1] == '(')
        {
            dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2] ;
        }
        maxValidParenthesis = max( maxValidParenthesis, dp[i]);
    }
    return maxValidParenthesis ;
}

int longestValidParentheses(string s)
{
    stack<int> stk ;
    int maxValidParentheses = 0;
    stk.push(-1);

    for( int i = 0 ; i < s.size() ; i++)
    {
        if( s[i] == '(')
            stk.push(i);
        else
        {
            stk.pop();
            if(stk.empty())
            {
                stk.push(i);
            }
            maxValidParentheses = max( maxValidParentheses, (i-stk.top()));
        }
    }
    return maxValidParentheses;
}

int main()
{
    string s  = "(())(())(()";
    cout<<longestValidParentheses(s)<<endl;
    return 0 ;
}






