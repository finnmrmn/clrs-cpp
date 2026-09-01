# Exercises 2.1

## 2.1-1
|   | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| Already sorted | 31| 41| 59| 26| 41| 58|
| Already sorted | 31| 41| 59| 26| 41| 58|
| Shift [1:3] | 26| 31| 41| 59| 41| 58|
| Shift [4] | 26| 31| 41| 41| 59| 58|
| Shift [5] | 26| 31| 41| 41| 58| 59|

## 2.1-2

### Loop Invariant
Let $sum_i$ denote the value of $sum$ at the start of iteration $i$.
```math
sum_{i} = \sum^{i-1}_{k=1} A[k]
```
Note that this sum does not include $A[i]$ itself, so this is the sum of the
subarray $A[1:i-1]$.
### Initialisation
When $i=1$, we get the empty sum,
```math
sum_1 = \sum^{1-1}_{k=1} A[k] = \sum^{0}_{k=1} A[k] = 0
```
### Maintenance
Before each loop iteration, we have the loop invariant,
$$sum_{i} = \sum^{i-1}_{k=1} A[k]$$
Adding the next element, $A[i]$, to $sum_i$ gives us,
```math
sum_i + A[i]
= \sum^{i-1}_{k=1} A[k] + A[i] 
=\sum^{i}_{k=1} A[k]
=\sum^{(i+1)-1}_{k=1} A[k]
= sum_{i+1}
```
The loop invariant is maintained and will hold for the next iteration.
### Termination
The loop terminates once $i - 1 = n\implies i = n + 1$,
```math
sum_{n+1}=\sum^{(n+1)-1}_{k=1} A[k] =\sum^{n}_{k=1} A[k]
```
After terminating the loop, we get the sum of $A[1:n]$.

## 2.1-3
```text
SUM-ARRAY(A, n)
    for i = 2 to n
        key = A[i]
        j = i - 1
        while j > 0 and A[j] < key // Changed '>' to '<'.
            A[j + 1] = A[j]
            j = j - 1
        A[j + 1] = key
```
The procedure now sorts in monotonically decreasing order.

## 2.1-4
```text
LINEAR-SEARCH(A, n, x)
    for i = 1 to n
        if A[i] == x
            return i
    return NIL
```
This finds the index of the first $x$ in the array, if at least one $x$ is 
present. Note that the exercise does not elaborate on how the algorithm should 
handle multiple occurences of $x$, so we will assume only one may be present or
that it simply does not matter.

### Loop Invariant
```math
x\notin A[1:i-1]
```

### Initialisation
Initially, $i = 1$,
```math
A[1:(1)-1] = A[1:0]\\
x \notin A[1:0]
```
This is an empty subarray.

### Maintenance
Consider case $i$,
```math
(x\notin A[1:i-1]) \land (x \neq A[i])\\
 \implies (x\notin A[1:i])
```
$x$ is not in the new subarray, so the loop invariant is maintained.
### Termination
There are two cases where the loop can terminate. Let us apply the loop 
invariant on the terminating iteration $i-1=n\implies i=n+1$,
```math
(x\notin A[1:(n+1)-1]) 
\implies (x\notin A[1:n]) 
\implies \text{NIL is returned.}
```
When $n+1$ is reached, the loop terminates.

The other case is when $x\in A[i]$.
```math
x = A[i] \implies i\text{ is returned.}
```