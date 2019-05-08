/****************************************************************/
/**********************PL ML CODING HW 2 ************************/
/*********************KIM JUNSEONG ******************************/
/*******************201414212***********************************/
/*********************************************2019.05.08********/

/***********************HEADER*********************************/
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
///////////////////////////////////////////////////////////////

/*              贸澜俊 立辟 沁带 规过                */ 
/*
#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head) {
    struct ListNode sorted;
    struct ListNode *cur = head;
    
    sorted.next = NULL;
    
    while (cur) {
        struct ListNode *next = cur->next;
        struct ListNode *sorted_cur = &sorted;
        while (1) {
            if (!sorted_cur->next || sorted_cur->next->val > cur->val) {
                cur->next = sorted_cur->next;
                sorted_cur->next = cur;
                break;
            }
            
            sorted_cur = sorted_cur->next;
        }
        cur = next;
    }
    return sorted.next;
}
*/
/////////////////////Change the way you provided it to me by the professor. //////////////// 
/////////////////////Modify using the POW function as it is//////////////////////

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
int IL_is_empty(PIL p);
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
   while(p != NULL) {
		printf("%d ", (p->h));
		p = p->t;
   }
   printf("]");
}/////////The last number was not output and has been modified////////////

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
int IL_is_empty(PIL p)
{
	if(p==NULL)
	return true;
	else
	return false;
}
/*****************Using STDBOOL instead of ENUM provided by professor******/
/////////////////this function Print out whether it is true or not/////////
bool greater_than(int n1,int n2)
{
	if(n1>n2)
	return true;
	else
	return false;
}
///////////////////////////////////////////////////////
PIL ins(bool (*gt)(int,int),int x, PIL l)
{ 
	int y;
	if(IL_is_empty(l)) /* [] */
	return IL_cons(x,l);
	else
	{
		if((*gt)(x,y=IL_head(l)))
		{
			return IL_cons(y, ins(gt,x, IL_tail(l)));
		}
		else{
			return IL_cons(x,l);
		}
	}
}
//////Convert ML CODE below to code/////////
/* fun ins gt(x,nil) = [x]
	| ins gt(x, y::Ys) =
		if gt(x,y) then
			y::ins gt(x,ys)
				else x::y::ys;
*/
PIL isort(bool (*gt)(int , int ),PIL l)
{
	if(IL_is_empty(l)) /* (!l->head=null) */
	return l;
	else
	ins(gt,IL_head(l),isort(gt,IL_tail(l)));	
}
//////////Convert ML CODE below to code////////////
/* fun isort gt nil= nil
	|isort gt(x::xs)=
		ins gt(x, (isort gt xs));

*/
main()
{
	PIL l;
	
	l=isort(&greater_than, IL_cons(3, IL_cons(1,IL_cons(4,IL_cons(5,IL_cons(9,IL_cons(2,IL_cons(6,NULL))))))));
	
	IL_print(l);
}

