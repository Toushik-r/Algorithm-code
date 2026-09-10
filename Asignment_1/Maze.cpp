#include<bits/stdc++.h>
using namespace std;

vector<vector<char>>  grid ;
vector<vector<bool >> vis ;
vector<vector<pair<int,int>>> parent ;
int n , m ;
int si,sj,di,dj ;
vector<pair<int,int>> drc = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


bool  valid(int x,int y ){
    return (x >= 0 && x < n && y >= 0 && y < m) ;

}
void bfs(int i ,int j ){


queue<pair<int,int>> q ;
q.push({i,j});
vis[i][j]= true ;
bool exit = false ;

while( !q.empty() ){
    
    pair<int,int> p = q.front();
    q.pop();

    int  pi ,pj ;
    pi = p.first;
    pj = p.second ;

  if(di == pi && dj == pj){
    exit =true ;
    break ;
  }
     

    for(int i = 0 ; i< 4 ;i++){
        int ci ,cj ;
        ci = pi + drc[i].first;
        cj = pj + drc[i].second ;
        if(valid(ci , cj ) && !vis[ci][cj] && grid[ci][cj] != '#'){
            
            vis[ci][cj] = true ;
            parent[ci][cj]= {pi,pj} ;
            q.push({ci, cj});
        }
    }

}

if( exit ){
    pair<int,int> a = parent[di][dj] ;
    int b = a.first ;
    int c = a.second ;
    while( !(b == si && c == sj) ){
            grid[b][c] = 'X' ;
            a = parent[b][c];
            b = a.first ;
            c = a.second ;
    }


}

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     
      cin >> n >> m ;
    grid.assign( n , vector< char>(m )  );
    vis.assign( n , vector<bool>(m , false) );
    parent.assign( n , vector<pair<int,int>>(m , {-1,-1}) );
   
    

     for(int i =0 ; i < n ; i++){
         for(int j = 0 ; j < m ; j++){

               cin>> grid[i][j] ;
               if(grid[i][j]=='R'){
                si = i ;
                sj = j;
               }
               else if(grid[i][j] == 'D'){
                di = i ;
                dj = j ;
               }

            }

        }

      bfs(si , sj );

       for(int i =0 ; i < n ; i++){
         for(int j = 0 ; j < m ; j++){

             cout<<grid[i][j] ;

            }
            cout<<endl ;

        }
return 0;
}