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
	int len;
	char c;
	int numphones = 0;
	int numsyllmatch = 1;
	int perfrhyme = 1;
	char *word = NULL;
	char *pronword = NULL;
	char **syllables;

	opterr = 0;
	while ((c = getopt(argc,argv,"Vn:iw:")) != -1) {
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
				numsyllmatch = atoi(optarg);
			} else {
				fprintf(stderr,"rhydict:  error:  argument of "
					"\"-n\" must be an integer; value entered was "
					"\"%s\"\n",optarg);
			}
			break;
		case 'i':
			perfrhyme = 0;
			break;
		case 'w':
			word = optarg;
			break;
		case '?':
			if ((optopt == 'n') || (optopt == 'w')) {
				fprintf(stderr,"rhydict:  error:  option \"-n\" "
					"requires an integer as an argument\n");
				exit(NO_OPTARG);
			}
			fprintf(stderr,"rhydict:  error:  option \"-%c\" "
				"not recognized\n",optopt);
			exit(BAD_OPT);
		}
	}
	if (word == NULL) {
		fprintf(stderr,"rhydict:  error:  give rhydict a word "
			"to rhyme with \"-w\"\n");
		exit(NO_WORD);
	}
	for (i = 0; strcmp(dict[i].word,word); ++i);
	len = strlen(dict[i].pron);
	pronword = malloc((len * sizeof(char)) + 1);
	strcpy(pronword,dict[i].pron);
	syllables = malloc(13 * sizeof(char *));
	numphones = syllabify(syllables,pronword);
	for (i = 0; syllables[i] != NULL; ++i)
		printf("%s ",syllables[i]);
	compwords(syllables,numphones,numsyllmatch,perfrhyme);

	free(pronword);
	for (i = 0; syllables[i] != NULL; ++i)
		free(syllables[i]);
	free(syllables);
	return 0;
}

int syllabify(char **sa, char *s)
{
	char *token;
	token = strtok(s," ");
	int numphones = 0;
	int i = 0;
	while (token != NULL) {
		numphones++;
		sa[i] = malloc((strlen(token) + 1) * sizeof(char));
		strip_stress(token);
		strcpy(sa[i],token);
		token = strtok(NULL," ");
		++i;
	}
	sa[i] = NULL; numphones--;
	return numphones;
}

int compwords(char **s, int numsylls, int numsyllmatch, int perfrhyme)
{
	char *token;
	char **syllables;
	int i, j, k, len = 0;
	char *pronword;
	int numphones = 0;

	for (i = 0; strcmp(dict[i].pron,"00"); ++i) {
		numphones = 0;
		len = strlen(dict[i].pron);
		pronword = malloc((len * sizeof(char)) + 1);
		strcpy(pronword,dict[i].pron);
		syllables = malloc(36 * sizeof(char *));
		numphones = syllabify(syllables,pronword);
		k = numsylls;
		while (!strcmp(syllables[numphones],s[k])) {
			if (isvowel(syllables[numphones]) == 0) {
				printf("%s\n",dict[i].word);
				break;
			}
			if ((numphones == 0) || (k == 0))
				break;
			else
				numphones--; k--;
		}
		free(pronword);
		for (j = 0; syllables[j] != NULL; ++j)
			free(syllables[j]);
		free(syllables);
	}
}

int strip_stress(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; ++i) {
		if (isdigit(s[i]))
			s[i] = '\0';
	}
	return 0;
}

/* returns 0 if it's a vowel, 1 if not */
int isvowel(char *s)
{
	int len; int i;
	char *t = s;

	len = strlen(t) - 1;
	strip_stress(t);
	for (i = 0; strcmp(phon[i].syll,"00"); ++i) {
		if (!strcmp(phon[i].syll,t) && !strcmp(phon[i].type,"vowel"))
			return 0;
	}
	return 1;
}
