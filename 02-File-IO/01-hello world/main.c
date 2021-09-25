#include <sys/types.h>  // open();
#include <sys/stat.h>   // open();
#include <fcntl.h>      // open();
#include <unistd.h>     // read();
#include <errno.h>      // errno;
#include <stdio.h>      // perror();

int main(void)
{
    int fd;
    int len = 100;
    int ret;
    char user_buf[100];
    char *buf = user_buf;

    fd = open("./test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Open");
    }

    while (len != 0 && (ret = read(fd, buf, len) != 0)) {
        if (ret == -1) {
            if (errno == EINTR) {
                continue;
            }
            perror("Read");
            break;
        }
        len -= ret;
        buf += ret;
    }
    puts(user_buf);
    return 0;
}
