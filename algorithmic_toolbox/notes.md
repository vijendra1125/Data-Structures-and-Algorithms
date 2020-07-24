<img src="https://render.githubusercontent.com/render/math?math=e^{i \pi} = -1">

# Week 1
## Testing:

* Test on the examples from the problem statement.
* Make a few other small test, solve them manually and check that your program output the correct answer. 
* Generate a big input and launch your program to check that it works fast enough and doesn’t consume too much memory. 
* Test for corner cases: smallest allowed value and largest allowed value (for integer overflow) of all input parameters, equal numbers in the input, verylong strings etc.
* Make stress test (comparison between naive and implementation to be considered with generated random inputs).


# Week 2

## Fibonacci numbers: 
* $F_{n} \newline
= 0 \;\;if \;n = 0, \newline
= 1 \;\;if \;n = 1, \newline
= F_{n-1} + F_{n-2} \;\;if \;n > 1$

* Fibonacci number grows as faster as power of 2, for eaxmple $F_{30}$ is over a million and $F_{100}$ already have 21 digits. In general 
  > $F_{n} > ~ 2^{0.649\,n}$

* Pisano period: 
  * For any integer $m≥2$, the sequence $F_{n}$ mod m is periodic. The period always starts with *0 1* and is known as Pisano period. 
  * Using above, in order to calculate caclate $F_{n}$ mod m where n is very large:
    * Find pisano period length for 'mod m' by finding index where *0 1* appears again while claculating mod
    * Divide n by pisano period length of 'mod m' to get reminder r $F_{r}$ mod m will be equal to $F_{n}$ mod m
    * Note:
        (a+b)%n = ((a%n) + (b%n)) % n <- use it with property of fibonacci
        number and it will help you overcome integer overflow problem
## Gereatest Common Divisor:
* For integers $a$ and $b$, $gcd(a,b)$ is greatest integer which divides both. 
* Lemma: Let $a'$ be the reminder when a is divided by b, then 
>>> $gcd(a,b) = gcd(b, a') = gcd(a', b)$

## Program's runtime complexity:
* Runtime depends on program and system used to run it. Increament because of system related factors like speed of computer, system architecture, compiler being used and detail of memory hirerarchy etc. is not so straight forward to calcuate but it multiply runtime by a (large) constant. so we need a method to measure runtime which ignore constant multiples.

* Asymptotic runtime measures how runtime scale with input size. 

* Below shows relative scaling of most useful ones for runtime measurement:
>>> $log(n) > \sqrt{n} > n > n.log(n) > n^2 > 2^n$

* Big-O Notation: 
  * $f(n) = O(g(n))$ is read as $f$ is Big-O $g$ and represents that $f(n)$ scales slower in compare to g(n) if there exist constants N and c so that for all $n >= N$, $f(n) <= c.g(n)$. 
  
  * Benefit of using Big-O notation: 
    * Clarifies growth-rate
    * Cleans up notation
    * Can ignore system related complicated details as its asymptotic
  * Cons definetily include that we lose detail of measured runtime 

  * Common rules of Big-O notation:
    * Multiplicative constant could be omitted 
    * Leave lower order term which becomes less significant as n grows and hence $5n^2 + 3n + 2$ becomes $O(n^2)$.
    * Note that growth rate of $5n^2 + 3n + 2$ is same as $n^2$
    * In order to keep bigger picture, we treat two functions equivalent if they differ only by multiplicative constant such that $f1/f2 <= constant1 \newline and \newline f2/f2 <= constant2$ 

* Other notation: 
  * As Big-O denotes <= $\Omega$ denotes >= and and $\Theta$ denotes ==

* Other runtime measurement notes:
  * Addition of n-bit number takes time roughly propotional to n

Useful logarithms for runtime measurement:
> $log_{a}(n^k) = k.log_{a}(n) \newline
log_{a}(n.m) = log_{a}(n) + log_{a}(m) \newline
n^{log_{a}(b)} = b^{(log_{a}(n)} \newline
log_{n}(a) . log_{b}(a) = log_{b}(n)$

## Additional Reading resource:
* Sanjoy Dasgupta, Christos Papadimitriou, and Umesh Vazirani. Algorithms (1stEdition). McGraw-Hill Higher Education. 2008.
  * Computing Fibonacci numbers: Section 0.2
  * Properties of Fibonacci numbers: Exercises 0.2–0.4
  * Greatest common divisor: Section 1.2.3
  * Big-O notation and growth rate: Section 0.3
* Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein. Introduction to Algorithms (3rd Edition). MIT Press and McGraw-Hill. 2009.
  * Greatest common divisor: Section 31.2
