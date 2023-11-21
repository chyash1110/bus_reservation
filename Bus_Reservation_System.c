#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch[10][130]={"AC Volvo","Volvo","RailYabsi","Primo","ZingBus","Indian Xpress"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int bsno;
void bus();//for list of bus
void name_number(int booking,char numsbs[100]);
void booking();//for booking the tickets
int read_number(int bsno);//for reading the number from the file
void read_name(int bsno);//for reading the name from the file
void status();//for printing the status by user input
void status_1(int bsno);//for printing the status while booking ticket
void cancle();
void login();

int main()
{
    printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
   login();
    int num,i;
    do
    {
        system("cls");
        printf("\n\n\n");
        printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
        printf("\t\t\t\t\t[1]=> View Bus List\n");
        printf("\n");
        printf("\t\t\t\t\t[2]=> Book Tickets\n");
        printf("\n");
        printf("\t\t\t\t\t[3]=> Cancel Booking\n");
        printf("\n");
        printf("\t\t\t\t\t[4]=> Bus Status Board\n");
        printf("\n");
        printf("\t\t\t\t\t[5]=> Exit\n\n");
        printf("===============================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%d",&num);
        switch(num)
        {
            case 1:
                bus();//for list of bus
                break;
            case 2:
                booking();//for booking the tickets
                break;
            case 3:
                cancle();
                break;
            case 4:
                status();
                break;
        }
        getch();
    }
    while(num != 5);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t Brought To You By Yash Chauhan");
    getch();
    return 0;
}


void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n");
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n");
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n");
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
}

void booking()
{

    int i=0;
    char numsbs[100];
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for entering bsain number
bus();//for seeing bus
printf("Enter the Bus number:--->");
scanf("%d",&bsno);
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for selecting coach
printf("Your Bus Number is %d ********** %s",bsno,ch[bsno-1]);
status_1(bsno);
 FILE *f1, *fopen();//for reading the seats from the user.
 char sbs1[80]="32",sbs2[4],sbs3[4];
 int seat1,seat2,booking=0;
if(bsno == 1)
{
 f1 = fopen("bs1.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}else if(bsno == 2)
{
 f1 = fopen("bs2.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}else if(bsno == 3)
{
 f1 = fopen("bs3.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}
else if(bsno == 4)
{
 f1 = fopen("bs4.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}
else if(bsno == 5)
{
 f1 = fopen("bs5.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}
seat1=atoi(sbs1);//covert the sbsing into number
if(seat1 <= 0)
{
 printf("There is no blank seat in this bus ");
}else
{
printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
printf("\n\t\t\t\tNumber of Tickets:----->");
scanf("%d",&booking);
printf("\n");

seat1=seat1-booking;
itoa(bsno,numsbs,10);
name_number(booking,numsbs);
printf("\n\t\t\t\tThe Total booking amount is %d",200*booking);
itoa(seat1, sbs1, 10);
//for reading the seats from the user.
if(bsno == 1)
{
 f1 = fopen("bs1.txt","w");
 fputs(sbs1,f1);
 fclose(f1);
}
else if(bsno == 2)
{
 f1 = fopen("bs2.txt","w");
 fputs(sbs1,f1);
  fclose(f1);
}
else if(bsno == 3)
{
 f1 = fopen("bs3.txt","w");
 fputs(sbs1,f1);
  fclose(f1);
}
else if(bsno == 4)
{
 f1 = fopen("bs4.txt","w");
 fputs(sbs1,f1);
  fclose(f1);
}
else if(bsno == 5)
{
 f1 = fopen("bs5.txt","w");
 fputs(sbs1,f1);
 fclose(f1);
}
}
}



void name_number(int booking,char numsbs[100])
{
char tempsbs[100],tempsbs1[12]="status",tempsbs2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numsbs,".txt");
   strcat(tempsbs1,numsbs);
   strcat(tempsbs2,numsbs);
   a = fopen(tempsbs1,"a");//for open the file to write the name in the file
   b = fopen(tempsbs2,"a");//for open the file for writing the number in the file
for(i=0; i<booking; i++)//for entering the person name and seat number in the file
{
    printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
      printf("\t\t\t\tEnter the seat number:--->");
      scanf("%d",&number);
      printf("\t\t\t\tEnter the name of person:--->");
      scanf("%s",name[number-1]);
    printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(number, tempsbs, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempsbs);

}
fclose(a);
fclose(b);
}



int read_number(int bsno)//for putting the numeric value in the array
{
char tempsbs[100],tempsbs2[12]="number";
FILE *a,*b;
char numsbs[100];
int i=0,j=0,k;
itoa(bsno,numsbs,10);
strcat(numsbs,".txt");
strcat(tempsbs2,numsbs);
a = fopen(tempsbs2,"a+");//for open the file to write the name in the file
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_name(int bsno)//for putting the numeric value in the array
{
char tempsbs1[12]="status";
FILE *b;
char numsbs[100];
int i=0,j=0,k=0;
itoa(bsno,numsbs,10);
strcat(numsbs,".txt");
strcat(tempsbs1,numsbs);
b = fopen(tempsbs1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status()
{
system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,bsno,index=0,j;
    printf("Enter the number of bus:---->");
    scanf("%d",&bsno);
    j=read_number(bsno);
    read_name(bsno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n",bsno,ch[bsno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void status_1(int bsno)
{
    printf("Your Bus Number is %d ********** %s",bsno,ch[bsno-1]);
    system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,index=0,j;
    j=read_number(bsno);
    read_name(bsno);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}


void cancle()
{
 int seat_no,i,j;
 char numsbs[100],tempsbs2[15]="number",tempsbs1[15]="status";
 printf("Enter the bus number:---->");
 scanf("%d",&bsno);
 itoa(bsno,numsbs,10);
 strcat(numsbs,".txt");
 strcat(tempsbs1,numsbs);
 strcat(tempsbs2,numsbs);
 read_number(bsno);
 read_name(bsno);
 status_1(bsno);
 printf("Enter the seat number:--->");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempsbs1,"w+");
 b = fopen(tempsbs2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tYour 200 rupees has been Refunded\t\t\t\n");
    printf("======================================================================================================\n");
}


void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10];
    do
{
	system("cls");

    printf("\n  =========================  LOGIN FORM  =========================  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"graphic_era")==0 && strcmp(pword,"geu123")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN FAILED !!!!");
		a++;

		getch();//holds the screen

	}
}
	while(a<=3);
	if (a>3)
	{
		printf("\nSorry you have entered the wrong username or password multiple times!!!");
		getch();
	}
    exit(0);
		system("cls");
}
