#include <iostream>
#include <vector>
using namespace std;

void ssp(vector<pair<int, int>> g[], int v)
{
    vector<int> dist(v, INT16_MAX);
    dist[0] = 0; // source
    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < v; j++)
        {
            for (auto x : g[j])
            {
                int u = j;
                int v = x.first;
                int w = x.second;

                if (dist[u] != INT16_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int j = 0; j < v; j++)
    {
        for (auto x : g[j])
        {
            int u = j;
            int v = x.first;
            int w = x.second;

            if (dist[u] != INT16_MAX && dist[u] + w < dist[v])
            {
                cout<<"graph contains -ve cycle \n";
                return;
            }
        }
    }

    for (auto i : dist)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<pair<int, int>> g[6];
    int e;
    cout << "enter no of edges : ";
    cin >> e;
    cout << endl;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cout << "enter s d w \n";
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
    }

    ssp(g, 6);

    return 0;
}

/*
nter no of edges : 9

enter s d w
0
1
6
enter s d w
0
2
4
enter s d w
0
3
5
enter s d w
1
4
-1
enter s d w
2
1
-2
enter s d w
2
4

3
enter s d w
3
2
-2
enter s d w
3
5
-1
enter s d w
4
5
3
0 1 3 5 0 3
PS C:\Users\Lenovo\Desktop\code\dsa\graph>
*/