# 3386-17240 - Seats 3

> [View the original problem](https://qoj.ac/contest/3386/problem/17240)

---
There are $2N + 2$ seats arranged in a row. The comfort level of the $i$-th seat from the left $(1 \le i \le 2N + 2)$ is $A_i$.

There are $N$ groups of two people each, and 2 VIP guests who came alone, making a total of $2N + 2$ guests. Each guest must be assigned exactly one seat. No seat may be assigned to more than one guest.

The two people belonging to the same group must be assigned to adjacent seats.

Your task is to write a program that, given the seat information, computes the maximum possible sum of the comfort levels of the two seats assigned to the two VIP guests.

### Input

The input is given from standard input in the following format:

```
N
A_1 A_2 \cdots A_{2N+2}
```

### Output

Output the maximum possible sum of the comfort levels of the two seats assigned to the two VIP guests in a single line.

### Constraints

- $1 \le N \le 200,000$.
- $1 \le A_i \le 10^9$ $(1 \le i \le 2N + 2)$.
- All input values are integers.

### Scoring

1. (10 points) $N = 1$.
2. (10 points) $N \le 2$.
3. (10 points) $N \le 3$.
4. (30 points) $N \le 2,000$.
5. (40 points) No additional constraints.

### Example

#### Example 1

**Input**

```
2
20 60 40 30 10 50
```

**Output**

```
90
```

By assigning seats as follows, the sum of the comfort levels for the two VIP guests becomes $90$:

- Assign seats $1$ and $2$ (from the left) to the first group.
- Assign seats $4$ and $5$ (from the left) to the second group.
- Assign seats $3$ and $6$ (from the left) to the two VIP guests.

It is impossible to achieve a sum greater than $90$, so output $90$.

This input satisfies the constraints for Subtasks 2, 3, 4, and 5.

#### Example 2

**Input**

```
1
1000000000 1000000000 1 1
```

**Output**

```
2000000000
```

This input satisfies the constraints for all subtasks.

#### Example 3

**Input**

```
4
4 10 8 6 7 6 7 8 12 3
```

**Output**

```
16
```

This input satisfies the constraints for Subtasks 4 and 5.

