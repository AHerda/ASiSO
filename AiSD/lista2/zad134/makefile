#MAKEFILE

all: generator merge quick insertion dual_quick hybrid

generator: generator.cpp
	g++ -O3 -o generator generator.cpp

merge: merge.cpp
	g++ -O3 -o merge merge.cpp

quick: quick.cpp
	g++ -O3 -o quick quick.cpp

insertion: insertion.cpp
	g++ -O3 -o insertion insertion.cpp

dual_quick: dual_quick.cpp
	g++ -O3 -o dual_quick dual_quick.cpp

hybrid: hybrid.cpp
	g++ -O3 -o hybrid hybrid.cpp

git:
	git add *pp
	git commit -m "Update"

clean:
	rm generator merge quick insertion dual_quick hybrid *.o
