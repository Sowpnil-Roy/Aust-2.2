#include<bits/stdc++.h>

using namespace std;
#define N 4

struct vertex
{
    int no;
    pair <int, int> path;
    int cost;
    bool visit[N];
    vector<int> nodes;

    int r_matrix[N][N];

    vertex()
    {
        ;
    }

    vertex(int num, int p, int matrix[N][N])
    {
        no = num;
        cost = 0;
        path.first = p;
        path.second = num;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                r_matrix[i][j] = matrix[i][j];
        }

        visit[num] = true;
    }

    void path_false()
    {
        for(int i = 0; i < N; i++)
            visit[i] = false;
    }

    void visit_array_copy(bool v[N])
    {
        for(int i = 0; i < N; i++)
            visit[i] = v[i];

        visit[no] = true;
    }

    void vector_copy(vector<int> &v)
    {
        for(int i = 0; i < v.size(); i++)
        {
            nodes.push_back(v[i]);
        }
    }

};

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

void pop_node(vector<vertex> &v)
{
    int cost = INT_MAX;
    int temp;

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].cost < cost)
        {
            cost = v[i].cost;
            temp = i;
        }
    }

    swap(v[temp], v[v.size() - 1]);

}

void matrix_inf(int matrix[N][N], int row, int col, bool v[N])
{
    for(int i = 0; i < N; i++)
    {
        matrix[row][i] = INT_MAX;
        matrix[i][col] = INT_MAX;
    }
    for(int i = 0; i < N; i++)
    {
        if(v[i] == true)
        {
            matrix[col][i] = INT_MAX;
        }
    }


}

void path(vector<int> &v, int node)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] + 1 << "->";
    cout << node + 1;
}

vertex tsp(int matrix[N][N], int root)
{
    vertex r = vertex(root, NULL, matrix);
    //obj matrix define
    r.cost = cost_n_reduce(r.r_matrix);
    r.path_false();
    r.visit[r.no] = true;


    vector <vertex> temp;
    temp.push_back(r);


    while(!temp.empty())
    {
        pop_node(temp);
        vertex m = temp[temp.size() - 1];

        cout << "Path: ";
        path(m.nodes, m.no);
        cout << endl;

        temp.pop_back();
        m.nodes.push_back(m.no);

        for(int i = 0; i < N; i++)
        {
            if(m.r_matrix[m.no][i] != INT_MAX)
            {
                vertex child = vertex(i, m.no, m.r_matrix);

                child.visit_array_copy(m.visit);
                child.vector_copy(m.nodes);

                matrix_inf(child.r_matrix, m.no, child.no, child.visit);

                child.cost = m.cost + m.r_matrix[m.no][i] + cost_n_reduce(child.r_matrix);

                cout << "Node: " << child.no + 1 << " ";
                cout << "Cost: " << child.cost << endl;

                for(int k = 0; k < N; k++)
                {
                    for(int j = 0; j < N; j++)
                    {
                        if(child.r_matrix[k][j] == INT_MAX)
                            cout << "x\t";

                        else
                            cout << child.r_matrix[k][j] << "\t";
                    }
                    cout << endl;
                }
                temp.push_back(child);


            }

            cout << endl;
        }


        int true_count = 0;
        for(int i = 0; i < N; i++)
        {
            if (m.visit[i] == true)
                true_count++;
        }
        if(true_count == N)
        {
            m.nodes.push_back(m.no);
            return m;
        }

    }
}

int main()
{
    int adj_mat[N][N] =
    {
        {INT_MAX, 10, 15, 20},
        {10, INT_MAX, 35, 25},
        {15, 35, INT_MAX, 30},
        {20, 25, 30, INT_MAX}
    };

    vertex x = tsp(adj_mat, 0);

    cout << endl;
    for(int i = 0; i < N; i++)
        cout << x.nodes[i] + 1 << " -> ";

    cout << "1" << endl;
    cout << "Total cost: " << x.cost;


    return 0;
}

/*{INT_MAX, 20, 30, 10, 11},
        {15, INT_MAX, 16, 4, 2},
        {3, 5,  INT_MAX, 2, 4},
        {19, 6, 18, INT_MAX, 3},
        {16, 4, 7, 16, INT_MAX}*/
