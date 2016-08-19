#include<iostream>
#include<malloc.h>
using namespace std;
#define false 0;
#define true 1;
typedef struct ElemType{
		char name[30];
		char mobile[30];
		char addr[30];
}ElemType;
typedef struct LNode{
        ElemType data;
		LNode* next;
}LNode,*LinkList;



//带头节点得链表初始化操作
bool initLinkList(LinkList &L)
{
	L=(LNode*)malloc(sizeof(LNode));
	if(L)
	{
		L->next=NULL;
		return true;
	}
	else
		return false;
}

//判断单链表是否为空，空返回true，否则返回false
bool IsEmpty(LinkList &L)
{
	if(!(L->next))
		return 1;
	else
		return false;

}

//查看链表得长度
int Length(LinkList L)
{

	int length=0;
	LNode* p=L->next;
	while(p)
	{
		++length;
		p=p->next;
	}
	return length;
}




//找到第i个节点所在的位置,p只想第i个元素的前驱
bool SearchPre(LinkList L,int i,LNode* p)
{
	if(!L)
		return false;
	if(i>Length(L)+1||i<1)
		return false;
	p=L;
	for(;i>1;--i)
		p=p->next;
}


//在第i个节点前加入元素元素



bool Insert(LinkList &L, int i,ElemType e)
{
	//位置不合理
	if(i<1||i>Length(L)+1)
	//cout<<"Insert fail,because the index is not true!"<<endl;
		return false;
	//为待插入元素分配空间
	LNode* elem=(LNode*)malloc(sizeof(LNode));
	elem->data=e;
	LNode* p=NULL;
	SearchPre(L,i,p);
	elem->next=p->next;//插入
	p->next=elem;
	return true;
}


//头插法





bool Insert(LinkList& L,ElemType e)
{
	LNode* p=(LNode*)malloc(sizeof(LNode));
	p->data=e;
	p->next=L->next;
	L->next=p;
	return 1;
	
}

//按姓名删除元素
bool deleteNode(LinkList &L,char* name)
{
	int flag=0;
	LNode *p= L->next;
	LNode *pre= L;//始终指示p的前驱
	if(!p) return false;
	while(p)
	{
		//delete所有的name域为给定值得元素。
		if(!strcmp(name,p->data.name))
		{
			pre->next=p->next;
			free(p);
			p=pre->next;	
			flag=1;
		}
		else
		{
			p=p->next;
			pre=pre->next;
		}
	}
	if(flag)
		return 1;
	else
		return false;

}
//按姓名查找元素
bool search(LinkList L,LNode *&result,char* name)
{
	LNode* p=L->next;
	if(!p)
		return false;
	while(p)
	{
		if(!strcmp(name,p->data.name))
		{
			result=p;
			return true;
		}
		else
			p=p->next;
	}
	return false;
}


//输出所有元素的值
void print(LinkList L)
{
	LNode * p=L->next;
	while(p)
	{
		cout<<"联系人为："<<p->data.name<<",电话号码为："<<p->data.mobile<<",家庭住址为："<<p->data.addr<<endl;
		p=p->next;
	}
}


void destory(LinkList& L)
{
	LNode* p=L->next;
	if(!p)
		return ;
	L->next=NULL;
	LNode*q=p->next;
	while(p)
	{
		free(p);
		p=q;
		q=q->next;
	}
}




void main()
{
	int judge=0;
	int choice=0;
	ElemType elem;
	//char *phoneNumber=new char[30];
	char name[30];
	LinkList L;
	initLinkList(L);
	cout<<"请选择相关操作：1代表查询表中元素，2表中元素个数，3代表插入元素，4代表删除元素操作,5代表退出"<<endl;
	while(scanf("%d",&choice)!=EOF)
	{
		
		if(choice==1)
		{
			cout<<"请输入要查询对象的名字：";
			cin>>name;
			LNode *p=NULL;
			judge=search(L,p,name);
			if(judge)
			{
				cout<<name<<"的信息为："<<(*p).data.mobile<<", "<<(*p).data.addr<<endl;

			}
			else
				cout<<"表中没有你要查找的元素"<<endl;
		}
			
		else if(choice==2)
			cout<<"表中元素为"<<Length(L)<<"个"<<endl;
		else if(choice==3)
		{

			cout<<"请输入需要插入的相关信息。"<<endl;
			cout<<"姓名：";

			cin>>elem.name;
			cout<<"电话号码：";
			cin>>elem.mobile;
			cout<<"家庭地址：";
			cin>>elem.addr;
			if(Insert(L,elem))
			{
				cout<<"插入成功！"<<endl;
				print(L);
			}
			else
				cout<<"插入失败！"<<endl;

		}
		else if(choice==4)
		{
			cout<<"请输入要删除人物的姓名：";
			cin>>name;
			if(deleteNode(L,name))
				cout<<"删除成功！"<<endl;
			else
				cout<<"表中不含该人物！删除失败"<<endl;

		}
		else
		{
			destory(L);
			return ;
		}


	}
}
