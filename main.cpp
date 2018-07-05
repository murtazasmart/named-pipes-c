//
//  main.cpp
//  FlexibleComputerLanguage
//
//  Created by Murtaza Anverali on 7/4/18.
//  Copyright © 2018 Murtaza Anverali. All rights reserved.
//

#include <iostream>
// #include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
    // std::string s;
    // while(1)
    // {
    //     // std::getline(std::cin, s)
    //     // cin >> s;
    //     std::cout << "Hello world " + s + "\n";
    //     // sleep(1);
    // }
    // int pipefd[2];
    // pid_t cpid;
    // char buf;
    // if (argc != 2) {
    // fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    // exit(EXIT_FAILURE);
    // }
    // if (pipe(pipefd) == -1) {
    //     perror("pipe");
    //     exit(EXIT_FAILURE);
    // }
    // cpid = fork();
    // if (cpid == -1) {
    //     perror("fork");
    //     exit(EXIT_FAILURE);
    // }
    // if (cpid == 0) {    /* Child reads from pipe */
    //     close(pipefd[1]);          /* Close unused write end */
    //     while (read(pipefd[0], &buf, 1) > 0)
    //         write(STDOUT_FILENO, &buf, 1);
    //     write(STDOUT_FILENO, "\n", 1);
    //     close(pipefd[0]);
    //     _exit(EXIT_SUCCESS);
    // } else {            /* Parent writes argv[1] to pipe */
    //     close(pipefd[0]);          /* Close unused read end */
    //     write(pipefd[1], argv[1], strlen(argv[1]));
    //     close(pipefd[1]);          /* Reader will see EOF */
    //     wait(NULL);                /* Wait for child */
    //     exit(EXIT_SUCCESS);
    // }
    int pos;
    std::size_t found;
    std::string s = "my world is round\n";
    found = s.find("\n");
    if (found==std::string::npos)
    {
        std::cout << "not found" << endl << found << endl;
    }
    else
    {
        std::cout << found << endl;
    }
}