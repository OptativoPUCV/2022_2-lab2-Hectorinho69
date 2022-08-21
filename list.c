#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList()
{
  List *list = (List *)malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
  
  return list;
}

void * firstList(List * list)
{
  if(list->head == NULL)
    return(NULL);
  
  list->current = list->head;
  
  return list->head->data;
}

void * nextList(List * list)
{
  if(list->current == NULL)
    return(NULL);
  
  if(list->current->next == NULL)
    return(NULL);
  
  list->current = list->current->next;
  
  return list->current->data;
}

void * lastList(List * list)
{
  if(list->current->next)
  {
    while(list->current->next != NULL)
    {
      list->current = list->current->next;
    }
  }  
  
  return list->current->data;
}

void * prevList(List * list)
{
  if(list->current == NULL)
    return(NULL);
  
  if(list->current->prev == NULL)
    return(NULL);

  if(list->current->prev)
    list->current = list->current->prev;
    
  return (list->current->data);
}

void pushFront(List * list, void * data)
{
  Node * nuevito = createNode(data);

  if(list->head)
  {
    nuevito->next = list->head;
    list->head->prev = nuevito;
  }
  if(list->tail == NULL)
    list->tail = nuevito;
  
  
  list->head = nuevito;
}

void pushBack(List * list, void * data)
{
  
  
  list->current = list->tail;
  pushCurrent(list,data);
}

void pushCurrent(List * list, void * data)
{
  Node * nodo = createNode(data);
  Node * aux = createNode(list->tail);

  Node * siguiente = list->current->next;

  nodo->prev = list->current;
  if(list->current->next) //si current no es el ultimo
  {
    aux->next = nodo;
  }
  else//si es current es el tail
  {
    list->tail = nodo;
    aux->prev = list->current;
  }
  //siguiente = nodo;
  if(list->current == list->head)
  {
    list->head->next = nodo;
  }
  
  
  
}

void * popFront(List * list)
{

  
  list->current = list->head;
  return popCurrent(list);
}

void * popBack(List * list)
{
  
  
  list->current = list->tail;
  return popCurrent(list);
}

void * popCurrent(List * list) 
{
  
  return NULL;
}

void cleanList(List * list)
{
  
  
  while (list->head != NULL)
  {
    popFront(list);
  }
}