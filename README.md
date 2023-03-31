# Brainfucc

Simple Brainfuck interpreter written in C, following the 
informal [specification](https://www.muppetlabs.com/~breadbox/bf/) 
provided by Brian Raiter in his website.

## Implementation details
- Interpreter ignores all characters except for the valid Brainfuck symbols
- Cell array has a size of 30000
- Value range of cells: -128 to 127 (char datatype)
- Unbalanced brackets cause undefined behavior, as currently there's no 
checking for it
- Increment or decrement commands that cause overflow on cells follow standard
C behavior of the value being wrapped around
- Trying to input a value when there is no more data in the input strem leaves
the current cell's value unchanged 
- Moving the array pointer out of bounds causes undefined behavior

## Building

``` bash
git clone git@github.com:joaoxyz/brainfucc.git
cd brainfucc
gcc brainfucc -o brainfucc
```

## Usage

``` bash
./brainfucc file.b
```
