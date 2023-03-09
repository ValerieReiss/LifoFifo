//LIFO Liste
//uebersetzen mit cc -o name progname

#include <stdio.h>
#include "flasche.h"
#define NL printf("\n")
#define TPL while(getchar()!='\n')

flasche *listeneu(FILE *f1)
{
 int i=0,j=0;
 flasche *head; head=NULL;		//zeiger auf *next sowie auf adresse d.flasche
 flasche *hp;			//hilfspointer macht platz + übergibt an head
 hp=(flasche*)malloc(sizeof(flasche));	//platzaufbereitung
 hp->name=(char*)malloc(5);		//namenallokierung da char!
 do
 {
  fscanf(f1,"%s %d %d",hp->name,&hp->neu,&hp->farbe);
  if(feof(f1)) 	{break;}
  if(hp->neu==0){j++;}
  else		{i++;
  		 hp->next=head;		//in next-feld wird head reingeschrieben
		 head=hp;		//head bekommt die neue adr.von hp
		 hp=(flasche*)malloc(sizeof(flasche));
		 hp->name=(char*)malloc(5);}
 }while(1);
 i+=j;printf("es gibt %d flaschen",i);NL;
 return head;
}

void listeausgeben(flasche*neu)
{
 while(neu)
 {//flasche *hp;
  printf("%s %d %d",neu->name,neu->neu,neu->farbe);NL;
  neu=neu->next;
 }
}

int main(int argc,char *argv[])
{
 FILE *f1;
 flasche *neu;

 if(argc!=2){printf("ERROR 0");NL;exit(0);}
 f1=fopen(argv[1],"r");
 	if(f1==NULL){printf("ERROR 1");NL;exit(1);}
 neu=listeneu(f1);
 listeausgeben(neu);
 return 0;
}
