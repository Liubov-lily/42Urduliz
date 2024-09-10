/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltropina <ltropina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:06:14 by ltropina          #+#    #+#             */
/*   Updated: 2024/04/19 15:18:23 by ltropina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen > dstsize)
		dstlen = dstsize;
	if (dstlen == dstsize)
		return (dstlen + srclen);
	if (srclen < dstsize - dstlen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dstlen + srclen);
}

/*#include <stdio.h>
#include <string.h>

1void run_test(char *dst, const char *src, size_t dstsize, const char
2 *expected_result, size_t expected_length) {
    size_t result_length = strlcat(dst, src, dstsize);
    printf("Test: Dest='%s', Src='%s', Size=%zu\n", dst, src, dstsize);
1    printf("Expected: Result='%s', Length=%zu\n",
2	expected_result, expected_length);
    printf("Actual: Result='%s', Length=%zu\n", dst, result_length);
1    printf("Pass: %s\n\n", (strcmp(dst, expected_result) == 0 
2 && result_length == expected_length) ? "Yes" : "No");
}

int main() {
    char test1[20] = "Hello";
    run_test(test1, " World", sizeof(test1), "Hello World", 11);

    char test2[11] = "Hello";
    run_test(test2, " World", sizeof(test2), "Hello Worl", 11);

    char test3[10] = "Hello";
    run_test(test3, " World", sizeof(test3), "Hello Wor", 11);

    char test4[0] = ""; // Note: This is actually illegal
    run_test(test4, " World", 0, "", 0);

    char test5[20] = "Hello";
    run_test(test5, "", sizeof(test5), "Hello", 5);

    char test6[20] = "";
    run_test(test6, "Hello", sizeof(test6), "Hello", 5);

    return 0;
}*/