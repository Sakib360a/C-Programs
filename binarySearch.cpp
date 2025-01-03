#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr,int l,int r,int x)
{
    while(l<=r)
    {
        int mid= (l+r)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        if(arr[mid]<x)
        {
            l=mid+1;
        }
        if(arr[mid]>x)
        {
            r=mid-1;
        }   
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the element to be searched: ";
    cin>>x;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

   int result = binarySearch(arr,0,n-1,x);
   if(result==-1)
    {
         cout<<"Element not found";
    }
    else
    {
        cout<<"Element found at index "<<result;
    }
    return 0;
}