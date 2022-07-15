#include <iostream>

using namespace std;

typedef struct Person{
    int x = 0, y = 0;
    int ord;
} Person;


int main()
{
    Person p[51];
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> p[i].x >> p[i].y;
        p[i].ord = i;
    }

    for(int i = 0; i < n ; i++){
        int rank = 1;
        for(int j = 0 ; j < n; j++){
            if(p[i].x < p[j].x && p[i].y < p[j].y)
                rank++;
        }
        cout << rank << endl;
    }
}