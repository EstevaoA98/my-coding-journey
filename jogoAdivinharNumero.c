
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int inicio, final, aleatorio, tentativa, tentativausa, resposta, i;
   
    printf("\n ---JOGO DE ADIVINHACAO---\n\n");

    // RF01. Escolha do Intervalo: o jogador pode definir o intervalo de números, dentro do qual um número deve ser adivinhado
    printf("Digite o limite inicial: ");
    scanf("%d", &inicio);


 printf("Digite o limite final: ");
    scanf("%d", &final);

while (final <= inicio)
{
    printf("Digite um valor meior que o inicial!\n");
    printf("Digite o limite final: ");
    scanf("%d", &final);
 }
  
    // RF02. Geração de Números Aleatórios: o programa deve gerar um número aleatório no intervalo definido.
    srand(time(0));
    aleatorio = inicio + rand() % (final - inicio + 1);

    // RF03. Entrada do Jogador: permitir que o jogador insira tentativas para adivinhar o número.
    printf("Para sair do jogo, digite '0' a qualquer momento.\n");
    printf("Quantas tentativas deseja para adivinhar o n�mero: \n");
    
while (final <= tentativa)
{
    printf("Digite um valor igual ou menor do que o maximo! ");
    scanf("%d", &tentativa);
}

    // RF04. Fornecimento de Dicas: informar aseo jogador  o número adivinhado é maior, menor ou igual ao número gerado.
    for (i = 0; i < tentativa; i++) {
        printf("Tentativa %d de %d. Digite sua resposta: ", i + 1, tentativa);
        scanf("%d", &resposta);

        // RG06. Opção de Sair: permitir que o jogador encerre o jogo a qualquer momento.
        if (resposta == 0) {
            printf("Jogo finalizado!\n");
            break;
        }
        
        if (resposta == aleatorio) {
            printf("Parabens, voce acertou o numero!!!\n");
            tentativausa = i + 1;
            printf("Voc� usou %d tentativas.\n", tentativausa);
            break;
        }
        else if (resposta < aleatorio) {
            printf("O numero e maior!\n");
        }
        else {
            printf("O numero e menor!\n");
        }

        //RF07. Mensagem de Encerramento: exibir uma mensagem de encerramento, informando o número de tentativas realizadas.
        if (i == tentativa - 1) {
            printf("Suas tentativas acabaram! \nO numero aleatorio era: %d\n", aleatorio);
            printf("Jogo finalizado.\n");
            
        }
    }

    return 0;
}
