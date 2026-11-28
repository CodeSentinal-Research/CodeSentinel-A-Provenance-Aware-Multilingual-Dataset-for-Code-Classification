#include <bits/stdc++.h>
using namespace std;
class ProductOfNumbers {
    vector<int> p;
public:
    void add(int num) {
        if(num==0) p.clear();
        else p.push_back((p.empty()?1:p.back())*num);
    }
    int getProduct(int k) {
        if(k > p.size()) return 0;
        if(k == p.size()) return p.back();
        return p.back() / p[p.size()-k-1];
    }
};
int main() {
    int q; cin >> q;
    ProductOfNumbers p;
    while(q--) {
        string op; cin >> op;
        if(op=="add") { int x; cin>>x; p.add(x); }
        else { int k; cin>>k; cout << p.getProduct(k) << endl; }
    }
    return 0;
}
