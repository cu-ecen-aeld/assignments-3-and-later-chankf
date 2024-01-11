/*
    writer.c
    assignment 2
    2024-01-02
        - can check no. of arguments
        - can write string to file
    2024-01-04
        - redirect messages as described in assignment instruction
        - convert errno to message descriptions
    2024-01-07
        - test make, makefile
        - test CROSS_COMPILE
        - corrected locations of arguments: argv[1]=filename, argv[2]=string

*/
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
    int fd;

    char *writestr;
    char *writefile;

    int len;
    ssize_t nr;

    openlog(NULL, 0, LOG_USER);

    if (argc <= 2)
    {
        printf("Error: Insufficient arguments.\n");
        printf("Usage: writer /path/to/file \"string to write\" \n");

        syslog(LOG_DEBUG, "Insufficient arguments! \nUsage: writer /path/to/file \"string\" ");

        exit (EXIT_FAILURE);
    }

    writefile = argv[1];
    writestr = argv[2];


    errno = 0;

    fd = creat(writefile, 0644);

    if (fsync (fd) == -1)
    {
        const int err = errno;

        syslog (LOG_DEBUG, "Cannot create file %s! System message: %s\n", writefile, strerror(err));
        exit (EXIT_FAILURE);

    } 
    else 
    {
        len = strlen(writestr);
        nr = write (fd, writestr, len);
        if (nr == -1)
        {
            const int err = errno;

            syslog (LOG_DEBUG, "Cannot write string %s to file %s! System message: %s\n", writestr, writefile, strerror(err));
            exit (EXIT_FAILURE);

        }

        if (close (fd) == -1) 
        {
            const int err = errno;

            syslog (LOG_DEBUG, "Error closing file %s! System message: %s\n", writefile, strerror(err));
            exit (EXIT_FAILURE);

        }

        exit (EXIT_SUCCESS);

    }

}
