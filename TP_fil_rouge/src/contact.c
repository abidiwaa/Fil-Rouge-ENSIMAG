#include <stdlib.h>
#include <stdio.h>

#include <directory.h>
#include <contact.h>
#include <hash.h>
#include <string.h>
#include <assert.h>

struct contact {
  char *nom;
  char *numero;
};

struct lc {
  struct contact *val;
  struct lc *suiv;
};

bool est_egale(const char* name1,const char* name2) {
  bool booleen = true;
  for (size_t i=0; i < strlen(name1); i++) {
    if (name1[i] != name2[i] ) {
      booleen = false;
      break;
    }
  }
  return booleen;
}

void insere_fin(struct lc **liste, struct contact *cont) {
    struct lc sent = { -1, *liste };
    struct lc *queue = &sent;
    while (queue->suiv != NULL) {
        queue = queue->suiv;
    }
    queue->suiv = malloc(sizeof(struct lc));
    assert(queue->suiv != NULL);
    queue->suiv->val = cont;
    queue->suiv->suiv = NULL;
    *liste = sent.suiv;
}

void remove_liste(struct lc **liste, struct contact *cont) {
    struct lc sent = { -1, *liste };
    struct lc *p = &sent;
    while (p->suiv != NULL && p->suiv->val != cont) {
        p = p->suiv;
    }
    if (p->suiv != NULL) {
        struct lc *style = p->suiv;
        p->suiv = style->suiv;
        free(style);
    }
    *liste = sent.suiv;
}


void affiche_liste(struct lc *liste) {
  while (liste != NULL) {
        struct contact *contact= liste->val;
        printf("{%s;%s} -> ", contact->nom, contact->numero);
        liste = liste->suiv;
    }
    printf("FIN\n");

}
