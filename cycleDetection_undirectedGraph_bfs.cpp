#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list ;
vector<bool> vis ;
vector<int> parent ;
bool flag ;

void bfs ( int src ){
    queue<int> q ;
    q.push(src) ;
    vis[src] = true ;
    while( !q.empty() ){
        int p = q.front() ;
        q.pop() ;

        for(int c : adj_list[p] ){
            if( !vis[c] ){
                q.push(c) ;
                vis[c] = true ;
                parent[c] = p ;
            }
            else if(parent[p] != c ) flag = true ;
        }
    }
    
}

bool isCycle(){
   flag = false ;
    for(int i = 0 ; i< adj_list.size() ;i++ ){
        if( !vis[i] ){
            
             bfs(i) ;
           
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