/*
 * +AMDG  This document was begun on 3 May 1201, the feast
 * of St. Juvenal, EC, and it is humbly dedicated to him and
 * to the Immaculate Heart of Mary for their prayers, and to
 * the Sacred Heart of Jesus for His mercy.
 */
/*
 * Part of the rhydict package; holds the data structures
 * we'll be using.
 */

typedef struct {
	char *syll;
} syms;

typedef struct {
	char *syll;
	char *type;
} phones;

typedef struct {
	char *word;
	char *pron;
} prondict;
