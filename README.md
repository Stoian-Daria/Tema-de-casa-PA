Problema este concepută pentru a distribui un număr de cărți în mai multe secțiuni astfel încât suma maximă a paginilor din fiecare secțiune să fie distribuită în mod egal pentru fiecare angajat. 
Pentru a realiza acest obiectiv, se folosesc două metode algoritmice principale: divide et impera și greedy. Această abordare asigură atât eficiență în găsirea soluției optime, cât și eficiență în distribuirea efectivă a cărților. 
Metoda divide et impera este utilizată în această aplicație pentru a determina suma maximă optimă a paginilor dintr-o secțiune. Algoritmul de bază pentru acest pas este căutarea binară.
Metoda greedy este utilizată pentru distribuirea efectivă a cărților în secțiuni, odată ce suma maximă optimă a fost determinată.
Fișierele componente:
 distribute_books.c - Contine implementarea funcțiilor principale pentru distribuirea cărților;
 distribute_books.h - Declarațiile funcțiilor;
 main.c - Codul principal pentru rularea aplicației și interacțiunea cu utilizatorul.
Seturile de date utilizate în cadrul programului de distribuire a cărților sunt generate pe baza numărului de cărți introdus de utilizator de la tastatură. Programul generează aleator dimensiunile cărților, exprimându-le în numărul de pagini.
