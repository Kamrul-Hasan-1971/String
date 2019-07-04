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
