//Longest Common Subsequence
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

#define pb push_back
#define f0(i,n) for(int i=0; i<n; ++i)
#define f1(i,n) for(int i=1; i<=n; ++i)

vector<vector <vector<char> > > lcs;

int main()
{
    int t;  cin>>t;
    cin.ignore();
    
    while(t--){
        lcs.clear();
        
        string x1,y1;
        getline(cin,x1);
        getline(cin,y1);
        int n=x1.size(), m=y1.size();
        
        //string to char with index starting from 1
        char x[n+1], y[m+1];
        f1(i,n)   x[i]=x1[i-1];
        f1(i,m)   y[i]=y1[i-1];
        
        vector<char>empty;
        vector<vector<char> >tempListOfObjects;
        f0(i,m+1) tempListOfObjects.pb(empty);
        f0(i,n+1) lcs.pb(tempListOfObjects);
        
        f1(i,n){
            f1(j,m){
                //either capacity = 0 or no character
                if(i==0 || j==0){
                    lcs[i][j]=empty;
                }
                
                //if end character matches
                else if(x[i]==y[j]){
                    
                    lcs[i][j]=lcs[i-1][j-1];
                    
                    //add new character
                    lcs[i][j].pb(x[i]);
                }
                else{
                    //matches second last and last element of str1, str2 respectively
                    vector<char>v1=lcs[i-1][j];
                    //matches last and second last element of str1, str2 respectively
                    vector<char>v2=lcs[i][j-1];
                    
                    if(v1.size() > v2.size())
                        lcs[i][j]=v1;
                    else
                        lcs[i][j]=v2;
                }
            }
        }
        
        int size=lcs[n][m].size();
        cout<<size<<": ";
        f0(i,size)  cout<<lcs[n][m][i]<<" ";
        cout<<endl;
    }
    
    return 0;
}


