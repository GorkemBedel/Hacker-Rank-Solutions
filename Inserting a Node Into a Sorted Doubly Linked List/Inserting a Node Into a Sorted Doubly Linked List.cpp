#include <bits/stdc++.h>
using namespace std;


/* 
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 */

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode *head = llist;
    DoublyLinkedListNode *newnode = new DoublyLinkedListNode(data);
    newnode -> next = NULL;
    newnode -> prev = NULL;
    while(head -> next != NULL && head -> data < data){
        head = head -> next;
    }
   
    if(head -> next == NULL && head->data < data){
        head -> next = newnode;
        newnode -> prev = head;
        return llist;

    }
    if(head -> next == NULL && head->data > data){
        DoublyLinkedListNode *prev = head -> prev; //4
        prev -> next = newnode;
        newnode -> prev = prev;
        newnode -> next = head;
        head -> prev = newnode;
        return llist;
        
    }
    if(head -> prev == NULL){
        newnode -> next = head;
        head -> prev = newnode;
        head = newnode;
        return head;
    }
    DoublyLinkedListNode *prev = head -> prev;
    prev -> next = newnode;
    newnode -> prev = prev;
    newnode -> next = head;
    head -> prev = newnode;
    return llist;
    
}
