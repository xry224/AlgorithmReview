#include<bits/stdc++.h>
using namespace std;

int cnt=0;
void merge(int a[],int b[],int start, int mid,int end)
{
	int l = start,m = mid+1, r = end,lb=start;
	while(l<=mid&&m<=end)
	{
		if(a[l]<=a[m])
		{
			b[lb++]=a[l++];
		}
		else
		{
			b[lb++]=a[m++];
			cnt +=  mid-l+1;
		}
	}
	while(l<mid+1)
	b[lb++]=a[l++];
	while(m<end+1)
	b[lb++]=a[m++];
	for(int i=start;i<=end;i++)
	{
		a[i] = b[i];
	}
}
void mergesort(int a[],int b[],int start, int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		mergesort(a,b,start,mid);
		mergesort(a,b,mid+1,end);
		merge(a,b,start,mid,end);
	}
	
}
int main()
{
    int n,T;
    cin>>T;
	for(int i=0;i<T;i++)
    {
    	cin>>n;
    	int a[n] ,b[n];
        for(int i = 0 ; i < n; i ++)
            cin >> a[i];
        mergesort(a,b,0 , n-1);
        cout <<cnt <<endl;
        cnt=0; 
    }
    return 0;
}