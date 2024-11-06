#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

// Aluno: Davi Carvalho de Lima
// IDE: VScode
// Compilador: gcc 14.2.0

void menu(int *voltarMenu);
void fazerReserva();
void listarReserva();
void totalPessoas();
int contarPessoas(int dia);
void despedida();

// Criando um tipo Reserva, para ser utilizado como Objeto.
typedef struct
{
    char nome[64];
    char cpf[64];
    int dia;
    int numeroPessoas;
} Reserva;

// Criando um array de reservas com o tipo Reserva.
Reserva reservas[64]; 
int quantidadeReservas = 0;

int main()
{
    // Configuração para aceitar acentos.
    setlocale(LC_ALL, "pt_BR.UTF-8"); 

    int voltarMenu = 1;
    do
    {
        system("cls");
        menu(&voltarMenu); // Passando o endereço da variável voltarMenu para a função menu.
    } while (voltarMenu); // Enquanto voltarMenu for verdadeiro, o menu será exibido.

    return 0;
}

void menu(int *voltarMenu)
{
    printf("---------------------------\n1 - Fazer reserva\n2 - Lista de reservas\n3 - Total de pessoas por dia\n4 - Sair\n---------------------------\n");
    int input = getch(); // Captura a tecla pressionada.
    int tecla = input - '0'; // Converte o valor ASCII para inteiro.
    switch (tecla)
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
    case 4:
        system("cls");
        despedida();
        *voltarMenu = 0;
        break;
    default:
        system("cls");
        break;
    }
}

void fazerReserva()
{
    printf("Nome: ");
    scanf(" %[^\n]", reservas[quantidadeReservas].nome); // Usei regex para aceitar espaços.

    printf("CPF: ");
    scanf("%s", reservas[quantidadeReservas].cpf);

    printf("1 - Quinta\n2 - Sexta\n3 - Sábado\n4 - Domingo\nInforme o dia da reserva: ");
    scanf("%d", &reservas[quantidadeReservas].dia);

    printf("Quantidade de Pessoas: ");
    scanf("%d", &reservas[quantidadeReservas].numeroPessoas);

    quantidadeReservas++;

    fflush(stdin); // Limpa o buffer do teclado para proxima reserva.
    system("cls");
    printf("Reserva feita com sucesso!\n");
    system("pause");
}

// Função para contar a quantidade de pessoas por dia.
int contarPessoas(int dia) 
{
    int contador = 0;

    for (int i = 0; i <= quantidadeReservas; i++) // Percorre todas as reservas.
    {
        if (dia == reservas[i].dia) // Se o dia da reserva for igual ao dia informado, soma a quantidade de pessoas.
        {
            int quantidadePessoas = reservas[i].numeroPessoas;
            contador += quantidadePessoas;
        }
    }

    return contador; // Retorna a quantidade de pessoas no dia informado.
}

// Função para exibir a quantidade de pessoas por dia.
void totalPessoas() 
{
    printf("1 - Quinta\n2 - Sexta\n3 - Sábado\n4 - Domingo\n5 - Sair\n");

    int tecla = getch(); // Mesma logica que está na função menu.
    int dia = tecla - '0';
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

// Função para listar todas as reservas.
void listarReserva() 
{
    if (quantidadeReservas == 0) // Se não houver nenhuma reserva, exibe a mensagem.
    {
        printf("Nenhuma reserva feita!\n");
    }

    for (int i = 0; i < quantidadeReservas; i++) // Percorre todas as reservas e imprime na tela.
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

// Função para exibir a mensagem de despedida.
void despedida() 
{
    printf("Até a proxima, obrigado!\n");
    system("pause");
}
