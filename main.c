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
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"data.h"
#include"exit_codes.h"

extern syms symbs[];
extern phones phon[];
extern prondict dict[];

int main(int argc, char **argv)
{
	int i;
	char c;
	int numsylls = 1;
	int perfrhyme = 1;

	opterr = 0;
	while ((c = getopt(argc,argv,"Vn:i")) != -1) {
		switch (c) {
		case 'V':
			printf("rhydict v0.9\n");
			printf("Copyright (C) 1201 (2017) by Donald P.  Goodman III\n");
			printf("License GPLv3+:  GNU GPL Version 3 or later "
				"<http://gnu.org/licenses/gpl.html>\n");
			printf("This is free software; you are free to change "
				"and redistribute it.  There is\nNO WARRANTY, "
				"to the extent permitted by law.\n");
			printf("Uses the CMUdict (the Carnegie Mellon "
				"Pronouncing Dictionary), maintained by\nAlex "
				"Rudnicky at Carnegie Mellon University.  CMUdict "
				"is essentially public\ndomain, with no "
				"restrictions on its use.\n");
			exit(SUCCESS);
			break;
		case 'n':
			for (i = 0; optarg[i] != '\0'; ++i) {
				if (!isdigit(optarg[i]))
					break;
			}
			if (i == strlen(optarg)) {
				numsylls = atoi(optarg);
			} else {
				fprintf(stderr,"rhydict:  error:  argument of "
					"\"-n\" must be an integer; value entered was "
					"\"%s\"\n",optarg);
			}
			break;
		case 'i':
			perfrhyme = 0;
			break;
		case '?':
			if (optopt == 'n') {
				fprintf(stderr,"rhydict:  error:  option \"-n\" "
					"requires an integer as an argument\n");
				exit(NO_OPTARG);
			}
			fprintf(stderr,"rhydict:  error:  option \"-%c\" "
				"not recognized\n",optopt);
			exit(BAD_OPT);
		}
	}
	

/*	for (i = 0; strcmp(dict[i].word,"00"); ++i) {
		if (!strcmp(dict[i].word,"rock"))
			printf("Found it!\n");
	}*/
/*	for (i = 0; strcmp(symbs[i].syll,"00"); ++i) {
		printf("%s ",symbs[i].syll);
	}
	for (i = 0; strcmp(phon[i].syll,"00"); ++i) {
		printf("(%s %s) ",phon[i].syll,phon[i].type);
	}
	for (i = 0; strcmp(dict[i].word,"00"); ++i) {
		printf("(%s %s)\n",dict[i].word,dict[i].pron);
	}*/
	return 0;
}
