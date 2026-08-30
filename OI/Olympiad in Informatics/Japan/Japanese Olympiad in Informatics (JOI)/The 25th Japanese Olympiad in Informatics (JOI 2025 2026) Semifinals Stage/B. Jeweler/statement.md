# 3386-17241 - Jeweler

> [View the original problem](https://qoj.ac/contest/3386/problem/17241)

---
### Jeweler

JOI runs a jewelry shop. There are $N$ customers who want to buy jewels, and they are numbered from $1$ to $N$. Customer $i$ $(1 \le i \le N)$ can visit the shop at any time between time $L_i$ and time $R_i$, and intends to buy $C_i$ jewels.

Since JOI is busy, he cannot keep the shop open all the time. Therefore, he has considered $M$ possible opening plans. The plans are numbered from $1$ to $M$. Plan $j$ $(1 \le j \le M)$ keeps the shop open from time $S_j - 0.1$ to time $T_j + 0.1$.

For each plan, if there exists a time when both the shop is open and customer $i$ can visit, then customer $i$ visits the shop and buys $C_i$ jewels. Otherwise, customer $i$ does not visit and buys nothing.

You may assume that the shop has a sufficient number of jewels and will never run out of stock.

Given the information about the customers and the opening plans, write a program that computes, for each plan, the total number of jewels sold.

### Input Format

The input is given from standard input in the following format:

```
N
L1 R1 C1
L2 R2 C2
.
.
.
LN RN CN
M
S1 T1
S2 T2
.
.
.
SM TM
```

### Output Format

Print $M$ lines to standard output. On the $j$-th line $(1 \le j \le M)$, output the total number of jewels sold under plan $j$.

### Constraints

- $1 \le N \le 300,000$.
- $1 \le L_i < R_i \le 1,000,000$ $(1 \le i \le N)$.
- $1 \le C_i \le 10^9$ $(1 \le i \le N)$.
- $1 \le M \le 300,000$.
- $1 \le S_j \le T_j \le 1,000,000$ $(1 \le j \le M)$.
- All input values are integers.

### Scoring

1. (12 points) $N \le 1,000$, $M \le 1,000$.
2. (17 points) $S_j = T_j$ $(1 \le j \le M)$.
3. (21 points) $S_j = 1$ $(1 \le j \le M)$.
4. (23 points) $S_j \le S_{j+1}$ and $T_j \le T_{j+1}$ $(1 \le j < M)$.
5. (27 points) No additional constraints.

### Example

### Sample Input 1

```
3
3 4 10
5 8 20
6 10 30
3
4 6
1 2
6 8
```

### Sample Output 1

```
60
0
50
```

In Plan 1, the shop is open from time $3.9$ to time $6.1$. Customer 1 can buy at time $4$, customer 2 at time $5$, and customer 3 at time $6$. Thus, a total of $10 + 20 + 30 = 60$ jewels are sold.

In Plan 2, the shop is open from time $0.9$ to time $2.1$. No customer can visit during this time, so $0$ jewels are sold.

In Plan 3, the shop is open from time $5.9$ to time $8.1$. Customers 2 and 3 can both buy at time $7$, so $20 + 30 = 50$ jewels are sold.

This example satisfies the constraints of Subtasks 1 and 5.

### Sample Input 2

```
4
10 90 1
40 60 2
10 20 4
80 90 8
3
1 15
1 60
1 100
```

### Sample Output 2

```
5
7
15
```

In Plan 1, customers 1 and 3 can buy jewels, so $1 + 4 = 5$ jewels are sold.

In Plan 2, customers 1, 2, and 3 can buy jewels, so $1 + 2 + 4 = 7$ jewels are sold.

In Plan 3, all customers can buy jewels, so $1 + 2 + 4 + 8 = 15$ jewels are sold.

This example satisfies the constraints of Subtasks 1, 3, 4, and 5.

### Sample Input 3

```
10
55 882 861052753
104 734 331227764
492 694 240198464
481 506 377367203
131 185 327968773
124 129 970226535
92 125 133053911
356 442 758055457
21 759 730522637
259 481 948997757
9
50 287
510 735
158 431
113 768
328 894
783 881
163 692
42 862
43 752
```

### Sample Output 3

```
4303050130
2163001618
3957825141
5678671254
4247422035
861052753
4575390808
5678671254
5678671254
```

This example satisfies the constraints of Subtasks 1 and 5.

