#include "distribute_books.h" // includem fisierul header pentru functiile de distribuire a cartilor
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Functie pentru distribuirea cartilor in sectiuni
void distribute_books(int* books, int number_books, int** sections, int number_sections)
{
    int total_sum=0; // initializam suma totala a dimensiunilor cartilor cu 0
    for(int i=0; i<number_books; i++) // parcurgem fiecare carte
    {
        total_sum+=books[i]; // adaugam dimensiunea fiecarei carti la suma totala
    }
    int left=0, right=total_sum; // initializam stanga cu 0 si dreapta cu suma totala
    while(left<right) // cat timp stanga este mai mica decat dreapta
    {
        int mid=(left+right)/2; // calculam mijlocul intervalului
        if(min_max_section_sum(books, number_books, mid)<=number_sections) // verificam daca suma minima maxima a sectiunii este mai mica sau egala cu numarul de sectiuni
        {
            right=mid; // restrangem intervalul la stanga
        }
        else
        {
            left=mid+1; // restrangem intervalul la dreapta
        }
    }
    int current_sum=0, current_section=0; // initializam suma curenta si sectiunea curenta cu 0
    for(int i=0; i<number_books; i++) // parcurgem fiecare carte
    {
        if(current_sum+books[i]>left) // verificam daca adaugarea dimensiunii cartii depaseste suma minima maxima a sectiunii
        {
            current_section++; // trecem la urmatoarea sectiune
            current_sum=0; // resetam suma curenta
        }
        sections[current_section][sections[current_section][0]+1]=books[i]; // adaugam dimensiunea cartii in sectiune
        sections[current_section][0]++; // incrementam numarul de carti din sectiune
        current_sum+=books[i]; // adaugam dimensiunea cartii la suma curenta
    }
}

// Functie pentru calculul sumei minime maxime a unei sectiuni
int min_max_section_sum(int* books, int number_books, int max_sum)
{
    int current_sum=0, sections=1; // initializam suma curenta cu 0 si numarul de sectiuni cu 1
    for(int i=0; i<number_books; i++) // parcurgem fiecare carte
    {
        if(current_sum+books[i]>max_sum) // verificam daca adaugarea dimensiunii cartii depaseste suma maxima
        {
            sections++; // incrementam numarul de sectiuni
            current_sum=0; // resetam suma curenta
        }
        current_sum+=books[i]; // adaugam dimensiunea cartii la suma curenta
    }
    return sections; // returnam numarul de sectiuni
}
