/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:13:26 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/16 14:21:36 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}

/*#include <stdio.h>
#include <stdlib.h>
 #include <string.h>
// Function to run tests
void run_tests() {
    // Test case 1: Allocate memory for 1 element of size 0
    void *result1 = ft_calloc(1, 0);
    printf("Test case 1: calloc(1, 0) - Result: %p\n", result1);
    free(result1); // Free the allocated memory

    // Test case 2: Allocate memory for 0 elements of size 1
    void *result2 = ft_calloc(0, 1);
    printf("Test case 2: calloc(0, 1) - Result: %p\n", result2);
    free(result2); // Free the allocated memory

    // Test case 3: Allocate memory for 3 elements of size 4
    //size_t size3 = 1 * sizeof(int);
    void *result3 = ft_calloc(1, sizeof(int));
    printf("Test case 3: calloc(1, sizeof(int)) - Result: %p\n", result3);
    // Check if memory is initialized to zero
    if (*(char *)result3 == '\0') {
        printf("Memory successfully initialized to zero.\n");
    } else {
        printf("Memory initialization failed.\n");
    }
    free(result3); // Free the allocated memory
}

int main() {
    run_tests();
    return 0;
}*/