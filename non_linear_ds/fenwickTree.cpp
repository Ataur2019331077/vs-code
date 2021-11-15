#include<bits/stdc++.h>
using namespace std;

#define sz 1000;

int getNext(int x) {return x+(x&(-x));}
int getParent(int x) {return x-(x&(-x));}

void updateTree(vector<int>& bit, int val, int index)
{
    while(index<bit.size())
    {
        bit[index]+=val;
        index=getNext(index);
    }
}

int getSum(vector<int>& bit, int index)
{
    index++;
    int sum=0;
    while(index>0) 
    {
        sum+=bit[index];
        index=getParent(index);
    }
    return sum;
}

vector<int> createTree(vector<int>input)
{
    int n=input.size();
    vector<int>bit(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        updateTree(bit, input[i-1], i);
    }
    return bit;

}


int main()
{
    int n;
    cin>>n;
    vector<int>input(n);
    for(int i=0; i<n; i++) cin>>input[i];

    vector<int>FenwickTree=createTree(input);

    int q;
    cin>>q;
    while(q--)
    {
        int type;   // type == 1 -> getsum of index
                    // type == 2 -> udate the tree in desire index with desire value
        cin>>type;
        if(type==1)
        {
            int id;
            cin>>id;
            int ans=getSum(FenwickTree, id);
            cout<<ans<<endl;
        }
        else{
            int val, id;
            cin>>val>>id;
            int ck=input[id];
            val-=ck;
            updateTree(FenwickTree, val, id+1); 
        }

    }

}