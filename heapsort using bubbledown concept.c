/****************************************************************/
/**********************PL ML CODING HW 3 ************************/
/*********************KIM JUNSEONG ******************************/
/*******************201414212***********************************/
/*********************************************2019.05.24********/

/***********************HEADER and define *********************************/
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAX 100
int arr[MAX+1];//// All this space was filled with zeros 
//when I declared this arrangement to the global variable. 


///////////////////////////////////////////////////////////////

/////////////////////Change the way you provided it to me by the professor. //////////////// 
/////////////////////Modify using the isort function as it is//////////////////////

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
   printf("[| ");
   while(p != NULL) {
		printf("%d ", (p->h));
		p = p->t;
   }
   printf("|]");
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
////////////////////////////////////////////////////////////////////////
/******************* add this three functions for heapsort *************/
void bubbleDown(int , PIL);
PIL heapSort(PIL,int);
PIL heapifyy(PIL, PIL, int);
////////////////////////////////////////////////////////////
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

 IL_is_empty(PIL p)
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
/**************Functions for ARRAY grammar provided by STANDARD ML****//////
int sub(int arr[],int i)
{
	return arr[i];	
}
int update(int arr[],int i, int v)
{
	arr[i]=v;
	return *arr; 
}
///////////////////////////////////////////

PIL isort(bool (*gt)(int , int ),PIL l)
{
	if(IL_is_empty(l)) /* (!l->head=null) */
	return l;
	else
	ins(gt,IL_head(l),isort(gt,IL_tail(l)));	
}
void bubbleDown(int i, PIL l)
{
	if (i<=1)
	return;
	else{
		int mid= i/2;
		if sub(l)
	}	
}
PIL heapify(PIL l1,PIL l2,int n)
{
;	
}
PIL heapsort(PIL l, int n)
{
	
}

main()
{
	PIL l;
	int i;	
	l=isort(&greater_than, IL_cons(3, IL_cons(1,IL_cons(4,IL_cons(5,IL_cons(9,IL_cons(2,IL_cons(6,NULL))))))));
	int arr[5]={1,2,3,4,5};
	update(arr,3,7);
	for(i=0; i<5; i++)
	printf("%d ",arr[i] );
	IL_print(l);
}

