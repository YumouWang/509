#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct nlist
{
	char *name;
	char *def;
	struct nlist *next;
}TABLE,*TABLEPTR;

#define HASHSIZE 100
static struct nlist *hashtab[HASHSIZE];

hash(s)
char *s;
{
	int hashval;
	for(hashval	= 0; *s != '\0';)
		hashval += *s++;
	return hashval % HASHSIZE;
}

struct nlist *lookup(s)
char *s;
{
	struct nlist *np;
	for(np = hashtab[hash(s)]; np != NULL; np = np -> next)
		if (strcmp(s, np -> name) == 0)
			return np;
	return NULL;
}

struct nlist *install(name, def)
char *name, *def;
{
	struct nlist *np, *lookup();
	int hashval;

	if((np = lookup(name)) == NULL){ // not found
		np = (struct nlist *)malloc(sizeof(*np));
		if(np == NULL)
			return NULL;
		if((np -> name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(np -> name);
		np -> next = hashtab[hashval];
		hashtab[hashval] = np;
	}else
		free(np -> def);
	if((np -> def = strdup(def)) == NULL)
		return NULL;
	return np;
};

main()
{
  if (lookup("test") == NULL)
    printf ("test does not yet exist.\n");

  install("test", "135");

  TABLEPTR node = lookup("test");

  if (node == NULL)
    printf ("test should exist but it doesn't.");
  else
    printf ("test maps to %s\n", node->def);
}
