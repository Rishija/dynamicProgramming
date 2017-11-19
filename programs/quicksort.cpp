//Quicksort
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

void quicksort(int a[], int p, int r)
{
    
    if(p<r){
        //qth element at correct position
        int q=partition(a,p,r);
        /*
        cout<<q<<"th element ie. "<<a[q]<<" at correct place"<<endl;
         */
        
        //sort left and right subarray
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
    
}


int main()
{
    int t;  cin>>t;
    
    while(t--){
        
        int n;  cin>>n;
        int a[n];   f0(i,n) cin>>a[i];
        
        quicksort(a,0,n-1);
        
        f0(i,n) cout<<a[i]<<"\t";
        cout<<endl<<endl;
    }
    
    return 0;
}

