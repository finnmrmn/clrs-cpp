# Exercises 2.1

## 2.1-1
|   | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| Already sorted  | **31**| **41**| 59| 26| 41| 58|
| Already sorted  | **31**| **41**| **59**| 26| 41| 58|
| Shift [1:3] | **26**| **31**| **41**| **59**| 41| 58|
| Shift [4] | **26**| **31**| **41**| **41**| **59**| 58|
| Shift [5] | **26**| **31**| **41**| **41**| **58**| **59**|

Numbers belonging to the sorted subarray are in **bold**.

## 2.1-2
### Loop Invariant
Let $sum_i$ denote the value of $sum$ at the start of iteration $i$.
$$sum_{i} = \sum^{i-1}_{k=1} A[k]$$
Note that this sum does not include $A[i]$ itself, so this is the sum of the
subarray $A[1:i-1]$.
### Initialisation
When $i=1$, we get the empty sum,
$$sum_1 = \sum^{1-1}_{k=1} A[k] = \sum^{0}_{k=1} A[k] = 0$$
### Maintenance
Before each loop iteration, we have the loop invariant,
$$sum_{i} = \sum^{i-1}_{k=1} A[k]$$
Adding the next element, $A[i]$, to $sum_i$ gives us,
$$
sum_i + A[i]
= \sum^{i-1}_{k=1} A[k] + A[i] 
=\sum^{i}_{k=1} A[k]
=\sum^{(i+1)-1}_{k=1} A[k]
= sum_{i+1}
$$
The loop invariant is maintained and will hold for the next iteration.
### Termination
The loop terminates once $i - 1 = n\implies i = n + 1$,
$$sum_{n+1}=\sum^{(n+1)-1}_{k=1} A[k] =\sum^{n}_{k=1} A[k]$$
After terminating the loop, we get the sum of $A[1:n]$.