#include <stdio.h>
#include <stdlib.h>

typedef struct _Lista {
	double v;
	struct _Lista * n; //n = next
} Lista, *PLista;

int main(int argc, char ** argv) {
	int i;
	PLista head = NULL;
	for (i = 1; i < argc; i++) {
		if (head == NULL) { //jezeli lista jest pusta to zaalokuj na nia pamiec i stworz ją
			// lista pusta
			head = (PLista) malloc(sizeof(Lista));
			head->n = NULL;
			head->v = atof( argv[i] );
		} else {
			// lista już coś ma, idziemy na koniec i dodajemy
			PLista tmp = head;
			while (tmp->n != NULL)
				tmp = tmp->n;
			tmp->n = (PLista) malloc(sizeof(Lista));
			tmp->n->v = atof( argv[i] );
			tmp->n->n = NULL;
		}
	}

	PLista tmp = head;
	i = 0;
	while (tmp != NULL) {
		printf("lista[%d] = %lf\n", i++, tmp->v);
		tmp = tmp->n;
	}

	return 0;
}
//DOM - zrobienie biblioteki do tego programu i makefile'a
//DOM2 - napisac funkcje(vec_insert), która wstawia element na dane miejsce w wariancie array i lista 

//VALGRING
//zaby wywolac w konsoli

//valgring ./nazwa_programu

/*istnieje zasada, że do każdego malloca jedno free(), dlatego też używamy free() w pętli*/