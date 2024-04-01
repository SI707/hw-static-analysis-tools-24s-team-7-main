#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/* Function that is supposed to find the vertex with the minimum
distance value from set of vertices not yet in shortest path tree
*/

int minDistance(vector<int>& dist, vector<bool>& sptSet, int V) 
{
    int minIndex, minDist = INT_MAX;


    //iterating through the vertices to find the min distance
    for (int v = 0; v < V; ++v) 
    {
        //supposed to check if the vertex is not in the shortest path tree
        //distance is < current minimum distance
        if (!sptSet[v] && dist[v] < minDist) 
        {
            minDist = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

//Function that prints the path from source to the given vertex
void printPath(vector<int>& parent, int j, vector<string>& cities) 
{
    if (parent[j] == -1) 
    {
        cout << cities[j] << " ";
        return;
    }

    printPath(parent, parent[j], cities);
    cout << cities[j] << " ";
}

//Main objective of project: Djikstra's algorithm implementation using arrays
//Mention this to message in treyce
void dijkstraArray(vector<vector<int> >& graph, int src, int V, vector<string>& cities) 
{
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);
    vector<int> parent(V, -1);

    dist[src] = 0;

    //iterate through all of the vertices
    for (int count = 0; count < V - 1; ++count) 
    {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        //using a for loop to update the distance values and parent for adjacent vertices
        for (int v = 0; v < V; ++v) 
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
            {
                //updating the distance and parent
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

   //printing the shortest path
    printPath(parent, V - 1, cities);
    cout << dist[V - 1] << endl;
}


int main() 
{
    int K; 
    cin >> K >> ws; 

    for (int k = 0; k < K; ++k) 
    {
        int n; 
        cin >> n >> ws; 

        vector<string> cityNames(n); 
        vector<vector<int> > graph(n, vector<int>(n));

        //input city names
        for (int i = 0; i < n; ++i) 
        {
            getline(cin, cityNames[i]);
        }

        //input adjancency matrix representing the graph
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                cin >> graph[i][j];
            }
        }

        //using the algorithm to find the shortest path
        dijkstraArray(graph, 0, n, cityNames);
    }

    return 0;
}
