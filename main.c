#include<stdio.h>
#include "queue.h"

int main(){
queue_t **teste;
int elem = 6;
queue_t * t= elem;
queue_append(teste,t);

int e = 8;
queue_t * s= e;
queue_append(teste,s);
}