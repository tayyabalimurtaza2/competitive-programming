# 1563 - It's Mooin' Time IV

> [View the original problem](https://usaco.org/index.php?page=viewproblem2&cpid=1563)

---
Bessie has a computer with a keyboard that only has two letters, M and O.

Bessie wants to type her favorite moo $S$ consisting of $N$ letters, each of which is either an M or an O. However, her computer has been hit with a virus. Every time she tries to type the letter O, every letter that she has typed so far flips, either from M to O or from O to M, before the O appears.

Is it possible for Bessie to type out her favorite moo?

Additionally, Bessie is given a parameter $k$ which is either $0$ or $1$.

- If $k = 0$, then Bessie only needs to determine whether it is possible to type out her favorite moo.
- If $k = 1$, then Bessie also needs to give an example of a sequence of keystrokes to type so she can type out her favorite moo.

### INPUT FORMAT (input arrives from the terminal / stdin):

The first line contains $T$, the number of independent test cases ($1\le T\le 10^4$) and $k$ ($0 \le k \le 1$).

The first line of each test case has $N$ ($1 \le N \le 2 \cdot 10^5$).

The second line of each test case has $S$. It is guaranteed that no characters will appear in $S$ besides $\texttt{M}$ and $\texttt{O}$.

The sum of $N$ across all test cases will not exceed $4 \cdot 10^5$.

### OUTPUT FORMAT (print output to the terminal / stdout):

For each test case, output either one or two lines using the following procedure.

If it is impossible for Bessie to type out $S$, print $\texttt{NO}$ on a single line.

Otherwise, on the first line print $\texttt{YES}$. Furthermore, if $k=1$, on the second line, print a string of length $N$, the characters in order that Bessie needs to type in order to type out her favorite moo. If there are multiple such strings, any will be accepted.

### Sample Input 1

```
2 0
3
MOO
5
OOMOO
```

### Sample Output 1

```
YES
YES
```

### Sample Input 2

```
2 1
3
MOO
5
OOMOO
```

### Sample Output 2

```
YES
OMO
YES
MOOMO
```

As Bessie types out $\texttt{MOOMO}$, this is how the letters change:

1. Before typing the first $\texttt{M}$, Bessie has an empty string. Afterwards, she has the string $\texttt{M}$.
2. After typing the first $\texttt{O}$, the $\texttt{M}$ flips to $\texttt{O}$, and then the $\texttt{O}$ is appended to form $\texttt{OO}$.
3. After typing the second $\texttt{O}$, the $\texttt{OO}$ flips to $\texttt{MM}$, and then the $\texttt{O}$ is appended to form $\texttt{MMO}$.
4. After typing the second $\texttt{M}$, Bessie has the string $\texttt{MMOM}$.
5. After typing the last $\texttt{O}$, the string $\texttt{MMOM}$ flips to $\texttt{OOMO}$, and then the $\texttt{O}$ is appended to form $\texttt{OOMOO}$, as desired.

### SCORING:

- Inputs 3-4: $k=0$.
- Inputs 5-6: $k=1, T \le 10^3, N \le 10$.
- Inputs 7-9: $k=1, T \le 10, N \le 1000$.
- Inputs 10-16: $k=1$.

Problem credits: Nick Wu

