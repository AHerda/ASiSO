#MAKEFILE

all: main plot

main: main.cpp
	g++ -O3 -o main main.cpp

plot: wykresy.py
	./main
	python3 wykresy.py
	mv *.png ../wykresy

git:
	git add *.cpp *.py
	git commit -m "Update"

clean:
	rm *.txt *.png main