#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

class Edge {
public:
	int u;
	int v;
};

void findRoot(list<Edge> &edges,int &root,int &len) {
	set<int> hash;
	for (auto &edge : edges) 
		hash.insert(edge.v);
	len = hash.size() + 1;
	for (auto &edge : edges) {
		if (find(hash.begin(), hash.end(), edge.u) == hash.end())
		{
			root = edge.u;
			return;
		}
	}
	return ;
}
list<int> Sort(list<Edge> edges) {
	int root, len;
	findRoot(edges, root, len);
	vector<int> vecs(len, 0);
	queue<int> qu; 
	qu.push(root);
	while (!qu.empty()) {
		int root = qu.front(); qu.pop();
		vecs[--len] = root;
		for(auto &edge : edges) {
			if (edge.u == root)
				qu.push(edge.v);
		}
	}
	return list<int>(vecs.begin(), vecs.end());
}
int main1() {
	list<Edge> edges;
	Edge edge;
	int n = 3;
	while (n--) {
		cin >> edge.u >> edge.v;
		edges.push_back(edge);
	}
	list<int> lst = Sort(edges);
	for (auto &l : lst)
		cout << l << endl;
	system("pause");
	return 0;
}