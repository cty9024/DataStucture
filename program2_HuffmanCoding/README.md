# Program Assignment 2: Huffman Coding

**Course:** Introduction to Data Structures and Object-Oriented Programming  
**Instructor:** Prof. Feng-Jian Wang 

---

## Assignment Description

### Part 1: Building the Huffman Tree  
Write a C++ function to construct a Huffman tree using the following alphabets and their respective weights:

|||||||
|--------|--------|--------|--------|--------|--------|  
| A = 11 | B = 5  | C = 2  | D = 3  | E = 12 | F = 3  |
| G = 5  | H = 6  | I = 8  | J = 1  | K = 2  | L = 4  |
| M = 8  | N = 7  | O = 2  | P = 2  | Q = 1  | R = 9  |
| S = 6  | T = 2  | U = 4  | V = 1  | W = 10 | X = 10 |
| Y = 1  | Z = 1  |        |        |        |        |

### Part 2: Encoding Text Using Huffman Tree
Write a C++ program to:  
1. Read characters from a file (e.g., `./test/1.txt`).  
2. Use the Huffman tree created in **Part 1** to convert each letter into its corresponding Huffman code.  

### Part 3: Decoding Huffman Code
Extend the program from **Part 2** to:  
1. Read Huffman code (e.g., `0101000…`) from the same file.  
2. Use the Huffman tree from **Part 2** to decode the Huffman code back into characters.  
