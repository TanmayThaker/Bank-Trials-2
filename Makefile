output: main.o menu.o bank.o employee.o manager.o cashier.o helper.o logger.o
	g++ main.o menu.o bank.o employee.o manager.o cashier.o helper.o logger.o -o output

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp menu.h
	g++ -c menu.cpp

bank.o: bank.cpp bank.h
	g++ -c bank.cpp

employee.o: employee.cpp employee.h
	g++ -c employee.cpp

manager.o: manager.cpp manager.h
	g++ -c manager.cpp

cashier.o: cashier.cpp cashier.h
	g++ -c cashier.cpp

helper.o: helper.cpp helper.h
	g++ -c helper.cpp

logger.o: logger.cpp logger.h
	g++ -c logger.cpp
	
clean:
	del *.o output