# Exercises 2.1

## 2.1-1
|   | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| [1:1] already sorted | 31| 41| 59| 26| 41| 58|
| [1:2] already sorted | 31| 41| 59| 26| 41| 58|
| [1:3] shift one right | 26| 31| 41| 59| 41| 58|
| [4:4] shift one right | 26| 31| 41| 41| 59| 58|
| [5:5] shift one right | 26| 31| 41| 41| 58| 59|

## 2.1-2

### Loop Invariant
Let $sum_i$ denote the value of $sum$ at the start of iteration $i$.
```math
sum_{i} = \sum^{i-1}_{k=1} A[k]
```
Note that this sum does not include $A[i]$ itself, so this is the sum of the
subarray $A[1:i-1]$.
### Initialisation
When $i=1$, we get the empty sum:
```math
sum_1 = \sum^{1-1}_{k=1} A[k] = \sum^{0}_{k=1} A[k] = 0
```
### Maintenance
Before each loop iteration, we have the loop invariant:
$$sum_{i} = \sum^{i-1}_{k=1} A[k]$$
Adding the next element, $A[i]$, to $sum_i$ gives us:
```math
sum_i + A[i]
= \sum^{i-1}_{k=1} A[k] + A[i] 
=\sum^{i}_{k=1} A[k]
=\sum^{(i+1)-1}_{k=1} A[k]
= sum_{i+1}
```
The loop invariant is maintained and will hold for the next iteration.
### Termination
The loop terminates once $i - 1 = n\implies i = n + 1$, giving us:
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
Initially, $i = 1$:
```math
A[1:(1)-1] = A[1:0]\\
x \notin A[1:0]
```
This is an empty subarray.

### Maintenance
Consider case $i$:
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
\implies \text{NIL is returned}
```
When $n+1$ is reached, the loop terminates.

The other case is when $x\in A[i]$.
```math
x = A[i] \implies i\text{ is returned}
```

## 2.1-5
Note that this problem uses 0-origin indexing.
```text
ADD-BINARY-INTERGERS(A, B, n)
    let C[0:n] be a new array
    carry = 0
    for i = 0 to n - 1
        sum = A[i] + B[i] + carry
        C[i] = sum mod 2
        carry = sum div 2
    C[n] = carry
    return C
```

# Exercises 2.2

## 2.2-1
Consider the expression:
```math
\frac{n^3}{1000}+100n^2-100n+3
```
Isolate the dominant term:
```math
\frac{n^3}{1000}
```
Remove the coefficient:
```math 
n^3
```
This reveals that the order of growth in $\Theta$-notation is:
```math
\Theta(n^3)
```
Thus, the expression is roughly proportional to $n^3$ when $n$ is large.

## 2.2-2
```text
SELECTION-SORT(A, n)
    for i = 1 to n - 1
        key_index = i
        for j = i + 1 to n
            if A[j] < A[key_index]
                key_index = j
        temp = A[i]
        A[i] = A[key_index]
        A[key_index] = temp
```

### Loop Invariant
The subarray from $1$ to $i-1$, where $1\le i\le n$, is sorted from least to 
greatest before each loop iteration, and any element from $i$ to $n$ is greater
than any element in the subarray.
```math
A[1:i-1]\text{ is monotonically increasing}\\
\text{and } \forall x\in A[1:i-1],\forall y\in A[i:n], x\le y
```

### Why $n - 1$ Iterations?
The algorithm terminates before $i=n$. However, if we take a look at what would
happen if we applied iteration $n$ to the loop invariant, we would obtain:
```math
\begin{align*}
&A[1:n-1]\text{ is monotonically increasing}\\
&\forall x\in A[1:n-1], x\le A[n]\\
&\therefore A[1:n]\text{ is monotonically increasing}
\end{align*}
```
The whole array is already sorted after iteration $n-1$.

### Worst-Case Running Time
```math
T(n) 
= c_1n 
+ c_2(n-1) 
+ c_3\sum_{i=1}^{n-1}(t_i+1)
+ c_4\sum_{i=1}^{n-1}t_i
+ c_5\sum_{i=1}^{n-1}t_i
+ c_6(n-1)
+ c_7(n-1)
+ c_8(n-1)
```
The number of times each line in the inner loop is executed depends on the outer
loop. That is to say the $i$-th iteration of the outer loop causes the inner
loop to execute $n-i$ times. This gives us $t_i=n-i$.
```math
T(n) 
= c_1n 
+ c_2(n-1) 
+ c_3\sum_{i=1}^{n-1}(n-i+1)
+ c_4\sum_{i=1}^{n-1}(n-i)
+ c_5\sum_{i=1}^{n-1}(n-i)
+ c_6(n-1)
+ c_7(n-1)
+ c_8(n-1)
```
Group the terms to find the dominant term.
```math
\begin{align*}
T(n) 
&= c_1n 
+ (c_2+c_6+c_7+c_8)(n-1) 
+ c_3\sum_{i=1}^{n-1}(n-i)
+ c_3\sum_{i=1}^{n-1}(1)
+ c_4\sum_{i=1}^{n-1}(n-i)
+ c_5\sum_{i=1}^{n-1}(n-i)\\
&= c_1n 
+ (c_2+c_6+c_7+c_8)(n-1) 
+ (c_3+c_4+c_5)\sum_{i=1}^{n-1}(n-i)
+ c_3\sum_{i=1}^{n-1}(1)\\
&= (c_1+c_2+c_6+c_7+c_8)n
+ (c_3+c_4+c_5)\sum_{i=1}^{n-1}(n-i)
+ c_3\sum_{i=1}^{n-1}(1) - (c_2+c_6+c_7+c_8)\\
&= (c_3+c_4+c_5)\frac{n(n-1)}{2}
+ (c_1+c_2+c_3+c_6+c_7+c_8)n
- (c_2+c_3+c_6+c_7+c_8)\\
&= \frac{c_3+c_4+c_5}{2}(n^2-n)
+ (c_1+c_2+c_3+c_6+c_7+c_8)n
- (c_2+c_3+c_6+c_7+c_8)\\
&= \frac{c_3+c_4+c_5}{2}n^2-\frac{c_3+c_4+c_5}{2}n
+ (c_1+c_2+c_3+c_6+c_7+c_8)n
- (c_2+c_3+c_6+c_7+c_8)\\
&= \frac{c_3+c_4+c_5}{2}n^2
+ (c_1+c_2+c_3+c_6+c_7+c_8-\frac{c_3+c_4+c_5}{2})n
- (c_2+c_3+c_6+c_7+c_8)\\
\therefore T(n)&\in\Theta(n^2)
\end{align*}
```
### Best-case running time faster?
Consider the dominant term.
```math
\frac{c_3+c_4+c_5}{2}n^2
```
The only difference with the best-case running time is eliminating the step that
replaces the key index. This effectively means $c_5=0$, but this does not
eliminate the $n^2$ term altogether. 
```math
\frac{c_3+c_4}{2}n^2
```
Therefore, the best and worst cases are roughly proportional to
$n^2$ when $n$ is large. The best-case running time is negligibly faster than
the worst-case running time.

## 2.2-3
Let us consider the average, best, and worst cases for linear search.

### Average Case
Checking the $i$-th element involves checking $i$ elements. This means the total
checks needed for all elements is:
```math
\sum_{i=1}^{n}i=\frac{n(n+1)}{2}
```
The average number of checks is then:
```math
T(n)=\frac{\frac{n(n+1)}{2}}{n}=\frac{n+1}{2}
```
```math
\implies T(n)\in\Theta(n)
```

### Worst Case
All $n$ elements must be checked.
```math
T(n)=n
```
```math
\implies T(n)\in\Theta(n)
```

### Best Case (Extra)
The first element checked is the element being searched for.
```math
T(n)=1
```
```math
\implies T(n)\in\Theta(1)
```

### Comparison
The worst and average cases fall into the same set of functions. However, the
best case instantly returns in constant time.

## 2.2-4
All sorting algorithms could first perform an already-sorted check to determine 
whether any sorting needs to be performed at all. This would bring the
best-case running time of any typical sorting algorithm down to $\Theta(n)$.