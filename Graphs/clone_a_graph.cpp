/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}

 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the 
first node with val == 1, the second node with val == 2, and so on. The graph is represented in 
the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list 
describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as
 a reference to the cloned graph.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void bfs(Node *src){
	map<Node*, bool> visit;
    queue<Node*> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        Node *u = q.front();
        cout << "Node: " << u->val << " at address: " << u << "\n";
        q.pop();
        vector<Node *> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (!visit[v[i]])
            {
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    cout << endl;
}

Node* cloneGraph(Node* node) {
    if(node == NULL) return NULL;
    //unordered_map is used so that we don't copy nodes multiple times
    unordered_map<Node*, Node*> copies;
    
    Node *copy = new Node(node->val);
    copies[node] = copy;
    
    queue<Node *> q;
    q.push(node);
    
    while(!q.empty()){
        Node *cur = q.front();
        q.pop();
        
        for(Node *neighbor: cur->neighbors){
            if(copies.find(neighbor) == copies.end()){
                copies[neighbor] = new Node(neighbor->val);
                q.push(neighbor);
            }
            
            copies[cur]->neighbors.push_back(copies[neighbor]);
        }
    }
    
    return copy;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<Node*> vertices(n+1);
	for(int i = 1; i <= n; i++){
		Node *cur = new Node(i);
		vertices[i] = cur;
	}

	for(int i = 0; i < m; i++){
		int f,s;
		cin >> f >> s;
		vertices[f]->neighbors.push_back(vertices[s]);
		vertices[s]->neighbors.push_back(vertices[f]);
	}

	Node *copy = cloneGraph(vertices[1]);
	bfs(vertices[1]);
	bfs(copy);
	return 0;
}