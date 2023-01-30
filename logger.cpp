/*
Stuart Wing

Implements the logger class giving a constructor,
 a destructor, a write to database method and method to return
 all of the database rows.
 */

#include "logger.h"
using namespace std;


// name of database created by constructed
string database = "3307.db";

// constructor for class, recieves appname and creates a table in the database for the app
logger::logger(string appname){
   this-> appname=appname;
   // initialize database exec paramaters
   char *zErrMsg = 0;
   int rc;
   string sql;
   // create sqlite database
   rc = sqlite3_open(database.c_str(), &db);
   // error handling 
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
     exit(0); 
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   

    // SQL code to perform database operation
   sql = "CREATE TABLE if not exists " +  this->appname + " (timestamp varchar(255), message varchar(255));"; 
	
     // execute sql statment on 3307.db
   rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
   // error handling
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   
}



// destructor 
logger::~logger(){
sqlite3_close(db);
}

// void logger write method which recieves a message from generation_station, creates a timestamp
// and writes both to 3307.db
void logger::write(string message){
   string sql;

   // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* timestamp = ctime(&now);
	string timestamp_string = timestamp;
     // SQL statement to insert the timestamp and message into the database
   sql = "INSERT INTO "+ appname + " VALUES(\""+ timestamp_string + "\",\""
   + message + "\");";

   // perform statement in 3307.db
   rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
   //error handling
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }


}

// vecotr method which returns a vector of every row in 3307.db
vector<log_messages> logger::read_all(){
         /* Create SQL statement */
   string timestamp,message,sql;

   sql = "SELECT * FROM "+appname+";";

  
   vector<log_messages> messages;

    sqlite3_stmt *stmt;

    rc = sqlite3_prepare_v2(db, sql.c_str(),-1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        
         timestamp = (const char*)(sqlite3_column_text(stmt, 0));
          message = (const char*)(sqlite3_column_text(stmt, 1));
      
        log_messages pushMessage(timestamp,message);

        messages.push_back(pushMessage);

    }
    if (rc != SQLITE_DONE) {
        cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);
    return messages;

}
