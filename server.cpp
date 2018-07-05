//
//  server.cpp
//  FlexibleComputerLanguage
//
//  Created by Murtaza Anverali on 7/4/18.
//  Copyright © 2018 Murtaza Anverali. All rights reserved.
//

// C program to implement one side of FIFO
// This side reads first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <cstdlib>

int main()
{
    std::cout << "Starting.." << std::endl;
    int BUF_SIZE = 4;
    int fdin;
    int fdout;

    // FIFO file path
    std::string sin = "/tmp/queryfifoin";
    std::string sout = "/tmp/queryfifoout";
    char *fifosin = (char *)sin.c_str();
    char *fifosout = (char *)sout.c_str();

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(fifosin, 0666);
    mkfifo(fifosout, 0666);

    char str1[BUF_SIZE], str2[BUF_SIZE];
    while (1)
    {
        // START
        fdin = open(fifosin, O_RDONLY);
        std::cout << "New start.." << std::endl;
        // First open in read only and read
        std::string queryObject;
        while (1)
        {
            int read2result = read(fdin, str1, BUF_SIZE);
            if (read2result < BUF_SIZE && read2result >= 0)
            {
                if (read2result != 0)
                {
                    queryObject += str1;
                }
                break;
            }
            queryObject += str1;
            memset(str1, 0, sizeof(str1));
        }
        std::cout << "The result is " << queryObject;
        close(fdin);
        // END

        // START
        std::string s = queryObject + " processed in server.";
        char *sc;
        // std::cin >> s;
        // Open FIFO for write only
        fdout = open(fifosout, O_WRONLY);

        // std::cout << s;
        sc = (char *)s.c_str();
        int i, j = 0;
        for (i = 0; sc[i]; i++)
        {
            str2[i % 4] = sc[i];
            // std::cout << "i is " << i << "sc is " << sc[i] << std::endl;
            if (i % 4 == 3 && i != 0)
            {
                // std::cout << "arr1 is " << str2 << std::endl;
                int status = write(fdout, str2, strlen(str2));
                // std::cout << "write status " << status << std::endl;
                // arr1 = new char[4];
                memset(str2, 0, sizeof(str2));
            }
            // printf("%c", sc[ i ]);
        }
        // std::cout << "i is " << i << std::endl;
        if (i % 4 < 4 && i % 4 != 0)
        {
            // std::cout << "arr1 is " << str2 << std::endl;
            int status = write(fdout, str2, strlen(str2));
            // std::cout << "write status " << status << std::endl;
        }
        // Write the input arr2ing on FIFO
        // and close it
        close(fdout);

        queryObject = "";
        // END
    }

    return 0;
}