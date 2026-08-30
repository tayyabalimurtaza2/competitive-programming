# 1471 - Farmer John's Favorite Operation

> [View the original problem](https://usaco.org/index.php?page=viewproblem2&cpid=1471)

---
It is another cold and boring day on Farmer John's farm. To pass the time, Farmer John has invented a fun leisure activity involving performing operations on an integer array.

Farmer John has an array $a$ of $N$ ($1 \leq N \leq 2 \cdot 10^5$) non-negative integers and an integer $M$ ($1 \leq M \leq 10^9$). Then, FJ will ask Bessie for an integer $x$. In one operation, FJ can pick an index $i$ and subtract or add $1$ to $a_i$. FJ's boredom value is the minimum number of operations he must perform so that $a_i-x$ is divisible by $M$ for all $1 \leq i \leq N$.

Among all possible $x$, output FJ's minimum possible boredom value.

### INPUT FORMAT (input arrives from the terminal / stdin):

The first line contains $T$ ($1 \leq T \leq 10$), the number of independent test cases to solve.

The first line of each test case contains $N$ and $M$.

The second line of each test case contains $a_1, a_2, ..., a_N$ ($0 \leq a_i \leq 10^9$).

It is guaranteed that the sum of $N$ over all test cases does not exceed $5 \cdot 10^5$.

### OUTPUT FORMAT (print output to the terminal / stdout):

For each test case, output an integer on a new line containing FJ's minimum possible boredom value among all possible values of $x$.

### Sample Input 1

```
2
5 9
15 12 18 3 8
3 69
1 988244353 998244853
```

### Sample Output 1

```
10
21
```

In the first test case, one optimal choice of $x$ is $3$. FJ can perform $10$ operations to make $a = [12, 12, 21, 3, 12]$.

### SCORING:

- Input 2: $N \le 1000$ and $M \le 1000$.
- Input 3: $N\le 1000$.
- Inputs 4-5: $M\le 10^5$.
- Inputs 6-16: No additional constraints.

Problem credits: Chongtian Ma

