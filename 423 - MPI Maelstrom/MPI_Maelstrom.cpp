/*
 * MPI_Maelstrom.cpp
 *
 *  Created on: Apr 27, 2015
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
#define INF 1000000000

typedef bool (*comp)(int,int);

int n;
vector<vii> neighbors;
vi vals;

bool compare(int a,int b){
	return vals[a]>vals[b];
}

void dijkstras(){
	priority_queue<int,vi,comp> pq(compare);
	vals[0]=0;
	pq.push(0);
	while(!pq.empty()){
		int top = pq.top();
		pq.pop();
		for(int i=0;i<neighbors[top].size();++i){
			ii x = neighbors[top][i];
			int node = x.first;
			if(vals[node]>vals[top]+x.second){
				vals[node]=vals[top]+x.second;
				pq.push(node);
			}
		}
	}
}


int main(){
	scanf("%d",&n);
	neighbors = vector<vii> (n,vii());
	vals = vi(n,INF);
	string temp;
	for(int i=1;i<n;++i){
		for(int j=0;j<i;j++){
			cin>>temp;
			if(temp!="x"){
				int val;
				istringstream ss(temp);
				ss >> val;
				neighbors[i].push_back(ii(j,val));
				neighbors[j].push_back(ii(i,val));
			}
		}
	}
	dijkstras();
	int ans = *max_element(vals.begin(),vals.end());
	if(ans==INF){
		ans=0;
	}
	printf("%d\n",ans);
	return 0;
}
