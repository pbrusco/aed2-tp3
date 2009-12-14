#!bin/bash

make

g++ diff.cpp -o diferencias

# TEST 1
./parser 1.in n1.out
./diferencias 1.out n1.out diff1.out

# TEST 2
./parser 2.in n2.out
./diferencias 2.out n2.out diff2.out

# TEST 3
./parser 3.in n3.out
./diferencias 3.out n3.out diff3.out

# TEST 4
./parser 4.in n4.out
./diferencias 4.out n4.out diff4.out

# TEST 5
./parser 5.in n5.out
./diferencias 5.out n5.out diff5.out

# TEST 6
./parser 6.in n6.out
./diferencias 6.out n6.out diff6.out

# TEST 7
./parser 7.in n7.out
./diferencias 7.out n7.out diff7.out

# TEST 8
./parser 8.in n8.out
./diferencias 8.out n8.out diff8.out

# TEST 9
./parser 9.in n9.out
./diferencias 9.out n9.out diff9.out

# TEST 10
./parser 10.in n10.out
./diferencias 10.out n10.out diff10.out
