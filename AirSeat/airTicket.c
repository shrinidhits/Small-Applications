#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<direct.h>
#include<string.h>
void intro();
void delay(float number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}
int isFull(int a[])
{
    int flag=0;
    for(int i=0;i<20;i++)
    {
        if(a[i]!=1)
        {
            return 0;
        }
    }
    return 1;
}
int isBusiFull(int a[])
{
    int flag=0;
    for(int i=0;i<5;i++)
    {
        if(a[i]!=1)
        {
            return 0;
        }
    }
    return 1;
}
int isEcoFull(int a[])
{
    int flag=0;
    for(int i=5;i<20;i++)
    {
        if(a[i]!=1)
        {
            return 0;
        }
    }
    return 1;
}
void reset(int a[]){
    for(int i=0;i<20;i++)
    {
        a[i]=0;
    }
}
void economy(int a[])
{
    if(!isFull(a))
    {
        if(!isEcoFull(a))
        {
            printf("\n\t\t\tSeat details of this plane\n\n\t\t\t");
            int seatNo[20];
            for(int i=0;i<5;i++)
            {
                printf("B%d ",a[i]);
            }
            for(int i=5;i<10;i++)
            {
                printf("E%d ",a[i]);
            }
            printf("\n\t\t\t-----------------------------\n\t\t\t");
            for(int i=10;i<20;i++)
            {
                printf("E%d ",a[i]);
            }
            printf("\n\n\t\t\tSeats available are:\n\t\t\t");
            for(int i=5;i<20;i++)
            {
                if(a[i]==0)
                {
                    printf("%d ",(i+1));
                }
            }
            printf("\n\n\t\t\tEnter number of seats to book:\n\t\t\t");
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                int x;
                printf("\n\n\t\t\tEnter seat number: ");
                scanf("%d",&x);
                if(x<6 || x>20 || a[x-1]!=0)
                {
                    printf("\t\t\tEnter a valid seat number\n\t\t\t");
                    scanf("%d",&x);
                }
                seatNo[i]=x;
                a[seatNo[i]-1]=1;
            }
            printf("\n--------------------------------------------------------------------------------");
            printf("\n\t\t\tBOOKED TICKET(S)\n");
            printf("\n\t\t\tSEAT NOs ARE:\n\t\t\t");
            for(int i=0;i<n;i++)
            {
                printf("%d ",seatNo[i]);
            }
            printf("\n\t\t\t");
            for(int i=0;i<5;i++)
            {
                printf("B%d ",a[i]);
            }
            for(int i=5;i<10;i++)
            {
                printf("E%d ",a[i]);
            }
            printf("\n\t\t\t-----------------------------\n\t\t\t");
            for(int i=10;i<20;i++)
            {
                printf("E%d ",a[i]);
            }
            printf("\n--------------------------------------------------------------------------------");
        }
        else{
            printf("\n\n\n\t\t\tEconomy class full");
        }
    }
    else{
        printf("\n\n\n\t\t\tFlight is booked");
    }
    getch();

}
void business(int a[])
{
    if(!isFull(a))
    {
        if(!isBusiFull(a))
        {
            int seatNo[20];
            printf("\n\t\t\tSeat details of this plane\n\n\t\t\t");
            for(int i=0;i<5;i++)
            {
                printf("B%d ",a[i]);
            }
            for(int i=5;i<10;i++)
            {
                printf("E%d ",a[i]);
            }
            printf("\n\t\t\t-----------------------------\n\t\t\t");
            for(int i=10;i<20;i++)
            {
                printf("E%d ",a[i]);
            }
            printf("\n\n\t\t\tSeats available are:\n\t\t\t");
            for(int i=0;i<5;i++)
            {
                if(a[i]==0)
                {
                    printf("%d ",(i+1));
                }
            }
            printf("\n\n\t\t\tEnter number of seats to book:\n\t\t\t");
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                int x;
                printf("\n\n\t\t\tEnter seat number: ");
                scanf("%d",&x);
                if(x<0 || x>5 || a[x-1]!=0)
                {
                    printf("\t\t\tEnter a valid seat number\n\t\t\t");
                    scanf("%d",&x);
                }
                seatNo[i]=x;
                a[seatNo[i]-1]=1;
            }
            printf("\n--------------------------------------------------------------------------------");
            printf("\n\t\t\tBOOKED TICKET(S)\n");
            printf("\n\t\t\tSEAT NOs ARE:\n\t\t\t");
            for(int i=0;i<n;i++)
            {
                printf("%d ",seatNo[i]);
            }
            printf("\n\t\t\t");
            for(int i=0;i<5;i++)
            {
                printf("B%d ",a[i]);
            }
            for(int i=5;i<10;i++)
            {
                printf("E%d ",a[i]);
            }
            printf("\n\t\t\t-----------------------------\n\t\t\t");
            for(int i=10;i<20;i++)
            {
                printf("E%d ",a[i]);
            }
            printf("\n--------------------------------------------------------------------------------");
        }
        else{
            printf("\n\n\t\t\tBusiness class full");
        }
    }
    else{
        printf("Flight is booked");
    }

    getch();
}
void delayanimation(float n)
{
    int l=29;
    printf("\n\t\t\t");
    while(l){
        printf("#");
        delay(n);
        l--;
    }
}
int login()
{
    FILE *pass;
    pass=fopen("userpass.txt","r");
    char username[6],realuser[6];
    char userpwd[6],realpass[6];
    int iuser=0,ipass=0;
    while(iuser<5)
    {
        realuser[iuser]=fgetc(pass);
        iuser++;
    }
    realuser[5]='\0';
    while(ipass<5)
    {
        realpass[ipass]=fgetc(pass);
        ipass++;
    }
    realpass[5]='\0';
    fclose(pass);
    int i;
    printf("\n\n\t\t\t\t  LOGIN     \n");
    printf("\n\n\t\t\tEnter your username : ");
    scanf("%s",username);
    printf("\n\n\t\t\tEnter your password : ");
    for(i=0;i<5;i++)
    {
        userpwd[i]=getch();
        printf("*");
    }
    userpwd[i]='\0';
    if(!strcmp(username,realuser) && !strcmp(userpwd,realpass))
    {
        printf("\n\n\n\t\t\tLogged In Successfully");
        return 1;
    }
    else
    {
        printf("\n\n\n\t\t\tIncorrect username or password");
        return 0;
    }
}
void homepage()
{
    printf("\n\n\n\t\t\t WELCOME TO BENGALURU AIRPORT\n\n\n");
    printf("\n\n\n\t\t       PASSENGER SEAT RESERVATION SYSTEM\n\n\n");
    printf("\n\n\n\t\t\t     LOADING ALL FLIGHTS\n\t\t\t");
    delayanimation(0.15);
    system("cls");
    int log;
    while(1)
    {
        log=login();
        if(!log){
            printf("\n\n\t\t\tEnter credentials again!!");
            getch();
            system("cls");
        }
        else{
            break;
        }
    }
    printf("\n\n\t\t\tPress any key to continue");
    getch();
}

void bd()
{
    int a[20];
    int choice;
    int seat;
    FILE *fp;
    for(;;)
    {
        fp=fopen("bangdel.txt","r");
        int idx=0;
        char ch;
        while((ch = fgetc(fp)) != EOF)
        {
            a[idx]=ch;
            idx++;
        }
        fclose(fp);
        system("cls");
        printf("\n\n\n\t\tSEAT BOOKING FOR BNG-DEL FLIGHT\n");
        printf("\n\n\t\t\t1.ECONOMY CLASS\n\t\t\t2.BUSINESS CLASS\n\t\t\t3.CLEAR SEATS\n\t\t\t4.BACK TO FLIGHTS\n\t\t\t");
        printf("\n\n\t\t\tPLEASE SELECT\n\t\t\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                system("cls");
                printf("\n\n\n");
                fp=fopen("bangdel.txt","w");
                economy(a);
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                break;
            case 2:
                system("cls");
                printf("\n\n\n");
                business(a);
                fp=fopen("bangdel.txt","w");
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                break;
            case 3:
                system("cls");
                reset(a);
                printf("\n\n\n\t\t\tCLEARING SEATS WAIT....\n\t\t\t");
                delayanimation(0.25);
                printf("\n\n\n\n\n\n\t\t\tALL SEATS CLEARED!!\n\t\t\t");
                fp=fopen("bangdel.txt","w");
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                getch();
                system("cls");
                break;
            case 4:
                system("cls");
                intro();
                break;

        }
    }
}
void bk()
{
    int a[20];
    int choice;
    int seat;
    FILE *fp;
    for(;;)
    {
        fp=fopen("bangkol.txt","r");
        int idx=0;
        char ch;
        while((ch = fgetc(fp)) != EOF)
        {
            a[idx]=ch;
            idx++;
        }
        fclose(fp);
        system("cls");
        printf("\n\n\n\t\tSEAT BOOKING FOR BNG-KOL FLIGHT\n");
        printf("\n\n\t\t\t1.ECONOMY CLASS\n\t\t\t2.BUSINESS CLASS\n\t\t\t3.CLEAR SEATS\n\t\t\t4.BACK TO FLIGHTS\n\t\t\t");
        printf("\n\n\t\t\tPLEASE SELECT\n\t\t\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                system("cls");
                printf("\n\n\n");
                fp=fopen("bangkol.txt","w");
                economy(a);
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                break;
            case 2:
                system("cls");
                printf("\n\n\n");
                business(a);
                fp=fopen("bangkol.txt","w");
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                break;
            case 3:
                system("cls");
                reset(a);
                printf("\n\n\n\t\t\tCLEARING SEATS WAIT....\n\t\t\t");
                delayanimation(0.25);
                printf("\n\n\n\n\n\n\t\t\tALL SEATS CLEARED!!\n\t\t\t");
                fp=fopen("bangkol.txt","w");
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                getch();
                system("cls");
                break;
            case 4:
                system("cls");
                intro();
                break;

        }
    }
}
void bm()
{
    int a[20];
    int choice;
    int seat;
    FILE *fp;
    for(;;)
    {
        fp=fopen("bangmang.txt","r");
        int idx=0;
        char ch;
        while((ch = fgetc(fp)) != EOF)
        {
            a[idx]=ch;
            idx++;
        }
        fclose(fp);
        system("cls");
        printf("\n\n\n\t\tSEAT BOOKING BANG-MNG FLIGHT\n");
        printf("\n\n\t\t\t1.ECONOMY CLASS\n\t\t\t2.BUSINESS CLASS\n\t\t\t3.CLEAR SEATS\n\t\t\t4.BACK TO FLIGHTS\n\t\t\t");
        printf("\n\n\t\t\tPLEASE SELECT\n\t\t\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                system("cls");
                printf("\n\n\n");
                fp=fopen("bangmang.txt","w");
                economy(a);
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                break;
            case 2:
                system("cls");
                printf("\n\n\n");
                business(a);
                fp=fopen("bangmang.txt","w");
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                break;
            case 3:
                system("cls");
                reset(a);
                printf("\n\n\n\t\t\tCLEARING SEATS WAIT....\n\t\t\t");
                delayanimation(0.25);
                printf("\n\n\n\n\n\n\t\t\tALL SEATS CLEARED!!\n\t\t\t");
                fp=fopen("bangmang.txt","w");
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                getch();
                system("cls");
                break;
            case 4:
                system("cls");
                intro();
                break;

        }
    }
}
void bb()
{
    int a[20];
    int choice;
    int seat;
    FILE *fp;
    for(;;)
    {
        fp=fopen("bangmumb.txt","r");
        int idx=0;
        char ch;
        while((ch = fgetc(fp)) != EOF)
        {
            a[idx]=ch;
            idx++;
        }
        fclose(fp);
        system("cls");
        printf("\n\n\n\t\tSEAT BOOKING FOR BNG-MUB FLIGHT\n");
        printf("\n\n\t\t\t1.ECONOMY CLASS\n\t\t\t2.BUSINESS CLASS\n\t\t\t3.CLEAR SEATS\n\t\t\t4.BACK TO FLIGHTS\n\t\t\t");
        printf("\n\n\t\t\tPLEASE SELECT\n\t\t\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                system("cls");
                printf("\n\n\n");
                fp=fopen("bangmumb.txt","w");
                economy(a);
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                break;
            case 2:
                system("cls");
                printf("\n\n\n");
                business(a);
                fp=fopen("bangmumb.txt","w");
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                break;
            case 3:
                system("cls");
                reset(a);
                printf("\n\n\n\t\t\tCLEARING SEATS WAIT....\n\t\t\t");
                delayanimation(0.25);
                printf("\n\n\n\n\n\n\t\t\tALL SEATS CLEARED!!\n\t\t\t");
                fp=fopen("bangmumb.txt","w");
                idx=0;
                while(idx<20)
                {
                    fprintf(fp,"%c",a[idx]);
                    idx++;
                }
                fclose(fp);
                getch();
                system("cls");
                break;
            case 4:
                system("cls");
                intro();
                break;

        }
    }
}
void intro()
{
    int ch;
    system("cls");
    for(;;)
    {
        printf("\n\n\t\t\tFLIGHTS \tTIME OF DEPARTURE");
        printf("\n\n\t\t\t1.BNG-DEL\t14:30\n\n\t\t\t2.BNG-KOL\t15:45\n\n\t\t\t3.BNG-MNG\t16:25\n\n\t\t\t4.BNG-MUB\t9:50\n\n\n\t\t\t");
        printf("\n\t\t\tSELECT THE FLIGHT\n\t\t\t");
        printf("\n\n\t\t\tPRESS 5 TO EXIT\n\t\t\t");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            bd();
            break;
        case 2:
            bk();
            break;
        case 3:
            bm();
            break;
        case 4:
            bb();
            break;
        default:
            exit(0);
        }
    }


}
int main()
{
    srand(time(0));
    homepage();
    intro();
}
