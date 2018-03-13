#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud
{
    int num;
    struct stud *next;
};

struct stud *Creat_List ();
void Print_List (struct stud *head);
struct stud *Insert_List (struct stud *head, int pos);
struct stud *Delete_List (struct stud *head, int pos);
struct stud *Order_List (struct stud *head);
struct stud *Merge_List (struct stud *La, struct stud *Lb);

int main ()
{
    struct stud *La, *Lb, *Lc;
    La = Creat_List ();
    Lb = Creat_List ();
//    Print_List(La);
//    Print_List(Lb);
    Lc = Merge_List(La, Lb);
    Print_List(Lc);
    return 0;
}

struct stud *Creat_List ()
{
    struct stud *head, *tail, *ptr;
    int num, size;
    size = sizeof(struct stud);
    head = tail = NULL;
    printf("Enter values:\n");
    scanf("%d", &num);
    while(num != 0)
    {
        ptr = (struct stud *)malloc(size);
        ptr->num = num;
        ptr->next = NULL;
        if(head == NULL)
        {
            head = ptr;
        }
        else
        {
            tail->next = ptr;
        }
        tail = ptr;
        scanf("%d", &num);
    }
    return head;
}

void Print_List (struct stud *head)
{
    struct stud *ptr;
    ptr = head;
    if(head == NULL)
    {
        printf("error!\n");
        return;
    }
    printf("Result:\n");
    for(ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%d\n", ptr->num);
    }
}

struct stud *Insert_List (struct stud *head, int pos)
{
    struct stud *ptr, *p;
    int i = 1, num;
    ptr = head;
    if(head == NULL)
    {
        printf("Error!\n");
        exit(-1);
    }
    while(i < pos-1)
    {
        ptr = ptr->next;
        i++;
    }
    p = (struct stud *)malloc(sizeof(struct stud));
    printf("Enter Insert Value:\n");
    scanf("%d", &num);
    p->num = num;
    p->next = ptr->next;
    ptr->next = p;
    return head;
}

struct stud *Delete_List (struct stud *head, int pos)
{
   struct stud *ptr, *p;
   int i = 1;
   ptr = head;
   if(head == NULL)
   {
       printf("Error!\n");
       exit(-1);
   }
   while(i < pos-1)
   {
       ptr = ptr->next;
       i++;
   }
   p = ptr->next;
   ptr->next = p->next;
   free(p);
   p = NULL;
   return head;
}

struct stud *Order_List (struct stud *head)
{
    struct stud *ptr, *p;
    int i, j, temp;
    for(i = 0; i < 5; i++)
    {
        ptr = head;
        p = ptr->next;
        for(j = 0; j < 4-i; j++)
        {
            if(ptr->num > p->num)
            {
                temp = ptr->num;
                ptr->num = p->num;
                p->num = temp;
            }
            ptr = ptr->next;
            p = ptr->next;
        }
    }
    return head;
}

struct stud *Merge_List (struct stud *La, struct stud *Lb)
{
    struct stud *Lc, *pa, *pb, *pc;
    Lc = NULL;
    pa = La;
    pb = Lb;
    while(pa && pb)
    {
        if(pa->num < pb->num)
        {
            if(Lc == NULL)
            {
                Lc = pa;
                pc = Lc;
            }
            else
            {
                pc->next = pa;
                pc = pa;
            }
            pa = pa->next;
        }
        else
        {
            if(Lc == NULL)
            {
                Lc = pb;
                pc = Lc;
            }
            else
            {
                pc->next = pb;
                pc = pb;
            }
            pb = pb->next;
        }
    }
    pc->next = pa?pa:pb;
    free(Lb);
    return Lc;
}
