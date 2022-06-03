#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool BFS(vector<vector<int>> &graph, int index, vector<int> &colorArr)
{
    colorArr[index] = 1;
    queue<int> Q;
    Q.push(index);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < graph[u].size(); i++)
        {
            if (colorArr[graph[u][i]] == -1)
            {
                colorArr[graph[u][i]] = 1 - colorArr[u];
                Q.push(graph[u][i]);
            }
            else if (colorArr[graph[u][i]] == colorArr[u])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> graph)
{
    unsigned int n = graph.size();
    vector<int> colorArr(n, -1);
    //...................
    for (int i = 0; i < n; i++)
    {
        if (colorArr[i] == -1)
        {
            if (BFS(graph, i, colorArr) == false)
            {
                return false;
            }
        }
    }
    //..................
    return true;
}

int main()
{
    int G[][4] = { { 0, 1, 0, 0 },
                   { 1, 0, 0, 0 },
                   { 0, 0, 0, 0 },
                   { 0, 0, 0, 0 } };
    int n = 1;

    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (G[i][j])
                graph[i].push_back(j);
        }
    }
    // cout<<graph.size();
    isBipartite(graph) ? cout << "Yes" : cout << "No";
}