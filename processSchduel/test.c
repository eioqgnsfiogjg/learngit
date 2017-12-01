#include <stdio.h>
#include <String.h>
#include <malloc.h>
#define OverFlow -1
#define UnderFlow -2
#define OK 1
#define True 1
#define False -1

typedef struct PCB
{
    int ID;                         //标识符
    int ComeTime;                   //到达时间
    int ServerTime;                 //服务时间
    int FinishTime;                 //完成时间
    int TurnOverTime;               //周转时间
    double WeightedTOTime;    //带权周转时间
} PCB;

typedef struct PCBlist{
    struct PCBlist *next;
    PCB data;
} PCBL,*PCBL_pointer;

PCBL_pointer Init_PCBL()
{
    PCBL *p;
    p=(PCBL *)malloc(sizeof(PCBL));     /*分配一个结点*/
    if (p==NULL)
        return NULL;                    /*分配失败*/
    p->next=NULL;
	return p;
}
int Empty_PCBL(PCBL *L_pointer)
{
    if(L_pointer==NULL)
        return True;
    else
        return False;
}
PCBL_pointer Push_PCB(PCBL *L_pointer,PCB x)
{
    PCBL *p,*q;
    p=(PCBL_pointer)malloc(sizeof(PCBL));
    p->data.ComeTime=x.ComeTime;
    p->data.ServerTime=x.ServerTime;
    p->data.ID=x.ID;
    q=L_pointer;
    
    while(q->next!=NULL)
    {
    	q=q->next;
	}
    q->next=p;
    p->next=NULL;
    return L_pointer;
}
/*int Pop_PCBL(PCBL *L_pointer,int x_id)
{
    PCBL *p,*q;
    p=L_pointer;
    q=p;
    while(p->next!=NULL)
    {

        if(p->data.ID==x_id)
        {
          q->next=p->next;
          free(p);
          return OK;
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
    return False;
}*/
/*
int GetTop_PCBL(PCBL *L_pointer,PCB *x_pointer)
{
    if(Empty_LinkStack(*L_pointer)==True)
        return UnderFlow;
    else
    {
        *x_pointer=(*L_pointer)->data;
        return *x_pointer;
    }
}
*/
void SetNull_PCBL(PCBL *L_pointer)
{
    PCBL *p,*q;
    p=L_pointer;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        free(q);
    }
    L_pointer=NULL;
}
int Locate(PCBL *L_pointer,int x_id)
{
    PCBL *p;
    p=L_pointer;
    while(p!=NULL)
    {
        if(p->data.ID==x_id)
        {
            printf("进程id号%d\n到达时间%d\n服务时间%d\n完成时间%d\n周转时间%d\n带权周转时间%f\n",p->data.ID,p->data.ComeTime,p->data.ServerTime,p->data.FinishTime,p->data.TurnOverTime,p->data.WeightedTOTime);
            return OK;
        }
        else
            p=p->next;
    }
    return False;
}
void Show(PCBL *Lp)
{
    PCBL *p;
    p=Lp->next;
    if(p==NULL)
    	printf("空表\n"); 
    printf("进程id\t到达时间\t服务时间\t完成时间\t周转时间\t带权周转时间\n");
    while(p!=NULL)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%f\n",p->data.ID,p->data.ComeTime,p->data.ServerTime,p->data.FinishTime,p->data.TurnOverTime,p->data.WeightedTOTime);
        p=p->next;
    }
}

PCBL_pointer SortFCFS(PCBL_pointer L)
{
	PCBL_pointer first;     /*排列后有序链的表头指针*/
    PCBL_pointer tail;      /*排列后有序链的表尾指针*/
    PCBL_pointer p_min;     /*保留键值更小的节点的前驱节点的指针*/
    PCBL_pointer min;       /*存储最小节点*/
    PCBL_pointer p;         /*当前比较的节点*/

    first = NULL;
    while (L != NULL) /*在链表中找键值最小的节点。*/
    {
        /*注意：这里for语句就是体现选择排序思想的地方*/
        for (p=L,min=L; p->next!=NULL; p=p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/
        {
            if (p->next->data.ComeTime < min->data.ComeTime) /*找到一个比当前min小的节点。*/
            {
                p_min = p; /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/
                min = p->next; /*保存键值更小的节点。*/
            }
        }

        /*上面for语句结束后，就要做两件事；
            一是把它放入有序链表中；
            二是根据相应的条件判断，安排它离开原来的链表。*/

        /*第一件事*/
        if (first == NULL) /*如果有序链表目前还是一个空链表*/
        {
            first = min; /*第一次找到键值最小的节点。*/
            tail = min; /*注意：尾指针让它指向最后的一个节点。*/
        }
        else /*有序链表中已经有节点*/
        {
            tail->next = min; /*把刚找到的最小节点放到最后，即让尾指针的next指向它。*/
            tail = min; /*尾指针也要指向它。*/
        }
        /*第二件事*/
        if (min == L) /*如果找到的最小节点就是第一个节点*/
        {
            //printf("表头%d已经是最小，当前结点后移。\n", min->data);
            L = L->next; /*显然让head指向原head->next,即第二个节点，就OK*/
        }
        else /*如果不是第一个节点*/
        {
            p_min->next = min->next; /*前次最小节点的next指向当前min的next,这样就让min离开了原链表。*/
        }
    }
    if (first != NULL) /*循环结束得到有序链表first*/
    {
        tail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL*/
    }
    L = first;
    return L;
}
PCBL_pointer SortSJF(PCBL_pointer L)
{
	PCBL_pointer first;     /*排列后有序链的表头指针*/
    PCBL_pointer tail;      /*排列后有序链的表尾指针*/
    PCBL_pointer p_min;     /*保留键值更小的节点的前驱节点的指针*/
    PCBL_pointer min;       /*存储最小节点*/
    PCBL_pointer p;         /*当前比较的节点*/

    first = NULL;
    while (L != NULL) /*在链表中找键值最小的节点。*/
    {
        /*注意：这里for语句就是体现选择排序思想的地方*/
        for (p=L,min=L; p->next!=NULL; p=p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/
        {
            if (p->next->data.ServerTime < min->data.ServerTime) /*找到一个比当前min小的节点。*/
            {
                p_min = p; /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/
                min = p->next; /*保存键值更小的节点。*/
            }
        }

        /*上面for语句结束后，就要做两件事；
            一是把它放入有序链表中；
            二是根据相应的条件判断，安排它离开原来的链表。*/

        /*第一件事*/
        if (first == NULL) /*如果有序链表目前还是一个空链表*/
        {
            first = min; /*第一次找到键值最小的节点。*/
            tail = min; /*注意：尾指针让它指向最后的一个节点。*/
        }
        else /*有序链表中已经有节点*/
        {
            tail->next = min; /*把刚找到的最小节点放到最后，即让尾指针的next指向它。*/
            tail = min; /*尾指针也要指向它。*/
        }
        /*第二件事*/
        if (min == L) /*如果找到的最小节点就是第一个节点*/
        {
            //printf("表头%d已经是最小，当前结点后移。\n", min->data);
            L = L->next; /*显然让head指向原head->next,即第二个节点，就OK*/
        }
        else /*如果不是第一个节点*/
        {
            p_min->next = min->next; /*前次最小节点的next指向当前min的next,这样就让min离开了原链表。*/
        }
    }
    if (first != NULL) /*循环结束得到有序链表first*/
    {
        tail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL*/
    }
    L = first;
    return L;
}
//先通过排序找到服务时间最短的作业，可以确定它的完成时间=到达时间+服务时间，然后排序后第二的作业
//当它到达时间比第一个作业的完成时间大或者它的到达时间+服务时间<第一作业的到达时间，此时它的完成时间=自己到达时间+服务时间
//否则，当它的到达时间+服务时间（它的最小完成时间>第一作业的到达时间,并且它的到达时间<第一作业的完成时间,只有这种情况，当它的到达时间+服务时间<
//第一作业完成时间时，会有优先执行第一作业， 它的完成时间应该等于它的到达时间+第一作业服务时间+自己的服务时间 
	   	
PCBL_pointer SJF(PCBL *L_pointer)
{
   PCBL *p,*q;
   /*
   while(p->next!=NULL)
   {
       p=p->next;

       if(q->data.ComeTime>p->data.ComeTime)
        {
            temp=p->next;
            p->next=q;
            q->next=temp;
        }

   }*/
   L_pointer=SortSJF(L_pointer);
    p=L_pointer->next;
   while(p!=NULL)
   {
   		if(p->data.ID!=L_pointer->next->data.ID) 
		{ 
	     	if(p->data.ComeTime+p->data.ServerTime>q->data.ComeTime&&p->data.ComeTime<q->data.FinishTime)
	   	   {
	   	   		p->data.FinishTime=p->data.ComeTime+p->data.ServerTime+q->data.ServerTime;	
	       }
	       else
	       {
	           p->data.FinishTime=p->data.ComeTime+p->data.ServerTime;
	       }   
		}
		else
		{
			p->data.FinishTime=p->data.ComeTime+p->data.ServerTime;
		} 
		p->data.TurnOverTime=p->data.FinishTime-p->data.ComeTime;
	    p->data.WeightedTOTime=(double)p->data.TurnOverTime/p->data.ServerTime;
	    q=p;
	    p=p->next;
	}
	return L_pointer;
}
void FCFS(PCBL *L_pointer)
{
   int FinishTime=-1;
   PCBL *p,*q,*Lp;
   
   /*
   while(p->next!=NULL)
   {
       p=p->next;

       if(q->data.ComeTime>p->data.ComeTime)
        {
            temp=p->next;
            p->next=q;
            q->next=temp;
        }

   }*/
   Lp=SortFCFS(L_pointer);
   p=Lp->next;
   while(p!=NULL)
   {
		//完成时间，周转时间，带权周转时间的求得
       if(p->data.ComeTime<FinishTime)
       {
           p->data.FinishTime=q->data.FinishTime+p->data.ServerTime; //如果该进程到达时间比上一进程的完成时间早 
       }
       else
       {
           p->data.FinishTime=p->data.ComeTime+p->data.ServerTime;
       }

        p->data.TurnOverTime=p->data.FinishTime-p->data.ComeTime;
        p->data.WeightedTOTime=(double)p->data.TurnOverTime/p->data.ServerTime;
        FinishTime=p->data.FinishTime;

       q=p;
       p=p->next;
   }

}
int main()
{
    int i,j,m,loc_id,del_id;
    PCBL *Head;
    Head=Init_PCBL();
    PCB x;
  	char ch;
  	printf("请输入进程数\n");
	scanf("%d",&m); 
    do
    {
        printf ("1---输入进程信息(Insert)\n");
        printf ("2---查询一个进程(Locate)\n");
        printf ("3---删除一个进程(Delete)\n");
        printf ("4---显示所有进程(Show)\n");
        printf ("5---进程调度\n");
        printf ("0---退出\n");
        printf("请输入操作号\n");
        scanf ("%d",&i);
        switch(i)
        {
        case 1:
        	for(j = 0;j<m;j++)
            {
				printf("请输入作业的到达时间,服务时间\n");
	            scanf("%d,%d",&x.ComeTime,&x.ServerTime);
	            x.ID=j;
	            if(x.ComeTime<0)
	            {
					printf("到达时间不能为负数\n");
					break; 
	            } 
	            if(x.ServerTime<0)
	            {
					printf("服务时间不能为负数\n");
					break; 
	            } 
	            Head=Push_PCB(Head,x);
	        
			}
            break;
        case 2:
            printf("请输入要查找进程的Id号\n");
            scanf("%d",&loc_id);
            if(Locate(Head,loc_id)==OK)
            {
                printf("查找成功\n");
            }
            else
                printf("查找错误\n");
            break;
        /*case 3:
            printf("请输入要删除进程的id\n");
            scanf("%d",&del_id);
            if(Pop_PCBL(Head,del_id)==OK)
                printf("删除成功\n");
            else
                printf("删除失败\n");
            break;*/
        case 4:
            Show(Head);
            break;
        case 5:
        	
        	printf("请输入选择的算法(FCFS,SJF,HRRN),只输入第一个字母\n");
        	getchar(); 
        	scanf("%c",&ch);
			switch(ch) {
				case 'F':
				case 'f':
					FCFS(Head);
					break;
				case 'S':
				case 's':
					Head=SJF(Head);
					break;
				case 'H':
				case 'h':
				default:
					printf("error！请重新输入\n");
					break;
			}
            break;
        
        case 0:
            break;
        default:
            printf("操作号错误\n");
            break;
        }
    } while(i!=0);
    SetNull_PCBL(Head);

    return 0;
}
