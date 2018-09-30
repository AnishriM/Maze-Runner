//Name:-Krishna Nadapurkar
//Roll No.:-2016BTECS00027
//Name:-Sagar Mhantati.
//Roll No:-2016BTECS00031





#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
typedef struct cordinate
{
int x;
int y;
}cordinates;

typedef struct snode
{
	int data;
	struct snode *next;
}snode;

typedef struct stack
{
	snode *top;
}stack;

void init(stack *t)
{
	t->top=NULL;

}
void push(stack *t,int n)
{
	snode *a=(snode*)malloc(sizeof(snode));
	a->data=n;
	a->next=NULL;
	if(t->top==NULL)
	{
		t->top=a;
	}
	else
	{
	a->next=t->top;
	t->top=a;

	}

}

int pop(stack *t)
{
   int x;
   snode *a=t->top;
	if(t->top==NULL)
	{
		return -1;
	}
	t->top=a->next;
	x=a->data;
	free(a);
	return x;

}
int stacktop(stack *t)
{
	if(t->top==NULL)
	return -1;

	return (t->top)->data;
}
int reverseprint(snode *head,snode *user,int vertex)
{
   //	FILE *fp;
	stack t;
	snode *a,*b;

	int flg=0;
	int st;
	b=head;
	if(head==NULL)
	return;
    //	fp=fopen("answer.txt","a");
      //	reverseprint(head->next);
      //	printf("%d ",head->data);
     //	printf("Head:\n");
	while(head!=NULL)
	{
       //		printf("%d ",head->data);
		push(&t,head->data);
		head=head->next;
	}
       //	printf("Stacktop of head:%d\n",head->data);
       //	printf("Copy of head:%d\n",b->data);
       //	printf("\n");
	a=t.top;
       //	b=user;
      /*	printf("User:\n");
	while(1)
	{
		printf("%d ",user->data);
		if(user->data==0)
		break;
		user=user->next;
	}*/
	printf("Path:\n");
	while(a!=NULL)
	{
	     printf("%d ",a->data);
	      if(a->data==vertex)
	     break;
	     a=a->next;
	}
    /*   while(a!=NULL||user->data!=vertex)
	{        printf("%d ",a->data);
		if(user->data!=a->data)
		break;
      //		fprintf(fp,"%d ",a->data);
	       a=a->next;

	       user=user->next;
	} */
	printf("\n");

	while(1)
	{
	      //	printf("Running\n");
	       //	printf("Head:%d User:%d",head->data,user->data);
		if(b->data!=user->data)
		break;
		b=b->next;
			user=user->next;
		if(b->data==0&&user->data==0)
		{
			printf("You win\n");
			flg=1;
			return 1;

		}
	}

	return 0;

      //f	fclose(fp);   */
}

int printstack(stack *t,stack *user,int vertex)
{
      int i=reverseprint(t->top,user->top,vertex);
	printf("\n");
	return i;
}

typedef struct node

	{
	int data;
	struct node *next;
}node;

typedef struct 	listnode
{
	int y;
	int j;
	int yv;
	int jv;
	int vertex;
	node *NXT;
}listnode;

typedef struct graph
{
	int E;
	int V;
	listnode *adj;
}graph;

int total=0;
graph* creategraph()
{
	FILE *fp;
	int x,y,i;
	node *t,*temp;
	int ee,vv,l;
	graph *G=(graph*)malloc(sizeof(graph));
	srand(time(0));
	l=rand()%3+1;
	if(l==1)
	{
		fp=fopen("maze1.txt","r");
	}
	else if(l==2)
	{
			  fp=fopen("maze1.txt","r");
	}
	else
	{
		fp=fopen("maze1.txt","r");
	}
       //	printf("Enter number of edges and nodes\n");
	fscanf(fp,"%d %d",&ee,&vv);
       //	printf("%d %d\n",ee,vv);
      // getch();
     //  printf("%d %d",*G->E,*G->V);
	G->E=ee;
	G->V=vv;
	G->adj=(listnode*)malloc(G->V*sizeof(listnode));
	for(i=0;i<G->V;i++)
	{
		(G->adj+i)->NXT=NULL;
		(G->adj+i)->y=(G->adj+i)->j=(G->adj+i)->yv=(G->adj+i)->jv=0;
		(G->adj+i)->vertex=i;
	}
	for(i=0;i<G->E;i++)
	{
		//printf("\nEnter edge %d as source-Destination\n",i+1);
		fscanf(fp,"%d %d",&x,&y);
	       //	printf("%d %d\n",x,y);
	     //	getch();
		temp=(node*)malloc(sizeof(node));
		temp->next=NULL;
		temp->data=y;
		t=(G->adj+x)->NXT;
		if(t==NULL)
				(G->adj+x)->NXT=temp;
		else
			{
			while(t->next!=NULL)
				t=t->next;
			t->next=temp;
			}
		(G->adj+x)->j++;
		(G->adj+y)->y++;

	}
       //	getch();
		fclose(fp);
	return G;
}
int findpath(stack *t,graph *G)
{
	int x,i,k;
	int steps=0;
	int path;
	node *tm;
	snode *a;
	stack user;
	int array[20];
	int check;
	time_t initialtime,finaltime;
	initialtime=time((0));
	printf("Enter your path");
       //	push(&user,0);
	while(1)
	{
	    scanf("%d",&array[i]);
	    push(&user,array[i]);
	//    printf("stacktop:%d\n",stacktop(&user));
	    if(array[i]==G->V-1)
	    break;
	    i++;
	}
	 a=user.top;
	while(stacktop(t)!=-1)
	{
		i=0;
		x=stacktop(t);

		if((G->adj+x)->j!=0)
		{
			tm=(G->adj+x)->NXT;
			while(i!=(G->adj+x)->jv)
			{   if(tm->next==NULL)break;
				tm=tm->next;

				i++;
			}
			push(t,tm->data);
			(G->adj+x)->jv=(G->adj+x)->jv%(G->adj+x)->j+1;
			if((G->adj+x)->y!=0)
				(G->adj+x)->yv=(G->adj+x)->yv%(G->adj+x)->y+1;

		}

		else
		{
			if(x==G->V-1)
				{
				   check=printstack(t,&user,G->V-1);
				  total++;
				   if(check==1)
				   {
				     //	printf("You Win!!!!!!!!\n");

					return;
				   }
				}



					while((G->adj+x)->j==(G->adj+x)->jv && x!=-1)
					{
						k=pop(t);
						x=stacktop(t);
					}

		}

	}

		if(check==0)
		{
		   printf("You Lose\n");
		}
	return(check);
}



void drawline(int x,int y,int a,int b)
{
int mx,my;
mx=(x+a)/2;
my=(y+b)/2;
delay(700);
line(x,y,mx,my);
setcolor(RED);
delay(700);
line(mx,my,a,b);
setcolor(WHITE);
}


void drawgraph(graph *G)
{  cordinates *c;
   char txt[10];
   int i,gd=0,gm;
   node *t;
   c=(cordinates*)malloc(sizeof(cordinates)*G->V);
   srand(time(0));
   for(i=0;i<G->V;i++)
   {
   (c+i)->x=(abs(rand()%590)+100)%590;
   (c+i)->y=(abs(rand()%430)+1+25+100)%430;
   }
 initgraph(&gd,&gm,"C://TURBOC3//BGI");
   for(i=0;i<G->V;i++)
   { t=(G->adj+i)->NXT;
      if(t==NULL)continue;
       sprintf(txt,"%d",i);
     txt[2]='\0';
     if(i==0)
     outtextxy((c+i)->x,(c+i)->y,"START");
    /* else if(i==G->V-1)
     outtextxy((c+i)->x,(c+i)->y,"GOAL"); */
     else
     outtextxy((c+i)->x,(c+i)->y,txt);
      while(t!=NULL)
      {
 /*     int x1=(c+i)->x;
      int y1=(c+i)->y;
      int x2=(c+(t->data))->x;
      int y2=(c+(t->data))->y;
      print("%d %d %d %d",x1,y1,x2,y2); */
      drawline( (c+i)->x, (c+i)->y, (c+(t->data))->x,(c+(t->data))->y);
     // printf("%d",t->data);
      t=t->next;
      }

   }
   outtextxy((c+G->V-1)->x,(c+G->V-1)->y,"GOAL");
   outtextxy(0,0,"Enter A to refresh the map else B to procced");
   if(toupper(getch())=='A')
   {
	drawgraph(G);
   }
   getch();
   closegraph();
}
void instruction()
{
clrscr();
printf("\n\t\tThis is the maze runner game.");
printf("\n\t\tThere is our Jerry at the start point");
printf("\n\t\tHe is so hungry so he wish to eat some delicious cheese");
printf("\n\t\tBut problem is that the cheese is at goal");
printf("\n\t\tand for this he need to travel from maze.");
printf("\n\t\tThe direction in the maze is given by lines");
printf("\n\t\twhich coloured half with white and remaining with red");
printf("\n\t\tJerry can move from white to red but can't red to white");
printf("\n\t\tSo friends help the Jerry to reach at the destination");
printf("\n\t\tBe fast because he is so hungry");
printf("\n\t\tBest of luck!");
getch();
}
void writescore(float score,char plnm[20])
{

float sc;
char nm[20];
FILE *f;
f=fopen("score.txt","r");
fscanf(f,"%s%f",&nm,&sc);
if(score<=sc)
  {
	sc=score;
	fclose(f);
	f=fopen("score.txt","w");
	fprintf(f,"%s\n%.2f",plnm,sc);
	fclose(f);
  }
}

void main()
{
//int loop;
graph *G;
FILE *fp;
int i,j,temp;
int steps;
float score;
time_t initialtime,finaltime;
char name[20],name1[20];
float fff;
   stack s;
	init(&s);
		push(&s,0);
   clrscr();
	  // init(&s);
	///	push(&s,0);


  /* for(i=0;i<G->V;i++)
   {
       printf("%d%fd%d%d\n",(G->adj+i)->y,(G->adj+i)->j,(G->adj+i)->yv,(G->adj+i)->jv);
   }
  */
  while(1)
  {

     clrscr();
     printf("\n\t\t--------------------------------");
     printf("\n\t\tEnter S to start the game");
     printf("\n\t\tEnter I for instructions");
     printf("\n\t\tEnter V for high score and history");
     printf("\n\t\tEnter Q to quit the game");
   //  printf("\n\t\tEnter F to findpath the game");
     printf("\n\t\t--------------------------------\n\n\t\t");
     printf("Enter your choice");
     switch(toupper(getch()))
     {
	case 'S': initialtime=(time(NULL));
		printf("\n\n\t\tEnter Player Name:");
		scanf("%s",name);
		fp=fopen("history.txt","w");
		fprintf(fp,"%s",name);
		fclose(fp);
		G=creategraph();
		drawgraph(G);
		steps=findpath(&s,G);
		getch();
		finaltime=(time(NULL));
		score=difftime(finaltime,initialtime);
		if(steps==1)
		{
		printf("Your Score is:%f\n",score/total);
			getch();
		}
		if(steps==1)
		{
		writescore(score/total,name);
		}
		break;
	case 'I':instruction();
		 break;
	case 'V': fp=fopen("score.txt","r");
		 fscanf(fp,"%s%f",&name1,&fff);
		 printf("\n\n\t\t");
		 printf("\n\n\t\t %s has secured the Highest Score %.2f",name1,fff);
		 printf("\n\n\t\t");
		 getch();
		 fclose(fp);
		 break;
	case 'Q':clrscr();
		 printf("\n\n\t\tThanks For Playing!");
		 getch();
		 exit(0);
		 break;
     }
  }
  getch();
}
