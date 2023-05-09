all: generator select rand_select select_5 bin_search quick dual_quick

generator: generator.cpp
	g++ -O3 -o generator generator.cpp

select: select.cpp
	g++ -O3 -o select select.cpp

rand_select: rand_select.cpp
	g++ -O3 -o rand_select rand_select.cpp

select_5: select_5.cpp
	g++ -O3 -o select_5 select_5.cpp

bin_search: bin_search.cpp
	g++ -O3 -o bin_search bin_search.cpp

quick: quick.cpp
	g++ -O3 -o quick quick.cpp

dual_quick: dual_quick.cpp
	g++ -O3 -o dual_quick dual_quick.cpp

git:
	git add *pp
	git commit -m "Update"

clean:
	rm select generator *.o