/*
author: Stuart WIng
description:
header file for logger.cpp

date: October 4th 2022
*/
#ifndef LOGGER_H
#define LOGGER_H
#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "sqlite3.h"
#include <ctime>
#include "log_messages.h"

//class
class logger
{
    private: 
        std::string appname; 
        sqlite3 *db; 
        char *zErrMsg = 0;
        int rc = 0;
        
    public: 
        logger(std::string appname); 
        ~logger(); 
        void write(std::string message); 
        std::vector<log_messages> read_all(); 
}; 

#endif
