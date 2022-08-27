# Huffman Compression

## Introduce 

In non-loss data compression, Huffman code is a wide range utilization and effective way. It compression concept is make a symbal base on it's appear frequency.

This project use minheap to make huffman tree, and use huffman tree get symbal table of source data.


## Compression rate

```
$ wc -m OriginalData.txt
1001 OriginalData.txt
```

26 * 8bits = 8008

```
$ cat HuffmanCode.txt
T 0000
G 0001
I 0010
M 0011
Y 0100
W 0101
D 0110
N 0111
H 10000
S 10001
K 10010
J 10011
X 10100
B 10101
F 10110
R 10111
O 11000
E 11001
C 11010
P 11011
U 11100
Z 11101
V 111100
A 111101
L 111110
Q 111111
```

4 * 8 + 5 * 14 + 4 * 6 = 126

Compression rate = ( 1 - (126 / 8008)) * 100% = 98%


## How to use

```
$make
```

it will spawn three file:
- HuffmanCode.txt: alphabet symbal table
- encoding.txt: target comparess file
- decoding.txt: decode encoding data into original data





