#include<stdio.h>
#include "queue.h"
int queue_size (queue_t *queue) {
    int cont = 0;
    if (queue == NULL){
        return cont;

    }
}
//------------------------------------------------------------------------------
// Percorre a fila e imprime na tela seu conteúdo. A impressão de cada
// elemento é feita por uma função externa, definida pelo programa que
// usa a biblioteca. Essa função deve ter o seguinte protótipo:
//
// void print_elem (void *ptr) ; // ptr aponta para o elemento a imprimir

void queue_print (char *name, queue_t *queue, void print_elem (void*) ) {

//------------------------------------------------------------------------------
// Insere um elemento no final da fila.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - o elemento deve existir
// - o elemento nao deve estar em outra fila
// Retorno: 0 se sucesso, <0 se ocorreu algum erro
}
int queue_append (queue_t **queue/* &first*/, queue_t *elem) {
    
     // Se a lista for vazia 
    //if (queue_size(queue) == 0){
        printf("queue pont antes %p \n",(*queue));
        printf("elem pont na f %p \n",&elem);
       // printf("entrou");
        (*queue)= &elem; //
        (*queue)->prev= &elem; 
        (*queue)->next= &elem; 
        

        printf("queue pont dps %p \n",&(*queue));
       printf(" queue %d \n",&(*queue)); // acessando &elem
        return 1;
    //}

     }
     // Se não for vazia a fila
    
    
    

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