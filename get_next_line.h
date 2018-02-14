#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 16

int	get_next_line(const int fd, char **line);

#endif
