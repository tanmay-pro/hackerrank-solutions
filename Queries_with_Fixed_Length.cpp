#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
int m = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    // ll t = 1;
    // cin >> t;

    // while (t--)
    // {
    // }
    ll n, q;
    cin >> n >> q;
    ll arr[n];
    fo(i, n)
    {
        ll x;
        cin >> x;
        arr[i] = x;
    }
    while (q--)
    {
        int d;
        cin >> d;
        ll max_el = arr[0];
        fo(i, d)
        {
            if (arr[i] > max_el)
                max_el = arr[i];
        }
        vl ans;
        ans.push_back(max_el);
        for (int i = d; i < n; i = i + 1)
        {
            if (max_el == arr[i - d])
            {
                max_el = arr[i];
                for (int j = i - d + 1; j <= i; j++)
                {
                    if (arr[j] > max_el)
                        max_el = arr[j];
                }
            }
            if (arr[i] > max_el)
                max_el = arr[i];
            ans.push_back(max_el);
        }
        ll minval = ans[0];
        fo(i, ans.size())
        {
            if (ans[i] < minval)
                minval = ans[i];
        }
        cout << minval;
        br;
    }

    return 0;
}