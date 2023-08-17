#include <bits/stdc++.h>
using namespace std;


int solution(vector<int> &A, int X, int Y)
{
    int days = (X - 1) * Y + 1;
    int slots = A.size() - days + 1;

    long long int min_cost = 1e9;
    for (int i = 0; i < slots; i++)
    {
        long long int cost = 0;
        for (int j = i; j < A.size(); j += Y)
        {
            cost += A[j];
        }

        min_cost = min(cost, min_cost);
    }

    return min_cost;
}

int main(int argc, char const *argv[])
{
    vector<int> a = {4, 2, 3, 7};
    int x = 2;
    int y = 2;
    cout<<solution(a, x, y);
    return 0;
}
