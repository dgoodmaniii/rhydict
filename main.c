/*
 * +AMDG  This document was begun on 3 May 1201, the feast
 * of St. Juvenal, EC, and it is humbly dedicated to him and
 * to the Immaculate Heart of Mary for their prayers, and to
 * the Sacred Heart of Jesus for His mercy.
 */
/*
 * Part of the rhydict package; the main function.
 */

#include<stdio.h>
#include<string.h>
#include"data.h"

extern syms symbs[];
extern phones phon[];
extern prondict dict[];

int main(int argc, char **argv)
{
	int n; int i;

	n = 85;
	for (i = 0; strcmp(symbs[i].syll,"00"); ++i) {
		printf("%s ",symbs[i].syll);
	}
	for (i = 0; strcmp(phon[i].syll,"00"); ++i) {
		printf("(%s %s) ",phon[i].syll,phon[i].type);
	}
	for (i = 0; strcmp(dict[i].word,"00"); ++i) {
		printf("(%s %s)\n",dict[i].word,dict[i].pron);
	}
	return 0;
}
