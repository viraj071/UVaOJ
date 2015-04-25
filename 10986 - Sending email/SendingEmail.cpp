/*
 * SendingEmail.cpp
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
vector<long long> val;
vector<vector<pair<int,int> > > neighbors;
int t,n,m,s,x,y,v;

void dijkstras(int s,int t){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push(pair<int,int>(s,0));
	val[s]=0;
	while(!pq.empty()){
		pair<int,int> top = pq.top();
		pq.pop();
		for(int j=0;j<neighbors[top.first].size();++j){
			pair<int,int> x = neighbors[top.first][j];
			if(val[x.first]>x.second+val[top.first]){
				val[x.first]=x.second+val[top.first];
				pq.push(make_pair(x.first,val[x.first]));
			}
		}
	}
}


int main(){
	int cases;
	scanf("%d",&cases);
	for(int i=1;i<=cases;++i){
		scanf("%d %d %d %d",&n,&m,&s,&t);
		val = vector<long long>(n,INF);
		neighbors = vector<vector<pair<int,int> > > (n,vector<pair<int,int> >());
		while(m--){
			scanf("%d %d %d",&x,&y,&v);
			neighbors[x].push_back(make_pair(y,v));
			neighbors[y].push_back(make_pair(x,v));
		}
		dijkstras(s,t);
		if(val[t]==INF){
			cout<<"Case #"<<i<<": unreachable\n";
		}
		else{
			cout<<"Case #"<<i<<": "<<val[t]<<"\n";
		}
	}
	return 0;
}
