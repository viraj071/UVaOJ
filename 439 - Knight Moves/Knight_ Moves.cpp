/*
 * Knight_ Moves.cpp
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

ii source;
ii destination;

int dx[8]={2,-2,2,-2,1,-1,1,-1};
int dy[8]={1,1,-1,-1,2,2,-2,-2};
vector<vi> visited;

int bfs(){
	queue<pair<ii,int> > q;
	q = queue<pair<ii,int> >();
	q.push(pair<ii,int>(source,0));
	visited[source.first][source.second]=1;
	while(!q.empty()){
		pair<ii,int> x = q.front();
		q.pop();
		int tempx=x.first.first,tempy=x.first.second;
		if(tempx==destination.first&&tempy==destination.second){
			return x.second;
		}
		for(int i=0;i<8;++i){
			int cx = tempx+dx[i];
			int cy = tempy+dy[i];
			if(cx<0||cx>=8||cy<0||cy>=8||visited[cx][cy]){
				continue;
			}
			visited[cx][cy]=1;
			q.push(pair<ii,int>(ii(cx,cy),x.second+1));
		}
	}
	return -1;
}

int main(){
	string s,d;
	while(cin>>s>>d){
		visited = vector<vi> (8,vi(8,0));
		source.first=s[0]-'a';
		source.second=s[1]-'1';
		destination.first=d[0]-'a';
		destination.second=d[1]-'1';
		int ans = bfs();
		if(ans==-1)ans=0;
		cout<<"To get from "<<s<<" to "<<d<<" takes "<<ans<<" knight moves.\n";
	}
	return 0;
}


