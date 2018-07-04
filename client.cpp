// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;
 
int main()
{
 
    std::cout << "Client starting.." << std::endl;
    int BUF_SIZE = 4;
    int fd1;

    // FIFO file path
    std::string sin = "/tmp/queryfifoin";
    std::string sout = "/tmp/queryfifoout";
    char *fifosin = (char *)sin.c_str();
    char *fifosout = (char *)sout.c_str();
 
    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    // mkfifo(fifosout, 0666);
 
    char str1[4], str2[4];
    while (1)
    {
        
        // // START
        // std::string s;
        // char * sc;
        // std::cin >> s;
        // // Open FIFO for write only
        // fd1 = open(fifosin, O_WRONLY);
        // std::cout << fd1;

        // // std::cout << s;
        // sc = (char *)s.c_str();
        // int i, j = 0;
        // for(i = 0; sc[ i ]; i++)
        // {
        //     str1[i%4] = sc[i];
        //     std::cout << "i is " << i << "sc is " << sc[i] << std::endl;
        //     if (i%4 == 3 && i != 0) 
        //     {
        //         std::cout << "arr1 is " << str1 << std::endl;
        //         int status = write(fd1, str1, strlen(str1));
        //         std::cout << "write status " << status << std::endl;
        //         // arr1 = new char[4];
        //         memset(str1, 0, sizeof(str1));
        //     }
        //     // printf("%c", sc[ i ]);
        // }
        // std::cout << "i is " << i << std::endl;
        // if(i%4 < 4 && i%4 != 0)
        // {
        //     std::cout << "arr1 is " << str1 << std::endl;
        //     int status = write(fd1, str1, strlen(str1));
        //     std::cout << "write status " << status << std::endl;
        // }

        // close(fd1);
        // END
 
        // Take an input arr2ing from user.
        // 80 is maximum length
        // fgets(arr2, 80, stdin);
 
        // Write the input arr2ing on FIFO
        // and close it
        // write(fd, arr2, strlen(arr2)+1);

         // First open in read only and read
        // fd1 = open(fifosout,O_RDONLY);
        // read(fd1, arr1, 4);
 
        // // Print the read string and close
        // printf("User1: %s\n", arr1);
        // close(fd1);

        // START
        fd1 = open(fifosout, O_RDONLY);
        std::cout << "New start.." << std::endl;
        // First open in read only and read
        std::string queryObject;
        while (1)
        {
            int read2result = read(fd1, str2, BUF_SIZE);
            // std::cout << "read2result is " << read2result << std::endl;
            // std::cout << str2 << std::endl;
            if (read2result < BUF_SIZE && read2result >= 0)
            {
                if (read2result != 0)
                {
                    queryObject += str2;
                }
                break;
            }
            queryObject += str2;
            memset(str2, 0, sizeof(str2));
        }
        std::cout << "The result is " << queryObject << std::endl;
        queryObject = "";
        close(fd1);
        // END

    }
    return 0;
}
