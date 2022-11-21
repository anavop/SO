#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include "ppos.h"
#include "queue.h"
#include <string.h>
#define STACKSIZE 64*1024
int  num_task =0; 
int usersTask =0;
task_t * atual, taskMain;
task_t * Filadispatcher,disp; // header da fila dispatcher e a task onde armazena o dispatcher
task_t * pont_dispatcher; // ponteriro que ira percorrer a fila dispatcher
short AGUARDANDO = 0;
short TERMINADA = 1;
short SUSPENSA,OCUPADO;
void Dispatcher();
//Esta função inicializa as estruturas internas do SO
void ppos_init (){

char* stack = malloc (STACKSIZE) ;
setvbuf (stdout, 0, _IONBF, 0);

if (stack){ // verifica se a stack que armazenara os valores da tarefa main foi armazenado com sucesso
    taskMain.id = num_task;
    taskMain.prev = NULL;
    taskMain.next = NULL;
    taskMain.status = AGUARDANDO;
    taskMain.context.uc_stack.ss_sp = stack ;
    taskMain.context.uc_stack.ss_size = STACKSIZE ;
    taskMain.context.uc_stack.ss_flags = 0 ;
    taskMain.context.uc_link = 0 ;
    taskMain.Sprio = 20;
    taskMain.Dprio = 20; 
    atual = &taskMain ; // salva o contexto atual na variável MAIs
   task_create(&disp,(void*)Dispatcher,NULL);
    printf("criou dispatcher \n");
}
else{
    perror ("Erro na criação da pilha: ") ;
    exit (1) ;
}
}

void task_setprio (task_t *task, int prio){
    printf("ENTROU  set \n");
    task->Dprio = prio;
    task->Sprio = prio;
}

int task_getprio (task_t *task){
    if (task == NULL) 
	    return task->Dprio;
    return task->Dprio;
}

task_t * scheduler(){ //  funcao que encaminha para o proximo 
	task_t * head = pont_dispatcher ;
    if (head->next != NULL)
	return head->next;


return head;
}


void Dispatcher(){
    int cont = 0;
    //printf(" entrou no dispatcher \n");
    task_t * proximo = &(*Filadispatcher) ; // 
    pont_dispatcher = &(*Filadispatcher); // salva o valor inicial do pont_dispatcher que ira percorrer a fila do dispatcher
    while (usersTask>0){ // enquanto a task nao for igual a 0
        printf("entrou no dispatcher \n");
        proximo = scheduler(); // pega o proximo elemento da filaDispatcher
        pont_dispatcher = proximo; //salva a posicao do elemento da fila que sera usado na funcao schuduler
        if (proximo != NULL){// 
         printf("entrou no dispatcher IF \n");
            task_switch(&(*proximo->prev)); // troca pra task anterior
        }
        cont++;
        printf("cont %d \n",cont);
       
    }
    //printf("saiu do dispatcher");
    exit(0); // voltou pra main 
}

void task_yield (){ // entra no dispatcher
    task_switch(&(disp));
}
/*task: estrutura que referencia a tarefa criada
start_routine: função que será executada pela tarefa
arg: parâmetro a passar para a tarefa que está sendo criada
retorno: o ID (>0) da tarefa criada ou um valor negativo, se houver erro
*/
int task_create (task_t *task, void (*start_routine)(void *),  void *arg) { //cria task  
    char *stack;
    getcontext(&task->context);
    stack = malloc (STACKSIZE) ;
    if (stack) // verifica se a stack que armazenara os valores da tarefa foi armazenado com sucesso
    {
        printf("criou task\n");
        task->context.uc_stack.ss_sp = stack ;
        task->context.uc_stack.ss_size = STACKSIZE ;
        task->context.uc_stack.ss_flags = 0 ;
        task->context.uc_link = 0 ;
        task->id = num_task++; 
        if (num_task>1){
            usersTask++;
            
            queue_append((queue_t **)&Filadispatcher, (queue_t *) task);
            task->status = AGUARDANDO;
        
            }
    }
    else {
    perror ("Erro na criação da pilha: ") ;
    exit (1) ;
    }
    makecontext(&(task->context),(void*)(*start_routine), 1,arg); //salva o contexto da task criada e começa uma rotina
    
    return 0;
}

int task_switch (task_t *task){ // troca de tarefa
    printf("entrou no task_switch \n");
    task_t * old;
    old =  atual;
    atual = task;
    swapcontext (&(old->context), &(atual->context)); // TROCA O CONTEXTO DA TAREFA SAI DE old e vai para a nova atual 
    return 0;
}


void task_exit (int exit_code){
    // enquanto as fila nao for diferente do header retorna pro dispatcher  
    if (&disp == atual){
    task_switch (&taskMain); //retorna para task main 
    }
    else{
          task_yield();
    }
}
int task_id (){ // retorna o id da tarefa em execução
    return atual->id;
}