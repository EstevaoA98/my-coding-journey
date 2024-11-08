#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int hora;
    int minuto;
} Relogio;

typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct
{
    char descricao[50];
    Data data;
    Relogio relogio;
    bool status;
} Tarefa;

#define MAX_TAREFAS 100

int main()
{
    int opcao, cont_tarefas = 0;
    Tarefa tarefa[MAX_TAREFAS];

    while (1)
    {
        //Opcao do usuario.
        printf("\nEscolha uma opcao:\n1. Cadastrar uma nova tarefa\n2. Listar todas as tarefas Pendentes\n3. Listar todas as tarefas Concluidas\n4. Sair\n\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1://Cadastrar uma nova tarefa

            if (cont_tarefas == MAX_TAREFAS)
            {
                printf("Nao e possivel cadastrar novas tarefas");
                break;
            }
            // Da linha 58 a 79 entrada de dados da tarefa.
            printf("Informe a descricao da tarefa: ");
            fgets(tarefa[cont_tarefas].descricao, sizeof(tarefa[cont_tarefas].descricao), stdin);
            tarefa[cont_tarefas].descricao[strcspn(tarefa[cont_tarefas].descricao, "\n")] = '\0';

            printf("Informe a dia: ");
            scanf("%d", &tarefa[cont_tarefas].data.dia);
            getchar();

            printf("Informe o mes: ");
            scanf("%d", &tarefa[cont_tarefas].data.mes);
            getchar();

            printf("Informe o ano: ");
            scanf("%d", &tarefa[cont_tarefas].data.ano);
            getchar();

            printf("Informe a hora: ");
            scanf("%d", &tarefa[cont_tarefas].relogio.hora);
            getchar();

            printf("Informe os minutos: ");
            scanf("%d", &tarefa[cont_tarefas].relogio.minuto);
            getchar();

            while (1)
            {
                // Solicita o status da tarefa.
                printf("Qual o status da tarefa? (1 - Concluida, 2 - Pendente) \n");
                int status_usuario;
                scanf("%d", &status_usuario);
                getchar();

                if (status_usuario == 1)
                {
                    tarefa[cont_tarefas].status = true;
                    break;
                }
                else if (status_usuario == 2)
                {
                    tarefa[cont_tarefas].status = false;
                    break;
                }
                else
                {
                    printf("Invalida.\n");
                }
            }

            cont_tarefas++;

            break;
        //Listar todas as tarefas Pendentes    
        case 2:

            for (int i = 0; i < cont_tarefas; i++)
            {
                if (tarefa[i].status == false)
                {
                    printf("\nDescricao: %s\n", tarefa[i].descricao);
                    printf("Data: %d/%d/%d\n", tarefa[i].data.dia, tarefa[i].data.mes, tarefa[i].data.ano);
                    printf("Hora: %d:%d\n", tarefa[i].relogio.hora, tarefa[i].relogio.minuto);
                    printf("Status: Pendente\n");
                    printf("\n----------------------------------------------------\n");
                }
            }
            break;
        //Listar todas as tarefas Concluidas
        case 3:

            for (int i = 0; i < cont_tarefas; i++)
            {
                if (tarefa[i].status == true)
                {
                    printf("\nDescricao: %s\n", tarefa[i].descricao);
                    printf("Data: %d/%d/%d\n", tarefa[i].data.dia, tarefa[i].data.mes, tarefa[i].data.ano);
                    printf("Hora: %d:%d\n", tarefa[i].relogio.hora, tarefa[i].relogio.minuto);
                    printf("Status: Concluida\n");
                    printf("\n----------------------------------------------------\n");
                }
            }
            break;
        // sair.    
        case 4:
            printf("Encerrando...");
            return 0;
            break;

        default:
            printf("Opcao invalida.\n");
            break;
        }
    }
}