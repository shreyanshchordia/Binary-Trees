#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a[100000];
    cout<<"enter the number of nodes\n";
    cin>>n;
    cout<<"The no of binary trees possible with distinct nodes are\n";
    a[0] = 1;
    a[1] = 1;
    for(i=2;i<=n;i++)
    {
        a[i] = 0;
        for(j=0;j<i;j++)
        {
            a[i]+=(a[j]*a[i-j-1]);
        }
    }
    cout<<a[n];
    return 0;
}