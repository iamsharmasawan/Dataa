#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
struct node *prev;
};
struct node *head;

void insertatstart(data){
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	ptr->next = head->next;
	ptr->data = data;
	head->next->prev = ptr;
	head->next = ptr;
	ptr->prev = NULL;
	printf("\n%d is inserted",data);
      }
void display(){
	struct node *ptr = head->next;
	if(head->next == NULL){
		printf("\nThe list is empty");
		return;
	}
	printf("\nThe list is: \n");
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}

}
void insertatspecific(int pos, int data){

	struct node *ptr = head->next;
	struct node *p = (struct node*)malloc(sizeof(struct node));
	int i;
	if(pos>=checklength()){
	printf("The enetered index is greater than the length of the list");
	return;
	}
	if(pos == 0){
		insertatstart(data);
		return;
	 }
	for(i=1;i<pos;i++){
		ptr = ptr->next;
	}
	p->data = data;
	p->next = ptr->next;
	ptr->next->prev = p;
	ptr->next = p;
	p->prev = ptr;
	printf("\n%d is inserted",data);
}
void deleteatspecific(int pos){
	struct node *ptr = head->next;
	int i;
	if(pos>=checklength()){
		printf("\n The list size is lesser than the index specified");
		return;
	}
	for(i=1;i<=pos;i++){
		ptr = ptr->next;
	}
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	printf("\n%d is deleted",ptr->data);
	free(ptr);
}

int checklength(){
int count=0;
struct node *ptr = head;
while(ptr->next!=NULL)
{
 ptr = ptr->next;
 count++;
}
return count;
}
void main(){
	    int n,data,ch;
	    head->next = NULL;

	    while(1){
		printf("\nPeformed by Hiten Dusseja\n");
		printf("\n-------------------------------");
		printf("\n1.Display");
		printf("\n2.Add at specific");
		printf("\n3.Add at start");
		printf("\n4.Delete at specific");
		printf("\n5.Exit");
		printf("\nWhat do you want to do? : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			display();
			break;
			case 2:
			printf("\nEnter where do you wanna add and the data as well: ");
			scanf("%d %d",&n,&data);
			insertatspecific(n,data);
			break;
			case 3:
			printf("\nEnter the data: ");
			scanf("%d",&data);
			insertatstart(data);
			break;
			case 4:
			printf("\nEnter the index: ");
			scanf("%d",&n);
			deleteatspecific(n);
			break;
			case 5:
			exit(0);
			break;
			default:
			printf("Please enter a valid choice!");
			break;
		      }
	    }
	    display();
	    
}



