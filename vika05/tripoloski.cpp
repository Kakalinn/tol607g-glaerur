#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

struct segtree {
    int n; vi d; 
    segtree(vi o) : n(o.size()), d(2 * o.size()) {
        for(int i = 0; i < n; ++i) d[n + i] = o[i];
        for(int i = n - 1; i > 0; --i) d[i] = d[i << 1] + d[i << 1|1];
    }
    void update(int at, int by) {
        for(d[at += n] = by; at > 1; at >>= 1) d[at >> 1] = d[at] + d[at ^ 1];
    }
    int query(int l, int r) { // [l, r[
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res += d[l++];
            if(r & 1) res += d[--r];
        }
        return res;
    }
};

int main() {
    vi tst = {0, 1, 2, 3, 4, 5, 6};
    segtree st(tst);
    cout << st.query(0, 3) << endl;
    st.update(1, 4);
    cout << st.query(1, 3) << endl;
}
