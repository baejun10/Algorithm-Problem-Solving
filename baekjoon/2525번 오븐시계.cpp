#include <iostream>
using namespace std;

int main()
{
    int dt, h, m;
    cin >> h >> m;
    cin >> dt;

    m = m+dt;
    h = (h + m/60)%24;
    m = m % 60;
    cout << h << " " << m;
}