#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATERIAIS 100

struct Material {
    int codigo;
    char descricao[100];
    int quantidade;
    int estoqueMinimo;
    int estoqueMaximo;
};

// Resto do c�digo permanece o mesmo

void cadastrarMaterial(struct Material materiais[], int *tamanho) {
    if (*tamanho >= MAX_MATERIAIS) {
        printf("Limite de materiais atingido.\n");
        return;
    }

    printf("Digite o c�digo do material: ");
    scanf("%d", &materiais[*tamanho].codigo);
    printf("Digite a descri��o do material: ");
    scanf(" %[^\n]", materiais[*tamanho].descricao);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &materiais[*tamanho].quantidade);
    printf("Digite o estoque m�nimo: ");
    scanf("%d", &materiais[*tamanho].estoqueMinimo);
    printf("Digite o estoque m�ximo: ");
    scanf("%d", &materiais[*tamanho].estoqueMaximo);

    (*tamanho)++;
}

int main() {
    struct Material materiais[MAX_MATERIAIS];
    int tamanho = 0;

    // Carrega a lista de materiais do arquivo
    tamanho = carregarLista(materiais);

    int escolha;
    while (1) {
        printf("---------------------\n");
        printf("Programa de cadastro de materiais\n");
        printf("Selecione a op��o desejada:\n");
        printf("1 - Cadastrar Material\n");
        printf("2 - Mostrar invent�rio\n");
        printf("3 - Registrar entrada de material\n");
        printf("4 - Registrar sa�da de material\n");
        printf("5 - Salvar e Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                Cadastrar Material();
                break;
            case 2:
                Mostrar Inventario();
                break;
            case 3:
                Registrar Entrada();
                break;
            case 4:
                Registrar Saida();
                break;
            case 5:
                // Salva a lista de materiais no arquivo antes de sair
                salvarLista();
                exit(0);
            default:
                printf("Op��o inv�lida.\n");
        }
    }

    return 0;
}
