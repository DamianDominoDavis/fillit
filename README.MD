**fillit**
===

Subject
---
**fillit** reads and assembles tetronimo pieces into the smallest available square. Its complete requirements and restrictions are described in the 42 [subject PDF](https://github.com/DamianDominoDavis/fillit/blob/master/fillit.en.pdf).

Make
---
Some of the usual rules, `all`, `clean`, `fclean`, and `re`. Note that `clean` and `fclean` will also execute on **libft**, if possible. And a few new rules:

- `libft/libft.a`: make **libft**, but do not make **get_next_line**.
- `libsync`: delete **libft**, clone from repo defined in *Makefile*'s `$(LSRC)` (cbrill's, by default)
- `libclean`: **libft**'s `clean`, if possible.
- `libfclean`: **libft**'s `fclean`, if possible.
- `just`: convenience `make re && make clean` for a tidy rebuild.
- `do`: convenience `just` and immediately execute with ?target?, to quickly demo **get_next_line**.
