
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define L 20
#define Q 200
struct book                   //定义一个book类结构体。
{
	char no[L];               //编号
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
int bookbaocun(struct book*p,int n);        //函数声明
void main()                                //主函数
{
	char slect,yn,moshi;
	struct book record[Q];                 //定义book类结构体变量存放图书信息共200条
	int total=0,flag;
	total=bookzairu(record,Q);              //从文件读取图书信息，不超过200条
	menu1();
	printf("访问模式选择：");
	moshi=getchar();
	getchar();
    if(moshi=='1')
    {
       	do
	  {
		menu2();                            //显示菜单
		printf("请服务项编号：");
		slect=getchar();
		getchar();
		switch(slect)
		{
        case'0': goout();break;
		case'1': bookliulan(record,total);break;  //函数调用
		case'2': bookchaxun(record,total);break;
		case'3': jiehuanshuji(record,total);break;
		case'4': bookpaixu(record,total);break;
		case'5': flag=bookbaocun(record,total);
			if("flag==1")
				printf("图书信息保存成功！\n");
			else
				printf("图书信息保存失败！\n");
			break;
		default:continue;
		}
		if(slect=='0') break;
		printf("\n还要继续选择吗？（Y/N）");      //提示是否结束
		do//做非法输入的异常处理
        {
			scanf("%c",&yn);
			getchar();
			if (yn=='Y'||yn=='y')
				break;
			else if (yn=='N'||yn=='n')
				break;
			else
		    	printf("非法选项！\n还要继续选择吗？（Y/N）");
        } while(1);
	   } while(yn!='N'&&yn!='n');
     }


     else if(moshi=='2')
     {
         do
	  {
		menu3();                            //显示菜单
		printf("请服务项编号：");
		slect=getchar();
		getchar();
		switch(slect)
		{
        case'0': goout();break;
		case'1': total=bookluru(record,total);break;   //函数调用
		case'2': bookliulan(record,total);break;
		case'3': bookchaxun(record,total);break;
		case'4': bookxiugai(record,total);break;
		case'5': jiehuanshuji(record,total);break;
		case'6': total=bookzhengjia(record,total);break;
		case'7': total=bookshanchu(record,total);break;
		case'8': bookpaixu(record,total);break;
		case'9': flag=bookbaocun(record,total);
			if("flag==1")
				printf("图书信息保存成功！\n");
			else
				printf("图书信息保存失败！\n");
			break;
		default:continue;
		}
		if(slect=='0') break;
		printf("\n还要继续选择吗？（Y/N）");      //提示是否结束
		do
		{
			scanf("%c",&yn);
			getchar();
			if (yn=='Y'||yn=='y')
				break;
			else if (yn=='N'||yn=='n')
				break;
			else
		    	printf("非法选项！\n还要继续选择吗？（Y/N）");
		}
		while(1);
	  }
	   while(yn!='N'&&yn!='n');
    }
    else printf("输入错误");

}
void menu1()//图书管理系统主菜单.
{
    system("cls");
    printf("\n\n");
    printf("请选择服务项目编号（1--2）\n");
    printf("******************************************************************\n");
    printf("§********************欢迎使用图书信息管理系统******************§\n");
    printf("§*************************请选择服务模式***********************§\n");
    printf("§**************************************************************§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("§§                    * 1 . 访问者模式.                        §§\n");
    printf("§§                    * 2 . 管理者模式.                        §§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("******************************************************************\n");
    printf("\n");
}
void menu2()
{
    system("cls");
    printf("\n\n");
    printf("请选择服务项目编号（0--5）\n");
    printf("******************************************************************\n");
    printf("§********************欢迎使用图书信息管理系统******************§\n");
    printf("§**************************访问者模式**************************§\n");
    printf("§**************************************************************§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("§§                    * 1 . 图书信息浏览.                        §§\n");
    printf("§§                    * 2 . 图书信息查询.                        §§\n");
    printf("§§                    * 3 . 图书书籍借还.                        §§\n");
    printf("§§                    * 4 . 图书信息排序.                        §§\n");
    printf("§§                    * 5 . 图书信息保存.                        §§\n");
    printf("§§                    * 0 . 退出图书管理系统.                    §§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("******************************************************************\n");
    printf("\n");
}
void menu3()
{
	system("cls");
    printf("\n\n");
    printf("请选择服务项目编号（0--9）\n");
    printf("******************************************************************\n");
    printf("§********************欢迎使用图书信息管理系统******************§\n");
    printf("§**************************管理者模式**************************§\n");
    printf("§**************************************************************§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("§§                    * 1 . 图书信息录入.                        §§\n");
    printf("§§                    * 2 . 图书信息浏览.                        §§\n");
    printf("§§                    * 3 . 图书信息查询.                        §§\n");
    printf("§§                    * 4 . 图书信息修改.                        §§\n");
    printf("§§                    * 5 . 图书书籍借还.                        §§\n");
    printf("§§                    * 6 . 图书信息增加.                        §§\n");
    printf("§§                    * 7 . 图书信息删除.                        §§\n");
    printf("§§                    * 8 . 图书信息排序.                        §§\n");
    printf("§§                    * 9 . 图书信息保存.                        §§\n");
    printf("§§                    * 0 . 退出图书管理系统.                    §§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("§§                                                             §§\n");
    printf("******************************************************************\n");
    printf("\n");
}
int bookluru(struct book *p,int n)//录入图书信息.
{
	int i=0;
	int m;
	printf("\n添加前的图书信息记录共有%d个：\n",n);        //显示原有的图书信息
	printf("----------------------------------------------------------------------------------------------------------");
	printf("\n%9s%9s%10s%10s%10s%10s%10s%10s\n","编号","书名","作者名","分类号","出版时间","出版单位","价格","借还情况");
	printf("----------------------------------------------------------------------------------------------------------");
	i=0;
	while((i<n)&&(strcmp(p->no,"")!=0))        //输入的编号不为空时，输出图书信息
	{
	printf("\n%9s%9s%9s%9s%9s%15s%9s%9s\n",p->no,p->name,p->author,p->fenlei,p->puttime,p->putfrom,p->price,p->jiehuan);//信息输出
		i++;
		p++;
	}
	printf("----------------------------------------------------------------------------------------------------------");
	printf("\n请输入要录入的图书数目X（0<X<%d）: ",200-n);  //设置图书信息存储最大值
	scanf("%d",&m);
	i=0;
	while(i<m)
	{
		printf("\n");
		printf("请输入第%d本图书的信息：\n",i+1);
		printf("编号(请勿重复): ");
		do
		{
		   gets(p->no);     //输入编号，再输入其他信息
		}
		while(strcmp(p->no,"")==0);
		printf("书名为:");
        gets(p->name);
        printf("作者名为:");
        gets(p->author);
        printf("分类号为:");
        gets(p->fenlei);
        printf("出版时间为:");
        gets(p->puttime);
        printf("出版单位为:");
        gets(p->putfrom);
        printf("价格为:");
        gets(p->price);
        printf("本书借还情况(已借或未借):");
        gets(p->jiehuan);
		p++;
		i++;
	}
	return m+n;
}

void bookliulan(struct book*p,int n)//图书信息浏览.
{
	int i=0;
	printf("----------------------------------------------------------------------------------------------------------");
	printf("\n%9s%9s%10s%10s%10s%10s%10s%10s\n","编号","书名","作者名","分类号","出版时间","出版单位","价格","借还情况");
	printf("----------------------------------------------------------------------------------------------------------");
	while(i<n)                                            //输出原有图书信息
	{
	printf("\n%9s%9s%9s%9s%9s%15s%9s%9s\n",p->no,p->name,p->author,p->fenlei,p->puttime,p->putfrom,p->price,p->jiehuan);
		p++;
		i++;
	}
	printf("----------------------------------------------------------------------------------------------------------");
}

void bookchaxun(struct book*p,int n)//图书信息查询.
{
	char c;
	bookliulan(p ,n);
	do
	{
		printf("\n请问按编号查询（D），还是按作者名查询（A）？");  //选择查询方式
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
			printf("\n输入的为非法字符！\n");
			continue;
		}
	}
	while(c!='D'||c!='d'||c!='A'||c!='a');
}

void DLsearch(struct book*p,int n)//按编号查询.
{
	int i,x=0;
	char DL[L];
	printf("\n请输入要查询图书的编号：");
	gets(DL);
	for(i=0;i<n;i++)
		if(strcmp(DL,p[i].no)==0)     //输入编号，如果在系统中找到则输出图书信息
		{
			printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","编号","书名","作者名","分类号","出版单位","出版时间","价格","借还情况");
			printf("\n%10s%10s%10s%10s%10s%10s%10s%10s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
			x=1;
			break;
		}
		if(x==0)
		printf("\n对不起，图书系统中没有包含此书的信息！\n");
}

void AUsearch(struct book*p,int n)//按作者名查询.
{
	int i,x=0;
	char AU[20];
	printf("\n请输入要查询图书的作者姓名：");
	gets(AU);
	for(i=0;i<n;i++)
	   if(strcmp(AU,p[i].author)==0)  //输入作者姓名，如果在系统中找到则输出图书信息
		{
			printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","编号","书名","作者名","分类号","出版单位","出版时间","价格","借还情况");
			printf("\n%10s%10s%10s%10s%10s%10s%10s%10s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
			x=1;
		}
		if(x==0)
		printf("\n对不起，图书系统中没有包含此书的信息！\n");  //提示信息
}
void bookxiugai(struct book*p,int n)//图书信息修改.
{
	int i,k=0;
	char no[L],slect;
	bookliulan(p,n);
	printf("\n请输入要修改图书的编号：");
	gets(no);
	for(i=0;i<n;i++,p++)
	{
		if(strcmp(no,p->no)!=0) continue;
		{
          printf("\n修改前的图书信息记录为：\n");        //显示原有的图书信息
	      printf("----------------------------------------------------------------------------------------------------------");
          printf("\n%9s%9s%10s%10s%10s%10s%10s%10s\n","编号","书名","作者名","分类号","出版时间","出版单位","价格","借还情况");
          printf("----------------------------------------------------------------------------------------------------------");
          printf("\n%9s%9s%9s%9s%9s%15s%9s%9s\n",p->no,p->name,p->author,p->fenlei,p->puttime,p->putfrom,p->price,p->jiehuan);//信息输出
          printf("----------------------------------------------------------------------------------------------------------");
          printf("\n****************************请输入要修改的部分的代号*******************************");
          printf("\n*****编号(1)，书名(2)，作者名(3)，分类号(4)，出版时间(5)，出版单位(6)，价格(7)*****");
          printf("\n***********************************************************************************");
          printf("\n需要修改的信息的代号为");
		  slect=getchar();
		  getchar();
		  switch(slect)
		  {
		   case'1': printf("\n请输入正确的图书编号：");gets(p->no);;break;  //函数调用
		   case'2': printf("\n请输入正确的图书书名:");gets(p->name);break;
		   case'3': printf("\n请输入正确的图书作者名:");gets(p->author);break;
		   case'4': printf("\n请输入正确的图书分类号:");gets(p->fenlei);break;
		   case'5': printf("\n请输入正确的图书出版时间:");gets(p->puttime);break;
		   case'6': printf("\n请输入正确的图书出版单位:");gets(p->putfrom);break;
		   case'7': printf("\n请输入正确的图书价格:");gets(p->price);break;
		   default:break;
		  }
			  printf("\n修改图书图书信息完成！！");
			  k=1;
		}
	}
	if(k==0)
		printf("\n对不起，图书系统中没有包含此书的信息！\n");
}
void jiehuanshuji(struct book *p,int n)//图书借还
{
    char c1;
    bookliulan(p ,n);
    do
    {
        printf("\n请问是借书(J),还是还书(H)？");
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
			printf("\n输入的为非法字符！\n");
			continue;
		}
    }while(c1!='j'||c1!='J'||c1!='h'||c1!='H');

}
void jieshu(struct book*p,int n)//借书
{
    int i,k=0;
    char no[L],name[L],m[L]="已借";
    printf("\n请输入所借书籍的编号或者书名:");
    printf("\n编号:"); gets(no);
    printf("\n书名:"); gets(name);
    for(i=0;i<n;i++,p++)
    {
        if((strcmp(no,p->no)!=0)&&(strcmp(name,p->name)!=0))  continue;
        
        if(strcmp(no,p->no)==0||strcmp(name,p->name)==0)//书名和作者只要有一个匹配就ok
        {
            if(strcmp(m,p->jiehuan)==0) k=2;
            else if (strcmp("未借",p->jiehuan)!=0)
       		{
        		k=3;
        	}
            else
                {
                    strcpy(p->jiehuan,m);
                    printf("\n借书成功!");
                    k=1;
                }
        }
    }
    if(k==0) printf("\n对不起，图书系统中没有包含此书的信息！\n");
    if(k==2) printf("\n对不起，本书已被借！\n");
    if (k==3) printf("\n此书禁止借阅\n");
    
}
void huanshu(struct book *p,int n)//还书
{
    int i,k=0;
    char no[L],name[L],m[L] ="未借";
    printf("\n请输入所还书籍的编号或者书名:");
    printf("\n编号:");
        gets(no);
    printf("\n书名:");
        gets(name);
    for(i=0;i<n;i++,p++)
    {
        if(strcmp(no,p->no)!=0&&strcmp(name,p->name)!=0) continue;
        if(strcmp(no,p->no)==0||strcmp(name,p->name)==0)
        {
          
            if(strcmp(m,p->jiehuan)==0) k=2;
            else if (strcmp("已借",p->jiehuan)!=0)
       		{
        		k=3;
        	}
            else
                {
                    strcpy(p->jiehuan,m);
                    printf("\n还书成功！");
                    k=1;
                }
        }
    }
    if(k==0) printf("\n对不起，图书系统中没有包含此书的信息！\n");
    if(k==2) printf("\n对不起，本书尚未被借，无法还书！\n");
    if (k==3) printf("\n本书借阅状态有误,无法还书\n");
    
}
int bookzhengjia(struct book *p,int n)//图书信息增加.
{
	int i=0;
	char c;
	struct book t,*q;
	printf("\n添加前图书信息的记录为：\n");
    bookliulan(p ,n);//显示添加前图书信息的记录
	do
	{
		printf("\n请输入新图书信息的编号:");
		gets(t.no);
		printf("\n请输入新图书信息的书名为:");
        gets(t.name);
        printf("\n请输入新图书信息的作者名为:");
        gets(t.author);
        printf("\n请输入新图书信息的分类号为:");
        gets(t.fenlei);
        printf("\n请输入新图书信息的出版时间为:");
        gets(t.puttime);
        printf("\n请输入新图书信息的出版单位为:");
        gets(t.putfrom);
        printf("\n请输入新图书信息的价格为:");
        gets(t.price);
        printf("\n请输入新图书信息的借还情况为:");
        gets(t.jiehuan);
		for(i=0;i<n;i++)
		    if(strcmp(t.no,(p+i)->no)==0)
			{
				printf("编号重复，要重新输入吗（Y/N）？");
				c=getchar();
				putchar('\n');
				break;
			}
			if(i==n)
			{
				*(p+i)=t;
				printf("\n添加后图书的信息记录为：\n");   //显示添加后图书的信息记录
				printf("----------------------------------------------------------------------------------------------------------");
				printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","编号","书名","作者名","分类号","出版单位","出版时间","价格","借还情况");
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
int bookshanchu(struct book *p,int n)//图书信息删除.
{
	int i,x,y=0;
	char c,name[20],no[20];
	printf("\n删除前图书的信息记录为：\n");
    bookliulan(p ,n);
	printf("\n请输入要删除图书的编号：");
	gets(no);
	for(x=0;x<n;x++)
	{
		if(strcmp(no,p[x].no)!=0)    ////输入的编号不匹配，结束本次循环
			continue;
		if(x<n)
		{
			for(i=x;i<n;i++)         //后一个图书信息对前一个图书信息覆盖删除
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
			printf("图书信息删除后的记录：\n");
	printf("----------------------------------------------------------------------------------------------------------");
	printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","编号","书名","作者名","分类号","出版单位","出版时间","价格","借还情况");
	printf("----------------------------------------------------------------------------------------------------------");
	for(i=0;i<n+1;i++)
	printf("\n%9s%9s%9s%9s%9s%9s%9s%9s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
	printf("----------------------------------------------------------------------------------------------------------");
			y=1;
		}
		else
			printf("\n对不起，图书系统中没有包含此书的信息！\n");
		return n-y;
	}
}
void bookpaixu(struct book*p,int n)//对图书信息排序.
{
	int j,i,k;
	char c1,c2;
	struct book temp;
	printf("\n排序前图书的信息记录为：\n");
	bookliulan(p,n);
	printf("\n按编号排序（D），还是按作者名排序（A）？");      //选择排序的方式
	c1=getchar();
	getchar();
	if(c1=='d'||c1=='D')                //选择编号由小到大排序
	{
		for(i=0;i<n-1;i++)
		{
			k=i;
			for(j=i+1;j<n;j++)
				if(strcmp(p[k].no,p[j].no)>0)     //使用选择法进行排序
					k=j;
				if(k!=i)    //如果最小熟不熟默认的p[i]，再交换，
				{
					temp=p[k];
					p[k]=p[i];
					p[i]=temp;
				}
		}
		printf("\n排序后图书的信息记录为：\n");            //输出排序后图书的信息
	printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","编号","书名","作者名","分类号","出版单位","出版时间","价格","借还情况");
	for(i=0;i<n+1;i++)
	printf("\n%9s%9s%9s%9s%9s%9s%9s%9s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
	}
	else if(c1=='a'||c1=='A')   //选择作者名由小到大排序
	{
		for(i=0;i<n-1;i++)
		{
			k=i;
			for(j=i+1;j<n;j++)
				if(strcmp(p[k].author,p[j].author)>0)
					k=j;
				if(k!=i)        //使用选择法进行排序
				{
					temp=p[k];
					p[k]=p[i];
					p[i]=temp;
				}
		}
		printf("\n排序后图书的信息记录为：\n");
		printf("\n %9s%9s%9s%9s%9s%9s%9s%9s\n","编号","书名","作者名","分类号","出版单位","出版时间","价格","借还情况");
	for(i=0;i<n+1;i++)
	printf("\n%9s%9s%9s%9s%9s%9s%9s%9s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
	}
	else
		printf("\n您输入的为非法字符！\n");
}
int bookzairu(struct book*p,int n)//图书信息文件存储.
{
	FILE *fp;               //定义FILE类型文件指针变量
	int i,all=0;
	char bookfile[200]="book.txt";
	fp=fopen("book.txt","r");       //以只读方式打开
	if(fp==NULL)
	{
		printf("\n***打开%s失败！！***",bookfile);

		return 0;
	}
	fscanf(fp,"%d\n",&all);  //从文件指针指向的文本文件中按指定格式逐个输入信息到指定变量
	if(all>200)                    //读取记录总数
	{
		printf("文件记录太多，不能读取！");
		return 0;
	}
	for(i=0;i<all;i++)       //图书信息按指定格式输入
	{	
		fscanf(fp,"%s %s %s %s %s %s %s %s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
	}
	fclose(fp);     //关闭文件
	return all;
}
int bookbaocun(struct book*p,int n)//图书信息文件保存.
{
	FILE *fp;                        //定义FILE类型文件指针变量
	int i;
	char bookfile[30]="book.txt";
	fp=fopen(bookfile,"w");       //以只写方式打开
	if(fp==NULL)                    //
	{
		printf("\n***打开%s失败！！***",bookfile);
		return 0;
	}
	fprintf(fp,"%d\n",n);         //将数据指定格式字符串输出到文件指针所指向的文本文件。
	for(i=0;i<n;i++)            //图书信息按指定格式输出
	{
	fprintf(fp,"%s %s %s %s %s %s %s %s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price,p[i].jiehuan);
	}
	fclose(fp);       //关闭文件
	return 1;
}
void goout()//图书管理系统退出
{
	printf("\n请按Enter键退出图书信息管理系统!\n");
}

