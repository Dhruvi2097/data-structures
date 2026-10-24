
#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

// Depth First Search
void DFS(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// Breadth First Search
void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);

    printf("\n");
    return 0;
}
