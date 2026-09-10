#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> grid ;
vector<vector<int>> dis ;
vector<vector<bool>> vis ;
vector<pair<int, int>> d = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
{1, 2}, {1, -2}, {-1, 2}, {-1, -2} };
int n ,m ;

bool  valid(int x,int y ){
    return (x>= 0 && x < n && y >= 0 && y < m) ;

}
void bfs(int si,int sj){
    queue<pair<int,int>> q;
    q.push({si,sj}) ;
    vis[si][sj] = true ;
    dis[si][sj] = 0 ;
    while( !q.empty() ){
        pair<int,int> f = q.front() ;
        q.pop() ;
        int pi = f.first ;
        int pj = f.second ;
        for(int k = 0 ;k < 8 ;k++){
           int ci = pi + d[k].first ;
           int cj = pj + d[k].second ;

            if(valid(ci,cj) && !vis[ci][cj] ){
                q.push({ci,cj});
                vis[ci][cj] = true ;
                dis[ci][cj] = dis[pi][pj] + 1 ;
            }
        }
    }
}




int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     int t ;
     cin>> t ;
     while(t--){
        cin>> n >> m ;
        grid.assign(n, vector<int>(m)) ;
        dis.assign(n, vector<int>(m,-1));
        vis.assign(n, vector<bool>(m,false));

        int ki,kj ,qi ,qj ;
        cin >> ki >> kj >> qi >> qj ;
        
        bfs(ki,kj);
        cout<< dis[qi][qj]<<"\n" ;
     }
return 0;
}