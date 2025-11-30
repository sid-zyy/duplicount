# duplicount
duplicount – Duplicate Line Counter

duplicount is a simple command-line utility written in C that scans a text file, finds all duplicate lines, and prints each line along with how many times it appears.

It works by:

Reading every line from the input file

Storing the lines in memory

Sorting them using qsort

Counting consecutive duplicates and printing only those that appear more than once
