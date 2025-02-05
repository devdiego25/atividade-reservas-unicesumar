#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_RESERVAS 100

typedef struct {
    char nome[100];
    char cpf[15];
    int dia;
    int quantidade;
} Reserva;

Reserva reservas[MAX_RESERVAS];
int total_reservas = 0;

void fazerReserva();
void listarReservas();
void totalPessoasPorDia();
void limparBuffer();

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        system("cls");
        printf("=== Sistema de Reservas de Restaurante ===\n");
        printf("1 - Fazer Reserva\n");
        printf("2 - Listar Reservas\n");
        printf("3 - Total de Pessoas por Dia\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                fazerReserva();
                break;
            case 2:
                listarReservas();
                break;
            case 3:
                totalPessoasPorDia();
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                system("pause");
        }
    } while (opcao != 4);

    return 0;
}

void limparBuffer() {
    fflush(stdin);
}

void fazerReserva() {
    if (total_reservas >= MAX_RESERVAS) {
        printf("Limite de reservas atingido.\n");
        system("pause");
        return;
    }

    Reserva r;

    printf("Digite o nome do responsável pela reserva: ");
    fgets(r.nome, 100, stdin);
    r.nome[strcspn(r.nome, "\n")] = '\0';

    printf("Digite o CPF: ");
    fgets(r.cpf, 15, stdin);
    r.cpf[strcspn(r.cpf, "\n")] = '\0';

    printf("Digite o dia da reserva (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo): ");
    scanf("%d", &r.dia);
    limparBuffer();

    if (r.dia < 1 || r.dia > 4) {
        printf("Dia inválido. Reserva não realizada.\n");
        system("pause");
        return;
    }

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &r.quantidade);
    limparBuffer();

    reservas[total_reservas++] = r;

    printf("Reserva realizada com sucesso!\n");
    system("pause");
}

void listarReservas() {
    system("cls");
    printf("=== Lista de Reservas ===\n");
    for (int i = 0; i < total_reservas; i++) {
        printf("Nome: %s\n", reservas[i].nome);
        printf("CPF: %s\n", reservas[i].cpf);
        printf("Dia: %d\n", reservas[i].dia);
        printf("Número de Pessoas: %d\n", reservas[i].quantidade);
        printf("===============================\n");
    }

    if (total_reservas == 0) {
        printf("Nenhuma reserva cadastrada.\n");
    }

    system("pause");
}

void totalPessoasPorDia() {
    int dia, total = 0;

    printf("Digite o dia (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo): ");
    scanf("%d", &dia);
    limparBuffer();

    if (dia < 1 || dia > 4) {
        printf("Dia inválido.\n");
        system("pause");
        return;
    }

    for (int i = 0; i < total_reservas; i++) {
        if (reservas[i].dia == dia) {
            total += reservas[i].quantidade;
        }
    }

    printf("Total de pessoas reservadas para o dia %d: %d\n", dia, total);
    system("pause");
}
