//Matrix Chain Multiplication
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

#define pb push_back
#define f0(i,n) for(int i=0; i<n; ++i)
#define f1(i,n) for(int i=1; i<=n; ++i)

vector< vector<int> > matrix(int n, int p[])
{
    int multiplication[n+1][n+1];
    vector< vector<int> >breakPoint;
    
    vector<int> zeroEntry;
    f0(i,n+1)   zeroEntry.pb(0);
    
    //Initialize multiplication and breakpoint
    f0(i,n+1)   breakPoint.pb(zeroEntry);
    f1(i,n+1)   multiplication[i][i]=0;
    
    for(int l=2; l<=n; ++l){
        
        f1(i, n-l+1){
            
            int j=i+l-1;
            multiplication[i][j]=1000000000;
            
            //number of multiplications for all possible combination
            for(int k=i; k<j; ++k){
                
                int q=multiplication[i][k]+multiplication[k+1][j]+p[i-1]*p[k]*p[j];
                
                //if new number is less than previous number
                if(q<multiplication[i][j]){
                    
                    //update number
                    multiplication[i][j]=q;
                    //add breakPoint
                    breakPoint[i][j]=k;
                }
            }
        }
    }
    
    /*
     Printing matrix `multiplication` and `breakPoint`
     
            f1(i,n){
                for(int j=i; j<=n; ++j)
                    cout<<setw(10)<<left<<multiplication[i][j];
                cout<<endl;
            }
            cout<<endl<<endl;
    
            f1(i,n){
                for(int j=i; j<=n; ++j)
                    if(i!=j)
                        cout<<breakPoint[i][j]<<"\t\t";
                cout<<endl;
            }
     */
    
    cout<<"\nrequired: "<<multiplication[1][n]<<endl;
    return breakPoint;
}

void printOrder(vector< vector<int> >breakPoint, int i, int j)
{
    if(i==j)
        cout<<" A"<<i<<" ";
    else{
        cout<<"( ";
        printOrder(breakPoint, i, breakPoint[i][j]);
        printOrder(breakPoint, breakPoint[i][j]+1, j);
        cout<<") ";
    }
}


int main()
{
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        int dimension[n+1];
        f0(i, n+1)  cin>>dimension[i];
        
        printOrder(matrix(n,dimension),1,n);
        cout<<endl<<endl;
    }
    
    return 0;
}
