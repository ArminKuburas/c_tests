# c_tests

Small C programs I wrote to test and explain language features. Some are demos for two presentations on C. Each program is short and stands alone, except where noted.

All commits are mine. This is a scratch repo, not a finished project.

## Contents

| Folder | What it shows |
| --- | --- |
| `code_demo_for_presentation/` | Presentation demos, one file per topic: enums, global variables, pointers (pointer to pointer, `malloc`, freeing), structs, unions, and swapping two ints with XOR. |
| `code_for_second_presentation/` | Second presentation. `demo_of_binary_trees.c` builds a binary search tree (insert, then in-order, pre-order and post-order printing). `trigraph_showcase.c` is a program written with C trigraphs such as `??<` for `{`. |
| `code_for_second_presentation/hash_functions/` | A small hash table: create hash, insert, search, resize and free. `main.c` reads keys from the terminal and is meant to double the table when it is more than 70% full. The Makefile builds the library `hash.a`. Known bug: the resize frees keys that the new table still points to, so `main.c` crashes with a double free at the 12th key. |
| `newer_test/` | Later experiments: unions with a struct inside, array and pointer syntax, function pointers (add, subtract, multiply, divide), passing a function as a parameter, a trigraph `??!??!` example, and a hash table using the djb2 hash. |
| `older_tests/` | Early tests: the comma operator and `2[str]` indexing, a struct with strings, the unsigned wraparound of `size_t i = -1`, two FizzBuzz versions, and a bash script `map_maker.sh` (`bash map_maker.sh 8 5 valid`) that makes random maps and writes `.ber` files in the current directory. |
| `rush-02/` | Hash table helper sources (`create_hash.c`, `insert_hash.c`, `search_hash.c`) and `rush02.h`. `main.c` and the `Makefile` are empty, so it does not build into a program. |

## Compile one demo

Single-file demos need only a C compiler:

```
cc -Wall -Wextra -Werror code_demo_for_presentation/union_examples.c -o union_examples
./union_examples
```

Trigraphs are off in the default GNU mode, so add `-trigraphs` for the trigraph files:

```
cc -trigraphs newer_test/new_weird_thing.c -o new_weird_thing
./new_weird_thing
```

The same applies to `code_for_second_presentation/trigraph_showcase.c`, which compiles with one warning (implicit `int`). Without `-trigraphs` it fails to compile.

The hash table with `main.c` needs the GNU readline library (`libreadline-dev` on Debian or Ubuntu):

```
cd code_for_second_presentation/hash_functions
make
cc -Wall -Wextra -Werror main.c hash.a -lreadline -o hash_demo
./hash_demo
```

Type keys, then press Ctrl-D to print the table. With 11 keys or fewer it works. The 12th key triggers the resize bug above and the program aborts.

`newer_test/hash_test_with_djb2.c` also uses readline:

```
cc newer_test/hash_test_with_djb2.c -lreadline -o hash_test
```

It asks for keys to insert (Ctrl-D ends that phase), then keys to search for. At the end it can segfault. Treat it as an unfinished experiment.

Some files are strange on purpose, so expect warnings from the files in `older_tests/` and `newer_test/`. Do not use `-Werror` on those. `newer_test/example.c` and `older_tests/test.c` do not compile (one is junk text, the other has no `main`), `older_tests/fizzbuzz_test_02.c` takes a number argument and aborts on `15`, and `rush-02/` has no `make` target.
