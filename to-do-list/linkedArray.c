#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct cel{
    char *content;
    struct cel *next;  
};

typedef struct cel celula;
celula *head = NULL;
int conter = 0;
int key = 0;
char task[300];

void addValueToLinkedArray(celula *head, char string[]){
    celula *current = head;
    celula *new_node = malloc(sizeof(celula));
    
    new_node->content = (char *)malloc(100 * sizeof(char));
    strcpy(new_node->content, string);

    new_node->next = NULL;

    while(current->next != NULL){
        printf("Aqui");
        current = current->next;
    }
    current->next = new_node;
}

void printTasks(celula *head){
    celula *current = head;
    int count = 1;
    while (current->next != NULL){
        printf("%d - %s", count ,current->content);
        current = current->next;
    }
    count++;
}

int main(){
    head = malloc(sizeof(celula));
    head->next = NULL;
    while (conter == 0){
        printf(" -- LISTA DE TAREFAS -- ");
        printf("O que deseja fazer?\n 1-Adicionar tarefa\n 2-Visualizar tarefas");
        scanf("%d", &key);
        switch(key){
            case 1:
                printf("Digite a tarefa que deseja adicionar!");
                scanf("%s", task);
                addValueToLinkedArray(head, task);
                printf("Tarefa adicionada com sucesso!");
                break;
            case 2:
                printTasks(head);
                break;
        }
    }
    
    return 0;
}




