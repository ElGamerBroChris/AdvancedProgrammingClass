all:
	gcc -g -o fibonacci fibonacci.c
	gcc -g -o fibonacci_memoization fibonacci_memoization.c

test: all
	time ./fibonacci ${num}
	time ./fibonacci_memoization ${num}

clean:
	rm fibonacci
	rm fibonacci_memoization

commit: all clean
	git add -A .
	git commit