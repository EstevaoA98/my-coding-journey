/*
1. Cadastrar conta bancaria
2. Realizar deposito
3. Relizar saque (se for conta correte - 5 reias)
4. Listar todas contas
5. Exibir uma conta em espeficio exibindo a idade atual do titular ao inves do ano de nascimento
6. Sair

A conta bancaria possui:
- Numero da conta
- Tipo de conta (poupanca ou conta-corrente)
- Saldo
- titular da conta

O titular possui:
- Nome
- Ano de nascimento
- CPF
*/
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char nome[30];
    int anoNascimento;
    char cpf[15];
} Usuario;

typedef struct
{
    int numeroConta;
    int contaPoupanca;
    int contaCorrente;
    float saldo;
    Usuario usuario;
} Conta;

#define Totalcontas 100

int main()
{
    int opcao, tipodeconta, numeroDecontaParaSaque, numeroDecontaParaDeposito, quantidade_conta = 0;
    float valorsaque, valordeposito;
    Conta conta[Totalcontas]; // 100

    while (1)
    {
        printf("\n1. Cadastrar conta bancaria\n2. Realizar deposito\n3. Realizar saque (se for conta corrente - 5 reais)\n4. Listar todas contas\n5. Buscar conta\n6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // Cadastrar conta bancaria
            printf("\n---- Cadastrar conta bancaria ----\n"); 

            bool contaExiste = false;
            bool cpfExiste = false;

            printf("Digite\n1. Conta poupanca \n2. Conta Corrente\n");
            scanf("%d", &tipodeconta);

            if (tipodeconta != 1 && tipodeconta != 2)
            {
                printf("Tipo de conta invalido!\n");
                break;
            }

            int numeroConta;
            printf("Digite o numero da conta: ");
            scanf("%d", &numeroConta);
            getchar();

            for (int i = 0; i < quantidade_conta; i++)
            {
                if (conta[i].numeroConta == numeroConta)
                {
                    printf("Numero de conta ja existe! Tente novamente.\n");
                    contaExiste = true;
                    break;
                }
            }

            if (contaExiste)
                break;

            char cpf[15];
            printf("Digite o CPF: ");
            fgets(cpf, sizeof(cpf), stdin);
            cpf[strcspn(cpf, "\n")] = '\0';

            for (int i = 0; i < quantidade_conta; i++)
            {
                if (strcmp(conta[i].usuario.cpf, cpf) == 0)
                {
                    printf("CPF ja existe! Tente novamente.\n");
                    cpfExiste = true;
                    break;
                }
            }

            if (cpfExiste)
                break;

            if (tipodeconta == 1)
            {
                printf("Conta poupanca escolhida!\n");
                conta[quantidade_conta].contaPoupanca = tipodeconta;
            }
            else if (tipodeconta == 2)
            {
                printf("Conta Corrente escolhida!\n");
                conta[quantidade_conta].contaCorrente = tipodeconta;
            }

            conta[quantidade_conta].numeroConta = numeroConta;
            strcpy(conta[quantidade_conta].usuario.cpf, cpf);

            printf("\nDigite o nome do usuario: \n");
            fgets(conta[quantidade_conta].usuario.nome, sizeof(conta[quantidade_conta].usuario.nome), stdin);
            conta[quantidade_conta].usuario.nome[strcspn(conta[quantidade_conta].usuario.nome, "\n")] = '\0';

            printf("Ano de nascimento: \n");
            scanf("%d", &conta[quantidade_conta].usuario.anoNascimento);
            getchar();

            printf("Saldo: \n");
            scanf("%f", &conta[quantidade_conta].saldo);
            getchar();

            quantidade_conta++;
            printf("Conta Cadastrada com sucesso");
            break;

        case 2: // Realizar deposito
            printf("\n---- Realizar deposito ----\n");
            bool contaEncontrada = false;
            while (!contaEncontrada)
            {

                printf("Digite o numero da conta:\n");
                scanf("%d", &numeroDecontaParaDeposito);
                for (int i = 0; i < quantidade_conta; i++)
                {

                    if (conta[i].numeroConta == numeroDecontaParaDeposito)
                    {
                        printf("Digite o valor que deseja depositar:\n");
                        scanf("%f", &valordeposito);
                        getchar();

                        conta[i].saldo += valordeposito;

                        printf("Seu saldo e: R$%.2f\n", conta[i].saldo);
                        contaEncontrada = true;
                        break;
                    }
                }
                if (!contaEncontrada)
                {
                    printf("Conta nao econtrado.\n");
                }
            }
            break;

        case 3: // Realizar saque (se for conta corrente - 5 reais)
            printf("\n---- Realizar saque ----\n");
            contaEncontrada = false;
            while (!contaEncontrada)
            {
                printf("digite a conta para verificar o saldo:\n");
                scanf("%d", &numeroDecontaParaSaque);
                getchar();
                for (int i = 0; i < quantidade_conta; i++)
                {

                    if (conta[i].numeroConta == numeroDecontaParaSaque)
                    {

                        printf("Titular: %s\n", conta[i].usuario.nome);
                        printf("Seu em saldo e de R$%.2f\n", conta[i].saldo);
                        printf("Digite o valor para saque: ");
                        scanf("%f", &valorsaque);
                        getchar();

                        if (conta[i].contaPoupanca == 1)
                        {
                            if (conta[i].saldo >= valorsaque)
                            {
                                conta[i].saldo -= valorsaque;
                                printf("Saque de R$%.2f realizado.\n", valorsaque);
                                printf("Saldo atual: R$%.2f\n", conta[i].saldo);
                                contaEncontrada = true;
                                break;
                            }
                        }
                        else
                        {
                            printf("Saque excedente ao limite em conta.\n");
                        }
                    }
                    else if (conta[i].contaCorrente == 2)
                    {
                        if (conta[i].saldo >= valorsaque + 5)
                        {
                            conta[i].saldo -= (valorsaque + 5);
                            printf("Saque de R$%.2f realizado.\n", valorsaque);
                            printf("Taxa de R$5,00 debitada da conta.\n");
                            printf("Saldo atual: R$%.2f\n", conta[i].saldo);
                            contaEncontrada = true;
                            break;
                        }
                        else
                        {
                            printf("Saque excedente ao limite em conta.\n");
                        }
                    }
                }
            }
            break;
        case 4:
            printf("\n---- Listar todas as contas ----\n");
            for (int i = 0; i < quantidade_conta; i++)
            {
                printf("Seu nome e: %s\n", conta[i].usuario.nome);
                printf("Seu cpf: %s\n", conta[i].usuario.cpf);
                printf("Data de nascimento: %d\n", conta[i].usuario.anoNascimento);
                printf("Numero da conta: %d\n", conta[i].numeroConta);
                printf("Saldo Atual: R$%.2f\n", conta[i].saldo);

                if (conta[i].contaPoupanca == 1)
                {
                    printf("Conta PoupanÃ§a\n");
                }
                else if (conta[i].contaCorrente == 2)
                {
                    printf("Conta corrente\n");
                }

                printf("\n---------------------------\n");
            }
            break;

        case 5:
            printf("\n---- Buscar conta ----\n");

            printf("\nDigite o numero da conta: \n");
            scanf("%d", &numeroConta);
            getchar();

            for (int i = 0; i < quantidade_conta; i++)
            {
                if (conta[i].numeroConta == numeroConta)
                {

                    printf("Nome do usuario: %s\n", conta[i].usuario.nome);
                    printf("CPF do usuario: %s\n", conta[i].usuario.cpf);
                    printf("Numero da conta: %d\n", conta[i].numeroConta);
                    printf("Saldo Atual: R$%.2f\n", conta[i].saldo);

                    int anoAtual, idade;

                    time_t tempo = time(NULL);
                    struct tm dataAtual = *localtime(&tempo);

                    anoAtual = dataAtual.tm_year + 1900;

                    idade = anoAtual - conta[i].usuario.anoNascimento;

                    printf("idade: %d anos", idade);
                }
            }
            break;

        case 6: // Sair
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
        }
    }
    return 0;
}
