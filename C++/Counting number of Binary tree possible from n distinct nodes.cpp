#include<bits/stdc++.h>
using namespace std;
//Algorithm to find total no of possible binary trees with n distinct nodes;
int main()
{
    int n,i,j,a[100000];
    cout<<"enter the number of nodes\n";
    cin>>n;
    cout<<"The no of binary trees possible with distinct nodes are\n";
    a[0] = 1;//this is an assumption because with 0 nodes no trees are possible;
    a[1] = 1;
    for(i=2;i<=n;i++)
    {
        a[i] = 0;
        for(j=0;j<i;j++)
        {
            a[i]+=(a[j]*a[i-j-1]); //we are using the catlan number algo to find the solution
        }
    }
    if(n==0)
    {
        cout<<"0";
    }
    else
    {
        cout<<a[n];
    }
    return 0;
}
