

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int M = 1e9+7;
const int N = 1e6+10;

int main()
{
	ios_base::sync_with_stdio(0);
  	cin.tie(0);

  	
  	int n,m;
  	cin>>n>>m;

  	vector<pair<ll,ll>>adj[n + 1];

  	for(int i = 1;i<=m;i++){

  		ll a,b,c;
  		cin>>a>>b>>c;
  		adj[a].push_back({b,c});
  	}

  	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;

  	vector<ll>ways(n + 1,0);
  	pq.push({0,1});
  	ways[1] = 1;
  	vector<ll>distance(n + 1,LLONG_MAX);
  	vector<ll>max_flights(n + 1,LLONG_MIN);
  	vector<ll>min_flights(n + 1,LLONG_MAX);

  	distance[1] = 0;
  	max_flights[1] = 0,min_flights[1] = 0;
  	while(!pq.empty()){

  		ll u = pq.top().second;
  		ll d = pq.top().first;
  		pq.pop();
  		for(auto node : adj[u]){

  			if(distance[node.first] > d + node.second){
  				distance[node.first] = d + node.second;

  				pq.push({distance[node.first],node.first});
  				ways[node.first] = ways[u];
  				min_flights[node.first] = min_flights[u] +1;
  				max_flights[node.first] = max_flights[u] + 1;
  			}
  			else if(distance[node.first] == d + node.second){
  				ways[node.first] = (ways[u] + ways[node.first])%M;
  				min_flights[node.first] = min(min_flights[node.first],min_flights[u] + 1);
  				max_flights[node.first] = max(max_flights[node.first],max_flights[u] + 1);
  			}
  		}

  	}

  	cout<<distance[n]<<" "<<ways[n]<<" "<<min_flights[n]<<" "<<max_flights[n]<<"\n";
}