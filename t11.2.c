#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack{
    int data;
    struct stack* next;
}stack;
typedef struct Node {

    char string[30];
    struct stack *value;
    struct Node* next;
}cList;
void createStack (stack** top_ref){
    stack *tmp = *top_ref;
    do {
        if(!(*top_ref =(stack*)calloc(1, sizeof(stack)))) exit(0);
        puts("Enter value to the stack:");
        scanf("%d", &(*top_ref)->data);
        (*top_ref)->next = tmp;
        tmp = *top_ref;
        rewind(stdin);
    }while(getchar()!= 'n');
}
void newNode (stack** top_ref, int newData){
    stack *tmp = *top_ref;
    if(!(*top_ref =(stack*)calloc(1, sizeof(stack)))) exit(0);
    (*top_ref)->data = newData;
    (*top_ref)->next = tmp;
    tmp = *top_ref;
}
void output(stack*top_ref){
    do{
        printf("%d ", top_ref->data);
        top_ref = top_ref->next;
    }while (top_ref);
}
void createCircle (cList **last){
    cList *newNode, *firstPointer;
    if(*last == NULL)
    {
        *last = malloc(sizeof(cList));
        puts("Enter string:");
        gets((*last)->string);
        (*last)->value = NULL;
        createStack(&(*last)->value);
        (*last)->next = *last;
    }
    puts("More?");
    rewind(stdin);
    if(getchar() == 'y')
        do {
            newNode = (cList *) malloc(sizeof(cList));
            firstPointer = (*last)->next;
            (*last)->next = newNode;
            puts("Enter string:");
            rewind(stdin);
            gets(newNode->string);
            newNode->next = firstPointer;
            newNode->value = NULL;
            createStack(&newNode->value);
            puts("More?");
            rewind(stdin);
        }while(getchar() == 'y');
}
void outputCircle (cList *first){
    cList *temp = first;
    if(first != NULL){
        do{
            printf("%s\n", temp->string);
            output(temp->value);
            printf("\n");
            temp=temp->next;
        }while(temp!=first);
    }
}
void copy (stack** firs_top_ref, stack** second_top_ref){

    do{
        newNode(second_top_ref, (*firs_top_ref)->data);
        (*firs_top_ref) = (*firs_top_ref)->next;
    } while (*firs_top_ref);

}
cList* search (cList* first){
    if(first == NULL)
        exit(0);
    int sizeStr = strlen(first->string);
    cList *temp = first, *strPointer = NULL;
    do{
        if(sizeStr > strlen(temp->string)) {
            sizeStr = strlen(temp->string);
            strPointer = temp;
        }
        temp = temp->next;
    } while (temp!=first);
    return strPointer;
}
cList *delete (cList* last, cList* delete_pointer){
    cList *temp;
    temp = last;
    copy(&(delete_pointer->value), &(delete_pointer->next->value));
    while (temp->next != delete_pointer)
        temp = temp->next;
    temp->next = delete_pointer->next;
    free(delete_pointer);
    return temp;
}

int main(){
    cList *circle = NULL;
    createCircle(&circle);
    outputCircle(circle);
    circle = delete(circle, search(circle));
    puts("New circle");
    outputCircle(circle);
    return 0;
}