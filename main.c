#include<stdio.h>
#include "queue.h"

int main(){
queue_t **teste;
queue_t * elem;
int t = 6;
elem = t;
printf("elem pont  %p\n",(&elem));
queue_append(&teste,elem);

printf("teste pont  %d  \n",(*teste)->next);

}