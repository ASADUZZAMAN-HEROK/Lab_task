/*
Asaduzzaman Herok
Department of Computer Science and Engineering
Islamic University of Technology
*/

#include <bits/stdc++.h>
using namespace std;

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
    int N, M;
    cin >> N >> M;

    bool isPossible[M + 2] = {};
    int minCount[M + 2] = {};

    int coins[N + 2] = {};
    int frq[N + 2] = {};

    for (int i = 0; i < N; i++)
        cin >> coins[i];

    for (int i = 0; i < N; i++)
        cin >> frq[i];

    isPossible[0] = true;

    for (int i = 0; i < N; i++)
    {
        for (int val = coins[i]; val <= M; val++)
        {
            if (isPossible[val])
                continue;

            if (minCount[val - coins[i]] < frq[i])
            {
                isPossible[val] = isPossible[val - coins[i]];
                minCount[val] = minCount[val - coins[i]] + 1;
            }
        }
        fill(minCount, minCount + M + 2, 0);
    }

    int cnt = 0;
    for (int i = 1; i <= M; i++)
        cnt += isPossible[i];

    cout << "Case " << csno++ << ": " << cnt << endl;
}
