#include<bits/stdc++.h>
using namespace std;


class SegmentTree{
    public:
    vector<int>tree;
    vector<int>lazy;
    SegmentTree(int n){
        tree.resize(4*n+1);
        lazy.assign(4*n+1, 0);
    }

    void build(int node, int start, int end, vector<int>&arr){
        if(start==end){
            tree[node] = arr[start];
            return;
        }
        int mid = (start+end)/2;
        build(2*node + 1, start, mid, arr);
        build(2*node + 2, mid+1, end, arr);

        tree[node] = tree[2*node + 1] + tree[2*node+2];
    }

    int query(int node, int start, int end, int l, int r){
        propagate(node, start, end);
        if(r<start || l>end)return 0;
        if(start==end){
            return tree[node];
        }
        if(l<=start && end<=r)return tree[node];
        int mid = (start+end)/2;
        int left = query(2*node + 1, start, mid, l, r);
        int right = query(2*node + 2, mid+1, end, l, r);
        return left+right;
    }

    void updatePoint(int node, int start, int end, int ind, int value, vector<int>&arr){
        propagate(node, start, end);
        if(start==end){
            arr[start] = value;
            tree[node] = value;
            return;
        }
        int mid = (start+end)/2;
        if(start<=ind && ind<=mid){
            updatePoint(2*node+1, start, mid, ind, value, arr);
        }
        else updatePoint(2*node+2, mid+1, end, ind, value, arr);

        tree[node] = tree[2*node + 1] + tree[2*node+2];

    }

    void propagate(int node, int start, int end){
        if(lazy[node] == 0) return;

        tree[node] += (end - start + 1) * lazy[node];

        if(start != end){
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }

        lazy[node] = 0;
    }

    void updateRange(int node, int start, int end, int l, int r, int value){
        propagate(node, start, end);
        if(r<start || l>end)return;

        if(l<=start && end<=r){
            lazy[node] += value;
            propagate(node, start, end);
            return;
        }
        int mid = (start+end)/2;
        updateRange(2*node + 1, start, mid, l, r, value);
        updateRange(2*node + 2, mid+1, end, l, r, value);

        tree[node] = tree[2*node+1] + tree[2*node +2];
    }

};


int main(){

    int n;cin>>n;
    vector<int>arr(n);
    for(auto &c:arr)cin>>c;

    SegmentTree st(n);
    st.build(0, 0, n-1, arr);

    int q;cin>>q;
    while(q-->0){
        int t;cin>>t;
        if(t==1){
            int l,r;
            cin>>l>>r;
            cout<<st.query(0,0,n-1,l,r)<<'\n';   
        }
        else if(t==0){
            int ind, val;
            cin>>ind>>val;
            st.updatePoint(0,0,n-1,ind,val,arr);
        }
        else if(t==2){
            int l,r,val;
            cin>>l>>r>>val;
            st.updateRange(0,0,n-1,l,r,val);
        }

    }

    return 0;
}