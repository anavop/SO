#include<stdio.h>
#include "queue.h"
int queue_size (queue_t *queue) {


//------------------------------------------------------------------------------
// Percorre a fila e imprime na tela seu conteúdo. A impressão de cada
// elemento é feita por uma função externa, definida pelo programa que
// usa a biblioteca. Essa função deve ter o seguinte protótipo:
//
// void print_elem (void *ptr) ; // ptr aponta para o elemento a imprimir
}
void queue_print (char *name, queue_t *queue, void print_elem (void*) ) {

//------------------------------------------------------------------------------
// Insere um elemento no final da fila.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - o elemento deve existir
// - o elemento nao deve estar em outra fila
// Retorno: 0 se sucesso, <0 se ocorreu algum erro
}
int queue_append (queue_t **queue, queue_t *elem) {
    if (queue == NULL ){ // Se a lista for vazia 
        queue_t * aux = elem;
        aux->prev = aux;
        aux->next = aux;
        queue = aux;


        return elem;
    }
    else{
        if (queue != NULL){ // insere quando a fila não ta vazia
            queue_t * aux = elem;
            queue_t * aux2 = queue;
            aux2 = aux2->next;
            printf("aux2 %d",aux2);
            /*if (queue != aux2){
            while (queue != aux2){
                aux2 = aux2->next;
                
            }
            }
            aux->prev = aux2->next->prev;
            aux->next = aux2->next;
            aux2->next->prev = aux;
            aux2->next = aux;
            */
            


        }
    }
    }
    

//------------------------------------------------------------------------------
// Remove o elemento indicado da fila, sem o destruir.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - a fila nao deve estar vazia
// - o elemento deve existir
// - o elemento deve pertencer a fila indicada
// Retorno: 0 se sucesso, <0 se ocorreu algum erro

int queue_remove (queue_t **queue, queue_t *elem) {

}