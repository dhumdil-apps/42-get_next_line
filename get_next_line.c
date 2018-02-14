#include "get_next_line.h"

static char		*ft_strcat_char(char *line, char c)
{
	size_t	i;
	size_t	len;
	char	*save;

	if (!line || !c)
	{
		return (NULL);
	}
	len = ft_strlen(line);
	save = ft_strnew(len + 1);
	if (!save)
	{
		return (NULL);
	}
	i = -1;
	while (++i < len)
		*(save + i) = *(line + i);
	*(save + i) = c;
	return (save);
}

static int		ft_fill_line(char **line, char *current_file_content, char c)
{
	int n;
	int i;
	int index;

	i = -1;
	while (current_file_content[++i])
		if (current_file_content[i] == c)
			break ;
	index = i;
	if (!(*line = ft_strnew(i)))
		return (0);
	n = 0;
	while (current_file_content[n] && n < i)
	{
		*line = ft_strcat_char(*line, current_file_content[n]);
		if (*line == NULL)
			return (0);
		n++;
	}
	return (index);
}

static t_list	*ft_current_file_fd(t_list **file, const int fd)
{
	t_list *save;

	save = *file;
	while (save)
	{
		if ((int)save->content_size == fd)
			return (save);
		save = save->next;
	}
	save = ft_lstnew("\0", fd);
	ft_lstadd(file, save);
	save = *file;
	return (save);
}

static int		ft_resolve(char *nline, int n, t_list *current_file, const int fd)
{
	while ((n = read(fd, nline, BUFF_SIZE)))
	{
		nline[n] = '\0';
		if (!(current_file->content = ft_strjoin(current_file->content, nline)))
			return (-1);
		if (ft_strchr(nline, '\n'))
			return (n);
	}
	return (n);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*current_file;
	char			nline[BUFF_SIZE + 1];
	int				return_value;
	int				i;

	return_value = 0;
	if (!line || read(fd, nline, 0) < 0 || fd < 0)
		return (-1);
	current_file = ft_current_file_fd(&file, fd);
	if (!(*line = ft_strnew(1)))
		return (-1);
	return_value = ft_resolve(nline, return_value, current_file, fd);
	if (return_value < BUFF_SIZE && !ft_strlen(current_file->content))
		return (0);
	else
	{
		i = ft_fill_line(line, current_file->content, '\n');
		if (i < (int)ft_strlen(current_file->content))
			current_file->content = current_file->content + i + 1;
		else
			ft_memset(current_file->content, '\0', ft_strlen(current_file->content));
	}
	return (1);
}
