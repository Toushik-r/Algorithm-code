#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     int n ,e ; cin>> n>> e;
     vector<pair<int,int>> edge_list;

     while(e--){
        int u ,v ; cin >> u >> v;
        edge_list.push_back({u , v });
     }
     for(auto x: edge_list){
        cout<< x.first << " " << x.second << endl;
      }
return 0;
}