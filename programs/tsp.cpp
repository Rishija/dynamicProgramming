// TSP
#include<iostream>
#include<vector>
#include<map>
#include<math.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define f0(i,n) for(int i=0; i<n; ++i)


int n;
vector<vector<int> >cost;
vector<vector<pair<int, vector<int> > > >val;

pair<int,vector<int> > tsp(int source, vector<int>unvisitedNodes)
{
    // convert set to set number
    int setNo=0;
    f0(i,n) if(unvisitedNodes[i])  setNo+=pow(2,i);
    
    //if value not calculated yet
    if(val[source][setNo].fir==-1){
        
        //maximum cost set
        int minCost=1000000000;
        
        //vertex not visited yet with minimum cost for rest of the path
        int minIndex=-1;
        
        pair<int, vector<int> > prevAns;
        
        f0(i,n){
            
            //vertices not yet visited
            if(unvisitedNodes[i]){
                
                //mark current node as visited
                vector<int>newSet = unvisitedNodes;
                newSet[i]=0;
                
                //find cost and path from current node
                pair<int, vector<int> > newAns=tsp(i, newSet);
                
                int newCost= cost[source][i] + newAns.fir;
                if(newCost<minCost){
                    prevAns=newAns;
                    minCost=newCost;
                    minIndex=i;
                }
            }
        }
        
        //set new minimum cost and path from source
        val[source][setNo].fir=minCost;
        val[source][setNo].sec=prevAns.sec;
        val[source][setNo].sec.insert(val[source][setNo].sec.begin(),minIndex);
    }
    
    return val[source][setNo];
}


int main()
{
    int t;  cin>>t;
    while(t--){
        val.clear();
        cost.clear();
        cin>>n;
        
        //cost matrix
        vector<int>initialCost(n);
        f0(i,n) cost.pb(initialCost);
        
        f0(i,n) f0(j,n) cin>>cost[i][j];
        
        
        int power=pow(2,n);
        /*
         when set is empty, cost = cost(i,0) and path = {0}
         else cost = -1, path = {}
         */
        vector<int>empty;
        vector<int>pathIsZero; pathIsZero.pb(0);
        
        vector<pair<int, vector<int> > >tempSubset;
        //path={0} for 0th subset
        tempSubset.pb(mp(0,pathIsZero));
        //otheriwse {}
        f0(i,power-1)   tempSubset.pb(mp(-1, empty));
        
        //set cost
        f0(i,n){
            val.pb(tempSubset);
            val[i][0].fir=cost[i][0];
        }
        
        // when source is 0, unvisitedNodes={1,2,....n-1}
        vector<int>unvisitedNodes;
        f0(i,n) unvisitedNodes.pb(1);
        unvisitedNodes[0]=0;
        
        //final cost and path
        pair<int, vector<int> > ans = tsp(0, unvisitedNodes);
        
        cout<<"cost: "<<ans.fir<<endl;
        cout<<"0 -> ";
        f0(i,ans.sec.size()-1)  cout<<ans.sec[i]<<" -> ";
        cout<<ans.sec[ans.sec.size()-1]<<endl<<endl;
    }
    
    return 0;
}
