#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int>parent;
unordered_map<int, int>Rank;

void makeSet(vector<int>a)
{
    for(int x : a)
    {
        parent[x]=x;
        Rank[x]=0;
    }
}

int findSet(int x)
{
    if(x==parent[x]) return x;

    return parent[x]=findSet(parent[x]);
}

void unionSet(int a, int b)
{
    a=findSet(a);
    b=findSet(b);

    if(a!=b)
    {
        if(Rank[a]<Rank[b]) swap(a, b);
        parent[b]=a;
        if(Rank[a]==Rank[b]) Rank[a]++;
    }
}



int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    makeSet(a);

    //check initialize
    for(int i=0; i<n; i++)
    {
        printf("The parent of %d is %d\n", a[i], findSet(a[i]));
    }

    int m;
    cin>>m;
    while(m--)
    {
        int x, y;
        cin>>x>>y;
        unionSet(x, y);
    }
    //final outcome
    for(int i=0; i<n; i++)
    {
        printf("The parent of %d is %d\n", a[i], findSet(a[i]));
    }

}