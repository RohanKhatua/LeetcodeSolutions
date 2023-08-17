#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[10][10];
    memset(arr, -10001, 10*10*sizeof(int));

    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    
}

