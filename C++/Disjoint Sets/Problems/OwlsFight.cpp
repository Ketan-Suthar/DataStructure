#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define lli long long int
#define pb push_back
int ar[100001];
int find(int a)
{
    if(ar[a] < 0) return a;
    
    return ar[a] = find(ar[a]);
}

void Union(int a , int b)
{
    ar[a] = min(ar[a] , ar[b]);
    ar[b] = a;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n , m , q , a , b , x , y;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
        ar[i] = -i;
    
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        a = find(a);
        b = find(b);
        if(a != b) Union(a , b);
    }
    
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        x = a, y = b;
        a = find(a) , b = find(b);
        if(a == b)
        cout<<"TIE\n";
        
        else
        {
            if(ar[a] < ar[b])
            cout<<x<<endl;
            else
            cout<<y<<endl;
        }
    }
}