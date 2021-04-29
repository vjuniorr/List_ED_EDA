#include <bits/stdc++.h>
#include "bst.h"

using namespace std;

struct Node{
    int key;
    int value;
    Node *left;
    Node *right;
};

Node *bst_clear(Node *node){
    if (node != nullptr){
        node->left = bst_clear(node->left);
        node->right = bst_clear(node->right);
        delete node;
    }
    return nullptr;
}

Node *insert(Node *node, int myKey, int value){
    if (node == nullptr){
        node = new Node;
        node->key = myKey;
        node->value = value;
        node->left = node->right = nullptr;
    }
    else if (myKey < node->key){
        node->left = insert(node->left, myKey, value);
    }
    else if (myKey > node->key){
        node->right = insert(node->right, myKey, value);
    }
    return node;
}

Node *bst_minimum(Node *node){
    if (node->left == nullptr){ // Se o proximo nó a esquerda for nulo, quer dizer que aquele nó é o menor da arvore
        return node;
    }
    return bst_minimum(node->left); // Procura pelo menor nó
}

void bst_delete_antecessor(Node* node){
    Node* aux = node->left; // Meu aux vai ser o maximo da minha sub-arvore esquerda
    Node* pai = node; // Pai do meu sucessor(aux)

    while (aux->right != nullptr){ // Percorre a sub-arvore até encontrar o maior elemento dela
        pai = aux;
        aux = aux->right;
    }

    node->key = aux->key; // A chave do meu nó passa a ser a chave do seu antecessor

    if(pai->right = aux){
        /*
        Se o meu maximo está na sub-arvore direita do pai e já que o maior elemento não possui filho
        direito, o pai do maximo passa a ter como filho direito a sub-arvore esquerda do meu maximo. 
        */
        pai->right = aux->left; 
    }else{
        /*
        Se o maximo está na sub-arvore a esquerda do pai ele não vai possuir um filho direito, então
        o pai passa a ter como filho a esquerda a sub-arvore a esquerda do maximo 
        */
        pai->left = aux->left;
    }
    
    delete aux; // Deleto o maximo da sub-arvore, que é o antecessor do valor que foi passado no começo
    
}

// --------------- Contar Folhas -----------------
// Complexidade: O(N)

int ContarFolhas(Node *root){
    // Uma folha é um nó que não possui filhos nem na direita nem na esquerda

    /*
    Se a raiz da arvore passada para a função é nula, então essa posição é invalida e retornamos 0.
    Esse também será nosso caso base, uma vez que vamos percorrer toda a arvore verificando se o nó 
    passado para a função (root) é ou não uma folha.
    */
    if (root == nullptr){
        return 0;
    }
    /*
    Se eu encontrar um nó que não tenha filho nem na direita e nem a esquerda eu retorno 1, já que aquele
    nó é um nó folha.
    */
    if (root->left == nullptr && root->right == nullptr){
        return 1;
    }
    /*
    Caso o nó passado tenha algum filho eu retorno a soma da função chamando ela para o filho da esquerda
    e da direita.
    */
    return ContarFolhas(root->left) + ContarFolhas(root->right);
}

// --------------- Contar Nós -----------------
// Complexidade: O(N)

int ContarNos(Node *root){
    // A função ContarNos tem como o objetivo contar todos os nós da arvore, independente se é folha ou não

    /*
    Se a raiz da arvore passada para a função é nula, então essa posição é invalida e retornamos 0.
    Esse também será nosso caso base, uma vez que vamos percorrer toda a arvore para contar quantos nós 
    ela possui.
    */
    if (root == nullptr){
        return 0;
    }
    /*
    Se o nó passado para a função não é nulo, eu retorno 1 + ContarNos(root->left) + ContarNos(root->right)
    onde o 1 é referente ao nó em que estou e chamo a função para os filhos do nó passado 
    */
    return 1 + ContarNos(root->left) + ContarNos(root->right);
}

// --------------- Remove Todos -----------------
// Complexidade : O(N)

Node *RemoveTodos(Node *root, int key){
    /*
    Se foi passada uma raiz nula para a função eu retorno nulo.
    Esse vai ser nosso caso base, uma vez que não sabemos se o nó com a chave passada está ou não na arvore
    então vamos precisar percorrer a arvore em busca dele
    */
    if (root == nullptr){
        return nullptr;
    }
    /*
    Vamos percorrer a arvore verificando a chave do nó passado com a chave que procuramos.
    Se a chave do meu nó é maior que a chave que procuro, então o nó com a chave que procuro está na
    sub-arvore esquerda daquele nó, caso contrario está na sub-arvore a direita do nó.
    */
    if (root->key > key){ // Caso em que a chave está na sub-arvore esquerda.
        /*
        Se a chave passada é menor que a chave do nó, o nó vai ter como sub-arvore à esquerda o retorno da
        função passando como nó a raiz da sub-arvore a esquerda(root->left).
        */
        root->left = RemoveTodos(root->left, key);
    }
    else if (root->key < key){ // Caso em que a chave está na sub-arvore direita.
        /*
        Se a chave passada é maior que a chave do nó, o nó vai ter como sub-arvore à direita o retorno da
        função passando como nó a raiz da sub-arvore a direita(root->right).
        */
        root->right = RemoveTodos(root->right, key);
    }
    /*
    Caso em que a chave é igual a chave do meu nó. Porém, antes de simplesmente deletarmos o nó, temos que
    verificar se ele possui filhos ou não. 
    */
    else if(root->left == nullptr && root->right == nullptr){ // Caso ele não possua nenhum filho
        /*
        Caso ele não possua nenhum filho, posso apenas deletar o conteudo do nó e retorna nullptr 
        */
        delete root;
        root = nullptr; 
    }
    else if(root->left == nullptr){ // Caso ele possua apenas o filho a direita 
        /*
        Caso ele possua apenas o filho da direita, nós criamos um auxiliar para não perder a referencia
        do nó que vamos deletar, fazemos o nosso nó receber o seu filho da direita, então deletamos o 
        aux que possui a referencia pro meu antigo nó 
        */
        Node* aux = root;
        root = root->right;
        delete aux;
    }
    else if(root->right == nullptr){
        /*
        Caso ele possua apenas o filho da esquerda, nós criamos um auxiliar para não perder a referencia
        do nó que vamos deletar, fazemos o nosso nó receber o seu filho da esquerda, então deletamos o 
        aux que possui a referencia pro meu antigo nó 
        */
        Node* aux = root;
        root = root->left;
        delete aux;
    }else{ // Caso em que ele possui os dois filhos 
        bst_delete_antecessor(root);
    }
    return root;
}

// --------------- Altura -----------------

/* 
Para que possamos atualizar a altura dos nós durante a inserção na arvore, temos que atualizar a altura
do nó, após termos lhe dado um nó filho, nesse caso vamos chamar a recursão após atualizarmos a sub-arvore
do nó. Na inserção que fiz np começo desse arquivo, a chamada da função para atualizar o nó ficaria após
node->left = insert(node->left, myKey, value); 
e
node->right = insert(node->right, myKey, value);
A função que nos da a altura do nó seria: 

int bst_height(Node *node) {
    if(node == nullptr){ 
        return 0;
    }
    return 1 + max(bst_height(node->left), bst_height(node->right));
}

Se chegarmos a uma possição invalida retornariamos 0 já que ali já seria nulo, caso contrario nós
retornamos 1 (Do nosso nó atual) + a maior altura entre a sub-arvore a esquerda e direita.
Nesse codigo as folhas teriam altura 1, mas também é possivel fazer com que as folhas possuam altura 0

*/

// --------------- Imprime Nós -----------------

void ImprimeNos(Node *root){
    /*
    Vamos começar criando uma pilha vazia para que possamos ordernar os nós 
    */
    stack<Node *> pilha;
    /*
    Criamos um auxiliar porque estamos mexendo diretamente com ponteiros, então para não alterarmos 
    a arvore original vamos mudar as coisas através desse auxiliar 
    */
    Node *aux = root;
    /*
    Vamos percorrer a arvore com o while, os casos de parada dele serão, meu aux = nulo, ou seja,
    cheguei em uma posição invalida da minha arvore ou ela já está vazia
    */
    while (aux != nullptr || pilha.empty() == false){
        /*
        Percorro toda a arvore para a esquerda empilhando os nós, de forma que o nó com menor chave fique
        no topo da minha pilha, exceto quando aux é nulo
        */
        while (aux != nullptr){
            pilha.push(aux);
            aux = aux->left;
        }
        /*
        Após empilhar todos os nós a esquerda da raiz, faço meu auxiliar receber o primeiro nó da pilha.
        Depois disso desempilho o nó da pilha e printo usando o aux. 
        */
        aux = pilha.top();
        pilha.pop();
        cout << aux->key << endl;
        /*
        Depois de imprimirmos o nó, repetimos o processo com o aux possuindo a sub-arvore a direita 
        */
        aux = aux->right;
    }
    return;
}

