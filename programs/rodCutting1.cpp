// Rod cutting bottom-up approach
#include<iostream>
using namespace std;

#define f0(i,n) for(int i=0; i<n; ++i)
#define f1(i,n) for(int i=1; i<=n; ++i)

int main()
{
    int t; cin>>t;
    while(t--){
        int n;  cin>>n;
        //profit for each length
        int profit[n];
        f1(i,n) cin>>profit[i];
        
        //value[i] stores max profit for rod of length `i`
        //breakPoint[i] stores last cutting position for rod of length `i`
        int value[n+1], breakPoint[n+1];
        value[0]=0; breakPoint[0]=0;
        
        f1(length,n){
            int max=-1;
            f1(cutPosition,length){
                int newProfit = profit[cutPosition]+value[length-cutPosition];
                if(newProfit > max){
                    max=newProfit;
                    breakPoint[length]=cutPosition;
                }
            }
            value[length]=max;
        }
        
        f1(count, n){
            int i=count;
            printf("\nn: %d\nProfit: %d\nDistribution: ", i, value[i]);
            while(i>0){
                cout<<breakPoint[i]<<" ";
                i-=breakPoint[i];
            }
            cout<<endl;
        }
        cout<<"***********************************"<<endl;
    }
    return 0;
}

