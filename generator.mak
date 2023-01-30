
generator: generator.o 
	./generator iwork1 iwork2 iwork3 iwork4 iwork5 iwork6 iwork7 iwork8
generator.o: generation_station.cpp logger.cpp log_messages.cpp 
	g++ generation_station.cpp logger.cpp log_messages.cpp -o generator -l sqlite3
      

