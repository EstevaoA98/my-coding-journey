
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
    float salario;

} Funcionario;

#define MAX_FUNCIONARIO 3

void CadastrodeFuncionario(Funcionario *cadastro)
{
    getchar();
    printf("Nome do funcionario: ");
    fgets(cadastro->nome, sizeof(cadastro->nome), stdin);
    cadastro->nome[strcspn(cadastro->nome, "\n")] = '\0';
    
    
    printf("Idade: ");
    scanf("%d", &cadastro->idade);
    getchar();

    printf("Valor do salario: ");
    scanf("%f", &cadastro->salario);
    getchar();
}

void CalcularIRPF(Funcionario *calculo)
{
    float IRPF;
    IRPF = calculo->salario * 0.20;

    printf("Funcionario: %s pagara %.2f de imposto de renda", calculo->nome, IRPF);
    getchar();
}
int main()
{
    int op, quantidadeFumcionario = 0;
    Funcionario funcionario[MAX_FUNCIONARIO];

    {
        while (1)
        {
            printf("\n1. Cadastrar um Funcionario\n2. Calcular o IPRF desse funcionario\n3. Sair\n");
            scanf("%d", &op);
            

            switch (op)
            {
            case 1:
                if (quantidadeFumcionario < MAX_FUNCIONARIO)
                {
                    CadastrodeFuncionario(&funcionario[quantidadeFumcionario]);
                    quantidadeFumcionario++;

                    break;
                }
                else
                {
                    printf("Limite de contas cadastradas!");
                    break;
                }

            case 2:
                for (int i = 0; i < quantidadeFumcionario; i++)
                {
                    CalcularIRPF(&funcionario[i]);
                }

                break;
            case 3:
                printf("Saindo");
                break;

            default:
                break;
            }
        }
    }
    return 0;
}
