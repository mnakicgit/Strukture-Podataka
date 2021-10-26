#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_SIZE (128)
#define MAX_LINE (1024)

typedef struct _student {
	char ime[MAX_SIZE];
	char prezime[MAX_SIZE];
	double bodovi;
} student;

int br_redaka(char* naziv_dat) {
	int br = 0;
	FILE* dat = NULL;
	char buffer[MAX_LINE] = {0};

	dat = fopen(naziv_dat, "r");

	if(!dat) {
		printf("Greska");
		return -1;
	}

	while(!feof(dat)) {
		fgets(buffer, MAX_LINE, dat);
		br++;
	}

	fclose(dat);
	return br;
}


student* alloc_stud_proc(int br_stud, char* naziv_dat) {
	int br = 0;
	FILE* dat = NULL;
	student* studenti = NULL;

	studenti = (student *)malloc(sizeof(student) * br_stud);

	dat = fopen(naziv_dat, "r");
	if(!dat) {
		printf("Greska pri alociranju");
		free(studenti);
		return NULL;
	}

	while(!feof(dat)) {
		fscanf(dat, " %s %s %lf", studenti[br].ime, studenti[br].prezime, &studenti[br].bodovi);
		br++;
	}

	fclose(dat);
	return studenti;
}

int max_bod(int br_stud, student* studenti) {
    int max = 0;
    int i = 0;

    for(i = 0; i < br_stud; i++) {
        if(studenti[i].bodovi > max) max = studenti[i].bodovi;
    }

    return max;
}

int ispisi_stud(int br_stud, student* studenti, int max) {
    int i = 0;

    printf("\nIme    Prezime    Apsolutni    Relativni br. bod.\n");

    for(i = 0; i < br_stud; i++){
        float rel_br = 0;
        rel_br =(float)studenti[i].bodovi / max * 100;
        printf("%s\t%s\t%.2f\t%.2f", studenti[i].ime, studenti[i].prezime, studenti[i].bodovi, rel_br);
        printf("\n");
    }

    return 0;
}

int main() {
    int br_red = 0; //broj redaka == broj studenata
    int max = 0;
    int* aps_br = 0, rel_br = 0;

    br_red = br_redaka("studenti.txt");
    printf("Broj redaka tj. studenata u datoteci: %d", br_red);

    student* studenti = alloc_stud_proc(br_red, "studenti.txt");

    max = max_bod(br_red, studenti);

    ispisi_stud(br_red, studenti, max);

	return 0;
}
