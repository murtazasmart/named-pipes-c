//
//  NamedPipeOperations.h
//  FlexibleComputerLanguage
//
//  Created by Murtaza Anverali on 7/4/18.
//  Copyright © 2018 Murtaza Anverali. All rights reserved.
//
#include <iostream>

class NamedPipeOperations
{

public:
  static std::string readFromPipe(int fd);
  static int writeToPipe(int fd, std::string s);

};
