#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
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