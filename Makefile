#
# Make version of builder, use only if Bazel doesn't work.
# You may need to tweak the variables to suit your environment.
#
# Copyright (c) 2019, Sekhar Ravinutala.
#

INC = -I. -I/usr/local/include
LIB = -L/usr/local/lib
G++ = g++ ${INC} ${LIB}
DEPS = dealer/*.cpp dealer/*.h data/*.cpp data/*.h

all: report agent_test dealer_test

report: report.cpp ${DEPS}
	${G++} -o $@ $^

agent_test: test/agent_test.cpp ${DEPS}
	${G++} -o $@ $^ -lpthread -lgtest_main

dealer_test: test/dealer_test.cpp ${DEPS}
	${G++} -o $@ $^ -lpthread -lgtest_main

clean:
	rm -f report agent_test dealer_test