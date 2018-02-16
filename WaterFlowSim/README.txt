Every deposit (except the last one) is connected with the next in line via a pipe. All deposits are equal
but the pipes can have different specifications (such as diameter, material quality), and therefore, some
may sustain greater flows of water than others.

Due to the influence of gravity, and assuming there are no water leaks and that the pipes are unobstructed,
after some time all the water will flow to the deposit that stands lowest on the mountainside
(’C’ in the previous figure).

Line 1 contains the number of water deposits on the mountainside.
Line 2 describes the initial contents of each water deposit, from the topmost to the lowest one.
Line 3 indicates the maximum flow of water allowed inside the pipes that connect each pair of
deposits, respecting the order imposed in the previous line.

===========================================================================================================

In the end it prints a table that shows how much time has passed in seconds and the other spaces represent the
amount of water in a deposit at that moment.
Test used is:
3
11 0 0
5 4
and the result must be
t A B C
--------
0 11 0 0
1 6 5 0
2 1 6 4
3 0 3 8
4 0 0 11
