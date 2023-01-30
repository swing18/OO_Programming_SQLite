/*
author: Stuart WIng
description:
header file for log_messages.cpp

date: October 4th 2022
*/
#ifndef LOG_MESSAGES_H
#define LOG_MESSAGES_H

#pragma once
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <ctime>
#include "log_messages.h"
#pragma once
//Class definition 
class log_messages
{
    private: 
        std::string message_text; 
        std::string timestamp; 
    public: 
        log_messages(std::string message_text, std::string timestamp); 
        ~log_messages(); 
        std::string get_message(); 
        std::string get_timestamp(); 
}; 

#endif
