#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
private:
    int num_vertex;
    vector<vector<int>> AdjList;
    int *color;
    int *discover;
    int *finish;
    int *predecessor;
    int *t;
public:
    Graph():num_vertex(0){};
    Graph(int n):num_vertex(n){
        AdjList.resize(n);
    };
    void AddEdgelist(int from, int to);
    void DFS(int start);
    void DFSvisit(int vertex);
    int* visitorder();
};

void Graph::AddEdgelist(int from, int to)
{
    AdjList[from].push_back(to);
    //cout << AdjList[from][0];
}

void Graph::DFS(int start)
{
    color = new int[num_vertex];
    discover = new int[num_vertex];
    finish = new int[num_vertex];
    predecessor = new int[num_vertex];
    
    //cout << "check" << endl;    
        
    t = new int;
    *t = 0;
    //cout << "ok" << endl;
    for(int i = 0;i < num_vertex;i++)
    {
        color[i] = 0;
        discover[i] = 0;
        finish[i] = 0;
        predecessor[i] = -1;
    }
    //cout << "ok" << endl;
    int i = start;
    
    for(int j = 0;j < num_vertex;j++)
    {
        //cout << i << endl;
        if(color[i] == 0)
            DFSvisit(i);
        i = j;
    }
    
    cout << "\ndiscover time:" << endl;  
    for (int i = 0; i < num_vertex; i++)
    {
        cout << "  " << discover[i];
    }
    
}

void Graph::DFSvisit(int vertex)
{
    //cout << vertex << endl;
    //cout << "ok" << endl;
    color[vertex] = 1;
    discover[vertex] = ++(*t);
    
    for(int i = 0;i < AdjList[vertex].size();i++)
    {
        //cout << AdjList[vertex][i] << endl;
        if(color[AdjList[vertex][i]] == 0)
        {
            predecessor[AdjList[vertex][i]] = vertex;
            DFSvisit(AdjList[vertex][i]);
        }
    }
    color[vertex] = 2;
    finish[vertex] = (*t)++;
}

int* Graph::visitorder()
{
    int order[num_vertex];
    for(int i = 0;i < num_vertex;i++)
        order[i] = discover[i];
    sort(order, order+num_vertex);
    
    int *index = new int[num_vertex];
    for(int i = 0;i < num_vertex;i++)
    {
        for(int j = 0;j < num_vertex;j++)
        {
            if(order[i] == discover[j])
                index[i] = j;
        }
    }
    return index;
}

int main ()
{
    
    Graph g2(8);
    g2.AddEdgelist(0, 1);g2.AddEdgelist(0, 2); 
    g2.AddEdgelist(1, 3);
    g2.AddEdgelist(2, 1);g2.AddEdgelist(2, 5);
    g2.AddEdgelist(3, 4);g2.AddEdgelist(3, 5);
    g2.AddEdgelist(5, 1);
    g2.AddEdgelist(6, 4);g2.AddEdgelist(6, 7);
    g2.AddEdgelist(7, 6);
    
    g2.DFS(0);
    //addEdgelist(AdjList, 4, 3);
    //cout << (*AdjList)[1][0] << endl;
    
    
    return 0;
}
