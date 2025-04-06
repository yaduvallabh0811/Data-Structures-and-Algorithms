//Stack is a linear data structure.
// Follows Last In First Out(LIFO) principle.
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int *stack;

void print_stack();
void add_stack(int);
int delete_stack();
void stack_full(int*);
stack s;
int top =-1;

int main (void)
{
    int i,k;
    s=(stack)calloc(MAXSIZE,sizeof(int));
    if(s==NULL)
    {
        printf("No Allocation Possible\n");
        exit(0);
    }
    for(i=1;i<25;i++)
        add_stack(i);
    printf("\n");
    print_stack();
    for(i=1;i<25;i++)
    {
        k = delete_stack();
        printf("%d",k);

    }
}
void print_stack()
{
    int i;
    for(i=0;i<=top;i++)
        printf("%d",s[i]);
    printf("\n");
}
void add_stack(int item)
{
    static int size = MAXSIZE;
    if(top==size-1)
    {
        print_stack();
        fprintf(stderr,"\nreallocation Made\n");
        printf("\n Size before reallocation = %d",size);
        stack_full(&size);
        printf("\nSize after Reallocation=%d\n",size);
    }
    s[++top]=item;
}
int delete_stack()
{
    if(top < 0)
    {
        printf("\nFatal error trying to delete from Empty stack.");
        exit(1);
    }
    return s[top--];
}
void stack_full (int *size)
{
    stack t;
    int i, tsize;
    int add_size;

    printf("\nEnter the size to be added: ");
    scanf("%d", &add_size);

    tsize = *size;
    *size += add_size;

    t = (stack)calloc(*size, sizeof(int));
    if(t == NULL)
    {
        printf("No allocation Possible\n");
        exit(0);
    }

    for(i = 0; i < tsize; i++)
    {
        t[i] = s[i];
    }

    free(s);
    s = t;
}
