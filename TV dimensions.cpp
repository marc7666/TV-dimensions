#include<stdio.h>
#include<math.h>
#define POL 2.54

int main () {
	int relacio = 0, diagonal_polzades = 0, diagonal_calculs = 0;
	float base = 0.0, altura = 0.0, area = 0.0, factor_de_escala = 0.0, diagonal_estandard = 0.0, diagonal_calculs_cm = 0.0;
	printf("Introdueix la mida de la pantalla de la TV en polzades: \n");
	scanf("%d", &diagonal_polzades);
	if(diagonal_polzades <= 2){
		printf("Les polzades han de ser >2.\n");
		return 0;
	}
	printf("Quina relacio d'apecte vols utilitzar\n Prem 1 per 4:3\n Prem 2 per 16:9\n");
	scanf("%d", &relacio);
	diagonal_calculs = (diagonal_polzades - 2); /*Es per printar desde les dues anteriors.*/
	diagonal_calculs_cm = diagonal_calculs * POL; /*Converssi� de la longitud de la diagonal de polzades a centimetres.*/
	printf("Polzades |Base \t\t |Altura \t |Superficie\n");
	for(int i = 0; i < 5; i ++){
		diagonal_calculs_cm = diagonal_calculs * POL; /*Converssio de la longitud de la diagonal de polzades a centimetres.*/
		if(relacio == 1){ //Relaci� 4:3
		diagonal_estandard = sqrt((3 * 3) + (4 * 4)); /*Mida de la diagonal estandard. Pantalla de 4 cm de base 3 cm de alt.*/
		factor_de_escala = diagonal_calculs_cm / diagonal_estandard; /*Proporcio entre la longitud del mateix costat entre dues figures similars.*/
		base = 4 * factor_de_escala; /*en cm*/
		altura = 3 * factor_de_escala; /*en cm*/
		area = base * altura; /*en cm^2*/
	} else if(relacio == 2){ /*relacio == 2*/ /*Relacio 16:9*/
		diagonal_estandard = sqrt((9 * 9) + (16 * 16));
		factor_de_escala = diagonal_calculs_cm / diagonal_estandard;
		base = 16 * factor_de_escala;
		altura = 9 * factor_de_escala;
		area = base * altura;
	}
	printf("%d \t | %.2f \t | %.2f \t | %.2f\n", diagonal_calculs, base, altura, area);
	diagonal_calculs ++;
	}
	return 0;
}
