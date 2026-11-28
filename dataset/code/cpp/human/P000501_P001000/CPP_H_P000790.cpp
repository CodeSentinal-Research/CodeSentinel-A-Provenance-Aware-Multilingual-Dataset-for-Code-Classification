#include <bits/stdc++.h>

using namespace std;
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename K, typename V>
string to_string(const map<K, V>& m) {
  string res = "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(kv.first) + ": " + to_string(kv.second);
  }
  res += "}";
  return res;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) {
            os << " ";
        }
        os<<"\n";
    }
    return os;
}


string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename T>
void read(T& val) {
  cin >> val;
}
template <typename T>
void read(vector<T>& a) {
  for (int i = 0; i < (int)a.size(); ++i) {
    read(a[i]);
  }
}
template <typename Head, typename... Tail>
void read(Head& H, Tail&... T) {
  read(H);
  read(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
#define endl '\n'
#define sz(x) (int)(x).size()
#define bits(x) __builtin_popcount(x)
#define vi vector<int>
#define gcd(a, b) __gcd((a), (b))
template <typename T>
int64_t sum(vector<T> a) {
  int64_t s = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    s += a[i];
  }
  return s;
}
int query_number = 1;
void print_query() {
#ifdef LOCAL
  cout << "Query #" << query_number++ << ": ";
#endif
}
int test_case_number = 1;
void print_case() {
#ifdef LOCAL
  // cout << "Case #" << test_case_number++ << ": ";
#endif
}

#define int int64_t

int max(int a,int b)
{
    if(a>b) return a;
    else
    return b;
}

int min(int a, int b)
{
    if (a<b) return a;
    else
    return b;
}

// int accurateFloor(int a, int b) {
// 	int val = a / b;
// 	while (val * b > a)
// 		val--;
// 	return val;
// }
// ----------------------------------------------------------------------------------------------------------------------------------------------------
//this is for seive and shit
// int N = 1e5 + 1;
// vector<int> spf(N), isActive(N), isOccupied(N);
// void sieve()
// {
//     for(int i = 0;i<N;i++) spf[i] = i;

//     for(int i = 2;i<N;i++)
//     {
//         for(int j = 2*i;j<N;j+=i)
//         {
//             if(spf[j]==j) spf[j] = i;
//         }
//     }
// }

// vector<int> primeFactorisation(int n)
// {
//     vector<int> primes;
//     while(n!=1)
//     {
//         int x = spf[n];
//         while(n%x==0) n/=x;
//         primes.push_back(x);
//     }
//     return primes;
// }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//this is for combinatorics
// Add this to the top of your file, right after other constants/macros
// const int MOD = 1e9 + 7; // You can change this to 998244353 if needed
// const int MAXN = 1e6 + 5;

// vector<int> fact(MAXN), inv_fact(MAXN);

// // Binary exponentiation
// int power(int a, int b, int m = MOD) {
//     int res = 1;
//     a %= m;
//     while (b > 0) {
//         if (b & 1)
//             res = (res * a) % m;
//         a = (a * a) % m;
//         b >>= 1;
//     }
//     return res;
// }

// // Precompute factorials and their modular inverses
// void precompute_factorials() {
//     fact[0] = 1;
//     for (int i = 1; i < MAXN; i++) {
//         fact[i] = (fact[i - 1] * i) % MOD;
//     }
//     inv_fact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
//     for (int i = MAXN - 2; i >= 0; i--) {
//         inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
//     }
// }

// // Binomial coefficient nCr % MOD
// int nCr(int n, int r) {
//     if (r < 0 || r > n) return 0;
//     return (((fact[n] * inv_fact[r]) % MOD) * inv_fact[n - r]) % MOD;
// }
//end of combinatorics
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// vector<int> decimal_to_binary(int x)
// {
//   vector<int> v(32);
 
//         for(int i=31; i>=0; i--){
//             v[i] = (x >= (1<<i));
//             x %= (1<<i);
//         }
//         return v;
// }


void solve() 
{
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  vi v(n);
  for(int &i:v) cin>>i;
  int p = -1;
  for(int i = 0; i<n; i++)
  {
    if(s[i]=='0')
    {
        p = i;
        v[i] = -1e13;
    }
  }
  int max_subarray_sum = 0; //overall
  int curr = 0; //continuous
  for(int i = 0; i<n; i++)
  {
    curr = max(curr + v[i], v[i]);
    max_subarray_sum = max(max_subarray_sum, curr);
  }

  if(max_subarray_sum > k || (max_subarray_sum!=k && p==-1))
  {
    cout<<"No\n";
    return;
  }

  if(p!=-1) //needs some fixing
  {
    max_subarray_sum = 0; curr = 0;
    int l,r;
    //p is index where we will make some changes
    for(int i = p+1; i<n; i++)
    {
        curr+=v[i];
        max_subarray_sum = max(max_subarray_sum, curr);
    }
    //baically max suffix subarray sum

    l = max_subarray_sum;
    max_subarray_sum = 0; curr = 0;
    for(int i = p-1; i>=0; i--)
    {
        curr += v[i];
        max_subarray_sum = max(max_subarray_sum, curr);
    }
    r = max_subarray_sum;
    //prefix max also done

    v[p] = k - l - r;
    //now this is overall max

  }
  cout<<"Yes\n";
  for(int &i:v) cout<<i<<" ";
  cout<<endl;

}

int32_t main() 
{
  fastio();
  int t;
  cin >> t;
  while (t--) 
  {
    solve();
  }
}
