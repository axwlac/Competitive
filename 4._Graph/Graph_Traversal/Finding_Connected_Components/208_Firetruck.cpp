#include <bits/stdc++.h>
using namespace std;
int d, contRoute; 
int Al[23][23];
bool visited[23];
vector<int> Route; 


void backtack(int u){
  
  if(u==d){
    contRoute++; 
    cout<<"1"; 
    for(int x=1;x<Route.size(); ++x){
      cout<<" "<<Route[x]; 
    }
    cout<<"\n"; 
    return; 
  }
  
  for(int k = 1; k < 21; ++k){
    if(Al[u][k] && !visited[k]){
      visited[k] = true;
      Route.push_back(k);
      backtack(k);
      Route.pop_back();
      visited[k] = false;
    }
  }
}

bool visitado[23];

void dfs(int u){
  for(int k = 1; k < 21; ++k){
    if(Al[u][k] && !visitado[k]){
      visitado[k] = true;
      dfs(k);
    }
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int  caso=0, i, j; 
  while(cin>> d){  
    memset(Al,0,sizeof(Al)); 
    memset(visited,0,sizeof(visited));
    memset(visitado, 0, sizeof(visitado));
    while(cin>>i>>j, (i || j)){
      Al[i][j] = 1; 
      Al[j][i] = 1;
    }
    cout<<"CASE "<<++caso<<":\n"; 
    visitado[1] = true;
    dfs(1);
    if(visitado[d]){
        visited[1] = true;
        contRoute=0; 
        Route.emplace_back(1); 
        backtack(1);
        Route.pop_back(); 
        cout<<"There are "<<contRoute<<" routes from the firestation to streetcorner "<<d<<".\n";
    }
    else{
        cout<<"There are 0 routes from the firestation to streetcorner "<<d<<".\n";
    }
  }
}