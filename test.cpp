#include <iostream>
#include <vector>

using namespace std;

void findEliminatedPlayers(int N, int K)
{
    vector<bool> visited(N, false);
    int current = 0;
    visited[current] = true;

    for (int i = 0; i < N - 1; ++i)
    {
        current = (current + K) % N;
        visited[current] = true;
    }

    bool anyEliminated = false;
    for (int i = 0; i < N; ++i)
    {
        if (!visited[i])
        {
            cout << i + 1 << " ";
            anyEliminated = true;
        }
    }

    if (!anyEliminated)
    {
        cout << 0;
    }
    cout << endl;
}

int main()
{
    int N, K;
    cin >> N >> K;

    findEliminatedPlayers(N, K);

    return 0;
}
