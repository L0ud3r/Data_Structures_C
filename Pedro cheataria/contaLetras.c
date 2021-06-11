typedef struct _list {
  char * palavra;
  struct _list* next;
} List;

int numPalavras(List* list) 
{
    int counter = 0;

    for(List* aux = list; list; list = list->next)
    {    
        if(strcmp(list->palavra[0], 'a') == 0 && strcmp(list->palavra[strlen(list->palavra)-1], 'a') == 0)
            counter++ ;
    }
    
    return counter;    
}