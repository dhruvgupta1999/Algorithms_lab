#include <bits/stdc++.h>
using namespace std;

int n;

int partition(int a[],int lo,int hi)
{
    //cout<<"in partition()"<<endl;
    int tmp;
    int  i=lo;
    int pvt=a[hi];
    for(int j=lo;j<hi;j++)
    {
        //cout<<"i="<<i<<endl;
        //cout<<"j="<<j<<endl;
        if(a[j]<=pvt)
        {
           tmp=a[j];
           a[j]=a[i];
           a[i]=tmp;
           i++;
        }
    }
    tmp=a[hi];
    a[hi]=a[i];
    a[i]=tmp;
    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return i;

}


void quicksort(int a[],int lo,int hi)
{
    int x;
    //cout<<"in quicksort"<<endl;
    if(lo<hi)
    {x=partition(a,lo,hi);
   
   if(0<x-1)
       quicksort(a,lo,x-1);
   if(x<hi)
       quicksort(a,x+1,hi);
}

}


int main(){
    
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    
    quicksort(a,0,n-1);



}