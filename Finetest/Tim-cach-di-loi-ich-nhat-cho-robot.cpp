#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[1005][1005], dist[1005], total[1005]; // graph[i][j]: do dai duong di giua 2 dinh i va j, dist[i]: do dai duong di tu dinh 1 den dinh i, total[i]: tong phan thuong tu dinh 1 den dinh i
bool picked[1005];                              // picked[i]: dinh i da xet hay chua
int reward[1005];                               // reward[i]: Gia tri phan thuong tai dinh i
int last[1005];                                 // last[i]: dinh truoc khi duyet i

// Tim dinh co khoang cach tu 1 den dinh do ngan nhat va tong gia tri phan thuong la lon nhat neu dinh do chua duoc tham
int minDistance(int dist[], int total[], bool picked[])
{
    int min = INT_MAX, min_index = -1, max_total = INT_MIN;
    for (int v = 1; v <= n; v++)
    {
        if (!picked[v])
        {
            if (dist[v] < min || (dist[v] == min && total[v] > max_total))
            {
                min = dist[v];
                max_total = total[v];
                min_index = v;
            }
        }
    }
    return min_index;
}

// In duong di ngan nhat tu 1 den n
void printShortestPath()
{
    printf("Shortest path from src = 1 to target = %d: ", n);
    vector<int> path;
    int i = n;
    while (i != -1)
    {
        path.push_back(i);
        i = last[i];
    }
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}

// In ra duong di ngan nhat va tong gia tri phan thuong lon nhat tu dinh 1 den cac dinh con lai
void printSolution(int dist[], int total[], int n)
{
    printf("Vertex\t\t Distance from Source\t\t Max reward\n");
    for (int i = 1; i <= n; i++)
        printf("%d \t\t %d \t\t\t\t %d\n", i, dist[i], total[i]);

    printShortestPath();
}

void Dijkstra(int src)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX, picked[i] = false, total[i] = 0, last[i] = -1;
    dist[src] = 0;
    total[src] = reward[src];
    last[src] = -1;

    for (int i = 1; i <= n - 1; i++)
    {
        int u = minDistance(dist, total, picked);
        if (u == -1)
            break;
        picked[u] = true;

        for (int v = 1; v <= n; v++)
            if (!picked[v] && graph[u][v] != -1 && dist[u] != INT_MAX)
            {
                if (dist[u] + graph[u][v] < dist[v] || (dist[v] == dist[u] + graph[u][v] && total[v] < total[u] + reward[v]))
                {
                    dist[v] = dist[u] + graph[u][v];
                    last[v] = u;
                    total[v] = total[u] + reward[v];
                }
            }
    }
    //	printSolution(dist, total, n);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> reward[i];
    cin >> m;
    memset(graph, -1, sizeof(graph));
    for (int i = 0; i < m; i++)
    {
        int p, q, u;
        cin >> p >> q >> u;
        graph[p][q] = graph[q][p] = u;
    }
    Dijkstra(1);
    cout << total[n] << endl;
}
