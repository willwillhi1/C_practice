#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
private:
    vector<vector<int>> Adjlist;
    int *distance;
    int *color;
    int *predecessor;
    int vertex_num;
public:
    Graph():vertex_num(0){};
    Graph(int n):vertex_num(n){
        Adjlist.resize(vertex_num);
    }
    void AddList(int from, int to);
    void BFS(int start);
};

void Graph::AddList(int from, int to)
{
    Adjlist[from].push_back(to);
    return;
}

void Graph::BFS(int start)
{
    distance = new int[vertex_num];
    color = new int[vertex_num];
    predecessor = new int[vertex_num];
    
    for(int i = 0;i < vertex_num;i++)
    {
        distance[i] = vertex_num - 1;
        color[i] = 0;
        predecessor[i] = -1;
    }
    
    queue<int> q;
    int i = start;
    
    for(int j = 0;j < vertex_num;j++)
    {
        if(color[j] == 0)
        {
            color[j] = 1;
            distance[j] = 0;
            q.push(j);
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(int k = 0;k < Adjlist[u].size();k++)
                {
                    if(color[Adjlist[u][k]] == 0)
                    {
                        color[Adjlist[u][k]] = 1;
                        distance[Adjlist[u][k]] = distance[u] + 1;
                        predecessor[Adjlist[u][k]] = u;
                        q.push(Adjlist[u][k]);
                    }
                }
                color[u] = 2;
            }
        }
        i = j;
    }
    
    for(int a = 0;a < vertex_num;a++)
    {
        cout << distance[a] << "  ";
    }
    cout << endl;
}

int main()
{
    Graph g1(9);    
    
    g1.AddList(0, 1);g1.AddList(0, 2);g1.AddList(0, 3);
    g1.AddList(1, 0);g1.AddList(1, 4);
    g1.AddList(2, 0);g1.AddList(2, 4);g1.AddList(2, 5);g1.AddList(2, 6);g1.AddList(2, 7);
    g1.AddList(3, 0);g1.AddList(3, 7);
    g1.AddList(4, 1);g1.AddList(4, 2);g1.AddList(4, 5);
    g1.AddList(5, 2);g1.AddList(5, 4);g1.AddList(5, 8);
    g1.AddList(6, 2);g1.AddList(6, 7);g1.AddList(6, 8);
    g1.AddList(7, 2);g1.AddList(7, 3);g1.AddList(7, 6);
    g1.AddList(8, 5);g1.AddList(8, 6);

    g1.BFS(0);    
    
    

    return 0;
}
