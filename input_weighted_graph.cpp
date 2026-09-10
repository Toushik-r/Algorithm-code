#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > adj_list ;
vector<bool> vis ;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     int n , e ;
     cin>> n >> e ;
     adj_list.assign(n , vector<pair<int,int> >() ) ;
     vis.assign(n , false) ;

     while(e--){
        int u ,v , w ;
        cin>> u >> v >> w ;

         adj_list[u].push_back({v,w});
         adj_list[v].push_back({u,w});
     }
     for(int i=0 ;i < n ; i++){
        cout << i <<"-> ";
        for(auto it : adj_list[i]){
            cout << it.first << " "<<it.second <<", ";
        }
        cout<<endl ;
     }
return 0;
}