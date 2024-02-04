#include <stdio.h>

int main() {
	typedef int ElementType;
	
	typedef struct _Node {
		ElementType Data;
		struct _Node *nextData; 
	} Node_t;

	printf("sizeof(int): %lu\n", sizeof(int));
	printf("sizeof(Node): %lu\n", sizeof(Node_t));
	printf("sizeof(Node*): %lu\n", sizeof(Node_t*));

	return 0;
}
