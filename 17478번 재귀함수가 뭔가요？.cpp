#include <iostream>

using namespace std;
int i = 0;
void underBar(int n){
    for(int j = 0;j < n; j++){
        printf("____");
    }
}
void recur(int n){
    
    underBar(i);
    printf("\"����Լ��� ������?\"\n");
    if(n == 0){
        underBar(i);
        printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
        return;
    }
    underBar(i);
    printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
    underBar(i);
    printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
    underBar(i);
    printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
    i++;
    recur(n-1);
    underBar(i);
    printf("��� �亯�Ͽ���.\n");
    i--;
    return;
}

int main()
{
    int n;
    cin >> n;
    printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
    recur(n);
    printf("��� �亯�Ͽ���.\n");

}