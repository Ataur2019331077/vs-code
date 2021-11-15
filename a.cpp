#include<bits/stdc++.h>
using namespace std;

#define lli long long int

void sol()
{
    lli a, b;
    cin>>a>>b;
    lli ans=(a*b)/3;
    if((a*b)%3) ans++;
    cout<<ans<<endl;
    cout << ans << endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        sol();
    }
}