

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int M = 1e9+7;
const int N = 1e6+10;

struct Edge{

	ll u,v,d;

	Edge(ll u,ll v,ll d) : u(u),v(v),d(d) {}
};

bool compare(Edge e1,Edge e2){

	return e1.d < e2.d;
}

ll find(vector<ll>&parent,ll p){

	if(parent[p]!=p)
		p = find(parent,parent[p]);
	return p;
}
ll ans;
void unionBySize(ll u,ll v,ll d,vector<ll>&parent,vector<ll>&size){

	ll pu = find(parent,u);
	ll pv = find(parent,v);

	if(pu == pv)
		return;
	if(size[pu] < size[pv]){
		parent[pu] = pv;
		size[pv]+=size[pu];
		ans = ans + d;
	}
	else{

		parent[pv] = pu;
		size[pu]+=size[pv];
		ans = ans + d;
		
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
  	cin.tie(0);

 	
 	ll n,m;
 	cin>>n>>m;
 	vector<Edge>edges;

 	vector<ll>parent(n + 1);
  	vector<ll>size(n +1,1);
  	
  	for(ll i = 1;i<=n;i++)
  		parent[i] = i;

 	for(ll i = 1;i<=m;i++){

 		ll u,v,d;
 		cin>>u>>v>>d;

 		edges.push_back(Edge(u,v,d));
 	}
 	sort(edges.begin(),edges.end(),compare);

 	for(auto e : edges){

 		unionBySize(e.u,e.v,e.d,parent,size);
 	}
 	int components = 0;	
 	for(int i = 1;i<=n;i++){
 		if(i == parent[i])
 			components++;
 	}
 	if(components == 1)
 		cout<<ans<<"\n";
 	else
 		cout<<"IMPOSSIBLE"<<"\n";
}