BASIC_DATA_DIR = ../InputData
FRAMEWORK_DIR = ../../EnumerationFramework/Version2Opt
COMPILE_OPTIONS = -I$(BASIC_DATA_DIR) -I$(FRAMEWORK_DIR) -Wall -O3 -std=c++11

TestBusSchedulingOpt.exe: TestBusSchedulingOpt.o EnumerationBusSchedulingOpt.o
	g++ -o TestBusSchedulingOpt.exe TestBusSchedulingOpt.o EnumerationBusSchedulingOpt.o $(BASIC_DATA_DIR)/BDS_Data.o

TestBusSchedulingOpt.o: EnumerationBusSchedulingOpt.hh TestBusSchedulingOpt.cc
	g++ -c $(COMPILE_OPTIONS) TestBusSchedulingOpt.cc

EnumerationBusSchedulingOpt.o: EnumerationBusSchedulingOpt.hh EnumerationBusSchedulingOpt.cc
	g++ -c $(COMPILE_OPTIONS) EnumerationBusSchedulingOpt.cc

clean:
	rm -f TestBusSchedulingOpt.exe TestBusSchedulingOpt.o EnumerationBusSchedulingOpt.o