#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n ,e ; cin >> n >> e ;
int adj_mat [n][n] ;

memset(adj_mat, 0 , sizeof(adj_mat) );
for(int i =0 ; i<n ; i++){
    for(int j =0 ; j < n ; j++){
        if(i==j) adj_mat[i][j] = 1 ;
    }
   
}
while(e--){
    int u ,v ; cin >> u >> v;
    adj_mat[u][v] = 1; 
    adj_mat[v][u] = 1; 
}
for(int i =0 ; i<n ; i++){
    for(int j =0 ; j < n ; j++){
        cout<< adj_mat[i][j] << " ";
    }
    cout<< "\n";
}
     
return 0;
}