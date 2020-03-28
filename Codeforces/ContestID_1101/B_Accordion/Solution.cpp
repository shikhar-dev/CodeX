#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#define ll /*unsigned*/ long long int
#define ld double
#define EXIT exit(0)
#define cinf(a) scanf("%lf",&a)
#define coutf(a) printf("%.12lf\n",a)
#define cins(a) scanf(" %s",a)
#define couts(a) printf("%s",a)
#define cin(a) scanf("%lld",&a)
#define cout(a) printf("%lld\n",a)
#define cout_(a) printf("%lld ",a)
#define coutc(a) printf("%c",a)
#define cinc(a) scanf(" %c",&a)
#define coutp(a, b) printf("%lld %lld\n",a,b)
#define debug couts("chu\n") ;
#define SZ(a) (ll)a.size()
#define next_prm std::next_permutation
#define ALL(x) x.begin(),x.end()
#define endl '\n'
#define M 1000000007
#define MAX 9223372036854775807
#define MIN -92233720368//54775807
#define pb(a) push_back(a)
#define mmp(a, b) make_pair (a,b)
#define pmp(a, b) push_back(make_pair(a,b))
#define pp pair
#define rev reverse
#define S second
#define F first
#define flush fflush(stdout)
#define LB lower_bound
#define UB upper_bound
#define cnt_bin1(x) __builtin_popcountll(x)
#define bsa(v, n, a) binary_search(v,v+n,a)
#define bsv(v, a) binary_search(v.begin(),v.end(),a)
#define PI 3.1415926535897932
#define fast() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
//******************************************************************--UTILITIES--************************************************************************************//
/*FILE INPUT OUTPUT REDIRECT
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 */
/*struct node2 {
    ll x,y ;
    ll val ;
    ll cid ;
}aux2;
struct compare {
    bool operator()(node2 l, node2 r) {
            return l.val > r.val ;					// MIN PQ
    }
};
std::priority_queue<node2,std::vector<node2>,compare > pq ;*/

/*  RANKED TREE ORDER STATISTIC TREE */
typedef tree<
pp<ll,ll>,
null_type,
less<pp<ll,ll>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
ll fast_power(ll a, ll x, ll mm) {
    if (x == 0)
        return 1;
    else if (x == 1)
        return a % mm;
    else {
        ll y = fast_power(a, x / 2, mm) % mm;
        y = ((y % mm) * (y % mm)) % mm;
        if (x % 2 == 1)
            return ((a % mm) * (y % mm)) % mm;
        else
            return y % mm;
    }
}

bool CheckOverflow(ll a, ll b) {
    if (a > 1e18 / b) return true;
    else return false;
}

ll SumOfDigits(ll x) {
    ll sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

ll mod(ll a, ll b) {
    if (a < 0) {
        a = (-a) % b;
        if (a != 0)
            a = b - a;
    } else
        a = a % b;
    return a;
}

ld ldabs(ld n) {
    if (n < 0) return -n;
    return n;
}

ll mul(ll a, ll b, ll mm) {
    return (mod(a, mm) * mod(b, mm)) % mm;
}

ll add(ll a, ll b, ll mm) {
    return (mod(a, mm) + mod(b, mm)) % mm;
}

ll sub(ll a, ll b, ll mm) {
    return mod(a - b, mm) % mm;
}

ll gcd(ll a, ll b) {
    if (a == -1 || b == -1) return -1;
    if (a == 0 || b == 0) return b | a;
    else return __gcd(a, b);
}

ll lcm(ll a, ll b) {
    return (a * b) / __gcd(a, b);
}

ll MMI(ll a, ll mm) {
    return fast_power(a, mm - 2, mm) % mm;
}
ll to_int(string ss) {
    ll n=0,i ;
    for (i=0;i<SZ(ss);i++)
        n=n*10+(ss[i]-48) ;
    return n ;
}
//***************************************************************************************************************************************************************//
//**********************************************************************-BY YOUR_DAD-****************************************************************************//
//**********************************************************************-PROGRAM STARTS FROM HERE-***************************************************************//
string str;
ll find_rep (char ch,bool st,ll start) {
    ll i;
    if (st) {
        for (i=start;i<SZ(str);i++)
            if (str[i] == ch)   return i;
            else str[i] = 'z';
    }
    else {
        for (i=start;i>-1;i--)
            if (str[i] == ch)   return i;
            else str[i] = 'z';
    }
    return -1;
}
int main () {
    cin>>str;
    ll t,b,cnt=0;
    t = find_rep('[',true,0);
    if (t == -1)  {
        cout(t);
        return 0;
    }
    t = find_rep(':',true,t+1);
    if (t == -1)  {
        cout(t);
        return 0;
    }
    b = find_rep(']',false,SZ(str)-1);
    if (b == -1)  {
        cout(b);
        return 0;
    }
    b = find_rep(':',false,b-1);
    if (b == -1)  {
        cout(b);
        return 0;
    }
    if (b<=t)   {
        couts("-1\n");
        return 0;
    }
    for (t++;t<b;t++)
        if (str[t] != '|')  str[t]='z';
    for (ll i=0;i<SZ(str);i++)
        if (str[i] == 'z')  cnt++;
    cout(SZ(str)-cnt);
    return 0;
}