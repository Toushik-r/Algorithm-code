#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > adj_list(1005);
vector<bool> vis(1005,false);
 
void dfs(int p){
         cout<< p << " ";
         vis[p] = true ; 
           
         for(int c : adj_list[p] ){
            if( !vis[c] ){
                dfs(c) ;
            }
         }
       

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     int n , e ; cin >> n >> e ;
     while(e--){
        int u , v ; cin>> u>> v ;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
     }
     int cnt = 0 ;
     for(int i =0 ; i < n ;i++){
        if( !vis[i] ){
            cnt++ ;
             dfs(i);
             cout<< "\n";
            }
     }
     cout << cnt <<endl ;
return 0;
}