#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "number.h"
#define NL printf("\n")
#define TPL while(getchar()!='\n')

number *sortieren(FILE *f1)
{
 number *first;
 first=NULL;
 number *new;
 number *hp;
 int i;
 new=(number*)malloc(sizeof(number));   //neuer speicherplatz
 new->name=(char*)malloc(7);
 while(!feof(f1))
  {
   fscanf(f1,"%s %d %lf",new->name,&new->zahl,&new->zehl);
   if(first==NULL)              //erstes element
   {
    first=new;
    new->next=NULL;
   }
   i=rand()%2;
   if(i==0)          		//element an anfang
   {
    new->next=first;
    first=new;
   }
   else                         //element an schluss
   {
    for(hp=first;hp->next!=NULL;hp=hp->next);
    hp->next=new;               //hp pointer auf neues element
    new->next=NULL;             //next pointer gleich NULL
   }
   new=(number*)malloc(sizeof(number));
   new->name=(char*)malloc(7);
  }
 return first;
}

void ausgabe(number *pointer)
{
 while(pointer)
 {
  printf("%s %d %.1lf",pointer->name,pointer->zahl,pointer->zehl);NL;
  pointer=pointer->next;
 }
}

int main (int argc, char *argv[])
{
 FILE *f1;
 number *pointer;
 if(argc!=2){printf("ERROR 0");NL;return;}
 f1=fopen(argv[1],"r");
        if(f1==NULL){printf("ERROR 1");return;}
 pointer=sortieren(f1);NL;
 ausgabe(pointer);
 return 0;
}
