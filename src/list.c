#include <stdio.h>  /*printf*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

typedef struct node {
  int data;
  struct node *next;
} node;

void add(node *head, int x){
  /*pre: head points to the first, empty element. The last element's next is NULL
    post: a new node containing x is added to the end of the list*/
  assert(head!=NULL);
  node *p = head;
  while (p->next!=NULL) {
    p = p->next;
  } /*p points to the last element*/
  node *element = (node*) malloc(sizeof(node));
  element->next = NULL;
  element->data = x;
  p->next = element; 
}

int size(node *head){
    // Excercise 3b)
    // Først tjekker jeg at mit head ikke er null, altså at der er "rigtige" elementer
    assert(head!=NULL);
    //Dernæst definerer jeg en pointer p, som peger på head i en node.
    node *p = head;

    //Her definerer jeg en variabel, som skal agere counter. 
    int size = 0;

    //Jeg laver nu en while løkke, som skal køre så længe p->next != NULL. Altså det skal gerne køre til det sidste element i rækken. 
    //For hver runde lægger jeg en til size. Dermed kan jeg tælle antallet af elementer i arrayet. 
    while (p->next!= NULL) {
      size++; 
      //Jeg opdaterer pointeren til at være det som pointeren peger på. Dermed kommer jeg et element frem i rækken.  
      p = p->next;
    }
    //Her er min gennemkørsel færdig og jeg kan returne size. 
    return size;
}

void printout(node *head) {
  /*Excercise 3d) Implement your changes.. 
    pre: head points to the first, empty element. The last element's next is NULL
    post: the values of the list are printed out*/
    
    //Her sørger jeg for at mine preconditions holder. At det sidste elements next er NULL, "tjekkes" af min while løkke længere nede. 
    assert(head != NULL);

    //Jeg definerer en pointer p til at pege på heads next. Altså på det første "rigtige" element. 
    node *p = head->next;

    //Her kører en while løkke så længe p != NULL altså skal den gerne køre indtil sidste element i rækken. 
    while (p!=NULL){
      //For hver gennemgang printer jeg p->data. og opdaterer p til at være p->next. Dermed kommer jeg til næste element i rækken. 
      printf("%d, ",p->data);
      p = p->next;
    }
    printf("\n");
}

int largest(node *head){
    /*Excercise 3e) Add your code below.
      pre: head points to the first, empty element. The last element's next is NULL. size(head>0)
      post: returns the largest value of the list*/
      
    //Igen tjekkes mine preconditions med en assert. Her tjekker jeg at head != NULL og at størrelsen af head > 0. 
    assert(head!=NULL && size(head)>0);

    //Her definerer jeg en pointer til at pege på heads -> next. Altså det første "rigtige" element i rækken. 
    node *p = head -> next;

    //Jeg laver en variabel, som skal være min største værdi i rækken. I starten må det være det første rigtige elements værdi. 
    int largest = p->data;

    //Her laver jeg en while, som skal køre så længe p != NULL. Altså så længe next i structen ikke er NULL. 
    while (p != NULL) {

      //Hvis data i gennemgangen er større end largest, så gemmer jeg den værdi, som den nye largest. 
      if(p->data > largest) {
        largest = p->data;
      }

      //Her opdaterer jeg p, så vi kommer igennem rækken af elementer. 
      p = p -> next; 
    }

    return largest; 
}

