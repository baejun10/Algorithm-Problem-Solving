#include <iostream>

using namespace std;

int main()
{
    int c , n, tot = 0, ov = 0;
    double avg = 0, percent = 0;
    cin >> c;

    for(int i = 0 ; i < c ;i++){
        tot = 0;
        ov = 0;
        int sc[1000] ={};

        cin >> n;
        for(int j = 0; j < n ; j++){
            cin >> sc[j];
            tot += sc[j];
        }
        avg = (double)tot/n;
        for(int j = 0 ; j < n ; j++){
            if(sc[j] > avg){
                ov++;
            }
        }

        percent = (double)ov/n*100;
        printf("%.3f%\n",percent);
        //printf("%d %d %d %f\n",ov, n, tot, avg);
    }
}