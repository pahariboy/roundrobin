#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct node
{
    int info;
    int id;
    struct node *next;
    struct node *prev;
};
void print(struct node *start)
{
    struct node *ptr;
    ptr=start;
do
    {
        cout<<ptr->info<<" ";
        ptr=ptr->next;
    }    while(ptr!=start);
}
struct node* insertion(struct node *start)
{
    struct node *ptr,*start1,*n;
    ptr=start;
        n=new node;

        n->info=rand()%10;
       n->id=rand()%10;
        cout<<n->id<<"            "<<n->info<<endl;
       if(start==NULL)
        {
       start=n;
       start->prev=start;
       start->next=start;
       ptr=start;
        }
        else{
        ptr->next=n;
        n->next=start;
        n->prev=ptr;
        start->prev=n;
        ptr=ptr->next;
        }

    return start;
 }
  struct node* deletion(struct node *start)
  {
      struct node *ptr,*ptr1,*ptr2;
      if(start->next==start)
      {
       ptr2=NULL;
       delete (start);
      }
      else
        {
    ptr=start;
      ptr1=ptr->prev;
      ptr2=ptr->next;
      ptr1->next=ptr->next;
      ptr2->prev=ptr1;
      delete(ptr);
        }
     return ptr2;
  }

int** roundRobin(int quantum,int *s)
 {
struct node *ptr,*ptr1,*ptr2,*start;
int savedtime=0,totaltime=0,cpu,**arr,i,k=0;
srand(time(NULL));
cpu=rand()%50;
arr=new int*[cpu*2];
for(i=0;i<cpu*2;i++)
{
    arr[i]=new int[3];
}
cout<<"Cpu frequency is:- "<<cpu<<endl;
cout<<"Id"<<"     "<<"Burst time"<<endl;
start=NULL;
ptr=insertion(start);
while(ptr!=NULL && cpu>totaltime)
    {
        if(ptr->info>quantum)
        {

           ptr->info=ptr->info-quantum;
           arr[k][0]=ptr->id;
           totaltime=totaltime+quantum;
           arr[k][1]=totaltime;
           ptr=ptr->next;
           k++;
        }
        else
        {

           totaltime=totaltime+ptr->info;
           savedtime=savedtime+quantum-ptr->info;
            arr[k][0]=ptr->id;
           arr[k][1]=totaltime;
           k++;
        ptr=deletion(ptr);
        }
ptr=insertion(ptr);

        }
*s=k;
     cout<<"saved time is :- "<<savedtime<<endl;
     cout<<"total time is :- "<<totaltime<<endl;

return arr;
 }
int main()
{
int quantum;
static int k;
srand(time(NULL));
quantum=rand()%10;
cout<<"Random quantum is:-"<<" "<<quantum<<endl;
int **arr=roundRobin(quantum,&k);
cout<<"Gantt chart is:-"<<endl;
for(int i=0;i<k;i++)
{
    for(int j=0;j<2;j++){
    cout<<arr[i][j]<<" ";
}
cout<<endl;
}
}
