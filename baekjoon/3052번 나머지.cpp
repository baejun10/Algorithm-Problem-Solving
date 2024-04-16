#include <iostream>

using namespace std;
// 이진 트리 응용하여 set 구현하기!
int set [20];
int idx_s = 0;

void swap(int id1, int id2){
    int tmp = set[id1];
    set[id1] = set[id2];
    set[id2] = tmp;
}

void tree_pop(int idx)
{
    set[idx] = 0; // 삭제할 노드 0으로 변경
    swap(idx_s,idx); // 마지막 노드와 삭제할 노드 교체
    --idx_s;

    int m_child = set[idx*2] > set[idx*2+1] ? idx*2 : idx*2+1; //큰 자식노드 index
    // 마지막 노드의 자식 노드와 비교해 더 작으면 교체
    while(idx!= 1 && set[idx] < set[m_child]){
        swap(m_child,idx);
        idx = m_child;
        m_child = set[idx*2] > set[idx*2+1] ? idx*2 : idx*2+1;
    }
    
}

void tree_push(int in)
{
    for(int i = 1 ; i<=idx_s ;i++){
        if(set[i] == in){
            return; // 중복 발견시 캔슬
            //cout<<"dup\n";
        }
            
    }
    // 중복 검사 후 추가
 
    int idx = ++idx_s;
    set[idx] = in;
    
    while(idx!= 1 && set[idx] > set[idx/2]){
        swap(idx, idx/2);
        idx /=2;
    }
    /*
    if(idx !=1 && set[idx] == set[idx/2]){ // 루트 노드 중복값 검사
            cout << "pop\n";
            tree_pop(idx);
    }
    //최하위 노드 중복값 검사
    if(idx != 1 && set){
        
    }
    // 내림차순 정렬, 큰게 위에 있다
    */

}


int main()
{
    int n[11], ans;
    for(int i = 0 ; i < 10 ; i++){
        cin >> n[i];
        tree_push(n[i]%42);
        /*
        cout << "tree: ";
        for(int j = 1 ; j <= idx_s ; j++){
            cout << set[j] << " ";
        }
        cout <<"\n";
        */
    }
    cout << idx_s;
    /*
    cout << "tree: ";
    for(int i = 1 ; i <= idx_s ; i++){
        cout << set[i] << " ";
    }
    */
}