// selection procedure
#include<iostream>
using namespace std;

#define f0(i,n) for(int i=0; i<n; ++i)

int partition(int a[], int p, int r)
{
    //last element is pivot element
    int x=a[r];
    int i=p-1;
    
    for(int j=p; j<r; ++j){
        
        if(a[j]<=x){
            
            //increment number of elements smaller than pivot elements
            ++i;
            
            //exchange current and last element (which was found to be smaller than pivot element)
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    
    //exchange (i+1)th and pivot element
    int temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    
    return i+1;
}

int selection(int a[], int p, int r, int k)
{
    
    if(p>r)
        return -1;
    
    if(p==r){
        if(k==p)
            return a[p];
        else
            return -1;
    }
    
    int m=partition(a,p,r);
    
    if(k==m)
        return a[m];
    if(k<m)
        return selection(a,p,m-1,k);
    
    return selection(a,m+1,r,k);
    
}

int main()
{
    int n;  cin>>n;
    int a[n];
    f0(i,n) cin>>a[i];
    
    //test cases
    int t;  cin>>t;
    while(t--){
        int b[n];
        f0(i,n) b[i]=a[i];
        
        //kth smallest element
        int k;  cin>>k;
        cout<<selection(b,0,n-1,k-1)<<endl;
    }
    
    return 0;
}
