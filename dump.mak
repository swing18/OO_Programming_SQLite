dump: dump.o 
	./dumper generator
      
 
dump.o: dumper.cpp logger.cpp log_messages.cpp 
	g++ dumper.cpp logger.cpp log_messages.cpp -l sqlite3 -o dumper


