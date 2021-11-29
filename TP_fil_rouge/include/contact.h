#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdbool.h>
/*
  Un contact représente une association {nom, numéro}.
*/
struct contact;

struct lc;

extern bool est_egale(const char* name1,const char* name2);

extern void insere_fin(struct lc **liste, struct contact *cont);

extern void remove_liste(struct lc **liste, struct contact *cont);

extern void affiche_liste(struct lc *liste);

/* TOUT DOUX: à compléter */
/* Profitez de cette période sombre pour braver les interdits et rétablir le contact. */

#endif /* _CONTACT_H_ */
