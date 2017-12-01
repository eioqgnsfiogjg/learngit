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
    int ID;                         //��ʶ��
    int ComeTime;                   //����ʱ��
    int ServerTime;                 //����ʱ��
    int FinishTime;                 //���ʱ��
    int TurnOverTime;               //��תʱ��
    double WeightedTOTime;    //��Ȩ��תʱ��
} PCB;

typedef struct PCBlist{
    struct PCBlist *next;
    PCB data;
} PCBL,*PCBL_pointer;

PCBL_pointer Init_PCBL()
{
    PCBL *p;
    p=(PCBL *)malloc(sizeof(PCBL));     /*����һ�����*/
    if (p==NULL)
        return NULL;                    /*����ʧ��*/
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
    PCBL *p;
    p=(PCBL_pointer)malloc(sizeof(PCBL));
    p->data.ID=x.ID;
    p->data.ComeTime=x.ComeTime;
    p->data.ServerTime=x.ServerTime;
    p->next=L_pointer;
    L_pointer=p;
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
            printf("����id��%d\n����ʱ��%d\n����ʱ��%d\n���ʱ��%d\n��תʱ��%d\n��Ȩ��תʱ��%f\n",p->data.ID,p->data.ComeTime,p->data.ServerTime,p->data.FinishTime,p->data.TurnOverTime,p->data.WeightedTOTime);
            return OK;
        }
        else
            p=p->next;
    }
    return False;
}
void Show(PCBL *L_pointer)
{
    PCBL *p;
    p=L_pointer;
    printf("����id\t����ʱ��\t����ʱ��\t���ʱ��\t��תʱ��\t��Ȩ��תʱ��\n");
    if(p==NULL)
        return;
    while(p->next!=NULL)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%f\n",p->data.ID,p->data.ComeTime,p->data.ServerTime,p->data.FinishTime,p->data.TurnOverTime,p->data.WeightedTOTime);
        p=p->next;
    }
}

void FCFS(PCBL *L_pointer)
{
   int FinishTime=-1;
   PCBL *p,*q,*temp;
   p=L_pointer;
	/*q=p;
   
   while(p->next!=NULL)
   {
   	   
       p=p->next;

       if(q->data.ComeTime>p->data.ComeTime)
        {
            q->next=p->next;
            p->next=q;
            p=q;
        }
        else
        	q=p;
		
   }*/

   while(p!=NULL)
   {

       if(p->data.ComeTime<FinishTime)
       {
           p->data.FinishTime=q->data.FinishTime+p->data.ServerTime;
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
    int i,m,loc_id,del_id;
    PCBL *Head;
    Head=Init_PCBL();
    PCB x;
    printf("�����������\n");
    scanf("%d",&m);
    do
    {
        printf ("1---����һ������(Insert)\n");
        printf ("2---��ѯһ������(Locate)\n");
        printf ("3---ɾ��һ������(Delete)\n");
        printf ("4---��ʾ���н���(Show)\n");
        printf ("5---�����ȷ���\n");
        printf ("0---�˳�\n");
        printf("�����������\n");
        scanf ("%d",&i);
        switch(i)
        {
        case 1:
            printf("��������̵�ID��,����ʱ��,����ʱ��\n");
            scanf("%d,%d,%d",&x.ID,&x.ComeTime,&x.ServerTime);
            
            Head=Push_PCB(Head,x);
            break;
        case 2:
            printf("������Ҫ���ҽ��̵�Id��\n");
            scanf("%d",&loc_id);
            if(Locate(Head,loc_id)==OK)
            {
                printf("���ҳɹ�\n");
            }
            else
                printf("���Ҵ���\n");
            break;
        /*case 3:
            printf("������Ҫɾ�����̵�id\n");
            scanf("%d",&del_id);
            if(Pop_PCBL(Head,del_id)==OK)
                printf("ɾ���ɹ�\n");
            else
                printf("ɾ��ʧ��\n");
            break;*/
        case 4:
            Show(Head);
            break;
        case 5:
            FCFS(Head);
            break;
        case 0:
            break;
        default:
            printf("����\n");
            break;
        }
    } while(i!=0);
    SetNull_PCBL(Head);

    return 0;
}
