#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct celula{
    char *s;
    struct celula *seg; 
}Celula;

int r = 0, first = 0;
char buffer[100];
Celula *head, *last;

void initializeHead(){
    head = malloc(sizeof(Celula));
    head->s = NULL;
    head->seg = NULL;
    last = head;
    first = 1;
}

void addTask(Celula **last, char *task) {
    Celula *new = malloc(sizeof(Celula));
    new->s = malloc(strlen(task) + 1);
    strcpy(new->s, task);
    new->seg = NULL;
    (*last)->seg = new;
    *last = new; 
}

void printTasks(Celula *head){
    Celula *current;
    current = head->seg;
    int numeroTask = 1;
    printf("\nLista de Tarefas");
    while(current->s != NULL){
        if(current->seg == NULL){
            printf("\n%d - %s\n\n", numeroTask, current->s);
            break;
        }
        printf("\n%d - %s", numeroTask, current->s);
        current = current->seg;
        numeroTask++;
    }
}

int main(){
    printf("---- Bem vindo a lista de tarefas! ----");
    while(1){
        printf("\n1 - Adicionar tarefa\n2 - Ver a Lista\n3 - Sair");
        scanf(" %d" , &r);
        getchar();
        switch(r){
            case 1:
                if(!first)
                    initializeHead();
                printf("Digite a tarefa para adicionar!");
                scanf(" %[^\n]", buffer);
                addTask(&last, buffer);
                break;
            case 2:
                printTasks(head);
                break;
            default:
                return 0;
        }
    }   
    
    return 0;
}




