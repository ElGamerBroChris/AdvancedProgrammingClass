For some time now, there have been several businesses dedicated to the sale of extraterrestrial real
estate on the planet Mars. The problem is that, as there is no centralised database, the same property
may have been sold twice, or several properties, owned by different people, may intersect each other.

Every property has a rectangular shape and one of its sides runs alongside one of the major Martian
roads. Moreover, the length of the sides that are perpendicular to the road are fixed for every road.
Mars roads are straight lines. So, a property may be identified by the name and the side of the road,
and the coordinates of the two corners next to the road.

Two properties intersect if the corresponding rectangles intersect and the intersection area is positive.

Write a program that, given a sequence of properties on the same side of a road, determines whether
at least two of them intersect.

Input

The first line contains an integer T (1 ≤ T ≤ 32), which is the number of test cases. The following
lines contain T test cases.
The first line of a test case contains an integer N (1 ≤ N ≤ 50000), which is the length of the
sequence of properties.

Each of the following N lines contains four non-negative integers, X1, Y1, X2 and Y2, separated by
a space. These integers do not exceed 231 − 1.

The pairs (X1, Y1) and (X2, Y2) specify the x-coordinate and the y-coordinate of the two property
corners next to the road.

Output

The output consists of T lines. The i-th line contains the message:
• ‘No problem’, if no two distinct elements of the i-th sequence of properties intersect; or
• ‘Difficult problem(s)’, otherwise.

======================================================================================================
Christian Miranda Espinoza A01223255
chrisme1320
Final Project

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=11&page=show_problem&problem=877

Test made in tcl

Input
3
4
100 214 120 254
55 124 20 54
12045 24104 12046 24106
56 126 100 214
5
4141 4196 4123 4196
761 4196 759 4196
757 4196 760 4196
0 4196 2 4196
144 4196 145 4196
4
60 30 22 11
214 107 256 128
48 24 46 23
214 107 256 128

Expected Output
No problem
Difficult problem(s)
Difficult problem(s)
