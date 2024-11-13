/*
Integrantes 
Jose Franklin Angel Guevara
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void Gestion_Procesos(); 
void Menu();

int main()
{
    char buffer[100];
    int numero;
    Menu();
    while (1)
    { // Inicia un bucle infinito

        fgets(buffer, sizeof(buffer), stdin); // Lee la entrada completa

        // Intenta convertir la cadena leída a un número entero
        if (sscanf(buffer, "%d", &numero) == 1)
        {
            if (numero == 1)
            {
                Gestion_Procesos();
            }
            else if (numero == 2)
            {
               // Gestion_Procesos();
            }
            else if (numero == 3)
            {
                //Gestion_Procesos();
            }
            else if (numero == 4)
            {
                break;
            }
            else
            {
                system("clear");
                Menu();
                printf("\nEntrada no válida. Por favor, ingresa un número entero.\n");
            }
        }
        else
        {

            system("clear");
            Menu();
            printf("Entrada no válida. Por favor, ingresa un número entero.\n");
        }
    }

    return 0;
}

void Menu()
{
    printf("------------MENU DEL PROYECTO GPO---------");
    printf("\n1- Gestion de Procesos");
    printf("\n2- Gestion de Memoria");
    printf("\n3- Gestion de Almacenamiento");
    printf("\n4- Salir");
    printf("\nIngrese un número entero: ");
}

void Gestion_Procesos()
{
    // creacion del proceso hijo
    pid_t pid = fork();

    // si pid retorna un valor menor a cero, significa que no se pudo crear el proceso hijo
    if (pid < 0)
    {

        perror("Error al crear el proceso hijo");
        exit(1);
        // Si pid retorna 0 entonces se esta ejecutando el proceso hijo
    }
    else if (pid == 0)
    {

        printf("Soy el proceso hijo. Mi PID es %d. Voy a esperar 4 segundos antes de ejecutar el comando 'ls'\n", getpid());

        // Se agrega un tiempo para notar que se esta ejecutando el proceso hijo
        sleep(6);

        // se ejecuta excelp que es parte de la familia de excec()
        execlp("ls", "ls", "-l", NULL);

        /// Si existe algun poblema en la ultima operacion en este caso si no se ejecuta exclp con exito
        perror("Error al ejecutar el comando");
        exit(1); // Salir en caso de error
    }
    else
    {

        // Este es el proceso padre
        printf("Soy el proceso padre. Mi PID es %d. Esperando que el proceso hijo termine...\n", getpid());

        // Esperar a que el proceso hijo termine se pasa el valor null como parametro ya que en este caso no importa obtener su estado
        wait(NULL);

        printf("El proceso hijo ha terminado.\n");
    }
}