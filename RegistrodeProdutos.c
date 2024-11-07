#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    int n, i;
    // Solicita a quantidade de produtos que o usuario deseja salvar.
    printf("Quantos produtos deseja inserir? ");
    scanf("%d", &n);

    struct Produto produtos[n];

    getchar();
    // Cadastro dos produtos.
    for (i = 0; i < n; i++) {
        printf("\nProduto %d:\n", i + 1);

        // Lendo o nome do produto.
        printf("Digite o nome do produto: ");
        fgets(produtos[i].nome, 50, stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0'; 

       
        printf("Digite o preco do produto: ");
        scanf("%f", &produtos[i].preco);

        
        printf("Digite a quantidade do produto: ");
        scanf("%d", &produtos[i].quantidade);
        getchar();
    }
    // Listagem de todos os produtos cadastrados.
    printf("\nProdutos cadastrados:\n");
    for (i = 0; i < n; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n", produtos[i].quantidade);
    }

    return 0;
}