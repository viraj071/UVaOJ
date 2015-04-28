/*
 * A_Node_Too_Far.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: viraj
 */

#include <stdio.h>
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

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF (1<<25)

map<int,vi> neighbors;
map<int,bool> visited;
int n;

void setFalse(){
	map<int,bool>::iterator it;
	for(it=visited.begin();it!=visited.end();++it){
		it->second=false;
	}
}

int bfs(int start,int ttl){
	int count=0;
	queue<ii> q;
	visited[start]=true;
	q.push(ii(start,ttl));
	while(!q.empty()){
		ii top = q.front();
		q.pop();
		int node = top.first;
		int tempttl = top.second;
		for(int i=0;i<neighbors[node].size()&&tempttl>=1;++i){
			if(!visited[neighbors[node][i]]){
				count++;
				visited[neighbors[node][i]]=true;
				q.push(ii(neighbors[node][i],tempttl-1));
			}
		}
	}
	return count;
}

int main(){
	scanf("%d",&n);
	int icase = 0;
	while(n!=0){
		visited.clear();
		neighbors.clear();
		for(int i=0;i<n;++i){
			int u,v;
			scanf("%d %d",&u,&v);
			neighbors[u].push_back(v);
			neighbors[v].push_back(u);
			visited[u]=false;
			visited[v]=false;
		}
		int node,ttl;
		while(true){
			scanf("%d %d",&node,&ttl);
			if(node==0&&ttl==0){
				break;
			}
			setFalse();
			icase++;
			int inodes=0;
			inodes = bfs(node,ttl);
			cout<<"Case "<<icase<<": "<<visited.size()-inodes-1<<" nodes not reachable from node "<<node<<" with TTL = "<<ttl<<"."<<endl;
		}
		scanf("%d",&n);
	}
	return 0;
}


