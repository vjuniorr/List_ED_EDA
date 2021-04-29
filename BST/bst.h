#ifndef BST_H
#define BST_H

struct Node;

Node *bst_clear(Node *node);
Node *insert(Node *node, int myKey, int value);
Node *bst_minimum(Node *node);
void bst_delete_antecessor(Node *node);

int ContarFolhas(Node *root);
int ContarNos(Node *root);
Node *RemoveTodos(Node *root, int key);
void ImprimeNos(Node *root);

#endif