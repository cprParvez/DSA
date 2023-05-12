// WAP to find the path matrix of a weighted graph using Warshall Algorithm.
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

// to create Path Matrix
void crtPathMat(vector<vector<int>> &dist, int n) {
    for(int k=0; k<n; k++) {
        // comparing all the elements a[i][j] individually
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                // Warshall formula
                if(dist[i][k]+dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

// to output path matrix
void cop(vector<vector<int>> dist, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dist[i][j] != INF)
                cout << dist[i][j] << "   ";
            else
                cout << "INF" << " ";
        }
        cout << endl;
    }
}

int main()
{
    // to input Matrix or 2D array
    vector<vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    int vertex = graph.size();          // no. of vertex

    vector<vector<int>> dist = graph;

    crtPathMat(dist, vertex);
    cop(dist, vertex);
    return 0;
}