#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int fd = 0;
	int flags = fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, flags | O_NONBLOCK);

	while (1)
	{
		int ret;
		char c;

		ret = read(0, &c, 1);
		if (ret == -1 && errno == EAGAIN)
		{
			printf("Try again\n");
		}
		else if (ret == -1)
		{
			printf("Error\n");
			break;
		}
		else if (ret == 0)
		{
			printf("Ret 0\n");
			break;
		}
		else
		{
			printf("Read: '%c'\n", c);
		}
		usleep(500000);
	}

}


