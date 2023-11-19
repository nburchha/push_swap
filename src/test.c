/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburchha <nburchha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:25:48 by nburchha          #+#    #+#             */
/*   Updated: 2023/11/16 20:25:52 by nburchha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "../includes/push_swap.h"

// Function to print the content of a stack
void print_stack(const char *stack_name, t_node *stack) {
    printf("%s: ", stack_name);
    while (stack) {
        printf("%d ", *((int *)stack->content));
        stack = stack->next;
    }
    printf("\n");
}

// Function to test if the stacks are implemented correctly
void test_functions(t_node **stack_a, t_node **stack_b) {
    // Test SA
    printf("\nBefore SA:\n");
    print_stack("stack_a", *stack_a);
    sa(*stack_a);
    printf("\nAfter SA:\n");
    print_stack("stack_a", *stack_a);

    // Add assertions to check if the stacks are in the expected state
    // assert(/* Add your assertion here for SA */);

	// Example test for PB
    printf("\nBefore PB:\n- - - -\n");
    print_stack("stack_a", *stack_a);
    print_stack("stack_b", *stack_b);
    pb(stack_a, stack_b);
    printf("\nAfter PB:\n- - - -\n");
    print_stack("stack_a", *stack_a);
    print_stack("stack_b", *stack_b);
	pb(stack_a, stack_b);
    printf("\nAfter PB, 2nd time:\n- - - -\n");
    print_stack("stack_a", *stack_a);
    print_stack("stack_b", *stack_b);

    // Test SB
    printf("\nBefore SB:\n- - - -\n");
    print_stack("stack_b", *stack_b);
    sb(*stack_b);
    printf("\nAfter SB:\n- - - -\n");
    print_stack("stack_b", *stack_b);

    // Test RA
    printf("\nBefore RA:\n- - -\n");
    print_stack("stack_a", *stack_a);
    ra(stack_a);
    printf("After RA:\n- - -\n");
    print_stack("stack_a", *stack_a);

    // Add assertions to check if the stacks are in the expected state
    // assert(/* Add your assertion here for RA */);

    // Test RB
    printf("\nBefore RB:\n- - -\n");
    print_stack("stack_b", *stack_b);
    rb(stack_b);
    printf("\nAfter RB:\n- - -\n");
    print_stack("stack_b", *stack_b);

    // // Add assertions to check if the stacks are in the expected state
    // // assert(/* Add your assertion here for RB */);

    // Test RRA
    printf("\nBefore RRA:\n- - -\n");
    print_stack("stack_a", *stack_a);
    rra(stack_a);
    printf("\nAfter RRA:\n- - - -\n");
    print_stack("stack_a", *stack_a);

    // Add assertions to check if the stacks are in the expected state
    // assert(/* Add your assertion here for RRA */);

    // Test RRB
    printf("\nBefore RRB:\n- - - -\n");
    print_stack("stack_b", *stack_b);
    rrb(stack_b);
    printf("\nAfter RRB:\n- - - -\n");
    print_stack("stack_b", *stack_b);

    // Add assertions to check if the stacks are in the expected state
    // assert(/* Add your assertion here for RRB */);

    // Test RRR
    printf("\nBefore RRR:\n- - - -\n");
    print_stack("stack_a", *stack_a);
    print_stack("stack_b", *stack_b);
    rrr(stack_a, stack_b);
    printf("\nAfter RRR:\n- - - -\n");
    print_stack("stack_a", *stack_a);
    print_stack("stack_b", *stack_b);

    // Add assertions to check if the stacks are in the expected state
    // assert(/* Add your assertion here for RRR */);


	// Example test for PA
    printf("\nBefore PA:\n- - - -\n");
    print_stack("stack_a", *stack_a);
    print_stack("stack_b", *stack_b);
    pa(stack_a, stack_b);
    printf("\nAfter PA:\n- - - -\n");
    print_stack("stack_a", *stack_a);
    print_stack("stack_b", *stack_b);
	pa(stack_a, stack_b);
    printf("\nAfter PA, 2nd time:\n- - - -\n");
    print_stack("stack_a", *stack_a);
    print_stack("stack_b", *stack_b);


    // Add assertions to check if the stacks are in the expected state
    // assert(/* Add your assertion here for SB */);

    // Repeat the same pattern for other functions...


    // Add assertions to check if the stacks are in the expected state
    // assert(/* Add your assertion here for PB */);

    // Continue testing other functions...

    // printf("All tests passed!\n");
}
