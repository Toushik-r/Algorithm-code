#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list ;
vector<bool> vis ;
vector<bool> path ;
int n ,e ;
bool f ; 

void dfs(int src){
    vis[src] = true ;
    path[src] = true ;
    for(int c : adj_list[src]){
        if( !vis[c] ){
            
            dfs(c);
           
        }
        else if( vis[c] && path[c]  ) f = true ;
    } 
    path[src] = false ;
}

bool isCycle(){
      f = false ;
     for(int i = 0 ; i < n ; i++){
        if( !vis[i]) dfs(i) ;
     }
     return f ;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     
     cin >> n>> e  ;

     adj_list.assign(n , vector<int>());
     vis.assign(n,false);
     path.assign(n,false);

     while(e--){
        int u , v ;
        cin >> u >>v  ;
        adj_list[u].push_back(v) ;
     }

    if( isCycle() ) cout<< "Cyclic\n";
    else cout<<"Acyclic\n";
     
return 0;
}