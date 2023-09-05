#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<int> v = {2,3,4,5};
    int upper = upper_bound(v.begin(), v.end(), 6) - v.begin()-1;
    cout<<upper;
}
