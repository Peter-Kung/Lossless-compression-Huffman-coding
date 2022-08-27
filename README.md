# Huffman Compression

## Introduction

In non-loss data compression, Huffman code is a wide range utilization and effective way. It compression concept is make a symbal base on it's appear frequency.

This project use minheap to make huffman tree, and use huffman tree get symbal table of source data.


## Compression rate

```
$ ./client
...
...
W: 35
X: 41
Y: 35
Z: 48
diff count: 26
Decode Data:
...
...
```

26 * 8bits = 8008

```
$ cat HuffmanCode.txt
O 0000
E 0001
C 0010
P 0011
U 0100
Z 0101
V 01100
A 01101
L 01110
Q 01111
T 10000
G 10001
I 10010
M 10011
Y 10100
W 10101
D 10110
N 10111
H 11000
S 11001
K 11010
J 11011
X 11100
B 11101
F 11110
R 11111
```

4 bits * 6 alphabets + 5 bits * 20 alphabets = 124

Compression rate = ( 1 - (124 / 8008)) * 100% = 98%


## How to use

```
$ make
```

it will spawn object file `client`, then execute `client`

```
$ ./client
```

it will spawn three files:
- HuffmanCode.txt: alphabet symbal table
- encoding.txt: target comparess file
- decoding.txt: decode encoding data into original data





