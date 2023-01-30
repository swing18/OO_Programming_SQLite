/*
author: Stuart WIng
description:
generator class to take arguements from the user as messages
randomly select a message every 5 seconds, then insert it
into the database

date: October 4th 2022
*/


#include "generation_station.h"
using namespace std;

// signal handler to exit the while loop upon the users command
void signal_callback_handler(int signum) {
   cout << "Caught signal " << signum << endl;
   // Terminate program
   exit(signum);
}

int main (int argc, char *argv[]){
// int's to store the random mesage index and number of messages passed in
int random_num, MessageNumber; 
//initialize rand
srand(time(NULL));
//to hold the random message
string messageToSend;
// vector for messages
vector<string> my_messages;
// raw filepath
string full_path= argv[0];
// get filename
string base_filename = full_path.substr(full_path.find_last_of("/\\") + 1);
// remove extension from filename
size_t const p(base_filename.find_last_of('.'));
// store filename
string filename = base_filename.substr(0, p);
   // create logger item
logger myLoggerObject(filename);


// check that there are messages to log
    if(argc==1){
        printf("no messages recieved");
        return(0);
    }
    

// store each message in vector 
    for(int i =1; i<argc;i++){
		
        my_messages.push_back(argv[i]);
        MessageNumber++;
    }
   
    // Register signal and signal handler
   signal(SIGINT, signal_callback_handler);
   while(true){
        //generate random number
        random_num= rand()%MessageNumber;
        // store a random message in messageToSend
        messageToSend= my_messages[random_num];
        // add the message to database
        myLoggerObject.write(messageToSend);
        // sleep for 5 seconds
        sleep(5);
   }
   
return(0);
}
