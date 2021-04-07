#ifndef LIST
#define LIST

#include "../Bool/__init__.c"
#include <stdlib.h>


typedef struct value
{
    int value_int;
    float value_float;
    char value_char;
} Value;


typedef struct element
{
    Value value;
    unsigned int pos_x;
    struct element *next;
    struct element *previous;
} EList;


typedef struct header
{
    unsigned int len;
    EList *first;
    EList *last;
} List;

/*
 * Cria uma nova lista
 * 
 * return   NULL : se não criou
 * return List * : se criou
*/
List *createList()
{
    List *new = (List *) malloc(sizeof(List));

    if (new == NULL)
        return NULL;
    
    new -> first = NULL;
    new -> last = NULL;
    new -> len = 0;

    return new;
}

/*
 * Verifica se uma lista está vazia
 * 
 * param list : um ponteiro pra uma lista
 * 
 * return    -1 : ERRO
 * return  true : se estiver vazia
 * return false : se não estiver vazia
*/
Bool listIsEmpty(List *list)
{
    if (list == NULL)
        return -1;
    
    if (list -> len == 0 && list -> first == NULL && list -> last == NULL)
        return true;
    
    return false;
}

/*
 * Obtém a quantidade de elementos que existe em uma lista
 * 
 * param list : um ponteiro para uma lista
 * 
 * return  -1 : ERRO
 * return int : tamanho da lista
*/
int lenList(List *list)
{
    if (list == NULL)
        return -1;
    
    return list -> len;
}

/*
 * Atualiza as posições subsequentes do elemento se elas forem iguais
 * 
 * param element : um ponteiro para um elemento
 * 
 * return int : quantidade de elementos atualizados
*/
int attPositionList(EList *element)
{
    int modifieds_elements = 0;

    if (element == NULL)
        return modifieds_elements;
    
    element = element -> next;

    while (element != NULL)
    {
        if (element -> pos_x == element -> previous -> pos_x)
        {
            element -> pos_x += 1;
            element = element -> next;

            modifieds_elements += 1;
        }

        else
            return modifieds_elements;
    }

    return modifieds_elements;
}

/*
 * Adiciona um elemento no início da lista
 * 
 * param  list : um ponteiro para uma lista
 * param value : valor a ser adicionado
 * 
 * return    -1 : ERRO
 * return  true : se conseguiu adicionar
 * return false : se não conseguiu adicionar
*/
Bool addFirstList(List *list, Value value)
{
    if (list == NULL)
        return -1;
    
    EList *new = (EList *) malloc(sizeof(EList));

    if (new == NULL)
        return false;

    new -> pos_x = 0;
    new -> next = list -> first;
    new -> previous = NULL;

    new -> value = value;

    if (listIsEmpty(list))
        list -> last = new;

    if (list -> first != NULL)
        list -> first -> previous = new;

    list -> first = new;

    list -> len += 1;

    attPositionList(new);

    return true;
}


#endif
