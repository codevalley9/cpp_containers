CMPLR=gcc
STDFLAGS=-Wall -Werror -Wextra -std=c++17
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lm -lpthread -lsubunit
LIBS=-lgtest -lstdc++

OS := $(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
	OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all: clean test

test: clean
ifeq ($(OS), Darwin)
	$(CMPLR) $(STDFLAGS) ./tests/s21_*.cc $(LIBS) -o unit_test
else
	$(CMPLR) $(STDFLAGS) ./tests/s21_*.cc $(LIBS) $(LINUX_FLAGS) -o unit_test
endif
	./unit_test

gcov_report: clean
ifeq ($(OS), Darwin)
	$(CMPLR) $(STDFLAGS) $(GCOV_FLAGS) ./tests/s21_*.cc -o unit_test $(LIBS) 
else
	$(CMPLR) $(STDFLAGS) $(GCOV_FLAGS) ./tests/s21_*.cc -o unit_test $(LIBS) $(LINUX_FLAGS)
endif
	./unit_test
ifeq ($(OS), Darwin)
	lcov --ignore-errors mismatch -o s21_test.info --no-external -c -d .
else
	lcov --exclude '/usr/include/*' -o s21_test.info -c -d .
endif
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html


debug: clean
ifeq ($(OS), Darwin)
	$(CMPLR) -g -O0 $(STDFLAGS) ./tests/s21_*.cc $(LIBS) -o unit_test
else
	$(CMPLR) -g -O0 $(STDFLAGS) ./tests/s21_*.cc $(LIBS) $(LINUX_FLAGS) -o unit_test
endif
	./unit_test

clang:
	clang-format -style=Google -n *.h
	clang-format -style=Google -n s21_*/s21_*
	clang-format -style=Google -n tests/s21_*

clang_i:
	clang-format -style=Google -i *.h
	clang-format -style=Google -i s21_*/s21_*
	clang-format -style=Google -i tests/s21_*

leaks: test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./unit_test
else
	valgrind --leak-check=full -s ./unit_test
endif


brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

lcov:
ifeq ($(OS),Linux)
	sudo apt install lcov
endif
ifeq ($(OS),Darwin)
	brew install lcov
endif

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf report
	rm -rf unit_test

git_add:
	git add s21_*/s21_*
	git add Makefile
	git add s21_*.h
	git add tests/s21_*.cc
	git add tests/s21_*.h

depend:
	makedepend
# DO NOT DELETE
