all:
	gcc -o main main.c TerrainOverlap.c
run: all
	./main
test: all
	./maintest.tcl ./main
clean:
	rm main TerrainOverlap
