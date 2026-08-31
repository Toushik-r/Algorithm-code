#include<bits/stdc++.h>
using namespace std;
vector<vector<char>>  grid ;
vector<vector<bool >> vis ;
int n , m ;
vector<pair<int,int>> drc = {{1,0},{-1,0},{0,1},{0,-1}};

bool valid(int i , int  j ){
    if(i < 0 || i >= n || j < 0 || j >= m ) return false ;
    return true ;
}
void dfs(int i , int j ){
    cout <<i << ","<< j<< " -> "<< grid[i][j] << " ";
    vis[i][j] = true ;
       
    for(int k = 0 ; k< 4 ; k++){
        int ci , cj ;
        ci = i + drc[k].first;
        cj = j + drc[k].second;
        if( valid(ci , cj ) && !vis[ci][cj] ) dfs(ci , cj );   
    }

}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     
      cin >> n >> m ;
    grid.assign( n , vector< char>(m )  );
    vis.assign( n , vector<bool>(m , false) );
    

     for(int i =0 ; i < n ; i++)
         for(int j = 0 ; j < m ; j++)
               cin>> grid[i][j] ;

      
   int si ,sj ; cin >> si >> sj ;
   dfs(si , sj );
return 0;
}