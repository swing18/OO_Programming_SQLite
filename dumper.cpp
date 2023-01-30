/*
author: Stuart WIng
description:
Dumper class to display the messages previously inputted
into the database by the generaion_station class

date: October 4th 2022
*/

#include "logger.h"
#include "log_messages.h"
using namespace std;
int main (int argc, char *argv[]){
    //vector to hold messages returned from read_all()
    vector<log_messages> MyMessages;


    // check that there is an appname 
    if(argc ==0){
        printf("no app name recieved");
        return(0);
    }
    // assign the app name from the user to a string variable
    string appname= argv[1];

    // create a logger object from appname
    logger myLog(appname);
    // store all database messages in MyMessages
    MyMessages = myLog.read_all();

    // check to make sure messages returned from the database
    if(MyMessages.size()==0){
        printf("Table dosent exist");
    }

    // print out contents of my messages

    for(int i=0;i<(int)MyMessages.size();i++){
       cout << MyMessages[i].get_message() << ": " << MyMessages[i].get_timestamp() << endl;
    }


   
    return(0);
}
