/*Autor: Eduardo Soares de Sousa*/
#include <stdio.h>
#include <string.h>
#define FUN_NAME 5 /*nomes dos 5 funcionários*/
#define MAX 50 /*tamanho máximo de cada string*/
#define MAX_SAL 5

void bubble_sort(float array[], float n);
void selection_sort(float array1[], float n1);
void insertion_sort(char array_name[][MAX], int n2);
int menu();

int main(int argc, char const *argv[]){
    
    char nome[FUN_NAME][MAX];
    float salario[MAX_SAL];
    int i, option;

    printf("\n----------------------------------------------\n\n");

    for(i = 0; i < FUN_NAME; i++){
        printf("Digite o nome do %dº funcionário: ", i+1);
        fgets(nome[i], MAX, stdin);

        printf("\n");

        nome[i][strcspn(nome[i], "\n")] = '\0';
    }

    printf("\n----------------------------------------------\n\n");

    for(i = 0; i < MAX_SAL; i++){
        printf("Digite o salário do(a) %s: ", nome[i]);
        scanf("%f", &salario[i]);
        printf("\n");
    }

    do{
        option = menu();

        switch(option){
        case 1:

            printf("\n----------------------------------------------\n\n");
    
            bubble_sort(salario, MAX_SAL);
    
            printf("Salário dos funcionários em ordem crescente: \n");
            for(i = 0; i < MAX_SAL; i++){
                printf("%s: R$ %.2f\n", nome[i], salario[i]);
            }
            
            break;
        
        case 2:

            printf("\n----------------------------------------------\n\n");

            selection_sort(salario, MAX_SAL);

            printf("Salário dos funcionários em ordem decrescente: \n");
            for(i = 0; i < MAX_SAL; i++){
                printf("%s: R$ %.2f\n", nome[i], salario[i]);
            }

            break;

        case 3:

            printf("\n----------------------------------------------\n\n");

            insertion_sort(nome, FUN_NAME);

            printf("Nomes em ordem alfabética: \n");
            for(i = 0; i < FUN_NAME; i++){
                printf("%s\n", nome[i]);
            }

            break;
        }
    
    }while(option > 0 && option <= 3);

    if(option == 0){
        printf("\n\n=====SISTEMA ENCERRADO=====\n\n");
    }else{
        if( (option > 3) || (option < 0) ){
            printf("\n-=-=-=-=-=-OPÇÃO INVÁLIDA-=-=-=-=-=-\n\n");
        }
    }

    return 0;
}

int menu(){
    int option;

    printf("\t--------------------------------------------------------------------\n\n");
    printf("\t=====Selecione a opção que deseja=====\n");
    printf("\t1 - Mostrar a lista de salários em ordem crescente......:\n");
    printf("\t2 - Mostrar a lista de salários em ordem decrescente.........:\n");
    printf("\t3 - Mostrar a lista dos funcionários em ordem alfabética................:\n");
    printf("\t0 - Sair.\n\n");
    printf("Digite a opção desejada...: ");
    scanf("%d", &option);

    return option;
}

void bubble_sort(float array[], float n){
    int i, j;
    float auxiliar;

    for(i = 0; i < n-1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(array[j] > array[j+1]){

                auxiliar = array[j];
                array[j] = array[j+1];
                array[j+1] = auxiliar;
            }
            
        }
        
    }
    
}

void selection_sort(float array1[], float n1){
    int i, j;
    int maior, troca;

    for(i = 0; i < n1-1; i++){
        maior = i;

        for(j = i + 1; j < n1; j++){
            if(array1[j] > array1[maior]){
                maior = j;
            }
            
        }

        if(i != maior){
            troca = array1[i];
            array1[i] = array1[maior];
            array1[maior] = troca;
        }
    } 
}

void insertion_sort(char array_name[][MAX], int n2){
    int i, j;
    char key[MAX];

    for (i = 1; i < n2; i++) {
        strcpy(key, array_name[i]);
        j = i - 1;

        while (j >= 0 && strcmp(array_name[j], key) > 0) {
            strcpy(array_name[j + 1], array_name[j]);
            j = j - 1;
        }

        strcpy(array_name[j + 1], key);
    }
}