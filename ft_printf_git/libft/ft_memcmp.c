/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:15:16 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/16 15:33:12 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*us1 != *us2)
			return ((int)(*us1 - *us2));
		n--;
		us1++;
		us2++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

// Function to run tests
void run_tests() {
    // Test case 1: Identical memory blocks
    char str1[] = "Hello, World!\200";
    char str2[] = "Hello, World!\0";
    int result1 = ft_memcmp(str1, str2, strlen(str1));
    printf("Test case 1: Identical memory blocks - Result: %d\n", result1);

    // Test case 2: Different memory blocks
    char str3[] = "Hello, World!";
    char str4[] = "Bonjour, World!";
    int result2 = ft_memcmp(str3, str4, strlen(str3));
    printf("Test case 2: Different memory blocks - Result: %d\n", result2);

    // Test case 3: Blocks with different sizes but containing the same content
    char str5[] = "Hello, World!";
    char str6[] = "Hello, World";
    int result3 = ft_memcmp(str5, str6, strlen(str5));
    printf("diff sizes but same - Result: %d\n", result3);
}

int main() {
    run_tests();
    return 0;
}*/