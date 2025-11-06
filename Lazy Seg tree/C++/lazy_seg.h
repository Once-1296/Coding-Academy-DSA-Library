#ifndef LAZY_SEG_H
#define LAZY_SEG_H

class SegTree {
    vector<ll> t;           // segment sums
    vector<ll> lz;          // pending add
    vector<ll> assignVal;   // pending assign value
    vector<char> assignFlag;// pending assign flag (0/1)
    ll n;
 
    void buildUtil(const vll &a, ll s, ll e, ll i) {
        if (s == e) { t[i] = a[s]; return; }
        ll m = (s + e) >> 1;
        buildUtil(a, s, m, 2*i+1);
        buildUtil(a, m+1, e, 2*i+2);
        t[i] = t[2*i+1] + t[2*i+2];
    }
 
    void applyAssign(ll i, ll s, ll e, ll val) {
        ll len = e - s + 1;
        t[i] = val * len;
        assignFlag[i] = 1;
        assignVal[i] = val;
        lz[i] = 0; // assignment overwrites pending adds
    }
 
    void applyAdd(ll i, ll s, ll e, ll val) {
        ll len = e - s + 1;
        t[i] += val * len;
        lz[i] += val;
    }
 
    void push(ll i, ll s, ll e) {
        if (s == e) {
            // leaf: nothing to propagate
            return;
        }
        ll m = (s + e) >> 1;
        ll L = 2*i+1, R = 2*i+2;
 
        // If an assignment pending on this node, push it to children (it overrides adds)
        if (assignFlag[i]) {
            applyAssign(L, s, m, assignVal[i]);
            applyAssign(R, m+1, e, assignVal[i]);
            assignFlag[i] = 0;
            // assignVal[i] can remain or be overwritten later
        }
 
        // Then push additive lazy (additions accumulate)
        if (lz[i] != 0) {
            applyAdd(L, s, m, lz[i]);
            applyAdd(R, m+1, e, lz[i]);
            lz[i] = 0;
        }
    }
 
    // range assign: set all elements in [us..ue] to val
    void updAssign(ll i, ll s, ll e, ll us, ll ue, ll val) {
        push(i, s, e);
        if (s > e || s > ue || e < us) return;
        if (s >= us && e <= ue) {
            applyAssign(i, s, e, val);
            return;
        }
        ll m = (s + e) >> 1;
        updAssign(2*i+1, s, m, us, ue, val);
        updAssign(2*i+2, m+1, e, us, ue, val);
        t[i] = t[2*i+1] + t[2*i+2];
    }
 
    // range add: add val to every element in [us..ue]
    void updAdd(ll i, ll s, ll e, ll us, ll ue, ll val) {
        push(i, s, e);
        if (s > e || s > ue || e < us) return;
        if (s >= us && e <= ue) {
            applyAdd(i, s, e, val);
            return;
        }
        ll m = (s + e) >> 1;
        updAdd(2*i+1, s, m, us, ue, val);
        updAdd(2*i+2, m+1, e, us, ue, val);
        t[i] = t[2*i+1] + t[2*i+2];
    }
 
    // point update: set index idx to val
    void pointUpd(ll i, ll s, ll e, ll idx, ll val) {
        push(i, s, e);
        if (s == e) {
            t[i] = val;
            // ensure no pending flags at leaf
            assignFlag[i] = 0;
            lz[i] = 0;
            return;
        }
        ll m = (s + e) >> 1;
        if (idx <= m) pointUpd(2*i+1, s, m, idx, val);
        else pointUpd(2*i+2, m+1, e, idx, val);
        t[i] = t[2*i+1] + t[2*i+2];
    }
 
    ll qUtil(ll i, ll s, ll e, ll qs, ll qe) {
        if (s > e || s > qe || e < qs) return 0;
        push(i, s, e);
        if (s >= qs && e <= qe) return t[i];
        ll m = (s + e) >> 1;
        return qUtil(2*i+1, s, m, qs, qe) + qUtil(2*i+2, m+1, e, qs, qe);
    }
 
public:
    SegTree(ll n_): n(n_) {
        t.assign(4*n, 0);
        lz.assign(4*n, 0);
        assignVal.assign(4*n, 0);
        assignFlag.assign(4*n, 0);
    }
    SegTree(const vll &a): n((ll)a.size()) {
        t.assign(4*n, 0);
        lz.assign(4*n, 0);
        assignVal.assign(4*n, 0);
        assignFlag.assign(4*n, 0);
        if (n>0) buildUtil(a, 0, n-1, 0);
    }
 
    // public wrappers
    // add 'd' to range [l..r]
    void upd(ll l, ll r, ll d) { if (l<=r) updAdd(0, 0, n-1, l, r, d); }
    // assign all elements in [l..r] = d
    void upd2(ll l, ll r, ll d) { if (l<=r) updAssign(0, 0, n-1, l, r, d); }
    // query sum on [l..r]
    ll query(ll l, ll r) { if (l>r) return 0; return qUtil(0, 0, n-1, l, r); }
    // point set
    void update(ll idx, ll val) { pointUpd(0, 0, n-1, idx, val); }
};
#endif