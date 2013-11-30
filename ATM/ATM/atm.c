#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>
#define LENGTH 2000

struct user
{
	char name[LENGTH];
	char password[LENGTH];
	double balance;
	int last;
	int next;
}user[20000];
int last_account=1;
int account_now;
//printf("If you want to exit ,input 'exit'\n");
void back_menu();
void check_exit(char order[]);
void welcome();
void mainnstyle();
void show_detail();
void change_password();
int check_account(char str[]);
void insert_account();
void insert_info(char name[],char password[],char money[]);
int check_password(int num);
void read_info();
void write_info();
void print_all_account();
void withdraw();
void deposit();
void delete_account();


void delete_account()
{
    char control[LENGTH];
    system("cls");
    check_password(account_now);
    printf("Are you sure to delete your account without withdraw your money?y/n");
    scanf("%s",control);
    if(control[0]=='y')
    {
        printf("Your account has been deleted.\n");
        user[user[account_now].next].last=user[account_now].last;
        user[user[account_now].last].next=user[account_now].next;
        write_info();
        exit(0);
    }
    else back_menu();
}


void withdraw()
{
    double temp;
    system("cls");
    printf("Please input how much money to withdraw.\n");
    while(1)
    {
        scanf("%lf",&temp);
        if(temp<0||temp>user[account_now].balance)
        {
            printf("You don't have that much money.\n");
        }
        else break;
    }
    user[account_now].balance-=temp;
    printf("Please take your money.\n");
    back_menu();
}

void deposit()
{
    double temp;
    system("cls");
    printf("Please input how much money to deposit.\n");
    while(1)
    {
        scanf("%lf",&temp);
        if(temp<0)
        {
            printf("Wrong input.\n");
        }
        else break;
    }
    user[account_now].balance+=temp;
    printf("Deposit successfully.\n");
    back_menu();
}

void insert_info(char new_name[],char new_password[],double new_money)
{
    strcpy(user[last_account].name,new_name);
    strcpy(user[last_account].password,new_password);
    user[last_account].balance=new_money;
    user[user[0].last].next=last_account;
    user[last_account].next=0;
    user[last_account].last=user[0].last;
    user[0].last=last_account;
    last_account++;
}

void back_menu()
{
    printf("Press enter to back the menu.\n");
    getchar();
    getchar();
}

void check_exit(char order[])
{
    if(order[0]=='e'&&order[1]=='x'&&order[2]=='i'&&order[3]=='t')
    {
        write_info();
        exit(0);
    }
    return;
}

void welcome()
{
    system("cls");
    printf("         |-------------------------------------------------|\n");
    printf("         |                                                 |\n");
    printf("         |        Welcome to Use XXX ATM System            |\n");
    printf("         |                                                 |\n");
    printf("         |-------------------------------------------------|\n\n");
    printf("         Please input your account:\n");
    printf("         Please input '-1' if you want to have a new account:\n");
    printf("         If you want to exit ,input 'exit'\n");
 }

void mainnstyle()
{
    system("cls");
    printf("              |-------------------------------------------------|             ");
    printf("               |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|              ");
    printf("               |                                                 |              ");
    printf("               |          Welcome to Use XXX ATM System          |              ");
    printf("               |      Please Select The Following Function:      |              ");
    printf("               |                                                 |              ");
    printf("               |     $$-Show Detail          -- press 1          |              ");
    printf("               |     $$-Change Password      -- press 2          |              ");
    printf("               |     $$-Withdraw Money       -- press 3          |              ");
    printf("               |     $$-Deposit Money        -- press 4          |              ");
    printf("               |     $$-Delete Acount        -- press 5          |              ");
    printf("               |     $$-Save and Exit        -- press 6          |              ");
	printf("               |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|              ");
    printf("\n\n\n");
    printf("                Please Input Number:");
 }

void show_detail()
 {
    system("cls");
    printf("Here is your account's detail.\n");
    printf("%d-%s-%s-%lf\n",account_now,user[account_now].name,user[account_now].password,user[account_now].balance);
    back_menu();
}

void change_password()
{
    int i;
    system("cls");
    printf("Please input your original password first\n");
    check_password(account_now);
    char new_password1[LENGTH],new_password2[LENGTH];
    while(1)
    {
        printf("\n");
        printf("Please input your new password.If you want to exit ,input 'exit'.\n");
        for(i=0;;)
        {
            new_password1[i]=getch();
            printf("*");
            if(new_password1[i]==13)break;
            i++;
        }
        new_password1[i]=0;
        check_exit(new_password1);
        printf("\nPlease input again\n");
        for(i=0;;)
        {
            new_password2[i]=getch();
            printf("*");
            if(new_password2[i]==13)break;
            i++;
        }
        new_password2[i]=0;
        if(strcmp(new_password1,new_password2))
        {
            printf("\nThe passwords you input are not same.\n");
        }
        else break;
    }
    strcpy(user[account_now].password,new_password1);
    printf("Your password has been changed successfuly.\n");
    back_menu();
}

int check_account(char str[])
{
    for(int i=user[0].next;i!=0;i=user[i].next)
    {
        if(!strcmp(str,user[i].name))return i;
    }
    return 0;
}

void insert_account()
{
    double new_money;
    char new_name[LENGTH],new_password[LENGTH];
    system("cls");
    printf("Please input the information about your new account:\n");
    printf("If you want to exit ,input 'exit'\n");
    printf("Use SPACE to separate the information,as the follow examole£º\n");
	printf("ID Password InitialMoney\n");
	while(1)
	{
        scanf("%s",new_name);
        check_exit(new_name);
        scanf("%s%lf",new_password,&new_money);
        if(check_account(new_name))
        {
            printf("account number has existed\n");
        }
        else break;
    }
    insert_info(new_name,new_password,new_money);
}


int check_password(int num)
{
    char password[LENGTH];
    int i;
    printf("Please input your password.If you want to exit ,input 'exit'\n");
    while(1)
    {
        //scanf("%s",password);
        for(i=0;;)
        {
            password[i]=getch();
            printf("*");
            if(password[i]==13)break;
            i++;
        }
        password[i]=0;
        check_exit(password);
        if(strcmp(password,user[num].password))
        {
            printf("\nWrong password\n");
        }
        else break;
    }
}

void read_info()
{
    FILE *in;
    double new_money;
    char new_name[LENGTH],new_password[LENGTH];
    in=fopen("data.txt","r");
    while(fscanf(in,"%s %s %lf\n",new_name,new_password,&new_money)!=EOF)
    {
        insert_info(new_name,new_password,new_money);
    }
    fclose(in);
}

void write_info()
{
    FILE *in;
    in=fopen("data.txt","w");
    for(int i=user[0].next;i!=0;i=user[i].next)
    fprintf(in,"%s %s %lf\n",user[i].name,user[i].password,user[i].balance);
    fclose(in);
}

void print_all_account()
{
    printf("--------\n");
    for(int i=user[0].next;i!=0;i=user[i].next)
    printf("%d-%s-%s-%lf\n",i,user[i].name,user[i].password,user[i].balance);
}

int main()
{
    char control_order[200];
    int control;
    user[0].last=0;
    user[0].next=0;
    read_info();
    while(1)
    {
        welcome();
        scanf("%s",control_order);
        check_exit(control_order);
        if(control_order[0]=='-'&&control_order[1]=='1')
        {
            insert_account();
        }
        else
        {
             if(!check_account(control_order))
            {
                printf("Error:the account named %s dose not exist\n",control_order);
                back_menu();
            }
            else break;
        }
    }
    account_now=check_account(control_order);
    check_password(account_now);
    while(1)
    {
        mainmenu:mainnstyle();
        while(1)
        {
            scanf("%d",&control);
            if(control<1||control>7)
            {
                printf("Wrong order,please input again.\n");
            }
            else break;
        }
        if(control==1)
        {
            show_detail();
            goto mainmenu;
        }
        if(control==2)
        {
            change_password();
            goto mainmenu;
        }
        if(control==3)
        {
            withdraw();
            goto mainmenu;
        }
        if(control==4)
        {
            deposit();
            goto mainmenu;
        }
        if(control==5)
        {
            delete_account();
            goto mainmenu;
        }
        if(control==6)
        {
            write_info();
            exit(0);
        }
    }
    return 0;
}
