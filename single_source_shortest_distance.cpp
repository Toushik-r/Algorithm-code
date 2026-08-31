#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list(1005);
vector<bool> vis(1005,false);
vector<int> dis(1005,-1) ;

void bfs(int src){
    queue<int> q ;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;

    while( !q.empty() ){
        int p = q.front() ;
        q.pop();

        for(int x : adj_list[p] ){
            if( !vis[x] ){
                q.push(x) ;
                vis[x] = true ;
                dis[x] = dis[p]+ 1;
            
            }
        }
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     int n ,e ; cin>> n >>  e ;
     while( e--){
        int u ,  v ;cin>> u >> v ;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    
    }
    int st ,dn ; cin >> st >> dn ;
    bfs(st) ;
    cout<< dis[dn] ;
return 0;
}