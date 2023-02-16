#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

void test_push_and_pop() 
{
  struct Stack stack;
  initStack(&stack);
//test pushing -1
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);

  int poppedValue = pop(&stack);
  assert(poppedValue == 3);

  poppedValue = pop(&stack);
  assert(poppedValue == 2);

  poppedValue = pop(&stack);
  assert(poppedValue == 1);

  poppedValue = pop(&stack);
  assert(poppedValue == -1);
}

int main() {
  test_push_and_pop();
  printf("All tests passed.\n");
  return 0;
}
