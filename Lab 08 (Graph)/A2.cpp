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

    bool hasCycleBFS() {
        bool visited[V] = {false};
        for(int start = 0; start < V; start++) {
            if(!visited[start]) {
                Queue q;
                int parent[V];
                for(int i = 0; i < V; i++) parent[i] = -1;

                q.push(start);  
                visited[start] = true;

                while(!q.isEmpty()) {
                    int u = q.pop();
                    for(int i = 0; i <= l[u].front; i++) {
                        int v = l[u].arr[i];
                        if(!visited[v]) {
                            visited[v] = true;
                            parent[v] = u;
                            q.push(v);
                        }
                        else if(parent[u] != v) {
                            cout << "Cycle detected!\n";
                            printCycle(u, v, parent);
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    void printCycle(int u, int v, int parent[]) {
        cout << "Cycle: ";
        int path1[100], path2[100];
        int i = 0, j = 0;

        int temp = u;
        while(temp != -1) {
            path1[i++] = temp;
            temp = parent[temp];
        }

        temp = v;
        while(temp != -1) {
            path2[j++] = temp;
            temp = parent[temp];
        }

        int x = i - 1, y = j - 1;
        while(x >= 0 && y >= 0 && path1[x] == path2[y]) {
            x--; y--;
        }
        x++; 
        y++;
        for(int k = 0; k <= x; k++)
            cout << path1[k] << " ";

        for(int k = y-1; k >= 0; k--)
            cout << path2[k] << " ";

        cout << endl;
    }
};


int main(){
    Graph g(8);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(5, 6);
    g.addEdge(4, 7);
    g.addEdge(6, 7);

    g.display();

    if(!g.hasCycleBFS()){
        cout << "No Cycle detected\n";
    }

    
}