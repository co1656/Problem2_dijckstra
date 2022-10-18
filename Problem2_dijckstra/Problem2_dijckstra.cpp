#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 4

int minDistance(int dist[], bool sptSet[]) //최단거리 저장
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) //새 최단거리 찾으면 변환
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSo(int dist[]) // 결과 출력
{
    printf("정점 \t\t\t\t 최소거리간선\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; //최단거리 파악하는 배열

    bool sptSet[V]; //확인한 정점 체크하는 배열

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0; //시작하는 정점의 간선은 0으로

    for (int count = 0; count < V - 1; count++) //첫 정점을 제외한 모든 정점 계산을 위해 V-1
    {

        int u = minDistance(dist, sptSet); //최단거리를 아는 정점중 가장 가까운 정점 가져옴

        sptSet[u] = true;

        for (int v = 0; v < V; v++) 
            if (!sptSet[v] && graph[u][v] //처리가 안된 정점이고 그래프가 존재하며
                && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) //새 간선값이 기존 최단거리 값보다 작을경우
                dist[v] = dist[u] + graph[u][v]; //바꿔줌
    }

    
    printSo(dist);
}


int main()
{

    int graph[V][V] = { { 0, 4, 0, 0},
                        { 4, 0, 8, 0},
                        { 0, 8, 0, 7},
                        { 0, 0, 7, 0} };

    dijkstra(graph, 0);

    return 0;
}