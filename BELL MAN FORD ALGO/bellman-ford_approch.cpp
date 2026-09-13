#include<bits/stdc++.h>
using namespace std;
class Edge{
    public :
      int a,b,c ; 
      Edge(int a,int b ,int c){
        this->a= a;
        this -> b = b ;
        this -> c= c ;
      }

};
int n ,e  ;
vector<int> dis ;
vector<Edge> edge_list ;
int INF = INT_MAX ;


void bellman_ford(){

    dis[0]= 0 ;
    for(int i =0 ; i < n-1 ; i++){
        for(auto ed : edge_list){
            int a = ed.a ;
            int b = ed.b ;
            int c = ed.c ;
            if( dis[a] != INF && dis[a] + c < dis[b]) dis[b] = dis[a] + c ;
        }
    }


    bool cycle = false ;
    for(auto ed : edge_list){
            int a = ed.a ;
            int b = ed.b ;
            int c = ed.c ;
            if( dis[a] != INF && dis[a] + c < dis[b]) cycle = true ;
        }         


   if(cycle) cout<<"Negative weighted cycle detected. \n" ;
   else{
        for(int i = 0  ; i < n ; i++){
             cout<<i<<"->"<< dis[i] << " \n";
        }
    }
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
   
      
      cin >> n >> e ;
      
      dis.assign(n,INF);
      while(e--){
             int a,b,c ;
             cin >> a>> b>> c ;
             edge_list.push_back( Edge(a,b,c) );
           //  edge_list.push_back( Edge(b,a,c) ); //undirected graph hole .....

       }
     
      bellman_ford() ;
     
return 0;
}