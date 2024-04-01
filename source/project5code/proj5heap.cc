#include <iostream>
#include <vector>
#include <queue>
#include <climits>

/*used  a parent vector to store the predecessor of each vertex
//basically serves as a lookup table bc I can trace back 
path from destination to the source
*/


using namespace std;

//function to print the path from the destination to the source
//by using a parent vector
void printPath(vector<int>& parent, int j, vector<string>& cities) 
{
    //best case
    if (parent[j] == -1) 
    {
        cout << cities[j] << " ";
        return;
    }

    //recur call
    printPath(parent, parent[j], cities);
    //printing out city names (current cities)
    cout << cities[j] << " ";
}


//implementation using min heap (priority queue)
void dijkstraHeap(vector<vector<int> >& graph, int src, int V, vector<string>& cities) 
{
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    //push the source vertex with distance 0 to priority queue
    pq.push(make_pair(0,src));
    dist[src] = 0;

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < V; ++v) 
        {
            //check if there is a shorter path to v through u
            if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
            {
                //updating dist and parent, then push that to priority queue
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }


    //cout << "Shortest path from " << cities[0] << " to " << cities[V - 1] << ": ";
    printPath(parent, V - 1, cities);
    cout <<  dist[V - 1] << endl;
}

int main() 
{
    //inputting test cases
    int K; 
    cin >> K;

    for (int k = 0; k < K; ++k) 
    {
        //input num of vertices
        int n; 
        cin >> n;

        vector<string> cityNames(n); 
        vector<vector<int> > graph(n, vector<int>(n));

        //input city names
        for (int i = 0; i < n; ++i) 
        {
            cin >> cityNames[i];
        }

        //adjacency matrix to represent the actual graph
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                cin >> graph[i][j];
            }
        }

        //applying the min heap to find the shortest path
        dijkstraHeap(graph, 0, n, cityNames);
    }

    return 0;
}
