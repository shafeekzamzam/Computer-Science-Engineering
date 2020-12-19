/******************************************

  Application: Linked List Example
  Compiled on: Borland Turbo C++ 3.0
  Programmer: Geetika Mukhi

******************************************/

#include <stdio.h>
#include <conio.h>

/* Structure for nodes of linked list*/
struct listnode {
int value;
struct listnode * next;
};
typedef struct listnode node;

node * first,*save,*current;
node * getnode();

void InsertAtStart(int x);
void InsertAtEnd(int x);
void InsertInMid(int n_no,int x);
int DeleteNode(int kv);
node * FindNode(int kv);
void ReverseList();
void SortList();
void ClearList();
void ShowList();
int CountNodes();

void main()
{
int choice,nodeValue,insertPos;
first = NULL;
do
{
clrscr();

printf("\n1.  Insert a Value at the Start");
printf("\n2.  Show the Linked List");
printf("\n3.  Insert a Value at the End");
printf("\n4.  Clear Linked List");
printf("\n5.  Show the Number of Nodes in the Linked List");
printf("\n6.  Insert the Value After Mentioned Node");
printf("\n7.  Delete a Node of Linked List");
printf("\n8.  Search a Node of Linked List");
printf("\n9.  Sort the Linked List");
printf("\n10. Reverse the Linked List");
printf("\n0.  Close the application");

printf("\n\nPlease Enter Your Choice\n");

scanf("%d",&choice);

switch (choice)
{
	case 1:
	     printf("\nEnter The Node Value To Be Inserted At The Start: \n");
      	     scanf("%d",&nodeValue);
             InsertAtStart(nodeValue);
             break;

	case 2:
	     ShowList();
      	     break;

	case 3:
 	     printf("\nEnter The Node Value To Be Inserted At The End: \n");
	     scanf("%d",&nodeValue);
             InsertAtEnd(nodeValue);
             break;

	case 4:
	     ClearList();
      	     break;

	case 5:
	     printf("\n%d Nodes are available in the Linked List",CountNodes());
	     getch();
	     break;

	case 6:
	     printf("\nEnter The Position after which you"
	       " want to Insert the new value: \n");
	     scanf("%d",&insertPos);
	     if ( insertPos > CountNodes())
	     {
	        printf(" Node at position %d cannot be inserted. There are only"
	        " %d node(s) in the list",insertPos,CountNodes());
	        getch();
	     }
	     else
	     {
	        printf("\nEnter The Value To Be Inserted after %d node(s): \n",insertPos);
	        scanf("%d",&nodeValue);
	        InsertInMid(insertPos,nodeValue);
	     }
	     break;

	case 7:
	     printf("\nEnter The Node Value To Be Deleted: \n");
	     scanf("%d",&nodeValue);
	     DeleteNode(nodeValue);
	     break;

	case 8:
	     printf("\nEnter The Node Value To Be Searched: \n");
	     scanf("%d",&nodeValue);
	     FindNode(nodeValue);
	     break;

	case 9:
	     SortList();
	     break;

	case 10:
	     ReverseList();
	     break;

}
}
while (choice!=0);

}

/* This function reverses the sequences of nodes in the linked list*/
void ReverseList()
{
 node *temp;
 current = save = first;
 if (first == NULL)
 {
  printf("\a\nThere are no nodes in the Linked List.\n");
  getch();
 }
 else
 {
  save = NULL;
  while (current != NULL)
  {
   temp = save;
   save = current;
   current = current->next;
   save->next = temp;
  }
  first = save;
  printf("\nThe Linked List Has Been Reversed.\n");
  getch();
 }
}

/* This function will sort the linked list*/
void SortList()
{
 int temp;
 current = save = first;
 if (first==NULL)
 {
  printf("\aThere are no nodes in the Linked List.\n");
  getch();
  }
  else
  {
   for (current=first;(current != NULL);current=current->next)
   {
       for (save=current->next;(save != NULL);save=save->next)
       {
        if ( current->value < save->value )
        {
	 temp = save->value;
	 save->value = current->value;
	 current->value = temp;
	}
      }
   }

   printf("\nThe Linked List Has Been Sorted.\n");
   getch();
   }
}

/* This function searches for a particular node value in the linked list*/
node * FindNode(int nValue)
{
 current = first;
 if (first == NULL)
 {
  printf("\a\nThere are no nodes in the Linked List.");
  getch();
 }
 else
 {
  while ( (current != NULL) && (current->value != nValue) )
  current = current->next;
  if (current->value == nValue)
  {
   printf("\nThe Node is available in the Linked List.\n");
   getch();
   return(current);
  }
  else
  printf("\nThe Node is not available in the Linked List. Please try again.\n");

 getch();
 }
}

/* This function deletes a node from the linked list*/
int DeleteNode(int nValue)
{
 int undel;
 current = first;
 if (first == NULL)
 {
  printf("\a\nThere are no nodes in the Linked List.");
  getch();
  }
  else
  {
    while ( (current != NULL) && (current->value != nValue) )
    {
     save = current;
     current = current->next;
    }
    if (current->value == nValue)
    {
      if (current == first)
      {
        undel = current->value;
        current = current->next;
        free(first);
        first = current;
      }
      else
      {
        undel = current->value;
        save->next = current->next;
        free(current);
      }

    printf("Node with Value %d has been Deleted.",nValue);
    getch();
    return(undel);
   }
   else
     printf("Node with value %d is not available in the Linked List. Please try again.",nValue);

  getch();
  }
}

/* This function inserts a node in the middle of the linked list*/
void InsertInMid(int nPos,int nValue)
{
 int count=0;
 node *temp;
 temp = getnode();
 temp->value = nValue;
 temp->next = NULL;
 current = first;
 while (count < nPos )
 {
  save = current;
  current = current->next;
  count++;
  }

  if (first == NULL) first = temp;
  else if (current == first)
  {
   temp->next = current;
   first = temp;
   }
   else
   {
    temp->next = save->next;
    save->next = temp;
   }
}

/* This function returns the node*/
node * getnode()
{
 node * temp;
 temp = (node *) malloc(sizeof(node));
 if (temp == NULL)
 {
  printf("\nProblem in allocating memory to the node.!\n");
  exit(1);
  }
  else
  return(temp);
  }

/* This function calculates the number of nodes contained in the linked list*/
int CountNodes()
{
 int count=0;
 current = first;
 while (current != NULL)
 {
  count++;
  current = current->next;
  }
  return(count);

}

/* This function inserts a node at the start of the linked list*/
void InsertAtStart(int nValue)
{
 node *temp;
 temp = getnode();
 temp->value = nValue;
 temp->next = NULL;
 if (first == NULL)
    first = temp;
 else
 {
  temp->next = first;
  first = temp;
  }
}

/* This function inserts a node at the end of the linked list*/
void InsertAtEnd(int nValue)
{
 node *temp;
 temp = getnode();
 temp->value = nValue;
 temp->next = NULL;
 if (first == NULL)
    first = temp;
 else
 {
  current = first;
  while (current != NULL)
  {
   save = current;
   current = current->next;
   }
   save->next = temp;
   }
}

/* This function shows all the data contained in the linked list*/
void ShowList()
{
 clrscr();
 current = first;
 if (current == NULL)
    printf("\aThere are no nodes in the Linked List.\n");
 while (current != NULL)
 {
  printf("\n%d",current->value);
  current = current->next;
  }
  getch();
}

/* This function clears all data from the linked list*/
void ClearList()
{
 current = first;
 while (current != NULL)
 {
  current = current->next;
  free(first);
  first = current;
  }
  printf("\nLinked List has been cleared.\n");
  getch();
}
