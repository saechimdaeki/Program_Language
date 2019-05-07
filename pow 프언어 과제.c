#include <stdio.h>
#include <stdlib.h>

/* Definition of Int List */
typedef struct IntList   IL;   /* */
typedef struct IntList* PIL;   /* */

struct IntList {
   int h;
   PIL t;
};

PIL IL_empty;
int IL_head(PIL);      /* IL head            */
PIL IL_tail(PIL);      /* IL tail            */ 
PIL IL_cons(int, PIL); /* ::  IL construct   */

void IL_print(PIL);

int IL_head(PIL pil) {
   return pil->h;
}

PIL IL_tail(PIL pil) {
   return pil->t;
}

PIL IL_cons(int head, PIL pil) {
   
   PIL il = (PIL)malloc(sizeof(IL));
   il->h = head;
   il->t = pil;
   return (il);
}

void IL_print(PIL p) {
   printf("[ ");
   while(p->t != NULL) {
		printf("%d ", (p->h));
		p = p->t;
   }
   printf("]");
}

/* Definition of Int List List */
typedef struct IntListList   ILL;   /* */
typedef struct IntListList* PILL;   /* */

struct IntListList {
   PIL   h;
   PILL t;
};

PILL ILL_empty;                
PIL  ILL_head(PILL);    /* ILL head            */
PILL ILL_tail(PILL);        /* ILL tail            */ 
PILL ILL_cons(PIL,  PILL);  /* ::  ILL Construct   */
PILL ILL_conc(PILL, PILL);  /* @   ILL Concatenate */

void ILL_print(PILL);

PIL  ILL_head(PILL pill) {
	return pill->h;	
}  
PILL ILL_tail(PILL pill) {
   return pill->t;
}

PILL ILL_cons(PIL pil,  PILL pill) 
{

	ILL_empty = (PILL)malloc(sizeof(ILL));
	ILL_empty->h = pil;
	ILL_empty->t = pill;
	return ILL_empty;   
}

PILL ILL_conc(PILL pill1, PILL pill2)
{
   PILL tmp = pill1;
   while(pill1->t != NULL)
   {
      pill1 = pill1->t;
   }
   pill1->t = pill2;
   return (tmp);
}

void ILL_print(PILL p) {
	printf("[");
	while(p->t != NULL) {
		IL_print(p->h);
		printf(", ");
		p = p->t;
   }
   IL_print(p->h);
   printf("]\n");
}

PILL pre(int x, PILL ll) 
{
   if (!ll)	return NULL;
   else	return ILL_cons(IL_cons(x,ILL_head(ll)),pre(x,ILL_tail(ll)));
}

/* 
  fun pre(x,nil) = nil
   |  pre(x,L::Ls) = (x::L)::pre(x,Ls); 
*/

PILL pow(PIL l) 
{
   PILL ps = NULL;

   if (!l)
      return ILL_cons(IL_empty, NULL);
   else 
   {
       ps = pow(IL_tail(l));
       return ILL_conc(ps, pre(IL_head(l),ps));   
   }
}

/* 
  fun pow([]) = [[]]
   |  pow(x::xs) =
       let
          val ps = pow(xs);
       in
          ps @ pre(x, ps)
       end;
*/

void main()
{
   PIL   set = NULL;
   PILL pset = NULL;

   /* Initialization for empty IL set and empty ILL set */
   
   if ((IL_empty=(PIL)malloc(sizeof(IL)))==NULL)
   {
      printf("No memory available!\n");
      exit(0);
   }
  
   /* Construct the set of {1, 2, 3} */
   set = IL_cons(1, IL_cons(2, IL_cons(3, NULL))); 
   
   /* This is just a simple version of defining a set. 
      You have to construct the code to input each set from the standard input. */

   /* Defining an empty set */
   IL_empty->h=0;
   IL_empty->t=NULL;
   
   /* Generate the power set of {1, 2, 3} */
   pset = pow(set);

   /* Output the power set */
   ILL_print(pset);
}

