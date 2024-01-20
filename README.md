# Line-by-line: Solutions to programming problems in C

## 1. Build

1.1. Requires a linux system with `gcc`.

1.2. Run `gcc -std=c89 -m64 -pedantic -Wall -Wextra -Wshadow -Wno-variadic-macros -I ./ *.c -o ./lbl`.

## 2. Run

2.1. Requires [-> 1. Build](#1-build).

2.2. List all available problems by running `lbl` or `lbl list`.

2.3. Execute the solution for a problem by running `lbl run N`, where `N` is the problem number.

2.4. Run `lbl help` for additional options.

## 3. Test

3.1. Requires [-> 1. Build](#1-build).

3.2. List all available problems by running `lbl` or `lbl list`.

3.3. Run all tests for a problem by running `lbl test N`, where `N` is the problem number.

3.4. Run all tests for all problems by running `lbl test`.
