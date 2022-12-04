# Dynamic Memory Allocation

Dynamic memory allocation is a technique for managing memory in a C program. It allows you to allocate memory for variables and data structures at runtime, rather than at compile time. This can be useful when you don't know how much memory you will need for your data until your program is running.

To use dynamic memory allocation in C, you can use the `malloc` function, which is defined in the `stdlib.h` header file. This function takes a single argument, which is the number of bytes of memory you want to allocate. It returns a pointer to the beginning of the allocated memory block.

For example, to allocate memory for an array of 10 integers, you can use the following code:

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Allocate memory for 10 integers
  int *arr = malloc(10 * sizeof(int));

  // Check if malloc failed
  if (arr == NULL) {
    printf("ERROR!");
    return - 1;
  }

  // Use the allocated memory

  // Free the allocated memory
  free(arr);

  return 0;
}
```

In this code, we use the `malloc` function to allocate memory for an array of 10 integers. We then check if the `malloc` call failed by checking if the returned pointer is `NULL`. If malloc failed, we print an error message and exit the program.

Once we have successfully allocated the memory, we can use it to store our data. In this example, we are not storing any data, but you can use the pointer returned by `malloc` to access and modify the allocated memory block just like you would with any other array.

When you are done using the allocated memory, you should free it using the free function. This function takes a single argument, which is a pointer to the beginning of the memory block you want to `free`. In our example, we pass the pointer returned by `malloc` to the `free` function to free the memory we allocated earlier.

It is important to always free any memory you allocate with `malloc` when you are done using it. This will prevent memory leaks and ensure that your program uses memory efficiently.

In summary, to use dynamic memory allocation in C, you can use the `malloc` and `free` functions. `malloc` allocates a block of memory of the specified size, and returns a pointer to the beginning of the block. You can use this pointer to access and modify the allocated memory. When you are done using the allocated memory, you should free it using the `free` function. This will prevent memory leaks and ensure that your program uses memory efficiently.
