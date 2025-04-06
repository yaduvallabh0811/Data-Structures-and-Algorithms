//A queue is an ordered list in which all insertions take place at one end rear while all the deletions take place on the other end called front.
// It works on First In First Out(FIFO).
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

void print_q();
void add_q(int);
int delete_q();
int queue[MAXSIZE];
int front = -1,rear= -1;
void adjust_q();
void main(void)
{
    add_q(8);
    add_q(12);
    add_q(62);
    print_q();
    delete_q();
    print_q();
    delete_q();
    print_q();
    add_q(67);
    print_q();
    delete_q();
    print_q();
    delete_q();
    print_q();
    delete_q();
    print_q();
    add_q(48);
    print_q();
    add_q(78);
    add_q(96);
    print_q();

}
void print_q()
{
    int i;
    if(front==rear)
        printf("There are no elements in the Q");
    else
        for(i=front+1;i<=rear;i++) printf("%d",queue[i]);
    printf("\n");

}
void add_q(int item)
{
    if(rear==MAXSIZE-1)
    if(front>=0)
    {
        adjust_q();
        queue[++rear]=item;
    }
    else
        printf("\nStack Full.Not Adding%d\n",item);
    else
        queue[++rear]=item;
}
int delete_q()
{
    if (rear == front)
    {
        printf("Queue is Empty\n");
        return(-1);
    }
    return queue[++front];
}
void adjust_q()
{
    int i,j;
    for(i=front+1,j=0;i<=rear;i++,j++)
        queue[j]=queue[i];
    rear = --j;
    front= -1;
}
