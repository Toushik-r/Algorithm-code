#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list(1005) ;
vector<bool> vis(1005,false) ;
void bfs(int src){
    queue<int> q;
    q.push(src) ;
      vis[src] = true ;
    while( !q.empty() ){
        int p = q.front();
        q.pop();

           cout<< p <<" ";  //kaj
           

           for(int child : adj_list[p] ){
            if( !vis[child] ) {
                q.push(child) ;
                vis[child] = true ;
            }
           }


    }

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n ,e ;cin>> n >> e ;


while(e--){
    int u , v ; cin>> u>> v ;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

bfs(0);

     
return 0;
}