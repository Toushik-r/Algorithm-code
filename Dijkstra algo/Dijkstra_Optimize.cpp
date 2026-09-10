#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > adj_list ;
vector<int> dis ;
const int INF = 1e9 ;
int a =0 ;
void dijkstra(int src){
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q ; // eta 1st element ke dhore sort kore age rakhe ..

    q.push({0,src}) ;
    dis[src] = 0 ;

    while( !q.empty() ){ a++ ;
        pair<int,int> f = q.top(); // priority queue te top thake ,front thake na 
        q.pop() ;
        int pn = f.second  ;
        int pd = f.first ;
          if( pd > dis[pn] ) continue ;
        for(auto it : adj_list[pn] ){
            int cn = it.first ;
            int cd = it.second ;

            if(pd+cd < dis[cn]){
                dis[cn] = pd+cd ;
                q.push({ dis[cn] , cn});
                 
            }
        }

    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     int n , e ;
     cin>> n >> e ;
     adj_list.assign(n , vector<pair<int,int> >() ) ;
     dis.assign(n , INF) ;

     while(e--){
        int u ,v , w ;
        cin>> u >> v >> w ;

         adj_list[u].push_back({v,w});
         adj_list[v].push_back({u,w});
     }
    int src ;cin>> src ;
    dijkstra(src) ;
    for(int i =0 ;i < n ;i++ ){
        if(dis[i] == INF) cout<< i<<" -> -1\n" ;
       else cout << i<<"-> " << dis[i] << " \n" ;
    }
  cout<<"\n"<<a ;
return 0;
}