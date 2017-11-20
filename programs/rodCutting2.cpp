// Rod cutting top-down approach
#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define pb push_back
#define fir first
#define sec second
#define f0(i,n) for(int i=0; i<n; ++i)
#define f1(i,n) for(int i=1; i<=n; ++i)

vector<pair<int, vector<int> > >value;

pair<int, vector<int> > rodcut(int n, int profit[])
{
    //value not calculated yet
    if(value[n].fir==(-1)){
        
        if(n==0){
            
            pair<int, vector<int> > nullPair;
            nullPair.fir=0;
            value[n]=nullPair;
        }
        else{
            
            int max=-1;
            int index=-1;
            pair<int, vector<int> >prevAns;
            
            //all cutting positions possible
            f1(i,n){
                
                //profit and list for cut at ith position
                pair<int, vector<int> >newAns = rodcut(n-i, profit);
                
                //profit calculated
                int newProfit = profit[i] + newAns.fir;
                
                if(newProfit > max){
                    max=newProfit;
                    index=i;
                    prevAns=newAns;
                }
            }
            value[n].fir=max;
            value[n].sec=prevAns.sec;
            value[n].sec.pb(index);
        }
    }
    
    return value[n];
}

int main()
{
    int t; cin>>t;
    while(t--){
        
        value.clear();
        int n;  cin>>n;
        int profit[n+1];
        f1(i,n) cin>>profit[i];
        
        //initially profit = -1 and splitList = {}
        pair<int, vector<int> >emptyPair;
        emptyPair.fir=-1;
        
        //initialized
        f0(i,n+1)   value.pb(emptyPair);
        
        pair<int, vector<int> > ans = rodcut(n, profit);
        
        cout<<"profit: "<<ans.fir<<"\nLength of subrods: ";
        f0(i, ans.sec.size())  cout<<ans.sec[i]<<" ";
        cout<<endl<<endl;
        
    }
    
    return 0;
}

