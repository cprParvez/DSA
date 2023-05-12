#include <bits/stdc++.h>
using namespace std;

void towerofHanoi(int n, char src, char dest, char aux) {

    if(n == 0)              // base case
        return;

    towerofHanoi(n-1, src, aux, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerofHanoi(n-1, aux, dest, src);
}

int main()
{
    int n;
    cout << "Enter total disks nubmer : ";
    cin >> n;
    towerofHanoi(n, 'A', 'C', 'B');
    return 0;
}