COMPILE_OPTIONS = -Wall -Wfatal-errors -O3

TestWLEnumeration.exe: TestWLEnumeration.o WL_Enumeration.o WL_Data.o
	g++ -o TestWLEnumeration.exe TestWLEnumeration.o WL_Enumeration.o WL_Data.o

TestWLEnumeration.o: WL_Enumeration.hh EnumerationOpt.hh WL_Data.hh TestWLEnumeration.cc
	g++ -c $(COMPILE_OPTIONS) TestWLEnumeration.cc

WL_Enumeration.o: WL_Enumeration.hh WL_Data.hh WL_Enumeration.cc
	g++ -c $(COMPILE_OPTIONS) WL_Enumeration.cc

WL_Data.o: WL_Data.cc WL_Data.hh
	g++ -c $(COMPILE_OPTIONS) -c WL_Data.cc

clean:
	rm -f TestWLEnumeration.exe TestWLEnumeration.o WL_Enumeration.o WL_Data.o