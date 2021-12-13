#ifndef PROJET_H_INCLUDED
#define PROJET_H_INCLUDED
enum
{
	EREF,
	ENOM,
	ECATEG,
	EQUANT,
	ETYPE,
	EDATE,
	EPOID,
	COLUMNS,
};
typedef struct
{char ref[20];
char nom[20];
char categ[20];
int quant;
char type[20];
char date[20];
int poid;
}produit;





#endif // PROJET_H_INCLUDED
