/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:31:42 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/11 10:13:21 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;

	slen = ft_strlen(src);
	if (slen + 1 < dstsize)
		ft_memcpy(dst, src, slen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (slen);
}

/*#include <stdio.h>
#include <string.h>

// Function to run the tests
void run_tests() {
    char dest[20]; // Destination buffer for tests

    // Test 1: Normal case
    printf("Test 1: Normal case\n");
    char src1[] = "Hello, world!";
    size_t copied_length1 = ft_strlcpy(dest, src1, sizeof(dest));
    printf("Copied string: %s\n", dest);
    printf("Length of the source string copied: %zu\n\n", copied_length1);

    // Test 2: Source string is larger than destination buffer
    printf("Test 2: Source string is larger than destination buffer\n");
    char src2[] = "This is a longer string than destination";
    size_t copied_length2 = ft_strlcpy(dest, src2, sizeof(dest));
	printf("Copied string: %s\n", dest);
    printf("Length of the source string copied: %zu\n\n", copied_length2);
	size_t copystr = strlcpy(dest, src2, sizeof(dest));
    printf("Copied string: %s\n", dest);
    printf("Length of the source string copied: %zu\n\n", copystr);

    // Test 3: Destination buffer size is 0
	
    printf("Test 3: Destination buffer size is 0\n");
    char src3[] = "Hello, world!";
    size_t copied_length3 = ft_strlcpy(dest, src3, 0);
    printf("Copied string: %s\n", dest);
    printf("Length of the source string copied: %zu\n\n", copied_length3);

    // Test 4: Source string is empty
    printf("Test 4: Source string is empty\n");
    char src4[] = "";
    size_t copied_length4 = ft_strlcpy(dest, src4, sizeof(dest));
    printf("Copied string: %s\n", dest);
    printf("Length of the source string copied: %zu\n\n", copied_length4);

    // Test 5: Destination buffer is NULL
    printf("Test 5: Destination buffer is NULL\n");
    size_t copied_length5 = ft_strlcpy(NULL, "Hello, world!", 10);
    printf("Length of the source string copied: %zu\n\n", copied_length5);
}

int main() {
    run_tests();
    return 0;
}*/