#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define lc (node + 1)
#define rc (node + 2 * (mid - tl + 1))

class SegmentTree {
private:
    int n;
    vector<int> arr, tree;
    void build(int tl, int tr, int node) {
        if (tl == tr) tree[node] = (1 << (arr[tl] - 1));
        else {
            int mid = (tl + tr) >> 1;
            build(tl, mid, lc);
            build(mid + 1, tr, rc);
            tree[node] = tree[lc] | tree[rc];
        }
    }
    void update(int tl, int tr, int node, int idx, int val) {
        if (tl == tr) tree[node] = (1 << (val - 1));
        else {
            int mid = (tl + tr) >> 1;
            if (idx <= mid)
                update(tl, mid, lc, idx, val);
            else
                update(mid + 1, tr, rc, idx, val);
            tree[node] = tree[lc] | tree[rc];
        }
    }
    int query(int tl, int tr, int node, int l, int r) {
        if (tl >= l and tr <= r) return tree[node];
        int mid = (tl + tr) >> 1;
        int ret = 0;
        if (l <= mid) {
            ret |= query(tl, mid, lc, l, r);
        }
        if (r > mid)
            ret |= query(mid + 1, tr, rc, l, r);
        return ret;
    }
public:
    SegmentTree(vector<int> &v) {
        arr = v;
        n = v.size();
        tree.resize(2 * n);
        build(0, n - 1, 1);
    }
    int query(int l, int r) {
        return __builtin_popcountll(query(0, n - 1, 1, l, r));
    }
    void update(int idx, int val) {
        update(0, n - 1, 1, idx, val);
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    SegmentTree st(v);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << st.query(l - 1, r - 1) << endl;
        } else {
            int idx, val;
            cin >> idx >> val;
            st.update(idx - 1, val);
        }
    }
}
