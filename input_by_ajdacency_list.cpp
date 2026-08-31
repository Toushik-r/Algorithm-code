#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     int n ,e ; 
     cin >> n >>e ;
     vector<int> adj_list[n] ;


     while(e--){
        int u ,v ; cin>> u >> v ;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
     }
     for(int i =0 ; i<n ; i++){
        cout<< i << "-> " ;
        for(int x: adj_list[i])
               cout<< x <<" ";

        cout<<"\n";       
     }
return 0;
}