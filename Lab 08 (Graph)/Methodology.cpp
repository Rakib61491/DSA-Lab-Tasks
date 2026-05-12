#include<iostream>
using namespace std;

class Stack{
public:
    int* arr;
    int front;

    Stack(){
        arr = new int[100];
        front = -1;
    }

    ~Stack() {delete[] arr;}

    void push(int a){
        arr[++front] = a;
    }

    bool isEmpty(){
        return front == -1;
    }

    int pop(){
        int val = arr[front];
        --front;
        return val;
    }

    void show(){
        for(int i=0; i<=front; i++)
            cout << arr[i] << " ";
    }
};

class Queue{
public:
    int* arr;
    int front, rear;

    Queue(){
        arr = new int[100];
        front = 0;
        rear = -1;
    }

    ~Queue() {delete[] arr;}

    void push(int a){
        arr[++rear] = a;
    }

    bool isEmpty(){
        return front>rear;
    }

    int pop(){
        int val = arr[front];
        ++front;
        return val;
    }
};

class Graph{
    int V;
    Stack* l;
public:
    Graph(int val){
        V = val;
        l = new Stack[V];
    }

    void addEdge(int u, int v){
        l[u].push(v);
        l[v].push(u);
    }

    void display(){
        for(int i=0; i<V; i++){
            if(!l[i].isEmpty()){
                cout << "Node " << i << " : ";
                l[i].show();
                cout << endl;
            }
        }
    }

    void bfs(){
        Queue res;
        bool visited[V] = {false};
        res.push(0);
        while(!res.isEmpty()){
            int u = res.pop();
            cout << u << " ";
            visited[u] = true;
            for(int i=0; i <= l[u].front; i++){
                int v = l[u].arr[i];
                if(!visited[v]){
                    visited[v] = true;
                    res.push(v);
                }
            }
        }
    }

    void dfs(){
        Stack res;
        bool visited[V] = {false};
        res.push(0);
        while(!res.isEmpty()){
            int u = res.pop();
            cout << u << " ";
            visited[u] = true;
            for(int i=0; i <= l[u].front; i++){
                int v = l[u].arr[i];
                if(!visited[v]){
                    visited[v] = true;
                    res.push(v);
                }
            }
        }
    }

    void shortestPath(int start, int target){
        Queue q;
        bool visited[V] = {false};
        int parent[V];

        for(int i = 0; i < V; i++)
            parent[i] = -1;

        q.push(start);
        visited[start] = true;

        while(!q.isEmpty()){
            int u = q.pop();

            for(int i = 0; i <= l[u].front; i++){
                int v = l[u].arr[i];

                if(!visited[v]){
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);

                    if(v == target)
                        break;
                }
            }
        }

        if(!visited[target]){
            cout << "No path exists";
            return;
        }

        int path[V];
        int idx = 0;

        for(int v = target; v != -1; v = parent[v])
            path[idx++] = v;

        for(int i = idx - 1; i >= 0; i--)
            cout << path[i] << " ";
    }

    void bfsLevels(int start){
        Queue q;
        bool visited[V] = {false};

        q.push(start);
        visited[start] = true;

        int level = 0;

        while(!q.isEmpty()){
            int size = 0;

            for(int i = q.front; i <= q.rear; i++)
                size++;

            cout << "Level " << level << " : " << size << " nodes\n";

            for(int i = 0; i < size; i++){
                int u = q.pop();
                cout << u << " ";

                for(int j = 0; j <= l[u].front; j++){
                    int v = l[u].arr[j];

                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }

            cout << endl;
            level++;
        }
    }
};


int main(){
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    g.display();

    cout << "BFS : ";
    g.bfs();

    cout << "\nDFS : ";
    g.dfs();

    cout << endl;
    g.shortestPath(0, 5);
    cout << endl;
    g.shortestPath(0, 3);
    cout << endl;
    g.shortestPath(4, 3);
    cout << endl;

    g.bfsLevels(0);
    g.bfsLevels(4);
    g.bfsLevels(3);
}