#include "log_messages.h"
#include "logger.h"

using namespace std;

log_messages::log_messages(string message_text, string timestamp){
this->message_text = message_text;
this-> timestamp = timestamp;

}

log_messages::~log_messages(){

}

string log_messages::get_message(){
 return message_text;   
}

string log_messages::get_timestamp(){
 return timestamp;   
}
