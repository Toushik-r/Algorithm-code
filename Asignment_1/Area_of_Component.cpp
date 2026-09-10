#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> grid ;
vector<vector<bool>> vis ;
vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}} ;
int n, m ,area ;
int dfs_cnt ;

bool valid(int i ,int j){
    if(i >= n || j >= m || i < 0 || j < 0) return false ;
    else return true ;
}
void dfs(int si ,int sj){
          dfs_cnt++ ;
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


area = INT_MAX ;
bool f =false;
for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
        if(!vis[i][j] && grid[i][j]== '.'){
              
              dfs_cnt = 0;
              dfs(i,j);
              area = min(area ,dfs_cnt );
              f = true ;
        }
    } 
}

if(f )cout<< area<<"\n" ;
else cout<< "-1\n";
     
return 0;
}