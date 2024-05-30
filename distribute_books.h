#ifndef DISTRIBUTE_BOOKS_H
#define DISTRIBUTE_BOOKS_H

// Declaratia functiei distribute_books care distribuie cartile in sectiuni
void distribute_books(int* books, int number_books, int** sections, int number_sections);
// Declaratia functiei min_max_section_sum care calculeaza numarul minim de sectiuni
int min_max_section_sum(int* books, int number_books, int max_sum);

#endif // DISTRIBUTION_H
