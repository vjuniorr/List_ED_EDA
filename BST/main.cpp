#include <bits/stdc++.h>
#include "bst.h"


using namespace std;

int main(){
    Node* root = nullptr;

    root = insert(root, 8, 1.0);
    root = insert(root, 3, 2.0);
    root = insert(root, 13, 3.0);
    root = insert(root, 7 , 4.0);
    root = insert(root, 14, 5.0);
    root = insert(root, 1, 6.0);
    root = insert(root, 10, 7.0);
    root = insert(root, 12, 8.0);
    root = insert(root, 4, 9.0);
    root = insert(root, 5, 10.0);   

    /* ImprimeNos(root);

    cout << ContarNos(root) << endl;
    cout << ContarFolhas(root) << endl; */ 

    cout << "Vamos remover o nó 8" << endl;
    RemoveTodos(root,8);

    ImprimeNos(root);

    cout << "Contar nos:" << ContarNos(root) << endl;
    cout << "Contar folhas:" << ContarFolhas(root) << endl;

    root = bst_clear(root);

    return 0;
}