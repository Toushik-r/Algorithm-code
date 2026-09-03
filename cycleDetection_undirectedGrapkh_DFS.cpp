#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list ;
vector<bool> vis ;
vector<int> parent ;
bool flag ;

void dfs ( int src ){
    vis[src] = true ;

    for(int c : adj_list[src]){
        if( !vis[c] ){
            
            
            parent[c] = src ;
            dfs(c) ;
        }
        else if( parent[src] != c  ) flag = true ;
    }
    
}

bool isCycle(){
   flag = false ;
    for(int i = 0 ; i< adj_list.size() ;i++ ){
        if( !vis[i] ){
            
             dfs(i) ;
           
        }
    }
    
   return flag ;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     int n ,  e ;
     cin >> n >> e  ;

     adj_list.assign(n, vector<int>( ));
     vis.assign( n , false);
     parent.assign( n , -1);

     while(e--){
        int u , v ;
        cin>> u >> v ;
        adj_list[u].push_back(v) ;
        adj_list[v].push_back(u) ;
     }

     if( isCycle() ) cout<< "Cyclic \n" ;
     else cout << " Acyclic \n" ;
return 0;
}