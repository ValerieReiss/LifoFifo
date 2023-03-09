//FIFO Liste
//uebersetzen mit cc -o name progname

#include <stdio.h>
#include "flasche.h"
#define NL printf("\n")
#define TPL while(getchar()!='\n')

flasche *listeneu(FILE*f2)
{
 int i=0;
 flasche *first=NULL;
 flasche *hp;
 flasche *new;
 new=(flasche*)malloc(sizeof(flasche));
 new->name=(char*)malloc(5);
 
 while(!feof(f2))
 {
  fscanf(f2,"%s %d %d",new->name,&new->neu,&new->farbe);
  if(first==NULL)	
  	{
	 first=new; new->next=NULL;i++;		 //noch keine liste
  	}
  else	{
  	 i++;					 //schon eine liste
 	 for(hp=first;hp->next!=NULL;hp=hp->next);//-> letztes element
 	 hp->next=new;
	 new->next=NULL;
	}
 new=(flasche*)malloc(sizeof(flasche));
 new->name=(char*)malloc(5);
 }
 printf("es gibt %d flaschen",i);NL;
 return first;
}

void listeausgeben(flasche *poi)
{
 while(poi)
 {
  printf("%s %d %d",poi->name,poi->neu,poi->farbe);NL;
  poi=poi->next;
 }
}

int main(int argc,char *argv[])
{
 FILE *f2;
 flasche *poi;

 if(argc!=2){printf("ERROR 0");NL;exit(0);}
 f2=fopen(argv[1],"r");
 	if(f2==NULL){printf("ERROR 1");NL;exit(1);}
 poi=listeneu(f2);
 listeausgeben(poi);
 return 0;
}
