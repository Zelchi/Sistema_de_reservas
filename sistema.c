#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu();
void fazerReserva();
void listarReserva();
void totalPessoas();
int contarPessoas(int dia);
void despedida();
int voltarMenu;

typedef struct
{
    char nome[64];
    char cpf[64];
    int dia;
    int numeroPessoas;
} Reserva;

Reserva reservas[64];
int quantidadeReservas = 0;

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    voltarMenu = 1;
    do
    {
        system("cls");
        menu();
    } while (voltarMenu);

    return 0;
}

void menu()
{
    int menu;

    printf("---------------------------\n1 - Fazer reserva\n2 - Lista de reservas\n3 - Total de pessoas por dia\n4 - Sair\n---------------------------\n");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        system("cls");
        fazerReserva();
        break;
    case 2:
        system("cls");
        listarReserva();
        break;
    case 3:
        system("cls");
        totalPessoas();
        break;
    default:
        system("cls");
        despedida();
        break;
    }
}

void fazerReserva()
{
    printf("Nome: ");
    scanf(" %[^\n]", reservas[quantidadeReservas].nome);

    printf("CPF: ");
    scanf("%s", reservas[quantidadeReservas].cpf);
    
    printf("1 - Quinta\n2 - Sexta\n3 - Sábado\n4 - Domingo\nInforme o dia da reserva: ");
    scanf("%d", &reservas[quantidadeReservas].dia);

    printf("Quantidade de Pessoas: ");
    scanf("%d", &reservas[quantidadeReservas].numeroPessoas);

    quantidadeReservas++;
    fflush(stdin);

    system("cls");
    printf("Reserva feita com sucesso!\n");
    system("pause");
}

int contarPessoas(int dia)
{
    int contador = 0;

    for (int i = 0; i <= quantidadeReservas; i++)
    {
        if (dia == reservas[i].dia)
        {
            int quantidadePessoas = reservas[i].numeroPessoas;
            contador += quantidadePessoas;
        }
    }

    return contador;
}

void totalPessoas()
{
    int dia;

    printf("1 - Quinta\n2 - Sexta\n3 - Sábado\n4 - Domingo\n5 - Sair\n");
    scanf("%d", &dia);

    switch (dia)
    {
    case 1:
        system("cls");
        printf("Quantidade de pessoas na Quinta: %d\n\n", contarPessoas(dia));
        totalPessoas();
        break;
    case 2:
        system("cls");
        printf("Quantidade de pessoas na Sexta: %d\n\n", contarPessoas(dia));
        totalPessoas();
        break;
    case 3:
        system("cls");
        printf("Quantidade de pessoas no Sábado: %d\n\n", contarPessoas(dia));
        totalPessoas();
        break;
    case 4:
        system("cls");
        printf("Quantidade de pessoas no Domingo: %d\n\n", contarPessoas(dia));
        totalPessoas();
        break;
    default:
        system("cls");
        break;
    }
}

void listarReserva()
{
    if (quantidadeReservas == 0)
    {
        printf("Nenhuma reserva feita!\n");
    }

    for (int i = 0; i < quantidadeReservas; i++)
    {
        printf("=======================================\n");
        printf("Nome: %s\n", reservas[i].nome);
        printf("CPF: %s\n", reservas[i].cpf);
        printf("Dia: %d\n", reservas[i].dia);
        printf("Quantidade de pessoas: %d\n", reservas[i].numeroPessoas);
        printf("=======================================\n");
    }

    system("pause");
}

void despedida()
{
    printf("Até a proxima, obrigado!\n");
    system("pause");
    voltarMenu = 0;
}