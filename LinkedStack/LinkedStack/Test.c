#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

int main() {

	HSTACK hStack;
	int i;
	DATATYPE val;

	if ((hStack = CreateStack()) == NULL) {
		fprintf(stderr, "cannot create stack!\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 10; ++i)
		Push(hStack, i);

	while (!IsEmptyStack(hStack)) {
		PopSecure(hStack, &val);
		printf("%d ", val);
	}

	printf("\n");

	ClearStack(hStack);

	for (i = 0; "ankara"[i] != '\0'; ++i)
		Push(hStack, "ankara"[i]);

	while (!IsEmptyStack(hStack))
		putchar(Pop(hStack));

	printf("\n");

	CloseStack(hStack);

	return 0;
}