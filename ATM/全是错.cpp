

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

/*插入表尾*/
user *CreateEnd()
{
    user *p,*last,*head;
    n=0;
    head=last=NULL;
    p=(user *)malloc(LEN);        /*创建第一个结点*/
    scanf("%ld-%s-%s-%lf",&p->num,p->name,p->pw,&p->balance);
    p->next=NULL;
    while(p->num!=0)            /*将结点加入链表*/
    {
        ++n;
        if(n==1)                /*是第一个结点，作表头*/
            head=p;
        else                    /*不是第一个结点，作表尾*/
            last->next=p;
        last=p;
        p=(user *)malloc(LEN);   /*开辟下一个结点*/
        scanf("%ld-%s-%s-%lf",&p->num,p->name,p->pw,&p->balance);
        p->next=NULL;
    }
    free(p);                    /*释放最后一个结点所占的内存*/
    return head;                /*返回链表的头指针*/
}

/*插入表头*/
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

/*链表显示*/
void list(user *head)
{
    user *p;
    printf("\n");
    p=head;
    printf("-%ld\n-%s\n-%lf\n",&p->num,p->name,&p->balance);
}


void print(struct user *head) //全显示 
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



user *insert_index(user *head)        //按指定位置插用户 
{
    int i=0,index;
    user *p0,*p1,*p2;
    p1=p2=head;

    printf("请输入要插入用户的信息:\n");
    p0=(user *)malloc(LEN);
    printf("请依次录入以下信息，以“-”间隔：");
	printf("姓名-密码-起始金额"); 
    scanf("%s-%s-%lf",p0->name,p0->pw,&p0->balance);
    p0->next=NULL;
    index=++n; 

    if(head==NULL)            //如果原来链表是空的，头结点指向新插入的结点
    {
        head=p0;p0->next=NULL;
    }
    else
    {
        while(p1!=NULL && i<index-1){
            p2=p1;p1=p1->next;            //找插入点
            i++;
        }
        if(p1==head)                    //如果插入点是第一位
        {
            p0->next=head;head=p0;
        }
        else                            //插入到指定的位置
        {
            p2->next=p0;p0->next=p1;
        }
    }
    printf("Now remember your imformation:");
    printf("ID :%d   password:%s",i,pw);//这里也不确定到底怎么表示那个密码 
    printf("Now you have the new uer"); 
    return head;
}

user *del(user *head)
{
  user *p1,*p2;
  int num;

  printf("请输入要删除的用户编号:\n");
  scanf("%d",&num);

  if(head==NULL)
  {
      printf("\n链表为空!\n");/*链表为空*/
      goto end;
  }       
  
  p1=p2=head;                    /*从头结点开始查找*/
  while(num!=p1->num && p1->next!=NULL)        /*p1指向的不是所要找的结点，并且没有到表尾*/
  {
      p2=p1;p1=p1->next;            /*后移一个结点*/
  }                
  if(num==p1->num)                /*找到需要删除的结点*/
  {
    if(p1==head)                /*p1指向的是头结点*/
      head=p1->next;            /*第二个结点成为新的头结点*/
    else
      p2->next=p1->next;            /*后继结点的地址赋给前一结点*/

    printf("员工号为%d的信息已经被删除\n",num);
    free(p1);
    n--;
  }
  else
    printf("没有发现 %d 号员工的信息!\n",num);
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
        printf("打开文件失败!");
        exit(0);
    }

    while(p!=NULL)
    {
        fprintf(fp,"%ld-%s-%s-%lf",&p->num,p->name,p->pw,&p->balance);
        p=p->next;
    }
    printf("信息保存成功!\n");
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
        printf("打开文件失败!");
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
    printf("成功启动!\n");
    fclose(fp);                    //关闭文件
    return head;                /*返回链表的头指针*/
    
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
		*insert_index(___); //插入到最后一个位置的下一个。。。不会写。。。 
		goto zuikaishi;
	}
	*sear(head,id);
 	password(p);
 	 

	if(strcmp(p,user.current.pw[w])==0)   //这里都是不知道怎么写的、。。。 
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
            list(current);  //伪代码。。。 
            break;
        case 2:
            system("cls");
			jihao1: ;
			printf("Please input your old password:\n");
			password(p);
			if(strcmp(p,user.current.pw[w])==0)   //不知道怎么写 
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
            printf("\nYour balance is %lf\n",balance);  //某伪代码。。。 
            break;
        case 4:
            system("cls");
            printf("how much do you want to take?\n");
            scanf("%d",&qu);
            balance=balance-qu;   //某伪代码。。。
            printf("OK\n");
			break;
        case 5:
            system("cls");
            printf("how much do you want to save?\n");
            scanf("%d",cun);
            balance=balance+cun;   //某伪代码。。。
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

