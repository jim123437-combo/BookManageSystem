
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define L 20
#define Q 200
struct book                   //����һ��book��ṹ�塣
{
	char no[L];               //���
	char name[L];
	char author[L];
	char fenlei[L];
	char puttime[L];
	char putfrom[L];
	char price[L];
	char jiehuan[L];
};
void menu1();
void menu2();
void menu3();
int bookluru(struct book*p,int n);
void bookliulan(struct book*p,int n);
void bookchaxun(struct book*p,int n);
void bookxiugai(struct book*p,int n);
void jiehuanshuji(struct book *p,int n);
void jieshu(struct book*p,int n);
void huanshu(struct book *p,int n);
int bookzhengjia(struct book*p,int n);
int bookshanchu(struct book*p,int n);
void bookpaixu(struct book*p,int n);
void DLsearch(struct book*p,int n);
void AUsearch(struct book*p,int n);
int bookzairu(struct book*p,int n);
void goout();
int bookbaocun(struct book*p,int n);        //��������
void main()                                //������
{
	char slect,yn,moshi;
	struct book record[Q];                 //����book��ṹ��������ͼ����Ϣ��200��
	int total=0,flag;
	total=bookzairu(record,Q);              //���ļ���ȡͼ����Ϣ��������200��
	menu1();
	printf("����ģʽѡ��");
	moshi=getchar();
	getchar();
    if(moshi=='1')
    {
       	do
	  {
		menu2();                            //��ʾ�˵�
		printf("��������ţ�");
		slect=getchar();
		getchar();
		switch(slect)
		{
        case'0': goout();break;
		case'1': bookliulan(record,total);break;  //��������
		case'2': bookchaxun(record,total);break;
		case'3': jiehuanshuji(record,total);break;
		case'4': bookpaixu(record,total);break;
		case'5': flag=bookbaocun(record,total);
			if("flag==1")
				printf("ͼ����Ϣ����ɹ���\n");
			else
				printf("ͼ����Ϣ����ʧ�ܣ�\n");
			break;
		default:continue;
		}
		if(slect=='0') break;
		printf("\n��Ҫ����ѡ���𣿣�Y/N��");      //��ʾ�Ƿ����
		do//���Ƿ�������쳣����
        {
			scanf("%c",&yn);
			getchar();
			if (yn=='Y'||yn=='y')
				break;
			else if (yn=='N'||yn=='n')
				break;
			else
		    	printf("�Ƿ�ѡ�\n��Ҫ����ѡ���𣿣�Y/N��");
        } while(1);
	   } while(yn!='N'&&yn!='n');
     }


     else if(moshi=='2')
     {
         do
	  {
		menu3();                            //��ʾ�˵�
		printf("��������ţ�");
		slect=getchar();
		getchar();
		switch(slect)
		{
        case'0': goout();break;
		case'1': total=bookluru(record,total);break;   //��������
		case'2': bookliulan(record,total);break;
		case'3': bookchaxun(record,total);break;
		case'4': bookxiugai(record,total);break;
		case'5': jiehuanshuji(record,total);break;
		case'6': total=bookzhengjia(record,total);break;
		case'7': total=bookshanchu(record,total);break;
		case'8': bookpaixu(record,total);break;
		case'9': flag=bookbaocun(record,total);
			if("flag==1")
				printf("ͼ����Ϣ����ɹ���\n");
			else
				printf("ͼ����Ϣ����ʧ�ܣ�\n");
			break;
		default:continue;
		}
		if(slect=='0') break;
		printf("\n��Ҫ����ѡ���𣿣�Y/N��");      //��ʾ�Ƿ����
		do
		{
			scanf("%c",&yn);
			getchar();
			if (yn=='Y'||yn=='y')
				break;
			else if (yn=='N'||yn=='n')
				break;
			else
		    	printf("�Ƿ�ѡ�\n��Ҫ����ѡ���𣿣�Y/N��");
		}
		while(1);
	  }
	   while(yn!='N'&&yn!='n');
    }
    else printf("�������");

}
void menu1()//ͼ�����ϵͳ���˵�.
{
    system("cls");
    printf("\n\n");
    printf("��ѡ�������Ŀ��ţ�1--2��\n");
    printf("******************************************************************\n");
    printf("��********************��ӭʹ��ͼ����Ϣ����ϵͳ******************��\n");
    printf("��*************************��ѡ�����ģʽ***********************��\n");
    printf("��**************************************************************��\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("���                    * 1 . ������ģʽ.                        ���\n");
    printf("���                    * 2 . ������ģʽ.                        ���\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("******************************************************************\n");
    printf("\n");
}
void menu2()
{
    system("cls");
    printf("\n\n");
    printf("��ѡ�������Ŀ��ţ�0--5��\n");
    printf("******************************************************************\n");
    printf("��********************��ӭʹ��ͼ����Ϣ����ϵͳ******************��\n");
    printf("��**************************������ģʽ**************************��\n");
    printf("��**************************************************************��\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("���                    * 1 . ͼ����Ϣ���.                        ���\n");
    printf("���                    * 2 . ͼ����Ϣ��ѯ.                        ���\n");
    printf("���                    * 3 . ͼ���鼮�軹.                        ���\n");
    printf("���                    * 4 . ͼ����Ϣ����.                        ���\n");
    printf("���                    * 5 . ͼ����Ϣ����.                        ���\n");
    printf("���                    * 0 . �˳�ͼ�����ϵͳ.                    ���\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("******************************************************************\n");
    printf("\n");
}
void menu3()
{
	system("cls");
    printf("\n\n");
    printf("��ѡ�������Ŀ��ţ�0--9��\n");
    printf("******************************************************************\n");
    printf("��********************��ӭʹ��ͼ����Ϣ����ϵͳ******************��\n");
    printf("��**************************������ģʽ**************************��\n");
    printf("��**************************************************************��\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("���                    * 1 . ͼ����Ϣ¼��.                        ���\n");
    printf("���                    * 2 . ͼ����Ϣ���.                        ���\n");
    printf("���                    * 3 . ͼ����Ϣ��ѯ.                        ���\n");
    printf("���                    * 4 . ͼ����Ϣ�޸�.                        ���\n");
    printf("���                    * 5 . ͼ���鼮�軹.                        ���\n");
    printf("���                    * 6 . ͼ����Ϣ����.                        ���\n");
    printf("���                    * 7 . ͼ����Ϣɾ��.                        ���\n");
    printf("���                    * 8 . ͼ����Ϣ����.                        ���\n");
    printf("���                    * 9 . ͼ����Ϣ����.                        ���\n");
    printf("���                    * 0 . �˳�ͼ�����ϵͳ.                    ���\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("���                                                             ���\n");
    printf("******************************************************************\n");
    printf("\n");
}
int bookluru(struct book *p,int n)//¼��ͼ����Ϣ.
{
	int i=0;
	int m;
	printf("\n���ǰ��ͼ����Ϣ��¼����%d����\n",n);        //��ʾԭ�е�ͼ����Ϣ
	printf("----------------------------------------------------------------------------------------------------------");
	printf("\n%9s%9s%10s%10s%10s%10s%10s%10s\n","���","����","������","�����","����ʱ��","���浥λ","�۸�","�軹���");
	printf("----------------------------------------------------------------------------------------------------------");
	i=0;
	while((i<n)&&(strcmp(p->no,"")!=0))        //����ı�Ų�Ϊ��ʱ�����ͼ����Ϣ
	{
	printf("\n%9s%9s%9s%9s%9s%15s%9s%9s\n",p->no,p->name,p->author,p->fenlei,p->puttime,p->putfrom,p->price,p->jiehuan);//��Ϣ���
		i++;
		p++;
	}
	printf("----------------------------------------------------------------------------------------------------------");
	printf("\n������Ҫ¼���ͼ����ĿX��0<X<%d��: ",200-n);  //����ͼ����Ϣ�洢���ֵ
	scanf("%d",&m);
	i=0;
	while(i<m)
	{
		printf("\n");
		printf("�������%d��ͼ�����Ϣ��\n",i+1);
		printf("���(�����ظ�): ");
		do
		{
		   gets(p->no);     //�����ţ�������������Ϣ
		}
		while(strcmp(p->no,"")==0);
		printf("����Ϊ:");
        gets(p->name);
        printf("������Ϊ:");
        gets(p->author);
        printf("�����Ϊ:");
        gets(p->fenlei);
        printf("����ʱ��Ϊ:");
        gets(p->puttime);
        printf("���浥λΪ:");
        gets(p->putfrom);
        printf("�۸�Ϊ:");
        gets(p->price);
        printf("����軹���(�ѽ��δ��):");
        gets(p->jiehuan);
		p++;
		i++;
	}
	return m+n;
}

void bookliulan(struct book*p,int n)//ͼ����Ϣ���.
{
	int i=0;
	printf("----------------------------------------------------------------------------------------------------------");
	printf("\n%9s%9s%10s%10s%10s%10s%10s%10s\n","���","����","������","�����","����ʱ��","���浥λ","�۸�","�軹���");
	printf("----------------------------------------------------------------------------------------------------------");
	while(i<n)                                            //���ԭ��ͼ����Ϣ
	{
	printf("\n%9s%9s%9s%9s%9s%15s%9s%9s\n",p->no,p->name,p->author,p->fenlei,p->puttime,p->putfrom,p->price,p->jiehuan);
		p++;
		i++;
	}
	printf("----------------------------------------------------------------------------------------------------------");
}

void bookchaxun(struct book*p,int n)//ͼ����Ϣ��ѯ.
{
	char c;
	bookliulan(p ,n);
	do
	{
		printf("\n���ʰ���Ų�ѯ��D�������ǰ���������ѯ��A����");  //ѡ���ѯ��ʽ
		c=getchar();
		getchar();
		if(c=='D'||c=='d')
		{
			DLsearch(p,n);
			break;
		}
		else if(c=='A'||c=='a')
		{
			AUsearch(p,n);
			break;
		}
		else
		{
			printf("\n�����Ϊ�Ƿ��ַ���\n");
			continue;
		}
	}
	while(c!='D'||c!='d'||c!='A'||c!='a');
}

void DLsearch(struct book*p,int n)//����Ų�ѯ.
{
	int i,x=0;
	char DL[L];
	printf("\n������Ҫ��ѯͼ��ı�ţ�");
	gets(DL);
	for(i=0;i<n;i++)
		if(strcmp(DL,p[i].no)==0)     //�����ţ������ϵͳ���ҵ������ͼ����Ϣ
		{
			printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","���","����","������","�����","���浥λ","����ʱ��","�۸�","�軹���");
			printf("\n%10s%10s%10s%10s%10s%10s%10s%10s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
			x=1;
			break;
		}
		if(x==0)
		printf("\n�Բ���ͼ��ϵͳ��û�а����������Ϣ��\n");
}

void AUsearch(struct book*p,int n)//����������ѯ.
{
	int i,x=0;
	char AU[20];
	printf("\n������Ҫ��ѯͼ�������������");
	gets(AU);
	for(i=0;i<n;i++)
	   if(strcmp(AU,p[i].author)==0)  //�������������������ϵͳ���ҵ������ͼ����Ϣ
		{
			printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","���","����","������","�����","���浥λ","����ʱ��","�۸�","�軹���");
			printf("\n%10s%10s%10s%10s%10s%10s%10s%10s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
			x=1;
		}
		if(x==0)
		printf("\n�Բ���ͼ��ϵͳ��û�а����������Ϣ��\n");  //��ʾ��Ϣ
}
void bookxiugai(struct book*p,int n)//ͼ����Ϣ�޸�.
{
	int i,k=0;
	char no[L],slect;
	bookliulan(p,n);
	printf("\n������Ҫ�޸�ͼ��ı�ţ�");
	gets(no);
	for(i=0;i<n;i++,p++)
	{
		if(strcmp(no,p->no)!=0) continue;
		{
          printf("\n�޸�ǰ��ͼ����Ϣ��¼Ϊ��\n");        //��ʾԭ�е�ͼ����Ϣ
	      printf("----------------------------------------------------------------------------------------------------------");
          printf("\n%9s%9s%10s%10s%10s%10s%10s%10s\n","���","����","������","�����","����ʱ��","���浥λ","�۸�","�軹���");
          printf("----------------------------------------------------------------------------------------------------------");
          printf("\n%9s%9s%9s%9s%9s%15s%9s%9s\n",p->no,p->name,p->author,p->fenlei,p->puttime,p->putfrom,p->price,p->jiehuan);//��Ϣ���
          printf("----------------------------------------------------------------------------------------------------------");
          printf("\n****************************������Ҫ�޸ĵĲ��ֵĴ���*******************************");
          printf("\n*****���(1)������(2)��������(3)�������(4)������ʱ��(5)�����浥λ(6)���۸�(7)*****");
          printf("\n***********************************************************************************");
          printf("\n��Ҫ�޸ĵ���Ϣ�Ĵ���Ϊ");
		  slect=getchar();
		  getchar();
		  switch(slect)
		  {
		   case'1': printf("\n��������ȷ��ͼ���ţ�");gets(p->no);;break;  //��������
		   case'2': printf("\n��������ȷ��ͼ������:");gets(p->name);break;
		   case'3': printf("\n��������ȷ��ͼ��������:");gets(p->author);break;
		   case'4': printf("\n��������ȷ��ͼ������:");gets(p->fenlei);break;
		   case'5': printf("\n��������ȷ��ͼ�����ʱ��:");gets(p->puttime);break;
		   case'6': printf("\n��������ȷ��ͼ����浥λ:");gets(p->putfrom);break;
		   case'7': printf("\n��������ȷ��ͼ��۸�:");gets(p->price);break;
		   default:break;
		  }
			  printf("\n�޸�ͼ��ͼ����Ϣ��ɣ���");
			  k=1;
		}
	}
	if(k==0)
		printf("\n�Բ���ͼ��ϵͳ��û�а����������Ϣ��\n");
}
void jiehuanshuji(struct book *p,int n)//ͼ��軹
{
    char c1;
    bookliulan(p ,n);
    do
    {
        printf("\n�����ǽ���(J),���ǻ���(H)��");
        c1=getchar();
        getchar();
        if(c1=='j'||c1=='J')
        {
            jieshu(p,n);
            break;
        }
        if(c1=='h'||c1=='H')
        {
            huanshu(p,n);
            break;
        }
        else
		{
			printf("\n�����Ϊ�Ƿ��ַ���\n");
			continue;
		}
    }while(c1!='j'||c1!='J'||c1!='h'||c1!='H');

}
void jieshu(struct book*p,int n)//����
{
    int i,k=0;
    char no[L],name[L],m[L]="�ѽ�";
    printf("\n�����������鼮�ı�Ż�������:");
    printf("\n���:"); gets(no);
    printf("\n����:"); gets(name);
    for(i=0;i<n;i++,p++)
    {
        if((strcmp(no,p->no)!=0)&&(strcmp(name,p->name)!=0))  continue;
        
        if(strcmp(no,p->no)==0||strcmp(name,p->name)==0)//����������ֻҪ��һ��ƥ���ok
        {
            if(strcmp(m,p->jiehuan)==0) k=2;
            else if (strcmp("δ��",p->jiehuan)!=0)
       		{
        		k=3;
        	}
            else
                {
                    strcpy(p->jiehuan,m);
                    printf("\n����ɹ�!");
                    k=1;
                }
        }
    }
    if(k==0) printf("\n�Բ���ͼ��ϵͳ��û�а����������Ϣ��\n");
    if(k==2) printf("\n�Բ��𣬱����ѱ��裡\n");
    if (k==3) printf("\n�����ֹ����\n");
    
}
void huanshu(struct book *p,int n)//����
{
    int i,k=0;
    char no[L],name[L],m[L] ="δ��";
    printf("\n�����������鼮�ı�Ż�������:");
    printf("\n���:");
        gets(no);
    printf("\n����:");
        gets(name);
    for(i=0;i<n;i++,p++)
    {
        if(strcmp(no,p->no)!=0&&strcmp(name,p->name)!=0) continue;
        if(strcmp(no,p->no)==0||strcmp(name,p->name)==0)
        {
          
            if(strcmp(m,p->jiehuan)==0) k=2;
            else if (strcmp("�ѽ�",p->jiehuan)!=0)
       		{
        		k=3;
        	}
            else
                {
                    strcpy(p->jiehuan,m);
                    printf("\n����ɹ���");
                    k=1;
                }
        }
    }
    if(k==0) printf("\n�Բ���ͼ��ϵͳ��û�а����������Ϣ��\n");
    if(k==2) printf("\n�Բ��𣬱�����δ���裬�޷����飡\n");
    if (k==3) printf("\n�������״̬����,�޷�����\n");
    
}
int bookzhengjia(struct book *p,int n)//ͼ����Ϣ����.
{
	int i=0;
	char c;
	struct book t,*q;
	printf("\n���ǰͼ����Ϣ�ļ�¼Ϊ��\n");
    bookliulan(p ,n);//��ʾ���ǰͼ����Ϣ�ļ�¼
	do
	{
		printf("\n��������ͼ����Ϣ�ı��:");
		gets(t.no);
		printf("\n��������ͼ����Ϣ������Ϊ:");
        gets(t.name);
        printf("\n��������ͼ����Ϣ��������Ϊ:");
        gets(t.author);
        printf("\n��������ͼ����Ϣ�ķ����Ϊ:");
        gets(t.fenlei);
        printf("\n��������ͼ����Ϣ�ĳ���ʱ��Ϊ:");
        gets(t.puttime);
        printf("\n��������ͼ����Ϣ�ĳ��浥λΪ:");
        gets(t.putfrom);
        printf("\n��������ͼ����Ϣ�ļ۸�Ϊ:");
        gets(t.price);
        printf("\n��������ͼ����Ϣ�Ľ軹���Ϊ:");
        gets(t.jiehuan);
		for(i=0;i<n;i++)
		    if(strcmp(t.no,(p+i)->no)==0)
			{
				printf("����ظ���Ҫ����������Y/N����");
				c=getchar();
				putchar('\n');
				break;
			}
			if(i==n)
			{
				*(p+i)=t;
				printf("\n��Ӻ�ͼ�����Ϣ��¼Ϊ��\n");   //��ʾ��Ӻ�ͼ�����Ϣ��¼
				printf("----------------------------------------------------------------------------------------------------------");
				printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","���","����","������","�����","���浥λ","����ʱ��","�۸�","�軹���");
				printf("----------------------------------------------------------------------------------------------------------");
				for(i=0;i<n+1;i++)
				printf("\n%9s%9s%9s%9s%9s%9s%9s%9s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
			    printf("----------------------------------------------------------------------------------------------------------");
				break;
			}
	}
	while(c=='y'||c=='Y');
	return n+1;
}
int bookshanchu(struct book *p,int n)//ͼ����Ϣɾ��.
{
	int i,x,y=0;
	char c,name[20],no[20];
	printf("\nɾ��ǰͼ�����Ϣ��¼Ϊ��\n");
    bookliulan(p ,n);
	printf("\n������Ҫɾ��ͼ��ı�ţ�");
	gets(no);
	for(x=0;x<n;x++)
	{
		if(strcmp(no,p[x].no)!=0)    ////����ı�Ų�ƥ�䣬��������ѭ��
			continue;
		if(x<n)
		{
			for(i=x;i<n;i++)         //��һ��ͼ����Ϣ��ǰһ��ͼ����Ϣ����ɾ��
			{
			   strcpy(p[i].no,p[i+1].no);
               strcpy(p[i].author,p[i+1].author);
               strcpy(p[i].name,p[i+1].name);
               strcpy(p[i].fenlei,p[i+1].fenlei);
               strcpy(p[i].price,p[i+1].price);
			   strcpy(p[i].putfrom,p[i+1].putfrom);
			   strcpy(p[i].puttime,p[i+1].puttime);
			   strcpy(p[i].jiehuan,p[i+1].jiehuan);
			}
			printf("ͼ����Ϣɾ����ļ�¼��\n");
	printf("----------------------------------------------------------------------------------------------------------");
	printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","���","����","������","�����","���浥λ","����ʱ��","�۸�","�軹���");
	printf("----------------------------------------------------------------------------------------------------------");
	for(i=0;i<n+1;i++)
	printf("\n%9s%9s%9s%9s%9s%9s%9s%9s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
	printf("----------------------------------------------------------------------------------------------------------");
			y=1;
		}
		else
			printf("\n�Բ���ͼ��ϵͳ��û�а����������Ϣ��\n");
		return n-y;
	}
}
void bookpaixu(struct book*p,int n)//��ͼ����Ϣ����.
{
	int j,i,k;
	char c1,c2;
	struct book temp;
	printf("\n����ǰͼ�����Ϣ��¼Ϊ��\n");
	bookliulan(p,n);
	printf("\n���������D�������ǰ�����������A����");      //ѡ������ķ�ʽ
	c1=getchar();
	getchar();
	if(c1=='d'||c1=='D')                //ѡ������С��������
	{
		for(i=0;i<n-1;i++)
		{
			k=i;
			for(j=i+1;j<n;j++)
				if(strcmp(p[k].no,p[j].no)>0)     //ʹ��ѡ�񷨽�������
					k=j;
				if(k!=i)    //�����С�첻��Ĭ�ϵ�p[i]���ٽ�����
				{
					temp=p[k];
					p[k]=p[i];
					p[i]=temp;
				}
		}
		printf("\n�����ͼ�����Ϣ��¼Ϊ��\n");            //��������ͼ�����Ϣ
	printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","���","����","������","�����","���浥λ","����ʱ��","�۸�","�軹���");
	for(i=0;i<n+1;i++)
	printf("\n%9s%9s%9s%9s%9s%9s%9s%9s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
	}
	else if(c1=='a'||c1=='A')   //ѡ����������С��������
	{
		for(i=0;i<n-1;i++)
		{
			k=i;
			for(j=i+1;j<n;j++)
				if(strcmp(p[k].author,p[j].author)>0)
					k=j;
				if(k!=i)        //ʹ��ѡ�񷨽�������
				{
					temp=p[k];
					p[k]=p[i];
					p[i]=temp;
				}
		}
		printf("\n�����ͼ�����Ϣ��¼Ϊ��\n");
		printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","���","����","������","�����","���浥λ","����ʱ��","�۸�","�軹���");
	for(i=0;i<n+1;i++)
	printf("\n%9s%9s%9s%9s%9s%9s%9s%9s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
	}
	else
		printf("\n�������Ϊ�Ƿ��ַ���\n");
}
int bookzairu(struct book*p,int n)//ͼ����Ϣ�ļ��洢.
{
	FILE *fp;               //����FILE�����ļ�ָ�����
	int i,all=0;
	char bookfile[200]="book.txt";
	fp=fopen("book.txt","r");       //��ֻ����ʽ��
	if(fp==NULL)
	{
		printf("\n***��%sʧ�ܣ���***",bookfile);

		return 0;
	}
	fscanf(fp,"%d\n",&all);  //���ļ�ָ��ָ����ı��ļ��а�ָ����ʽ���������Ϣ��ָ������
	if(all>200)                    //��ȡ��¼����
	{
		printf("�ļ���¼̫�࣬���ܶ�ȡ��");
		return 0;
	}
	for(i=0;i<all;i++)       //ͼ����Ϣ��ָ����ʽ����
	{	
		fscanf(fp,"%s %s %s %s %s %s %s %s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
	}
	fclose(fp);     //�ر��ļ�
	return all;
}
int bookbaocun(struct book*p,int n)//ͼ����Ϣ�ļ�����.
{
	FILE *fp;                        //����FILE�����ļ�ָ�����
	int i;
	char bookfile[30]="book.txt";
	fp=fopen(bookfile,"w");       //��ֻд��ʽ��
	if(fp==NULL)                    //
	{
		printf("\n***��%sʧ�ܣ���***",bookfile);
		return 0;
	}
	fprintf(fp,"%d\n",n);         //������ָ����ʽ�ַ���������ļ�ָ����ָ����ı��ļ���
	for(i=0;i<n;i++)            //ͼ����Ϣ��ָ����ʽ���
	{
	fprintf(fp,"%s %s %s %s %s %s %s %s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
	}
	fclose(fp);       //�ر��ļ�
	return 1;
}
void goout()//ͼ�����ϵͳ�˳�
{
	printf("\n�밴Enter���˳�ͼ����Ϣ����ϵͳ!\n");
}

