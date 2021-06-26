# Highest Peak Detection

> You should finish in about 90 minutes. Everything you type is recorded. Don't forget to test for edge cases. 
> You may run it as much as you want.



A non-empty array A consisting of N integers is given. A peak in this array is any triplet of integers (P, Q, R) such that:

0 ≤ P < Q < R < N;
sequence [A[P], A[P+1], ..., A[Q]] is strictly increasing, 
i.e. A[P] > A[P+1] > ... > A[Q];
sequence A[Q], A[Q+1], ..., A[R] is strictly decreasing, 
i.e. A[Q] < A[Q+1] < ... < A[R].
The depth of a peak (P, Q, R) is the number min{A[Q] − A[P], A[Q] − A[R]}.

For example, consider array A consisting of 10 elements such that:

  A[0] =   0
  A[1] =   1
  A[2] =   3
  A[3] =   0
  A[4] =  -1
  A[5] =   1
  A[6] =   0
  A[7] =  -3
  A[8] =   2
  A[9] =   3

Triplet (0, 2, 4) is one of the peaks in this array, because sequence [A[0], A[2]] is strictly increasing (0 < 3) and sequence [A[2], A[4]] is strictly decreasing(3 > -1). Its depth is min{A[2] − A[0], A[2] − A[4]} = 3. Triplet (4, 5, 7) is another peak with depth 2. There is no peak in this array higher (i.e. having depth greater) than 3.

Write a function:

public int detectHighestPeaks(int[] A);

that, given a non-empty array A consisting of N integers, returns the depth of the highest peak in array A. 

The function should return −1 if there are no peaks in array A.

For example, consider array A consisting of 10 elements such that:

  A[0] =  0
  A[1] =  3
  A[2] =  2
  A[3] =  0
  A[4] =  4
  A[5] =  3
  A[6] =  0
  A[7] = -3
  A[8] =  2
  A[9] =  3
the function should return 4, as explained above.

Write an *efficient* algorithm for the following assumptions:

N is an integer within the range [1..1,000,000];
each element of array A is an integer within the range [−100,000,000..100,000,000].
