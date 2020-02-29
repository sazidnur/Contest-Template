///////BFS\\\\\\\

map <int, vector <int> > graph;
map <int, int> path;
map <int, int> level;
void bfs(int start){
	queue <int> q;
	q.push(start);
	level[start]=0;
	while(!q.empty()){
		int i, top=q.front();
		q.pop();
		for(i=0; i<graph[top].size(); i++){
			int v=graph[top][i];
			if(!level.count(v)){
				level[v]=level[top]+1;
				path[v]=top;
				q.push(v);
			}
		}
	}
}

void print(int start, int end){
	if(start==end){
		cout << end << " ";
		return;
	}
	print(start, path[end]);
	cout << end << " ";
}

int calc(int m){
	int cnt=0;
	map <int, int>::iterator it;
	for(it=level.begin(); it!=level.end(); it++){
		if(it->second <= m) cnt++;
	}
	return cnt;
}

int main()
{
    graph.clear();
    level.clear();
    path.clear();
    return 0;
}
