#include "get_next_line_bonus.h"

//Checks for some extra leaks that fsanitzeaddress won't.

// void	leak_test()
// {
// 	system("leaks a.out");
// }

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line1;
	char	*line2;
	char	*line3;
	int		a = 1;
	int		b = 1;
	int		c = 1;

	
	//atexit(leak_test);
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	while(line1)
	{
		printf("Line1[%d]:|%s|\n", a, line1);
		printf("\n");
		line1 = get_next_line(fd1);
	}
	while(line2)
	{
		printf("Line2[%d]:|%s|\n", b, line2);
		printf("\n");
		line2 = get_next_line(fd2);
		b++;
	}
	while(line3)
	{
		printf("Line3[%d]:|%s|\n", c, line3);
		printf("\n");
		line3 = get_next_line(fd3);
		c++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
}
