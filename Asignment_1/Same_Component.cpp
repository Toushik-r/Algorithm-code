#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> grid ;
vector<vector<bool>> vis ;
vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}} ;
int n, m ;


bool valid(int i ,int j){
    if(i >= n || j >= m || i < 0 || j < 0) return false ;
    else return true ;
}
void dfs(int si ,int sj){
    
          vis[si][sj] = true ;
          for(int k = 0 ;k < 4;k++){
            int ci,cj ;
            ci =  si + d[k].first ;
            cj =  sj + d[k].second ;
             if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == '.') dfs(ci,cj) ;

          }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

cin >> n >> m ;
grid.assign( n , vector<char> (m));
vis.assign(n , vector<bool> (m ,false) ) ;

for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++) cin>> grid[i][j] ;
}


int si ,sj ,di ,dj ;
cin >> si >>sj ;
cin >> di >> dj ;
dfs(si,sj);

if( vis[di][dj] ) cout<< "YES\n";
else cout << "NO\n" ;

     
return 0;
}