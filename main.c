#include "get_next_line_bonus.h"

//Checks for some extra leaks that fsanitzeaddress won't.

// void	leak_test()
// {
// 	system("leaks a.out");
// }

int	main(void)
{
	int		fd;
	char	*line;
	int		i = 1;
	
	// atexit(leak_test);
	fd = open("test1.txt", O_RDONLY);
	// fd = 20;
	line = get_next_line(fd);
	while(line)
	{
		line = get_next_line(fd);
		printf("Line[%d]|%s|\n", i, line);
		printf("\n");
		i++;
	}
	close(fd);
}