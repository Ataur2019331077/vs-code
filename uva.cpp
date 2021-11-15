#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll ans=0;
        cin>>n;
        map<char, int>mp;
        for(int i=0; i<n; i++)
        {
            char c;
            int x;
            cin>>c>>x;
            mp[c]=x;
        }
        cin>>n;
        getchar();
        while(n--)
        {
            string s;
            getline(cin, s);
            for(int i=0; i<s.size(); i++)
            {
                if(mp.find(s[i])!=mp.end())
                {
                    ans+=mp[s[i]];
                }
            }
        }
        double res=(double)ans/100.0;
        printf("%.2lf$\n", res);
    }
    
}