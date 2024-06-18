# Push Swap 42 Project

## Overview
Push Swap 42 is a sorting algorithm project at 42 school that involves sorting a stack of integers using a predefined set of operations with the goal of using as few operations as possible. This project focuses on algorithm optimization, understanding data structures (stacks), and efficient manipulation of data.

## Getting Started
To get started with Push Swap 42, follow these steps:

1. **Clone the repository:**
    ```bash
    git clone https://github.com/nburchha/push_swap/ push_swap
    cd push_swap
    ```

2. **Compile the project**:
    Initialize and update submodules and use `make` to compile the project:
    ```bash
    git submodule update --init
    make
    ```


3. **Generate a list of integers:**
You can generate a list of integers using various methods, such as:
- Manually creating a list in a file.
- Using a script to generate random integers within a specific range.

4. **Run the Push Swap program:**
    After compilation, you can run the program the generated integers:
    ```bash
    ./push_swap <list_of_integers>
    ```
5. **Optional: Check if the sorting is correct using the checker program:**
   ```bash
   ./push_swap <list_of_integers> | ./checker <list_of_integers>
   ```
   The checker program will read instructions from standard input. You can pipe the output of push_swap to the checker for validation.

## Operations
The Push Swap program uses the following operations to sort the stack:

- `sa`: swap a - swap the first 2 elements at the top of stack a.
- `sb`: swap b - swap the first 2 elements at the top of stack b.
- `ss`: sa and sb at the same time.
- `pa`: push a - take the first element at the top of b and put it at the top of a.
- `pb`: push b - take the first element at the top of a and put it at the top of b.
- `ra`: rotate a - shift up all elements of stack a by 1.
- `rb`: rotate b - shift up all elements of stack b by 1.
- `rr`: ra and rb at the same time.
- `rra`: reverse rotate a - shift down all elements of stack a by 1.
- `rrb`: reverse rotate b - shift down all elements of stack b by 1.
- `rrr`: rra and rrb at the same time.

## Example
Here's an example of how to use Push Swap:

```bash
$ ./push_swap 4 67 3 87 23
ra
ra
pb
ra
ra
pb
rra
pa
pa
```

This is an example of 100 numbers, sorting calculated by my Push Swap, visualized:

https://github.com/nburchha/push_swap/assets/67442077/8232b340-f100-4e51-84d6-ce467629049f



