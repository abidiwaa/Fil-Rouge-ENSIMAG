#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <directory.h>
#include <contact.h>
#include <hash.h>

struct contact {
  char *nom;
  char *numero;
};

struct lc {
  struct contact *val;
  struct lc *suiv;
};

struct dir {
  uint32_t taille;
  struct lc *tableau;
};


char* remplir(char* ch1,const char* ch2) {
  ch1[0]='\0';
  for (size_t i=0;i<strlen(ch2);i++) {
    ch1[i] = ch2[i];
  }
  return ch1;
}
/*
  Crée un nouvel annuaire contenant _len_ listes vides.
*/
struct dir *dir_create(uint32_t len)
{
    struct dir *dir;
    struct lc *tab[len];
    dir->taille = 0;

    for (uint32_t i=0; i<len;i++) {
      tab[i] = NULL;
      dir->taille++;
    }
    dir->tableau = *tab;
    return dir;
}

/*
  Insère un nouveau contact dans l'annuaire _dir_, construit à partir des nom et
  numéro passés en paramètre. Si il existait déjà un contact du même nom, son
  numéro est remplacé et la fonction retourne une copie de l'ancien numéro.
  Sinon, la fonction retourne NULL.
*/
char *dir_insert(struct dir *dir, const char* name, const char* num)
{
   int m = hash(name) % dir->taille;
   struct lc *tab[] = {dir->tableau};
   struct lc *liste = tab[m];
   while (liste->suiv != NULL) {
      struct contact *c1 = liste->val;
      if (est_egale(name, c1->nom)) { /* fonction qui teste si 2 char sont egales */
         int taille = strlen(c1->numero);
         char numm[taille];
         remplir(numm, c1->numero);
         remplir(c1->numero,num);

         return numm;
         break;
      }
      else {
        struct contact *cont;
        remplir(cont->nom,name);
        remplir(cont->numero, num);
        insere_fin(liste, cont); /* fonction a creer dans le module contact, il faudra creer aussi la structure contact */
        return '\0';
      }

   }
   }

/*
  Retourne le numéro associé au nom _name_ dans l'annuaire _dir_. Si aucun contact
  ne correspond, retourne NULL.
*/
const char *dir_lookup_num(struct dir *dir, const char *name)
{
    int m = hash(name) % dir->taille;
    struct lc *tab[] = {dir->tableau};
    struct lc *liste = tab[m];
    while (liste->suiv != NULL && liste->val->nom != name) {
      liste = liste->suiv;
    }
    if (liste->val->nom == name) {
      return liste->val->numero;
    }
    else {
      return NULL;
    }
}

/*
  Supprime le contact de nom _name_ de l'annuaire _dir_. Si aucun contact ne
  correspond, ne fait rien.
*/
void dir_delete(struct dir *dir, const char *name)
{
  int m = hash(name) % dir->taille;
  struct lc *tab[] = {dir->tableau};
  struct lc *liste = tab[m];
  while (liste->suiv != NULL && liste->val->nom != name) {
    liste = liste->suiv;
  }
  if (liste->val->nom == name) {
    char *numero = liste->val->numero;
    struct contact *contact;
    remplir(contact->nom,name);
    remplir(contact->numero, numero);
    remove_liste(liste, contact);
  }

}

/*
  Libère la mémoire associée à l'annuaire _dir_.
*/
void dir_free(struct dir *dir)
{
    dir = dir_create(1);


}

/*
  Affiche sur la sortie standard le contenu de l'annuaire _dir_.
*/
void dir_print(struct dir *dir)
{
  struct lc *tab[] = {dir->tableau};
  for ( uint32_t i=0; i < dir->taille ;i++) {
    struct lc *liste = tab[i];
    affiche_liste(liste);
  }
}
