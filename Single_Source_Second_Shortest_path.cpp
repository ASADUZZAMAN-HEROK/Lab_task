//https://lightoj.com/problem/not-the-best
#include "bits/stdc++.h"
using namespace std;
#define LLMX 0x3fffffffffffffff

int csno = 1;
void Solution();

int main()
{
    int test = 1;
    cin >> test;
    while (test--)
    {
        Solution();
    }

    return 0;
}

void Solution()
{

    int N, R;
    cin >> N >> R;

    struct node
    {
        int x = 0;
        long long cost = 0;
        bool operator<(const node &y) const
        {
            return cost > y.cost;
        }
    };
    vector<vector<node>> edge(N + 1);

    int u, v, w;
    for (int i = 0; i < R; i++)
    {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    vector<long long> dist_1(N + 1, LLMX), dist_2(N + 1, LLMX);

    priority_queue<node> relax;
    relax.push({1, 0});

    while (relax.empty() == false)
    {
        int parent = relax.top().x;
        int depth = relax.top().cost;
        relax.pop();

        for (auto child : edge[parent])
        {
            if (dist_1[child.x] > depth + child.cost)
            {
                dist_2[child.x] = min({dist_1[child.x], depth + 3 * child.cost,dist_2[parent]+child.cost});
                dist_1[child.x] = depth + child.cost;
                relax.push({child.x, dist_1[child.x]});
            }
            else if (depth + child.cost > dist_1[child.x])
                dist_2[child.x] = min(dist_2[child.x], depth + child.cost);
            else
                dist_2[child.x] = min({dist_2[child.x], depth + 3 * child.cost, dist_2[parent]+child.cost});
        }
    }

    cout << "Case " << csno++ << ": " << dist_2[N] << endl;
}
