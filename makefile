GTEST_DIR = /u/a/e1401162/googletest/googletest
GTEST_INCLUDE=-I $(GTEST_DIR)/include

my_test: linkListTest.o linkList.o Gtest_main.c libgtest.a
	g++ -isystem $(GTEST_DIR)/include -pthread linkListTest.o linkList.o Gtest_main.c libgtest.a -o my_test --coverage
	
linkListTest.o: linkListTest.c
	g++ $(GTEST_INCLUDE) -c linkListTest.c --coverage
	
linkList.o: linkList.c linkList.h
	g++ -c linkList.c --coverage

libgtest.a: gtest-all.o
	ar -rv libgtest.a gtest-all.o
	
gtest-all.o:
	g++ -isystem $(GTEST_DIR)/include -I $(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc

clean:
	rm my_test *.o libgtest.a
