/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 4. Defina uma estrutura em C para armazenar dados de um veículo (Marca, modelo, cor, quantidade de 
portas, motorização), crie uma função para armazenar os dados de 10 veículos, outra para mostrar os dados 
armazenados, a função main() deve conter um pequeno menu para chamar as funções criadas.
*/

// !LIBRARIES _________________________________________________________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
#include<ctype.h>

//! STRUCTS ___________________________________________________________________________________________________
struct Carro
{
    char marca[50];
    char modelo[50];
    char cor[50];
    int quantidadePortas;
    float motorizacao;
};

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________
void messageTitle();
void messageMenu();
void messageNameInput(int index, int option);
void messageConfirmExit();
void messageExit();
void messageName(struct Carro *carros, int size);


//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________
void errorMessageInput(int quantityOfError, int option);
void errorExit();

//! VALIDATION INPUT __________________________________________________________________________________________
bool validationString(char *string);
bool validationNumber(int intNumber, float floatNumber, int option);

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________
int functionOptionInput();
void functionInputString(struct Carro *carros, int size);


int main()
{
    int option, quantityOfError = 0, size;
    struct Carro carros[10];
    bool validation = false, exitValidation = false;

    size = sizeof(carros)/sizeof(carros[0]);

    do
    {
        messageTitle();
        messageMenu();
        option = functionOptionInput();

        switch (option)
        {
        case 1:
            system("cls");
            quantityOfError = 0;
        
            functionInputString(carros, size);
            break;

        case 2:
            system("cls");
            quantityOfError = 0;

            messageName(carros, size);
            break;
        case 3:
            system("cls");
            quantityOfError = 0;
            
            do
            {
                messageConfirmExit();
                option = functionOptionInput();

                if (option == 1)
                {
                    exitValidation = true;
                    validation = true; 
                }
                else if(option == 2)
                {
                    exitValidation = true;
                    validation = false;
                }
                else
                {
                    exitValidation = false;
                    system("cls");
                    quantityOfError++;
                    errorMessageInput(quantityOfError, 1);

                    if (quantityOfError == 3)
                    {
                        errorExit();
                        exit(EXIT_FAILURE);
                    }    
                }

            } while (exitValidation == false);


            system("cls");
            quantityOfError = 0;
            
            break;

        default:
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 1);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
            break;
        }
    
    } while (validation == false);
    
    messageExit();
    exit(EXIT_SUCCESS);
}

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________

//  MESSAGE TITLE OF THE SYSTEM
void messageTitle()
{
    printf("SISTEMA PARA FORMATAR OS NOMES\n\n\n");
}

//  MESSAGE MENU
void messageMenu()
{
    printf("---------------------------------\n");
    printf("[1] ENTRADA DOS DADOS DO CARROS\n");
    printf("[2] SA\326DA DOS DADOS DOS CARROS\n");
    printf("[3] SAIR DO PROGRAMA\n");
    printf("---------------------------------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE ASK NAME INPUT
void messageNameInput(int index, int option)
{
    switch (option)
    {
    case 1:
        printf("DIGITE A MARCA DO CARRO %d: ", index);
        break;
    
    case 2:
        printf("DIGITE O MODELO DO CARRO %d: ", index);
        break;

    case 3:
        printf("DIGITE A COR DO CARRO %d: ", index);
        break;

    case 4:
        printf("DIGITE A QUANTIDADE DE PORTAS DO CARRO %d: ", index);
        break;

    case 5:
        printf("DIGITE A MOTORIZA\200\307O DO CARRO %d: ", index);
        break;

    default:
        break;
    }
}

//  MESSAGE ASK CONFIRM EXIT OF THE SYSTEM
void messageConfirmExit()
{
    printf("DESEJA CONFIRMAR A SA\326DA DO SISTEMA?\n\n");
    printf("-------\n");
    printf("[1] SIM\n");
    printf("[2] N\307O\n");
    printf("-------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE TO EXIT SYSTEM
void messageExit()
{
    printf("O SISTEMA IR\265 FINALIZAR\n");
}

//  MESSAGE TO PRINT THE NAMES
void messageName(struct Carro *carros, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("---------\n");
        printf("CARRO %d\n", i+1);
        printf("---------\n");
        printf("Marca: %s\n", carros[i].marca);
        printf("Modelo: %s\n", carros[i].modelo);
        printf("Cor: %s\n", carros[i].cor);
        printf("Quantidade de portas: %d\n", carros[i].quantidadePortas);
        printf("Motoriza\207\306o: %.1f\n", carros[i].motorizacao);
        printf("----------------------------------------\n\n\n");
    }
}

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________

//  ERROR MESSAGE INPUT
void errorMessageInput(int quantityOfError, int option)
{
    switch (option)
    {
    case 1:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UMA OP\200\307O V\265LIDA\n\n\n");
        break;
    
    case 2:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM NOME V\265LIDO\n\n\n");
        break;

    case 3:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM N\351MERO V\265LIDO\n\n\n");
        break;

    default:
        break;
    }
}

//  ERROR EXIT SYSTEM
void errorExit()
{
    printf("QUANTIDADE DE ERROS ATINGIDO!\n");
    printf("O SISTEMA IR\265 FINALIZAR!\n\n\n");
}

//! VALIDATION INPUT __________________________________________________________________________________________

//  FUNCTION TO VALIDATE A STRING
bool validationString(char *string)
{
    int index = 0;

    if (strlen(string) == 1)
    {
        if (string[index] == "\n" || string[index] == " " || string[index] == '\0' || string[index] == '\r' || 
        string[index] == '\r\n' || !isalpha(string[index] || !isdigit(string[index])))
        {
            return false;
        }
    }
    else
    {
        while (index < strlen(string))
        {
            if (string[index] != "\n" && string[index] != " " && string[index] != '\0' && string[index] != '\r' && 
            string[index] != '\r\n' && !isspace(string[index]) && (isalpha(string[index]) || isdigit(string[index])))
            {
                return true;
            }
            index++;
        }

        return false;
    }

    return false;
}

//  FUNCTION TO VALIDATE A NUMBER
bool validationNumber(int intNumber, float floatNumber, int option)
{
    switch (option)
    {
    case 1:
        if (intNumber < 0)
        {
            return false;
        }
        else if (intNumber >= 2 && intNumber <= 4)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    
    case 2:
        if (floatNumber < 0)
        {
            return false;
        }
        else if (floatNumber >= 1.0 && floatNumber <= 4.0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    default:
        return false;
        break;
    }
    
}

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________

//  FUNCTION OPTION INPUT
int functionOptionInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}

//  FUNCTION INPUT STRING
void functionInputString(struct Carro *carros, int size)
{
    int quantityOfError = 0, count = 0;
    bool validation = false;

    for (int i = 0; i < size; i++)
    {
        while (validation == false) //  MARCA
        {
            messageTitle();
            messageNameInput(i+1, 1);
            fflush(stdin);
            fgets(carros[i].marca, sizeof(carros[i].marca), stdin);
            validation = validationString(carros[i].marca);

            if (strlen(carros[i].marca) == sizeof(carros[i].marca))
            {
                char charactere;
                while ((charactere = getchar()) != '\n' && charactere != EOF);
            }
            else
            {
                int j = strlen(carros[i].marca);
                carros[i].marca[j-1] = '\0';
            }

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        count = 0;
        validation = false;

        while (validation == false) //  MODELO
        {
            messageTitle();
            messageNameInput(i+1, 2);
            fflush(stdin);
            fgets(carros[i].modelo, sizeof(carros[i].modelo), stdin);
            validation = validationString(carros[i].modelo);

            if (strlen(carros[i].modelo) == sizeof(carros[i].modelo))
            {
                char charactere;
                while ((charactere = getchar()) != '\n' && charactere != EOF);
            }
            else
            {
                int j = strlen(carros[i].modelo);
                carros[i].modelo[j-1] = '\0';
            }
            

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

                system("cls");
        count = 0;
        validation = false;

        while (validation == false) //  COR
        {
            messageTitle();
            messageNameInput(i+1, 3);
            fflush(stdin);
            fgets(carros[i].cor, sizeof(carros[i].cor), stdin);
            validation = validationString(carros[i].cor);

            if (strlen(carros[i].cor) == sizeof(carros[i].cor))
            {
                char charactere;
                while ((charactere = getchar()) != '\n' && charactere != EOF);
            }
            else
            {
                int j = strlen(carros[i].cor);
                carros[i].cor[j-1] = '\0';
            }

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        count = 0;
        validation = false;
        
        while (validation == false) //  QUANTIDADE DE PORTAS
        {
            messageTitle();
            messageNameInput(i+1, 4);
            fflush(stdin);
            scanf("%d", &carros[i].quantidadePortas);

            validation = validationNumber(carros[i].quantidadePortas, 0, 1);
            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        count = 0;
        validation = false;
        
        while (validation == false) //  MOTORIZAÇÃO
        {
            messageTitle();
            messageNameInput(i+1, 5);
            fflush(stdin);
            scanf("%f", &carros[i].motorizacao);

            validation = validationNumber(0, carros[i].motorizacao, 2);
            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 3);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }

        system("cls");
        count = 0;
        validation = false;
    }
}