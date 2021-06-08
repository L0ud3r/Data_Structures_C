#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
typedef struct _Pessoa
{
    char* nome;
    int idade, key, id;
} Pessoa;

typedef struct _BTree
{
    Pessoa p;
    struct _BTree *left, *right;
} BTree;
*/

typedef struct _BTree
{
    char* nome;
    int idade, key, id;

    struct _BTree *left, *right;
} BTreePessoas;

#pragma region OrganizacaoNodos

/**
 * @brief Criar nodo de arvore
 * 
 * @param nome 
 * @param idade 
 * @param id 
 * @param chave 
 * @return BTreePessoas* 
 */
BTreePessoas *btree_new_node(char* nome, int idade, int id, int chave){
    BTreePessoas *aux = malloc(sizeof(BTreePessoas));

    aux->nome = strdup(nome);
    aux->idade = idade;
    aux->id = id;
    aux->key = chave;

    aux->left = aux->right = NULL;

    return aux;
}

/**
 * @brief Inserir nodo em arvore
 * 
 * @param root 
 * @param nome 
 * @param idade 
 * @param id 
 * @param value 
 * @return BTreePessoas* 
 */
BTreePessoas *btree_insert(BTreePessoas *root, char* nome, int idade, int id, int value){
    if(root){
        if(value < root->key)
            root->left = btree_insert(root->left, nome, idade , id, value);
        if(value > root->key)
            root->right = btree_insert(root->right, nome, idade, id, value);
    }
    else{
        root = btree_new_node(nome, idade, id, value);
    }

    return root;
}

/**
 * @brief Navega para o nodo mais pequeno possivel (à esquerda)
 * 
 * @param root 
 * @return BTreePessoas* 
 */
BTreePessoas *btree_leftmost(BTreePessoas *root){
    if(root && root->left)
        return btree_leftmost(root->left);
        
    else return root;
}

/**
 * @brief Limpar arvore
 * 
 * @param root 
 * @return void* 
 */
void *btree_free(BTreePessoas *root){
    if(root){
        btree_free(root->left);
        btree_free(root->right);

        //free aos dados necessarios
        free(root->nome);
        free(root);
    }
}

//Rever bem, com problemas
/**
 * @brief Remove a arvore binaria de forma alternativa
 * 
 * @param root 
 * @param key 
 * @return BTreePessoas* 
 */
BTreePessoas *btree_free_alt(BTreePessoas* root, int key){
    if(root){
        if(key < root->key)
            root->left = btree_free_alt(root->left, key);

        else if(key > root->key)
            root->right = btree_free_alt(root->right, key);

        else if (!root->left && !root->right){
            free(root);
            root = NULL;
        }
    }
    else if(root->left == NULL)
    {
        BTreePessoas *sTree = root->right;
        free(root);
        root = sTree;
    }
    else if(root->right == NULL)
    {
        BTreePessoas *sTree = root->left;
        free(root);
        root = sTree;
    }
    else
    {
        BTreePessoas *smaller = btree_leftmost(root->right);

        //Trocar informacao
        int min = smaller->key;
        smaller->key = root->key;
        root->key = min;
        
        root->right = btree_free_alt(root->right, key);
    }
}

#pragma endregion

#pragma region ListagensOrdenadas(Travessias)

/**
 * @brief Mostra arvore por ordem de chaves
 * 
 * @param root 
 */
void btree_inorder(BTreePessoas* root){
    if(root){
        btree_inorder(root->left);
        printf("%s\n", root->nome);
        btree_inorder(root->right);
    }
}

/**
 * @brief Mostra arvore a começar pelo primeiro nodo, depois lado esquerdo, depois direito
 * de cima para baixo
 * 
 * @param root 
 */
void btree_preorder(BTreePessoas* root){
    if(root){
        printf("%s\n", root->nome);
        btree_preorder(root->left);
        btree_preorder(root->right);
    }
}

/**
 * @brief Mostra arvore a começar pelo lado esquerdo, depois direito, depois o primeiro nodo
 * de baixo para cima
 * 
 * @param root 
 */
void btree_postorder(BTreePessoas* root){
    if(root){
        btree_postorder(root->left);
        btree_postorder(root->right);
        printf("%s\n", root->nome);
    }
}

#pragma endregion

#pragma region Listagem/Navegacao

/**
 * @brief Devolve tamanho da arvore
 * 
 * @param root 
 * @return int 
 */
int btree_size(BTreePessoas* root){
    if(root){
        int tamEsq, tamDir;
        tamEsq = btree_size(root->left);
        tamDir = btree_size(root->right);
        return 1 + tamEsq + tamDir;
    }
    else
        return 0;
}

/**
 * @brief Retorna a profundidade da arvore, ou seja, o quao "funda" esta é
 * 
 * @param root 
 * @return int 
 */
int btree_depth(BTreePessoas *root){
    int aux = 0;

    if(root){
        int pesoEsq = btree_depth(root->left);
        int pesoDir = btree_depth(root->right);
        int pesoMax = pesoEsq;

        if(pesoDir > pesoEsq)
            pesoMax = pesoDir;

        aux = 1 + pesoMax;
    }

    return aux;
}

/**
 * @brief Procura nodo especifico na arvore pela chave
 * 
 * @param root 
 * @param key 
 * @return BTreePessoas* 
 */
BTreePessoas *btree_search(BTreePessoas *root, int key){
    if(root){
        if(key < root->key)
            return btree_search(root->left, key);
        else if(key > root->key)
            return btree_search(root->right, key);
        else 
            return root;
    }
    else 
        return NULL;
}

#pragma endregion

//Funcao teste para mostrar 1 pessoa (nodo)
void Show(BTreePessoas* root){
    printf("%s\n", root->nome);
}

int main(){
    BTreePessoas *pessoas = NULL;


    pessoas = btree_insert(pessoas, "Pedro", 20, 123, 20);
    pessoas = btree_insert(pessoas, "Maria", 16, 235, 30);
    pessoas = btree_insert(pessoas, "Andre", 43, 323, 10);
    pessoas = btree_insert(pessoas, "Jose", 43, 323, 12);
    pessoas = btree_insert(pessoas, "Sett", 43, 323, 132);
    pessoas = btree_insert(pessoas, "Jorge", 43, 323, 14);
    pessoas = btree_insert(pessoas, "Ni", 43, 323, 45);

    /*
    Show(pessoas);
    Show(pessoas->left);
    Show(pessoas->left->right);
    Show(pessoas->left->right->right);
    Show(pessoas->right);
    Show(pessoas->right->right);
    Show(pessoas->right->right->left);
    */

    //btree_preorder(pessoas);

    printf("Tamanho da arvore: %d\nProfundidade da arvore: %d\n", btree_size(pessoas), btree_depth(pessoas));

    BTreePessoas *aux = btree_search(pessoas, 20);

    if(aux)
        printf("\nPessoa com a chave %d: %s encontrado/a!\n", aux->key, aux->nome);
    else printf("\nPessoa inexistente na arvore!\n");

    btree_free(pessoas);
    return 0;
}