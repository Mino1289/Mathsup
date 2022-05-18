# Mathsup

## Goal of Mathsup
### Goal

The goal of this project, is to perform fast operation between differents maths objects (Polynomes, Complexes, Matrices, and more..).  
Currently, we do support a lot of operation :

- Every operand for the [Complexes](complexe.c) type.
- A lot of operand for the [Polynomes](polynomes.c) type, which is based on the Complexes type.
- Some operand for both [squared](matricesquare.c) or not [Matrices](matrice.c).

### How to use
**NOT WORKNG NOW**  
Get the executable file or see [Compilation](#compiling).  
Then you can execute the program and :  
* Use it as an interpreter. (write you calculation in the terminal, which is not very convenient)
* Use it to read a file with the `-r` option. (Easier to use)

## Compiling
To compile from source, you must have make and gcc.
Then in the root of the project, type :
```sh
~$ make clean all run
```

The Mathsup project is currently platform independant (Windows & Linux).

## Contact
Create an [Issue](https://github.com/Mino1289/Mathsup/issues/new) to explain a problem or give us some advice / idea.
