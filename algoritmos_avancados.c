#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Estrutura da Sala ---
typedef struct Sala {
    char nome[50];          // Nome do cômodo
    struct Sala *esquerda;  // Caminho à esquerda
    struct Sala *direita;   // Caminho à direita
} Sala;

// --- Função para criar uma sala ---
Sala* criarSala(const char *nome) {
    Sala *novaSala = (Sala*) malloc(sizeof(Sala));
    if (!novaSala) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

// --- Função para explorar a mansão ---
void explorarSalas(Sala *salaAtual) {
    if (!salaAtual) return;

    printf("\nVocê está na: %s\n", salaAtual->nome);

    // Se não há caminhos, fim da exploração
    if (!salaAtual->esquerda && !salaAtual->direita) {
        printf("Esta sala não possui mais caminhos. Fim da exploração!\n");
        return;
    }

    char escolha;
    do {
        printf("Escolha para onde ir - esquerda (e), direita (d) ou sair (s): ");
        scanf(" %c", &escolha);

        if (escolha == 'e') {
            explorarSalas(salaAtual->esquerda);
            break;
        } else if (escolha == 'd') {
            explorarSalas(salaAtual->direita);
            break;
        } else if (escolha == 's') {
            printf("Exploração encerrada pelo jogador.\n");
            return;
        } else {
            printf("Opção inválida! Digite 'e', 'd' ou 's'.\n");
        }
    } while (1);
}

// --- Função principal ---
int main() {
    // Criando salas da mansão
    Sala *hall = criarSala("Hall de Entrada");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *cozinha = criarSala("Cozinha");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *jardim = criarSala("Jardim");
    Sala *quartoSecreto = criarSala("Quarto Secreto");
    Sala *sotao = criarSala("Sótão Misterioso");

    // Montando a árvore binária da mansão
    hall->esquerda = biblioteca;
    hall->direita = cozinha;

    biblioteca->esquerda = salaEstar;
    biblioteca->direita = jardim;

    cozinha->esquerda = quartoSecreto;
    cozinha->direita = sotao;

    // Início da exploração
    printf("Bem-vindo(a) ao Detective Quest! Explore a mansão.\n");
    explorarSalas(hall);

    // Liberar memória
    free(hall);
    free(biblioteca);
    free(cozinha);
    free(salaEstar);
    free(jardim);
    free(quartoSecreto);
    free(sotao);

    printf("Obrigado por jogar!\n");
    return 0;
}
