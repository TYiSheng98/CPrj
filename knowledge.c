/*
 * ICT1002 Assignment 2, 2018-19 Trimester 2.
 *
 * This file implements the chatbot's knowledge base.
 *
 * knowledge_get() retrieves the response to a question.
 * knowledge_put() inserts a new response to a question.
 * knowledge_read() reads the knowledge base from a file.
 * knowledge_reset() erases all of the knowledge.
 * kowledge_write() saves the knowledge base in a file.
 *
 * You may add helper functions as necessary.
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chat1002.h"

typedef struct node_struct {
	char intent[MAX_INTENT];
	char entity[MAX_ENTITY];
	char response[MAX_RESPONSE];
	struct node_struct *next;
} Node;
Node *search_list(Node *head,const char userintent[],const char userentity[]);
Node *create_node(const char *intent,const char entity[],const char response[]);
Node *insert_at_head(Node *head, Node *new_node);
//Node *insert_at_tail(Node *head, Node *new_node);
//Node *delete_node(Node *head, Node *node_ptr);
Node *print_list(Node *head, const char *text);
Node *free_list(Node *head);
Node *head = NULL;
Node *new_node;
Node *temp;
/*
 * Get the response to a question.
 *
 * Input:
 *   intent   - the question word
 *   entity   - the entity
 *   response - a buffer to receive the response
 *   n        - the maximum number of characters to write to the response buffer
 *
 * Returns:
 *   KB_OK, if a response was found for the intent and entity (the response is copied to the response buffer)
 *   KB_NOTFOUND, if no response could be found
 *   KB_INVALID, if 'intent' is not a recognised question word
 */
int knowledge_get(const char *intent, const char *entity, char *response, int n) {
	
	/* to be implemented */

	temp = search_list(head, intent,entity);
//printf("Node %d found at %p\n", 200, temp);
if(temp== NULL){
	return KB_NOTFOUND;
}
else{
	response= temp->response;
	return KB_OK;
}
//	if( compare_token(entity,"SIT")==0){
//		char ans[MAX_RESPONSE] ="SIT is an autonomous university in Singapore.";
//		int i=0;
//		while(ans[i]!= 0){
//			response[i]= ans[i];
////			printf("%c",response[i]);
//			i++;
//		}
//		response[i]=0;
//		return  KB_OK;
//	}
//	else {
//
//		return KB_NOTFOUND;
	}
	
//}


/*
 * Insert a new response to a question. If a response already exists for the
 * given intent and entity, it will be overwritten. Otherwise, it will be added
 * to the knowledge base.
 *
 * Input:
 *   intent    - the question word
 *   entity    - the entity
 *   response  - the response for this question and entity
 *
 * Returns:
 *   KB_FOUND, if successful
 *   KB_NOMEM, if there was a memory allocation failure
 *   KB_INVALID, if the intent is not a valid question word
 */
int knowledge_put(const char *intent, const char *entity, const char *response) {
	
	/* to be implemented */
	if(!(compare_token(intent,"what") == 0 || compare_token(intent,"where") == 0 || compare_token(intent,"who") == 0)){
		return  KB_INVALID;
	}
	else {
		new_node = create_node(intent, entity, response);
		if (new_node == NULL) {
			return KB_NOMEM;
		} else {
			head = insert_at_head(head, new_node);
			print_list(head, "After one node");
			return 0;
		}
	}
//	return KB_INVALID;
	
}


/*
 * Read a knowledge base from a file.
 *
 * Input:
 *   f - the file
 *
 * Returns: the number of entity/response pairs successful read from the file
 */
int knowledge_read(FILE *f) {
	
	/* to be implemented */
	
	return 0;
}


/*
 * Reset the knowledge base, removing all know entitities from all intents.
 */
void knowledge_reset() {
	
	/* to be implemented */
	head = free_list(head);
	print_list(head, "After freeing the list");
}


/*
 * Write the knowledge base to a file.
 *
 * Input:
 *   f - the file
 */
void knowledge_write(FILE *f) {
	
	/* to be implemented */
	
}

///* add one node */
//new_node = create_node(100);
//head = insert_at_head(head, new_node);
//print_list(head, "After one node");
///* search for node 200 */
//temp = search_list(head, 200);
//printf("Node %d found at %p\n", 200, temp);
//head = free_list(head);
//print_list(head, "After freeing the list");
//return 0;

/* create a new node; returns NULL if there is not enough memory */
Node *create_node(const char *intent,const char *entity,const char *response) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL) {
		strcpy(new_node->intent,intent);
		strcpy(new_node->entity,entity);
		strcpy(new_node->response,response);

		new_node->next = NULL;
	}
	return new_node;
}

/* search for the node containing the target value */
Node *search_list(Node *head,const char *userintent,const char *userentity) {
	Node *temp = head;
	while (temp != NULL && temp->intent != userintent && temp->entity != userentity)
		temp = temp->next;
	return temp;
}

/* insert a node at the head of the list */
Node *insert_at_head(Node *head, Node *new_node) {
	new_node->next = head;
	return new_node;
}

//Node *insert_at_tail(Node *head, Node *new_node) {
//	if (head == NULL) {
//		return new_node;
//	}
//	Node *temp = head;
//	while (temp->next != NULL)
//		temp = temp->next;
//	temp->next = new_node;
//	return head;
//}
//
///* delete the node indicated by node_ptr */
//Node *delete_node(Node *head, Node *node_ptr) {
//	if (head == NULL) { //if head is NULL
//		return NULL;
//	}
//
//	if (head == node_ptr) { //if head is the targeted node to change
//		head = head->next; //get head's nxt & return 'new head'
//		free(node_ptr);
//		return head;
//	}
//
//	Node *prev_ptr = head;
//	while (prev_ptr->next != NULL && prev_ptr->next != node_ptr) {
//		prev_ptr = prev_ptr->next;
//	}
//	if (prev_ptr->next == NULL) {
//		return head;
//	} else {
//		prev_ptr->next = node_ptr->next;
//		free(node_ptr);
//	}
//	return head;
//}
//
/* print out ever elment in the list */
Node *print_list(Node *head, const char *text) {
	printf("%s: ", text);
	Node *temp = head;
	while (temp != NULL) {
		printf("Intent:%c ", temp->intent);
		printf("Entity:%c ", temp->entity);
		printf("Response:%c ", temp->response);
		temp = temp->next;
	}
	printf("\n");
	return head;
}

/* de-allocate list */
Node *free_list(Node *head) {
	Node *temp = head;

	while (temp != NULL) {
		temp = temp->next;
		free(head);
		head = temp;
	}
	return NULL;
}