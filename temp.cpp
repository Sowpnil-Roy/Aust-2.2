#include<bits/stdc++.h>
#define N 5
#define inf INT_MAX
using namespace std;

int cost_n_reduce(int matrix[N][N])
{
    //reduce row
    int cost = 0;
    for(int i = 0; i < N; i++)
    {
        int small = INT_MAX;
        for(int j = 0; j < N; j++)
        {
            if(matrix[i][j] < small)
                small = matrix[i][j];
        }
        for(int k = 0; k < N; k++)
        {
            if(matrix[i][k] != INT_MAX)
                matrix[i][k] = matrix[i][k] - small;
        }
        if(small != INT_MAX)
            cost += small;
    }


    //reduce col
    for(int i = 0; i < N; i++)
    {
        int small = INT_MAX;
        for(int j = 0; j < N; j++)
        {
            if(matrix[j][i] < small)
                small = matrix[j][i];
        }
        for(int k = 0; k < N; k++)
        {
            if(matrix[k][i] != INT_MAX )
                matrix[k][i] = matrix[k][i] - small;
        }
        if(small != INT_MAX)
            cost += small;
    }
    return cost;
}

int main()
{
    int adj_mat[N][N] =
    {
        {inf,   inf,    inf,    inf,    inf},
        {12,   inf,    inf,     2,      0},
        {inf,     3,    inf,    0,      2},
        {15,    3,    inf,     inf,    0},
        {11,    0,    inf,      12,     inf}
    };

    cout << "cost is: " << cost_n_reduce(adj_mat) << endl;
    cout << endl;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(adj_mat[i][j] == INT_MAX)
                cout << "x ";

            else
                cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}
