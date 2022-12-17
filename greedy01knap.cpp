#include<bits/stdc++.h>

using namespace std;

int w[4] = {5,4,3,6};
int p[4] = {4,3,2,1};

Gknapsack(int m)
{
    int U = m;
    int x[4] = {0};

    for(int i = 0; i < 4; i++)
    {
        if(w[i] <= U)
        {
            x[i] = 1;
            U = U - w[i];
        }
    }

    for(int i = 0; i < 4; i++)
        cout << x[i] << ",";
}


int main()
{
    Gknapsack(8);
}
