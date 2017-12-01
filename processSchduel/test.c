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
            printf("����id��%d\n����ʱ��%d\n����ʱ��%d\n���ʱ��%d\n��תʱ��%d\n��Ȩ��תʱ��%f\n",p->data.ID,p->data.ComeTime,p->data.ServerTime,p->data.FinishTime,p->data.TurnOverTime,p->data.WeightedTOTime);
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
    	printf("�ձ�\n"); 
    printf("����id\t����ʱ��\t����ʱ��\t���ʱ��\t��תʱ��\t��Ȩ��תʱ��\n");
    while(p!=NULL)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%f\n",p->data.ID,p->data.ComeTime,p->data.ServerTime,p->data.FinishTime,p->data.TurnOverTime,p->data.WeightedTOTime);
        p=p->next;
    }
}

PCBL_pointer SortFCFS(PCBL_pointer L)
{
	PCBL_pointer first;     /*���к��������ı�ͷָ��*/
    PCBL_pointer tail;      /*���к��������ı�βָ��*/
    PCBL_pointer p_min;     /*������ֵ��С�Ľڵ��ǰ���ڵ��ָ��*/
    PCBL_pointer min;       /*�洢��С�ڵ�*/
    PCBL_pointer p;         /*��ǰ�ȽϵĽڵ�*/

    first = NULL;
    while (L != NULL) /*���������Ҽ�ֵ��С�Ľڵ㡣*/
    {
        /*ע�⣺����for����������ѡ������˼��ĵط�*/
        for (p=L,min=L; p->next!=NULL; p=p->next) /*ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣*/
        {
            if (p->next->data.ComeTime < min->data.ComeTime) /*�ҵ�һ���ȵ�ǰminС�Ľڵ㡣*/
            {
                p_min = p; /*�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p��*/
                min = p->next; /*�����ֵ��С�Ľڵ㡣*/
            }
        }

        /*����for�������󣬾�Ҫ�������£�
            һ�ǰ����������������У�
            ���Ǹ�����Ӧ�������жϣ��������뿪ԭ��������*/

        /*��һ����*/
        if (first == NULL) /*�����������Ŀǰ����һ��������*/
        {
            first = min; /*��һ���ҵ���ֵ��С�Ľڵ㡣*/
            tail = min; /*ע�⣺βָ������ָ������һ���ڵ㡣*/
        }
        else /*�����������Ѿ��нڵ�*/
        {
            tail->next = min; /*�Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������*/
            tail = min; /*βָ��ҲҪָ������*/
        }
        /*�ڶ�����*/
        if (min == L) /*����ҵ�����С�ڵ���ǵ�һ���ڵ�*/
        {
            //printf("��ͷ%d�Ѿ�����С����ǰ�����ơ�\n", min->data);
            L = L->next; /*��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK*/
        }
        else /*������ǵ�һ���ڵ�*/
        {
            p_min->next = min->next; /*ǰ����С�ڵ��nextָ��ǰmin��next,��������min�뿪��ԭ����*/
        }
    }
    if (first != NULL) /*ѭ�������õ���������first*/
    {
        tail->next = NULL; /*������������һ���ڵ��nextӦ��ָ��NULL*/
    }
    L = first;
    return L;
}
PCBL_pointer SortSJF(PCBL_pointer L)
{
	PCBL_pointer first;     /*���к��������ı�ͷָ��*/
    PCBL_pointer tail;      /*���к��������ı�βָ��*/
    PCBL_pointer p_min;     /*������ֵ��С�Ľڵ��ǰ���ڵ��ָ��*/
    PCBL_pointer min;       /*�洢��С�ڵ�*/
    PCBL_pointer p;         /*��ǰ�ȽϵĽڵ�*/

    first = NULL;
    while (L != NULL) /*���������Ҽ�ֵ��С�Ľڵ㡣*/
    {
        /*ע�⣺����for����������ѡ������˼��ĵط�*/
        for (p=L,min=L; p->next!=NULL; p=p->next) /*ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣*/
        {
            if (p->next->data.ServerTime < min->data.ServerTime) /*�ҵ�һ���ȵ�ǰminС�Ľڵ㡣*/
            {
                p_min = p; /*�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p��*/
                min = p->next; /*�����ֵ��С�Ľڵ㡣*/
            }
        }

        /*����for�������󣬾�Ҫ�������£�
            һ�ǰ����������������У�
            ���Ǹ�����Ӧ�������жϣ��������뿪ԭ��������*/

        /*��һ����*/
        if (first == NULL) /*�����������Ŀǰ����һ��������*/
        {
            first = min; /*��һ���ҵ���ֵ��С�Ľڵ㡣*/
            tail = min; /*ע�⣺βָ������ָ������һ���ڵ㡣*/
        }
        else /*�����������Ѿ��нڵ�*/
        {
            tail->next = min; /*�Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������*/
            tail = min; /*βָ��ҲҪָ������*/
        }
        /*�ڶ�����*/
        if (min == L) /*����ҵ�����С�ڵ���ǵ�һ���ڵ�*/
        {
            //printf("��ͷ%d�Ѿ�����С����ǰ�����ơ�\n", min->data);
            L = L->next; /*��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK*/
        }
        else /*������ǵ�һ���ڵ�*/
        {
            p_min->next = min->next; /*ǰ����С�ڵ��nextָ��ǰmin��next,��������min�뿪��ԭ����*/
        }
    }
    if (first != NULL) /*ѭ�������õ���������first*/
    {
        tail->next = NULL; /*������������һ���ڵ��nextӦ��ָ��NULL*/
    }
    L = first;
    return L;
}
//��ͨ�������ҵ�����ʱ����̵���ҵ������ȷ���������ʱ��=����ʱ��+����ʱ�䣬Ȼ�������ڶ�����ҵ
//��������ʱ��ȵ�һ����ҵ�����ʱ���������ĵ���ʱ��+����ʱ��<��һ��ҵ�ĵ���ʱ�䣬��ʱ�������ʱ��=�Լ�����ʱ��+����ʱ��
//���򣬵����ĵ���ʱ��+����ʱ�䣨������С���ʱ��>��һ��ҵ�ĵ���ʱ��,�������ĵ���ʱ��<��һ��ҵ�����ʱ��,ֻ����������������ĵ���ʱ��+����ʱ��<
//��һ��ҵ���ʱ��ʱ����������ִ�е�һ��ҵ�� �������ʱ��Ӧ�õ������ĵ���ʱ��+��һ��ҵ����ʱ��+�Լ��ķ���ʱ�� 
	   	
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
		//���ʱ�䣬��תʱ�䣬��Ȩ��תʱ������
       if(p->data.ComeTime<FinishTime)
       {
           p->data.FinishTime=q->data.FinishTime+p->data.ServerTime; //����ý��̵���ʱ�����һ���̵����ʱ���� 
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
  	printf("�����������\n");
	scanf("%d",&m); 
    do
    {
        printf ("1---���������Ϣ(Insert)\n");
        printf ("2---��ѯһ������(Locate)\n");
        printf ("3---ɾ��һ������(Delete)\n");
        printf ("4---��ʾ���н���(Show)\n");
        printf ("5---���̵���\n");
        printf ("0---�˳�\n");
        printf("�����������\n");
        scanf ("%d",&i);
        switch(i)
        {
        case 1:
        	for(j = 0;j<m;j++)
            {
				printf("��������ҵ�ĵ���ʱ��,����ʱ��\n");
	            scanf("%d,%d",&x.ComeTime,&x.ServerTime);
	            x.ID=j;
	            if(x.ComeTime<0)
	            {
					printf("����ʱ�䲻��Ϊ����\n");
					break; 
	            } 
	            if(x.ServerTime<0)
	            {
					printf("����ʱ�䲻��Ϊ����\n");
					break; 
	            } 
	            Head=Push_PCB(Head,x);
	        
			}
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
        	
        	printf("������ѡ����㷨(FCFS,SJF,HRRN),ֻ�����һ����ĸ\n");
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
					printf("error������������\n");
					break;
			}
            break;
        
        case 0:
            break;
        default:
            printf("�����Ŵ���\n");
            break;
        }
    } while(i!=0);
    SetNull_PCBL(Head);

    return 0;
}
