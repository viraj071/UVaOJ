/*
 * Network.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: viraj
 */



#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define INF 1000000000

using namespace std;

vector<vector<int> > neighbors;
vector<bool> visited;
int nodes;

int getvisitedtotal(){
	int total=0;
	for(int i=0;i<visited.size();++i){
		if(visited[i]){
			total++;
		}
	}
	return total;
}

void dfs(int source,int ignore){
	visited = vector<bool> (nodes,false);
	stack<int> st;
	st.push(source);
	while(!st.empty()){
		int node = st.top();
		st.pop();
		visited[node]=true;
		for(int j=0;j<neighbors[node].size();++j){
			if(neighbors[node][j]!=ignore&&!visited[neighbors[node][j]]){
				st.push(neighbors[node][j]);
			}
		}
	}
}


int main(){
	while(true){
		scanf("%d",&nodes);
		if(nodes==0){
			break;
		}
		neighbors = vector<vector<int> > (nodes,vector<int> ());
		string temp;
		while(getline(cin,temp)){
			if(temp=="0"){
				break;
			}
			//cout<<temp<<endl;
			istringstream ss(temp);
			int source;
			ss >> source;
			int neighbor;
			while(ss >> neighbor){
				neighbors[source-1].push_back(neighbor-1);
				neighbors[neighbor-1].push_back(source-1);
			}
		}
		int ans=0;
		for(int i=0;i<nodes;++i){
			if(i==0){
				dfs(1,0);
			}
			else{
				dfs(0,i);
			}
			int nnodes = getvisitedtotal();
			if(nnodes<(nodes-1)){

				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
