#include <stdio.h>

int main()
{
	//plusieurs flag 0 ca reviens au meme que un seul
	//flag . c est le nombre de caractere a l ecran
	//0 est ignore quand on a un -
	//0 ajoute 0*int derriere sachant que le nombre de 0 depend de la longueur de ce qu on affiche sachant pour un negatif
	char s[2];
	char *s2;

	s[0] = 'a';
	printf("%-.20d", 1);
}
