

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int M = 1e9+7;
const int N = 1e6+10;

int components,max_size;

int find(vector<int>&parent,int p){

	if(parent[p]!=p)
		p = find(parent,parent[p]);
	return p;
}

void unionBySize(int u,int v,vector<int>&parent,vector<int>&size){

	int pu = find(parent,u);
	int pv = find(parent,v);

	if(pu == pv)
		return;
	if(size[pu] < size[pv]){
		parent[pu] = pv;
		size[pv]+=size[pu];
		max_size = max(max_size,size[pv]);
		components--;
	}
	else{

		parent[pv] = pu;
		size[pu]+=size[pv];
		max_size = max(max_size,size[pu]);
		components--;
	}




}
int main()
{
	ios_base::sync_with_stdio(0);
  	cin.tie(0);

  	int n,m;
  	cin>>n>>m;

  	vector<int>parent(n + 1);
  	vector<int>size(n +1,1);
  	components = n,max_size = 1;
  	for(int i = 1;i<=n;i++)
  		parent[i] = i;


  	for(int i = 1;i<=m;i++){
  		int u,v;
  		cin>>u>>v;

  		unionBySize(u,v,parent,size);
  		cout<<components<<" "<<max_size<<"\n";
  	}

}