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

#include "NamedPipeOperations.h"

int main()
{
    std::cout << "Starting.." << std::endl;
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

    while (1)
    {
        // START
        fdin = open(fifosin, O_RDONLY);
        std::cout << "New start.." << std::endl;
        // First open in read only and read

        std::string queryObject = NamedPipeOperations::readFromPipe(fdin);

        close(fdin);
        // END

        // START
        std::string s = queryObject + " processed in server.";
        char *sc;
        // std::cin >> s;
        // Open FIFO for write only
        fdout = open(fifosout, O_WRONLY);

        NamedPipeOperations::writeToPipe(fdout, s);

        close(fdout);

        queryObject = "";
        // END
    }

    return 0;
}