#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct _Node {
	ElementType Data;
	struct _Node *NextItem;
} Node_t;

Node_t* SLL_CreateNode(ElementType data) {
	Node_t *NewNode = (Node_t *)malloc(sizeof(Node_t));
	
	NewNode->Data = data;
	NewNode->NextItem = NULL;

	return NewNode;
}

void SLL_DeleteNode(Node_t *node) {
	free(node);
}

void SLL_AppendNode(Node_t** head, Node_t** new) {
	Node_t *tail;
	
	if(*head == NULL || *new == NULL) {
		fprintf(stderr, "NULL ptr is passed in append\n");
		return;
	}

	// find the tail node
	tail = *head;
	while((tail->NextItem) != NULL) {
		tail = tail->NextItem;	
	}

	tail->NextItem = *new;
	return;
}

int main() {
	Node_t *tmp, *head = SLL_CreateNode(0), *new = SLL_CreateNode(1);
	SLL_AppendNode(&head, &new);

	tmp = head;	
	while(tmp->NextItem != NULL) {
		printf("data: %d\n", tmp->Data);
		tmp = tmp->NextItem;
	}	

	printf("data: %d\n", tmp->Data);

	SLL_DeleteNode(head);
	SLL_DeleteNode(new);

	return 0;
}
