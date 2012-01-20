

import random

"""
WARNING: REALLY BAD ENGLISH IN THE NEXT PARAGRAPHS. FIX IT LATER.

This function tries to reproduce the behavior of the
builtin Python random.random_sample method.

It should correctly produce a random sublist 
with k elements from the input list A, but it,
for not use any additional space, does alter the order
of elements in A, which is not desirable in some cases. 

To prove the correctness of the algorithm we can
proof that each of the possibles k! permutation of
any subset of size k is equaly likely to appear. 
We prove it by induction by showing that on
the ith iteration each subset permutaton of size $i$ is equaly 
probable:

After the first iteration) Clearly each element
is equaly probable since we chose a random element
between [0, n). So, the base case holds.

After the m-th iteration) Let's calculate the
probability of a permutation <a_1, a_2, ..., a_m>
be select at the end of the mth iteration.
By induction hyphotesis each (m - 1)! permutation of each
subset is equaly likely before the m-th iteration starts,
 so the probability of <a_1, a_2, ..., a_m-1> be current permutation
is 1/(n choose (m - 1)) * (m - 1)! = (n - m + 1)!/ n!, and
we have a chance of 1/(n - m + 1) of choosing a_m in the
iteration $m$. So, the probabilty of <a_1, a_2, ..., a_m> is
(n - m + 1)!/n! * (n - m + 1) = (n - m)!/n!, which is 
the exact likelyhood of choosing a permutation of size $m$
from a set of size $n$. 

This random sample algorithm can also be used to generate
a random permutation, since we can chose k = n and then
all permutation will be equaly likely

"""

def random_sample(A, k):
	n = len(A)
	for i in xrange(k):
			r = random.randrange(i, n)
			A[i], A[r] = A[r], A[i]
	return A[0:k]
	

if __name__ == '__main__':
	A = range(10)
	for test in xrange(0, 10):
		print random_sample(A, 5)
			
