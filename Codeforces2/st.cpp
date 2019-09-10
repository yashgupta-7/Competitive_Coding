#include<bits/stdc++.h>
using namespace std;
const int n=1e6+7;
int tree[n],A[n];

void build(int node,int start,int end)
{
    if (start==end){
        tree[node]=A[start];
    }
    else{
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

void update(int node,int start,int end,int idx,int val){
    if (start==end){
        A[idx]=val;
        tree[start]=val;
    }
    else{
        int mid=(start+end)/2;
        if (idx<=mid){
            update(2*node,start,mid,idx,val);
        }
        else if (idx>mid){
            update(2*node+1,mid+1,end,idx,val);
        }
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

int query(int node,int start,int end,int l,int r){
    //cout<<node<<" "<<start<<" "<<end<<" "<<l<<" "<<r<<" "<<endl;
    if(l>r||l>end||r<start){
        return 2e9;
    }
    else if(l<=start && end<=r)
    {
        return tree[node];
    }
    int mid=(start+end)/2;
    int q1=query(2*node,start,mid,l,r);
    int q2=query(2*node+1,mid+1,end,l,r);
    return min(q1,q2);
}

int main()
{
    int N,Q;cin>>N>>Q;
    for(int i=1;i<N+1;i++){
        cin>>A[i];
    }
    build(1,1,N);
    for(int i=0;i<Q;i++)
    {
        char c;cin>>c;
        if (c=='q'){
            
            int l,r;cin>>l>>r;
            cout<<query(1,1,N,l,r)<<'\n';
        }
        else if (c=='u'){
            int idx,val;
            cin>>idx>>val;
            update(1,1,N,idx,val);
        }
    }
}
