#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>  //del
#include <string.h>  //del
#include <stdlib.h>  //del

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

#endif
