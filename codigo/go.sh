#!bin/bash

make

# TEST 1
./parser 1.in n1.out
diff -s 1.out n1.out

# TEST 2
#./parser 2.in n2.out
#diff -s 2.out n2.out

# TEST 3
#./parser 3.in n3.out
#diff -s 3.out n3.out

# TEST 4
#./parser 4.in n4.out
#diff -s 4.out n4.out

# TEST 5
#./parser 5.in n5.out
#diff 5 -s out n5.out

# TEST 6
#./parser 6.in n6.out
#diff -s 6.out n6.out

# TEST 7
./parser 7.in n7.out
diff -s 7.out n7.out

# TEST 8
#./parser 8.in n8.out
#diff -s 8.out n8.out

# TEST 9
#./parser 9.in n9.out
#diff -s 9.out n9.out

# TEST 10
#./parser 10.in n10.out
#diff -s 10.out n10.out
