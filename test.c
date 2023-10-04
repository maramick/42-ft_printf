#include <stdio.h>
#include <stdint.h>



int main() {
  int x = 10;
  int *p = &x;

  // Convert the pointer to uintptr_t
  uintptr_t address = (uintptr_t)p;

  // Print the address of x
  printf("The address of x is: 0x%lx\n", address);
  printf("The address of x is: %p", &x);

  return 0;
}

