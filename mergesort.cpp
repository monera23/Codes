#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include<sstream>
using namespace std;

void merge(int* left,int lcount,int* right,int rcount,int* a)
{
    int i=0,j=0,k=0;
    
    while(i<lcount && j<rcount)
    {
        if(left[i]<right[j])
        {
            a[k++]=left[i++];
        
        }
        
        else
        {
            a[k++]=right[j++];
            
        }
        
    }
    
    while(i<lcount)
    a[k++]=left[i++];
    
    while(j<rcount)
    a[k++]=right[j++];
    
}

void mergesort(int* a,int n)
{
    if(n<2)
    return ;
    
    int mid=n/2;
    int left[mid];
    for(int y=0;y<mid;y++)
    left[y]=0;
    
    int right[n-mid];
    for(int z=0;z<n-mid;z++)
    right[z]=0;
    
    for(int i=0;i<mid;i++)
    left[i]=a[i];
    
    for(int j=mid;j<n;j++)
    right[j]=a[j];
    
    mergesort(left,mid);
    mergesort(right,n-mid);
    merge(left,mid,right,n-mid,a);
    
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int n;
       scanf("%d",&n);
       int a[n];
       for(int i=0;i<n;i++)
       cin>>a[i];
       
       mergesort(a,n);
       
       for(int i=0;i<n;i++)
       cout<<a[i]<<" ";
       
    }
    
    return 0;
}

