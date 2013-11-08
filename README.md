mrpgstat
========

Simple and fast statistics

This is a very simple and easy-to-use statistics program. With input from
stdin, it provides some information about standard deviation, average,
minimum and maximum.

When the input is a binomial distribution with a sufficiently large
sample, this program is also for estimating the underlying probability p.

This programm is using double precision in C++.

Simply use ***make*** to build from source. The binary can be installed
with ***make install***.

Example
-------

There is a random number generator equipped with this distribution of
mrpgstat. You can use it like this:

> perl gen.pl | ./mrpgstat

If you have a file _file.txt_ with some samples, you can invoke the program like this:

> ./mrpgstat < file.txt

Todo
----

  - Parallelization
