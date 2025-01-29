#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int x1=v[i].first;
                int y1=v[i].second;
                int x2=v[j].first;
                int y2=v[j].second;
                int x3=v[k].first;
                int y3=v[k].second;
                int area=abs((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
                if(area!=0 && area%2==0)
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}