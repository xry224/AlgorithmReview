#include<bits/stdc++.h>

using namespace std;

double serch(double l , double h , double a[] , int n)
{ 
    double d=0.0000000000001;
    double force =0.0 , m , x;
    m =(l+h)/2.0;

    for(int i=0;i<n;i++)
    {
        x=1.0/(m-a[i]);
        force+=x;
    }

    if(abs(force)<d)
    {
        return m;
    }

     if(force>0)
     {
         return serch (m , h , a , n);
     }
     else{
         return serch(l , m , a , n);
     }
}
int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        double a[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++)
        {
            double ans =serch(a[i] , a[i+1] , a , n);

            cout<<fixed<<setprecision(2)<<ans<<" ";
        }
        cout<<endl;
    }
}