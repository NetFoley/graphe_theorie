#include <stdio.h>
#include <stdlib.h>

void main()
{
	int matriceAdjacence[6][6];
	int matriceDegres[6][6];
	int matriceLaplacienne[6][6];
	int matriceIncidence[7][6];

	int i,j,k;

	for(i=0; i<6; i++) {
		for(j=0; j<6; j++) {
			matriceAdjacence[i][j] = 0;
			matriceDegres[i][j] = 0;
			matriceLaplacienne[i][j] = 0;
		}
	}

	for(i=0; i<7; i++) {
		for(j=0; j<6; j++) {
			matriceIncidence[i][j] = 0;
		}
	}


	matriceIncidence[0][0] = 1;
	matriceIncidence[0][1] = 1;
	matriceIncidence[1][1] = 1;
	matriceIncidence[1][2] = 1;
	matriceIncidence[2][0] = 1;
	matriceIncidence[2][3] = 1;
	matriceIncidence[3][2] = 1;
	matriceIncidence[3][4] = 1;
	matriceIncidence[4][3] = 1;
	matriceIncidence[4][4] = 1;
	matriceIncidence[5][4] = 1;
	matriceIncidence[5][5] = 1;
	matriceIncidence[6][1] = 1;
	matriceIncidence[6][4] = 1;



	printf("Graphe non-oriente :\n\n");

	printf("a--1--b--2--c\n");
	printf("|     |    / \n");
	printf("|     |   /  \n");
	printf("3     7  4   \n");
	printf("|     | /    \n");
	printf("|     |/     \n");
	printf("d--5--e--6--f\n");


	printf("\n");
	printf("\n");
	printf("Matrice d'Incidence\n");
	printf("\n");

	printf("   ");
	for(j=0; j<6; j++) {
		printf("%c  ", 'a'+j);
	}
	printf("\n");
	for(i=0; i<7; i++) {
		printf("%d: ", i+1);
		for(j=0; j<6; j++) {
			printf("%d, ", matriceIncidence[i][j]);
		}
		printf("\n");
	}


	printf("\n");
	printf("\n");
	printf("Matrice d'Adjacence\n");
	printf("\n");

	for(k=0; k<7; k++) {
		i = 0;
		while(matriceIncidence[k][i] == 0 && i<6) {
			i++;
		}

		j = 0;
		while((matriceIncidence[k][j] == 0 || i==j) && j<6) {
			j++;
		}

		if(i<6 && j<6) {
			matriceAdjacence[i][j] = 1;
			matriceAdjacence[j][i] = 1;
		}
	}

	printf("   ");
	for(j=0; j<6; j++) {
		printf("%c  ", 'a'+j);
	}
	printf("\n");
	for(i=0; i<6; i++) {
		printf("%c: ",'a'+i);
		for(j=0; j<6; j++) {
			printf("%d, ",matriceAdjacence[i][j]);
		}
		printf("\n");
	}


	printf("\n");
	printf("\n");
	printf("Matrice des Degres\n");
	printf("\n");

	for(i=0; i<6; i++) {
		for(j=0; j<6; j++) {
			if(matriceAdjacence[i][j] != 0) {
				matriceDegres[i][i] = matriceDegres[i][i] + matriceAdjacence[i][j];
			}
		}
	}

	printf("   ");
	for(j=0; j<6; j++) {
		printf("%c  ", 'a'+j);
	}
	printf("\n");
	for(i=0; i<6; i++) {
		printf("%c: ",'a'+i);
		for(j=0; j<6; j++) {
			printf("%d, ",matriceDegres[i][j]);
		}
		printf("\n");
	}


	printf("\n");
	printf("\n");
	printf("Matrice Laplacienne\n");
	printf("\n");

	for(i=0; i<6; i++) {
		for(j=0; j<6; j++) {
			if(i == j) {
				matriceLaplacienne[i][j] = matriceDegres[i][j];
			} else {
				matriceLaplacienne[i][j] = matriceAdjacence[i][j];
			}
		}
	}

	printf("   ");
	for(j=0; j<6; j++) {
		printf("%c  ", 'a'+j);
	}
	printf("\n");
	for(i=0; i<6; i++) {
		printf("%c: ",'a'+i);
		for(j=0; j<6; j++) {
			printf("%d, ",matriceLaplacienne[i][j]);
		}
		printf("\n");
	}




}
