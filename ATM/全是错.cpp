

#include <stdlib.h>
#include <conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<windows.h>
#define LEN sizeof(struct user)

void enter()
	{
    printf("                |-------------------------------------------------|              ");
    printf("                |                                                 |              ");
    printf("                |        Welcome to Use XXX ATM System            |              ");
    printf("                |                                                 |              ");
    printf("                |-------------------------------------------------|          \n\n");
    printf("                Please input your account:\n");
    printf("                Please input -1 if you want to have a new user:/n");
    //return 0;
 }

int w;



typedef struct user    
{
	long int num;
	char name[20];
	char pw[7];
	double balance;
	struct user *next;
};

int n;

/*�����β*/
user *CreateEnd()
{
    user *p,*last,*head;
    n=0;
    head=last=NULL;
    p=(user *)malloc(LEN);        /*������һ�����*/
    scanf("%ld-%s-%s-%lf",&p->num,p->name,p->pw,&p->balance);
    p->next=NULL;
    while(p->num!=0)            /*������������*/
    {
        ++n;
        if(n==1)                /*�ǵ�һ����㣬����ͷ*/
            head=p;
        else                    /*���ǵ�һ����㣬����β*/
            last->next=p;
        last=p;
        p=(user *)malloc(LEN);   /*������һ�����*/
        scanf("%ld-%s-%s-%lf",&p->num,p->name,p->pw,&p->balance);
        p->next=NULL;
    }
    free(p);                    /*�ͷ����һ�������ռ���ڴ�*/
    return head;                /*���������ͷָ��*/
}

/*�����ͷ*/
user *CreateStart()
{
    user *head,*p;
    n=0;
    head=NULL;
    p=(user *)malloc(LEN);
    scanf("%ld-%s-%s-%lf",&p->num,p->name,p->pw,&p->balance);
    p->next=head;
    while(p->num!=0)
    {
        ++n;
        head=p;
        p=(user *)malloc(LEN);
        scanf("%ld-%s-%s-%lf",&p->num,p->name,p->pw,&p->balance);
        p->next=head;
    }
    free(p);
    return head;
}

/*������ʾ*/
void list(user *head)
{
    user *p;
    printf("\n");
    p=head;
    printf("-%ld\n-%s\n-%lf\n",&p->num,p->name,&p->balance);
}


void print(struct user *head) //ȫ��ʾ 
{
	struct user*p;
	printf("\%dnThese records are:\n",n);
	p=head;
	if(head!=NULL)
	while(p!=NULL)
	{
		printf("%ld\n%s\n%s\n%lf\n",p->num,p->name,p->pw,p->balance);
		p=p->next;
	}
	
	
}    



user *insert_index(user *head)        //��ָ��λ�ò��û� 
{
    int i=0,index;
    user *p0,*p1,*p2;
    p1=p2=head;

    printf("������Ҫ�����û�����Ϣ:\n");
    p0=(user *)malloc(LEN);
    printf("������¼��������Ϣ���ԡ�-�������");
	printf("����-����-��ʼ���"); 
    scanf("%s-%s-%lf",p0->name,p0->pw,&p0->balance);
    p0->next=NULL;
    index=++n; 

    if(head==NULL)            //���ԭ�������ǿյģ�ͷ���ָ���²���Ľ��
    {
        head=p0;p0->next=NULL;
    }
    else
    {
        while(p1!=NULL && i<index-1){
            p2=p1;p1=p1->next;            //�Ҳ����
            i++;
        }
        if(p1==head)                    //���������ǵ�һλ
        {
            p0->next=head;head=p0;
        }
        else                            //���뵽ָ����λ��
        {
            p2->next=p0;p0->next=p1;
        }
    }
    printf("Now remember your imformation:");
    printf("ID :%d   password:%s",i,pw);//����Ҳ��ȷ��������ô��ʾ�Ǹ����� 
    printf("Now you have the new uer"); 
    return head;
}

user *del(user *head)
{
  user *p1,*p2;
  int num;

  printf("������Ҫɾ�����û����:\n");
  scanf("%d",&num);

  if(head==NULL)
  {
      printf("\n����Ϊ��!\n");/*����Ϊ��*/
      goto end;
  }       
  
  p1=p2=head;                    /*��ͷ��㿪ʼ����*/
  while(num!=p1->num && p1->next!=NULL)        /*p1ָ��Ĳ�����Ҫ�ҵĽ�㣬����û�е���β*/
  {
      p2=p1;p1=p1->next;            /*����һ�����*/
  }                
  if(num==p1->num)                /*�ҵ���Ҫɾ���Ľ��*/
  {
    if(p1==head)                /*p1ָ�����ͷ���*/
      head=p1->next;            /*�ڶ�������Ϊ�µ�ͷ���*/
    else
      p2->next=p1->next;            /*��̽��ĵ�ַ����ǰһ���*/

    printf("Ա����Ϊ%d����Ϣ�Ѿ���ɾ��\n",num);
    free(p1);
    n--;
  }
  else
    printf("û�з��� %d ��Ա������Ϣ!\n",num);
end:
  return head;
}

int writeInfo(user *head)
{
    FILE *fp;
    user *p;
    p=head;
    if((fp=fopen("info.txt","w"))==NULL)
    {
        printf("���ļ�ʧ��!");
        exit(0);
    }

    while(p!=NULL)
    {
        fprintf(fp,"%ld-%s-%s-%lf",&p->num,p->name,p->pw,&p->balance);
        p=p->next;
    }
    printf("��Ϣ����ɹ�!\n");
    fclose(fp);
}

user *readInfo()
{
    FILE *fp;
    user *p,*last,*head;
    n=0;
    head=last=NULL;
    if((fp=fopen("info.txt","r"))==NULL)
    {
        printf("���ļ�ʧ��!");
        exit(0);
    }
    p=(user *)malloc(LEN);
    while(fscanf(fp,"%ld-%s-%s-%lf",&p->num,p->name,p->pw,&p->balance)!=EOF)
    {
        p->next=NULL;
        ++n;
        if(n==1)
            head=p;
        else
            last->next=p;
        last=p;
        p=(user *)malloc(LEN);
        
    }
    free(p);
    printf("�ɹ�����!\n");
    fclose(fp);                    //�ر��ļ�
    return head;                /*���������ͷָ��*/
    
}


struct user *sear(struct user *head, long int num) 
{
   struct user *current;
   long int i = 1;
   current = head;
   while ((i < num) && (current != NULL)) {
     current = current -> next;
     i++; 
    }
    return current;
 }

void password (char b[])
{
    char str[100];
    int i;
    printf ("Please input the password:\n");
    for (i = 0; (str[i] = getch ()) != 13; printf ("*"), ++i);
    str[i] = 0;
    strcpy(b,str);
    return ;
}


int mainnstyle(){
    printf("               |-------------------------------------------------|             ");
    printf("               |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|              ");
    printf("               |                                                 |              ");
    printf("               |          Welcome to Use XXX ATM System          |              ");
    printf("               |      Please Select The Following Function:      |              ");
    printf("               |                                                 |              ");
    printf("               |     $$-show       Detail    -- press 1          |              ");
    printf("               |     $$-Change     Password  -- press 2          |              ");
    printf("               |     $$-Check      Balance   -- press 3          |              ");
    printf("               |     $$-Withdraw   Money     -- press 4          |              ");
    printf("               |     $$-Deposit    Money     -- press 5          |              ");
    printf("               |     $$-Delete     Acount    -- press 6          |              ");
    printf("               |     $$-Save and Exit        -- press 7          |              ");
	printf("               |$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|              ");
    printf("\n\n\n");
    printf("                Please Input Number:");
 }




main()
{
    long int id;
    char p[7],a[7],m[7]="456456";
	user *head,*emp;
    int del_num,index;
    int what,temp,qu,cun;
    user current ;
     system("cls");
     head=readInfo();
	 zuikaishi:enter();
	scanf("%ld",&id);
	if(id==-1)
	{
		printf("Now you want to set a new user:");
		*insert_index(___); //���뵽���һ��λ�õ���һ������������д������ 
		goto zuikaishi;
	}
	*sear(head,id);
 	password(p);
 	 

	if(strcmp(p,user.current.pw[w])==0)   //���ﶼ�ǲ�֪����ôд�ġ������� 
	{
		printf("Wrong id or password\n Try again!");
		goto zuikaishi;
	}
	
	
	
    do
    {
        scanf(" %d",&what);
		mainnstyle();

        switch (what)
        {
        case 1:
            system("cls");
            list(current);  //α���롣���� 
            break;
        case 2:
            system("cls");
			jihao1: ;
			printf("Please input your old password:\n");
			password(p);
			if(strcmp(p,user.current.pw[w])==0)   //��֪����ôд 
			{
				printf("Wrong id or password\n Try again!");
                goto jihao1;	
			}
			jihao2: ;
			printf("Please input your new password:\n");
			password(p);
			printf("Please input your new password again:\n");
			password(a);
			if(strcmp(p,a)==0)
			{
				printf("Different password,try again?\n");
				printf("1-----yes.      2-----no.\n");
				scanf("%d",&temp);
				if(temp==1)goto jihao2;
			}
            break;
        case 3:
            system("cls");
            printf("\nYour balance is %lf\n",balance);  //ĳα���롣���� 
            break;
        case 4:
            system("cls");
            printf("how much do you want to take?\n");
            scanf("%d",&qu);
            balance=balance-qu;   //ĳα���롣����
            printf("OK\n");
			break;
        case 5:
            system("cls");
            printf("how much do you want to save?\n");
            scanf("%d",cun);
            balance=balance+cun;   //ĳα���롣����
            printf("\nOK\n");
			break;
        case 6:
            system("cls");
            printf("Please input manager password:");
            password(p);
            if(strcmp(p,m)==0)
            {
            	printf("Sorry,you cannot use this function");
            	break;
            }
            else 
            {
            	print(head);
            	
            }
            break;
        case 7:
            system("cls");
            printf("Save ..."); 
            writeInfo(head);
			printf("OK");
            break;                     
        }
    }while ( what!=7);
	return 0;
}

