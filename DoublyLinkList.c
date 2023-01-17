#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node*prev; struct
node *next;
int data;
};
struct node *head;
void insertion_beginning();
void insertion_specified();
void deletion_beginning();
void display();
void main () {
int choice =0;
while(choice != 5) {
printf("\n1.Insert at begining\n2.Insert at specified location\n3.Delete at begining\n4.Display\n5.Exit\n");
printf("\nEnter your choice: \n");
scanf("\n%d",&choice);
switch(choice) {
case 1:
insertion_beginning();
break;
case 2:
insertion_specified();
break;
case 3:
deletion_beginning();
break;
case 4:
display();
break;
case 5:
exit(0);
break;
default:
printf("Please enter valid choice..");
}
}
system("pause");
}
void insertion_beginning() {
struct node *ptr;
int item;
ptr = (struct node *)malloc(sizeof(struct
node)); printf("\nEnter Item: ");
scanf("%d",&item);
if(head==NULL) {
ptr->next =
NULL;
ptr->prev=NULL;
ptr->data=item;
head=ptr;
}
else
{
ptr->data=item;
ptr->prev=NULL;
ptr->next = head;
head->prev=ptr;
head=ptr;
}
printf("\nNode inserted\n");
}
void insertion_specified() {
struct node *ptr,*temp;
int item,loc,i;
ptr = (struct node *)malloc(sizeof(struct node));
temp=head;
printf("Enter the location:");
scanf("%d",&loc);
for(i=0;i<loc;i++)
{
temp = temp->next;
if(temp == NULL)
{
printf("\n There are less than %d elements", loc);
return;
}
}
printf("Enter value");
scanf("%d",&item);
ptr->data = item;
ptr->next = temp->next;
ptr -> prev = temp;
temp->next = ptr;
temp->next->prev=ptr;
printf("\nNode inserted\n");
}
void deletion_beginning()
{
struct node *ptr;
if(head->next == NULL) {
head = NULL;
free(head);
printf("\nnode deleted\n");
}
else {
ptr = head;
head = head -> next;
head -> prev = NULL;
free(ptr);
printf("\nnode deleted\n");
}
}
void display()
{
struct node *ptr;
printf("\n printing values...\n"); ptr = head;
while(ptr != NULL) {
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}
