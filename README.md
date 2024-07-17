# read_line_bench

This repo is a joke, though the results are "real".

## The why

Why not?

## The how

Using `time` to measure the execution of the programs.
I do not have the proper skills to optimize any of these programs, so take it with a shovel of salt.

## The test

File generated by while loop of monkey typing on keyboard and redirected to a filename.extensionsdontmatter file.

Data: 1.2G
Lines: 27276413

"Benchmarking" the following languages by reading each line and bytes:
 - C (The lords language, line counting is wrong because of skill issues)
 - Zig (Fun, though not my code. see [https://www.openmymind.net/Performance-of-reading-a-file-line-by-line-in-Zig/])
 - Go (Also fun, and not my code. see [https://www.openmymind.net/Performance-of-reading-a-file-line-by-line-in-Zig/])
 - Rust (chatgippidy)
 - Python (Googling)
 - Bash (Yeah.. the infra in me kicked in)
 - C with pthreads (I suck at pthreads so it's slower)
 - wc coreutil (Their code is better by kilometers)


## RESULTS

unremarkable.
Also because the programs are horribly coded so even the line counts are messed up, though the Zig and Go codes are great because I did not write them.

C is fast, Python is slow and Bash is slower.
The interesting bit here is that Zig still remains slow. This was after all inspired by this great post: [https://www.openmymind.net/Performance-of-reading-a-file-line-by-line-in-Zig/]



The below should be a tabel:
Lang       Time
C          0m0.585s
Rust       0m6.030s
Go         0m2.142s
Zig        0m3.016s
Cpthreads  0m1.381s
wc         0m0.191s
python3    0m3.187s
