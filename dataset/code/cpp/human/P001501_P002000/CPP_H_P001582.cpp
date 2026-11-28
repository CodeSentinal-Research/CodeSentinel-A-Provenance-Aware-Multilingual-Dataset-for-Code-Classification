// Question 2: Longest Non-Decreasing Subsequence After Reversing One Subarray

// You are given an array A of length n.
// You may choose at most one contiguous subarray A[l...r] (1 ≤ l ≤ r ≤ n) and reverse it exactly once.
// After performing this operation (or choosing not to perform it), determine the maximum possible length of the Longest Non-Decreasing Subsequence (LNDS) of the resulting array.
// A subsequence is obtained by deleting zero or more elements without changing the relative order of the remaining elements.
// A sequence is non-decreasing if every element is less than or equal to the next element.


// Input
// An integer n.
// An array A of length n.

// Output:
// Print the maximum possible length of the longest non-decreasing subsequence after reversing at most one subarray.


// Example:
// Input
// n = 10
// A = [1,1,2,2,2,1,1,2,2,1]

// Output :
// 9

// Explanation:
// Choose the subarray from index 2 to 6 (1-based indexing) and reverse it.

// Original array:
// 1 1 2 2 2 1 1 2 2 1
// After reversing the chosen subarray:
// 1 1 1 1 2 2 2 2 2 1
// The longest non-decreasing subsequence now has length:
// 9

// Therefore, the answer is:
// 9


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define maxe(v) (*max_element(all(v)))
#define mine(v) (*min_element(all(v)))
#define sumv(v) (accumulate(all(v), 0LL))
#define lb(v, x) (lower_bound(all(v), x) - (v).begin())
#define ub(v, x) (upper_bound(all(v), x) - (v).begin())
#define ispresent(v, x) (binary_search(all(v), x))
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define repr(i, a, b) for (int i = (a); i >= (b); --i)
#define ff first
#define ss second
#define mod 1000000007

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}



void solve() {

  
}

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}