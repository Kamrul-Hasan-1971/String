string multiply(string num1, string num2)
{
    ll n1 = num1.size();
    ll n2 = num2.size();
    if (n1 == 0 || n2 == 0)
    return "0";

    vector<ll> result(n1 + n2, 0);

    ll i_n1 = 0;
    ll i_n2 = 0;

    for (ll i=n1-1; i>=0; i--)
    {
        ll carry = 0;
        ll n1 = num1[i] - '0';

        i_n2 = 0;

        for (ll j=n2-1; j>=0; j--)
        {
            ll n2 = num2[j] - '0';

            ll sum = n1*n2 + result[i_n1 + i_n2] + carry;

            carry = sum/10;

            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }

    ll i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;

    if (i == -1)
    return "0";

    string s = "";

    while (i >= 0){
        char pp = result[i--] +'0';
        s += pp;
    }
    return s;
}


string summation(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    ll n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    ll carry = 0;
    for (ll i=0; i<n1; i++)
    {
        ll sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (ll i=n1; i<n2; i++)
    {
        ll sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}




string binaryToDecimal(string n)
{
    string num = n;
    string dec_value = "0";

    string base = "1";

    ull len = (ull)num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
           dec_value=summation(dec_value, base);
        base = multiply(base , "2");
    }
    return dec_value;
}
