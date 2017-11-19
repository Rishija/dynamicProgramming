// 0/1knapsack
#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define f0(i,n) for(int i=0; i<n; ++i)
#define f1(i,n) for(int i=1; i<=n; ++i)

int main()
{
    int t;  cin>>t;
    while(t--){
        //capacity of bag
        int w;  cin>>w;
        //Number of objects
        int n;  cin>>n;
        
        int profit[n+1], weight[n+1];
        f1(i,n) cin>>profit[i];
        f1(i,n) cin>>weight[i];
        
        vector<int>emptyList;
        pair<int, vector<int> > emptyPair = mp(0,emptyList);
        
        //pair stores profit and list of objects
        vector< pair< int, vector<int> > >tempPairList;
        f0(i,w+1)   tempPairList.pb(emptyPair);
        
        //matrix of size (n+1)*(w+1) where each cell is a pair
        vector< vector< pair< int, vector<int> > > >knapSack;
        f0(i,n+1)   knapSack.pb(tempPairList);
        
        f0(i,n+1) f0(j,w+1){
            if(i==0 || j==0){
                knapSack[i][j]=emptyPair;
            }
            else if(weight[i]>j){
                knapSack[i][j]=knapSack[i-1][j];
            }
            else{
                //if ith object is added
                pair<int, vector<int> > v1 = knapSack[i-1][j-weight[i]];
                //add it's profit
                v1.fir+=profit[i];
                
                //without adding ith object
                pair<int, vector<int> > v2 = knapSack[i-1][j];
                
                if(v1.fir>v2.fir){
                    //add current object
                    (v1.sec).pb(i);
                    
                    //new profit and list of objects
                    knapSack[i][j]=v1;
                }
                else
                    knapSack[i][j]=v2;
            }
        }
        
        
        int minProfit=knapSack[n][w].fir;
        int size=knapSack[n][w].sec.size();
        
        cout<<"Profit: "<<minProfit<<endl<<"Objects: ";
        f0(i,size)  cout<<knapSack[n][w].sec[i]<<" ";
        cout<<endl<<endl;
    }
    
    return 0;
}

