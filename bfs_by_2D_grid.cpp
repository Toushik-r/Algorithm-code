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
void bfs(int i ,int j ){


queue<pair<int,int>> q ;
q.push({i,j});
vis[i][j]= true ;

while( !q.empty() ){
    
    pair<int,int> p = q.front();
    q.pop();

    int  pi ,pj ;
    pi = p.first;
    pj = p.second ;


    cout << pi << "," << pj <<" -> "<< grid[pi][pj] << " \n" ;
     

    for(int i = 0 ; i< 4 ;i++){
        int ci ,cj ;
        ci = pi + drc[i].first;
        cj = pj + drc[i].second ;
        if(valid(ci , cj ) && !vis[ci][cj] ){
            // bfs(ci , cj); // bfs diye dfs er kaj kora ,, mane etake rakhle dfs output ase...
            q.push({ci, cj});
            vis[ci][cj] = true ;
        }
    }

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
   bfs(si , sj );
return 0;
}