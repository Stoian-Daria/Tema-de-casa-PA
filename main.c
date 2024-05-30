#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Biblioteca pentru obtinerea timpului
#include "distribute_books.h" // Header-ul care contine declaratiile functiilor de distribuire a cartilor
#define MAX_NUMBER_BOOKS 1000 // Definim numarul maxim de carti
#define MAX_SECTIONS 3 // Definim numarul maxim de sectiuni
#define MAX_NUMBER_PAGES 10000 // Definim numarul maxim de pagini pentru o carte

int main()
{
    FILE *output_file; // Declaram un pointer pentru fisierul de iesire
    output_file=fopen("output1.txt", "w"); // Deschidem fisierul de iesire in modul scriere
    if(output_file==NULL) // Verificam daca fisierul s-a deschis corect
    {
        printf("Eroare la deschiderea fisierului."); // Afisam un mesaj de eroare daca fisierul nu s-a deschis
        return 1;
    }

    int number_books, number_sections=MAX_SECTIONS; // Declaram variabilele pentru numarul de carti si numarul de sectiuni
    int books[MAX_NUMBER_BOOKS]; // Declaram vectorul pentru paginile cartilor
    srand(time(NULL)); // Initializarea generatorului de numere aleatoare cu timpul curent

    printf("Introduceti numarul de carti: "); // Afisam un mesaj pentru a cere utilizatorului sa introduca numarul de carti de la tastatura
    scanf("%d", &number_books); // Citim numarul de carti de la utilizator
    fprintf(output_file, "Numarul de carti este: %d\n", number_books); // Afisam numarul de carti in fisierul de iesire
    fprintf(output_file, "Numarul de pagini generat pentru fiecare carte: \n"); // Afisam mesajul in fisierul de iesire
    for(int i=0; i<number_books; i++) // Parcurgem numarul de pagini pentru fiecare carte
    {
        books[i]=rand()%MAX_NUMBER_PAGES+1; // Generam un numar de pagini intre 1 si MAX_NUMBER_PAGES
        fprintf(output_file, "Cartea %d are %d pagini;\n", i+1, books[i]); // Afisam numarul de pagini pentru fiecare carte in fisierul de iesire
    }
    fprintf(output_file, "\n");
    int**sections=(int**)malloc(number_sections*sizeof(int*)); // Alocarea memoriei pentru sectiuni
    for(int i=0; i<number_sections; i++) // Parcurgem numarul de sectiuni pentru fiecare sectiune
    {
        sections[i]=(int*)malloc((number_books+1)*sizeof(int)); // Alocam memorie pentru fiecare sectiune
        sections[i][0]=0; // Initializam contorul de carti din fiecare sectiune
    }
    // Apelarea functiei pentru distribuirea cartilor in sectiuni
    distribute_books(books, number_books, sections, number_sections);
    fprintf(output_file, "Distribuirea cartilor in sectiuni:\n"); // Afisam mesajul pentru distribuirea cartilor in fisierul de iesire
    for(int i=0; i<number_sections; i++) // Parcurgem fiecare sectiune
    {
        fprintf(output_file, "Sectiunea %d: ", i+1); // Afisam mesajul pentru fiecare sectiune
        for(int j=1; j<=sections[i][0]; j++) // Iterarea prin fiecare carte din sectiune
        {
            fprintf(output_file, "%d ", sections[i][j]); // Afisam fiecare carte din sectiune
        }
        fprintf(output_file, "\n");
    }
    // Eliberarea memoriei alocate pentru sectiuni
    for(int i=0; i<number_sections; i++)
    {
        free(sections[i]);
    }
    free(sections);
    fclose(output_file);
    return 0;
}
