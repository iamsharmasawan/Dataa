#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int arr[4], top = -1,n = 0;
void push();
void pop();
void peek();
void display();
void main()
{
int ch;
while(true){

printf("\n+++++OPERATIONS OF STACK+++++\n");
printf("\n1. PUSH\n");
printf("2. POP\n");
printf("3. PEEK\n");
printf("4. DISPLAY\n");
printf("5. EXIT\n");
printf("Enter your choice: \n");

scanf("%d",&ch);

switch(ch){
case 1:
push();
break;
case 2:
pop();
break;
case 3:
peek();
break;
case 4:
display();
break;
case 5:
exit(0);
break;
default:
printf("Please enter  valid option");
}
}
}
void push()
{int val;
if(top == 3){
printf("Stack is OVERFLOW");

}else{
printf("ENTER the value you want to add: \n");
scanf("%d",&val);
top++;
arr[top] = val;
display();
}
}
void pop(){
if(top == -1){
printf("STACK is UNDERFLOW");
}
else{
printf("Element Popped %d", arr[top]);
top--; 
}
}
void peek(){
if(top == -1){
printf("Stack is EMpty");
}
else{
printf("Element at top: %d", arr[top]); 
}
}
void display(){
if(top == -1){
printf("Stack is Empty");
}
else{
for(int i=top; i>=0; i--){
printf("%d",arr[i] );
printf(" ");
}
}
}

