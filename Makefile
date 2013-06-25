# makefile
PY_INCLUDE_PATH = /usr/include/python2.7

MAIN: longnumber.o longnumber_cpp.o longnumber_cpp_wrap.o liblongnumber_cpp.so  #test_c.o test_cpp.o 
	#gcc -o test_c test_c.o -L. -llongnumber -lm -Wl,-rpath,.
	#g++  -o test_cpp test_cpp.o -L. -llongnumber -llongnumber_cpp -Wl,-rpath,. 

liblongnumber_cpp.so: liblongnumber.so
	g++  -shared -o liblongnumber_cpp.so longnumber_cpp.o -L. -llongnumber -Wl,-rpath,.
	g++ longnumber_cpp_wrap.o longnumber_cpp.o -shared -fPIC -L. -llongnumber -Wl,-rpath,. -o _longnumber_cpp.so

liblongnumber.so:
	gcc -shared -o liblongnumber.so longnumber.o


#test_c.o: test_c.c liblongnumber.so
#	gcc -c test_c.c


longnumber.o: longnumber.c
	gcc -c -fPIC longnumber.c

#test_cpp.o: test_cpp.cpp liblongnumber.so liblongnumber.so
#	g++ -c test_cpp.cpp



longnumber_cpp_wrap.o: longnumber_cpp_wrap.cxx 
	g++ -fPIC -c longnumber_cpp.cpp longnumber_cpp_wrap.cxx -I$(PY_INCLUDE_PATH)

longnumber_cpp_wrap.cxx: longnumber_cpp.i longnumber_cpp.o
	swig -c++ -python longnumber_cpp.i

longnumber_cpp.o: longnumber_cpp.cpp liblongnumber.so
	g++ -c -fPIC longnumber_cpp.cpp 

clean:
	rm -f *.o
	rm -f *.pyc

cleanall: clean
	rm -f *.cxx
	rm -f *.so



