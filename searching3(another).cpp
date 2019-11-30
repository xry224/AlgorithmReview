#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void precompute(vector<pair<ll,ll>>vec,vector<ll>&diff){
    int n=vec.size();
    for(int i=0;i<n;i++){
        if(i==0)
            diff.push_back(vec[i].first-1);
        else
            diff.push_back(diff[i-1]+vec[i].first-vec[i-1].second-1);
    }
}

ll search_marks(vector<pair<ll,ll>>vec,vector<ll>diff,ll rank){
    int l,n,mid;
    n=vec.size()-1;
    l=0;
    while(l<=n){
        mid=(l+n)/2;
        if(rank+diff[mid]>=vec[mid].first && rank+diff[mid]<=vec[mid].second){
            break;
        }
        else if(rank+diff[mid]<vec[mid].first){
            n=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return rank+diff[mid];
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,q,i,a,b,rank,marks;
        cin>>n>>q;
        vector<pair<ll,ll>>vec;
        vector<ll>diff;
        for(i=0;i<n;i++){
            cin>>a>>b;
            vec.push_back(make_pair(a,b));
        }
        precompute(vec,diff);
        for(i=0;i<q;i++){
            cin>>rank;
            marks=search_marks(vec,diff,rank);
            cout<<marks<<" ";
        }
        cout<<endl;
    }
    return 0;
}