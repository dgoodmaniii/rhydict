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
#include"data.h"

extern syms symbs[];

int main(int argc, char **argv)
{
	int n; int i;

	n = 85;
	for (i = 0; i < n; ++i) {
		printf("%s\n",symbs[i].syll);
	}
	return 0;
}
