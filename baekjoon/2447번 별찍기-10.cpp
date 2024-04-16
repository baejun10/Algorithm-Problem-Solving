#include <iostream>
using namespace std;
void show_star(int i, int j, int num)
{if((j / num)%3 == 1 && (i / num)%3 == 1) {
        cout << ' ';
    }
    else{
        if(num / 3 == 0)
            cout <<'*';
        else
            show_star(i,j,num/3);
    }
}
int main() {
    int num;
    cin >> num;
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++)
            show_star(i,j,num);
        cout << '\n';
    }
}