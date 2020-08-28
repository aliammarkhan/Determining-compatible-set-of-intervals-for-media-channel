# Determining-compatible-set-of-intervals-for-media-channel
An application of a Binary Search Tree

## About Problem
One of the main application of Binary Search Trees are for handling a dynamically changing
datasets. This can be very efficient choice for deciding many compatible issues. One of the media
channel is looking to decide a non-overlapping intervals for their transmission. Each program from
the channel is comprises of a start time, duration and commercial time for the program. For an
example an Interval I (start_time, duration, ctime) = (2, 6, 3) implies that the program starts at 2
and can be finish by 11 with commercial time included for on airing the show. The program
managers collect all programs information is a single file. There are 5 program managers and each
provides program information in a file. All you need to maintain a combine data structures that
maintain a non-overlapping compatible set of programs for the channel and maintain a separate
file for all those program that are conflicting in time. For example, consider the files from the 2
programs managers: 

```bash
Program Manager #1 
5
2 3 2
54 5 2
9 10 1
26 10 4
65 5 4 

Program Manager #2
3
16 4 4
7 5 3
3 3 1 
```
The channel does not want a silent period of transmission and select a program that is close to
reduce the silent time. 

```bash
Compatible Programs 
2 3 2
7 5 3
16 4 4
26 10 4
54 5 2
65 5 4 


Conflicting programs 
3 3 1
9 10 1 
```
We need to maintain a BST for maintaining a set of compatible programs. The searching and
finding a conflict in program can be perform in log n time.

Input
The input is provided by a set of files; the processing order can be random order of files. As there
are 5 program managers you can have five input files. The convention is A3P1ProgMgr1.txt The
first line of each file contains number of programs with three consecutive positive integers.

Output
There will be 2 output files. One with set of all compatible programs in ascending order of start
time. Second file contains all conflicting programs again ascending order of start time. 



