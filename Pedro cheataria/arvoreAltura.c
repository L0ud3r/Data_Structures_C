#include <stdio.h>

#pragma region Joshy's resolution (nao entendi)
Arvore *arvore_insere(Arvore *a, int p)
{
    if(a)
    {
        if(altura < a -> chave)
        a -> left = arvore_insere(a->left, p);
        if(altura < a -> chave)
        {
            root -> right = arvore_insere(a -> right, p);
        }
    }
    else
    {
        a = (Arvore*) malloc(sizeof(Arvore));
        a -> chave = p;
        a -> left = a -> right = NULL;
    }
    return a;
}

Arvore *arvore_pesquisa(Arovre *a, int chave)
{
    int tempMaior = 0;
    if (a)
    {
        if(chave > a-> chave)
        tempMaior = chave;
        return arvore_pesquisa(a -> left, chave);
        else if(chave > a -> chave)
        return arvore_pesquisa(a -> right, chave);
        else
        return a;
    }
    else
    {
        return NULL;
    }
}

#pragma endregion

#pragma region myRes

int alturaArvore(Btree* t){
    int soma = 0, alturaEsq, alturaDir, maior;

    if(t){
        alturaEsq = alturaArvore(t->left);
        alturaDir = alturaArvore(t->right);

        if(alturaEsq < alturaDir) maior = alturaDir;
        else maior = alturaEsq;

        soma = 1 + maior;
    }

    return soma;
}

#pragma endregion
