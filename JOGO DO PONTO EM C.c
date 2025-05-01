#include <stdio.h>

// Protótipos das funções
void exibirMenu();
void trocar(int *a, int *b);
void somar(int *a, int *b);
void mostrarVencedor(int *a, int *b);
void alterarValor(int *alvo);
void mostrarEnderecos(int *a, int *b);
void adicionarPontos(int *alvo);

int main() {
    int jogador1 = 0, jogador2 = 0;
    int turno = 1; // 1 para jogador 1, 2 para jogador 2
    int vencedor = 0;

    do {
        printf("\n--- Rodada %d (Jogador %d) ---\n", (turno+1)/2, turno);
        printf("Jogador 1: %d pontos\n", jogador1);
        printf("Jogador 2: %d pontos\n", jogador2);

        exibirMenu();
        int opcao;
        printf("Escolha uma acao: ");
        scanf("%d", &opcao);

        int *alvo = (turno == 1) ? &jogador2 : &jogador1;

        switch (opcao) {
            case 1:
                adicionarPontos(alvo);
                break;
            case 2:
                trocar(&jogador1, &jogador2);
                break;
            case 3:
                somar(&jogador1, &jogador2);
                break;
            case 4:
                printf("Alterar qual jogador? (1/2): ");
                int escolha;
                scanf("%d", &escolha);
                if (escolha == 1) alterarValor(&jogador1);
                else if (escolha == 2) alterarValor(&jogador2);
                else printf("Jogador invalido!\n");
                break;
            case 5:
                mostrarEnderecos(&jogador1, &jogador2);
                break;
            case 6:
                printf("Encerrando...\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }

        // Verifica condição de vitória
        if (jogador1 >= 15 || jogador2 >= 15) {
            vencedor = (jogador1 >= 15) ? 2 : 1;
            break;
        }

        // Alterna turno
        turno = (turno == 1) ? 2 : 1;

    } while (1);

    printf("\nJOGADOR %d VENCEU!\n", vencedor);
    return 0;
}

void exibirMenu() {
    printf("1. Adicionar pontos (1-5) ao adversario\n");
    printf("2. Trocar pontos com adversario\n");
    printf("3. Somar pontos\n");
    printf("4. Alterar valor manual\n");
    printf("5. Mostrar enderecos\n");
    printf("6. Sair\n");
}

void adicionarPontos(int *alvo) {
    int pontos;
    do {
        printf("Quantos pontos adicionar (1-5)? ");
        scanf("%d", &pontos);
    } while (pontos < 1 || pontos > 5);
    
    *alvo += pontos;
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void somar(int *a, int *b) {
    int total = *a + *b;
    *a = total;
    *b = total;
}

void alterarValor(int *alvo) {
    printf("Novo valor: ");
    scanf("%d", alvo);
}

void mostrarEnderecos(int *a, int *b) {
    printf("Endereco Jogador 1: %p\n", (void*)a);
    printf("Endereco Jogador 2: %p\n", (void*)b);
}

void mostrarVencedor(int *a, int *b) {
    if (*a > *b) printf("Jogador 1 esta vencendo!\n");
    else if (*b > *a) printf("Jogador 2 esta vencendo!\n");
    else printf("Empate!\n");
}