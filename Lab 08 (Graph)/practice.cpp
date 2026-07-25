#include<bits/stdc++.h>
using namespace std;

class Graph{

    int V;

    vector<vector<int>> l;

public:

    Graph(int vertices){

        V = vertices;

        l.resize(V);
    }

    void addEdge(int u, int v){

        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(int start){

        vector<bool> visited(V,false);

        queue<int> q;

        visited[start] = true;

        q.push(start);

        while(!q.empty()){

            int u = q.front();
            q.pop();

            cout << u << " ";

            for(int v : l[u]){

                if(!visited[v]){

                    visited[v] = true;

                    q.push(v);
                }
            }
        }
    }
};

int main(){

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.bfs(0);
}