fillit
===
**fillit** reads and assembles tetronimo pieces into the smallest available square. Its complete requirements and restrictions are described in the 42 [subject PDF](https://github.com/DamianDominoDavis/fillit/blob/master/fillit.en.pdf). A sample tetronimo file is provided as *tet.txt*.

Make
---
Some of the usual rules, `all`, `clean`, `fclean`, and `re`. Note that `clean` and `fclean` will also execute on **libft**, if possible. And a few new rules:

- `libft/libft.a`: make **libft**, but do not make **fillit**.
- `libsync`: delete **libft**, clone from repo defined in *Makefile*'s `$(LSRC)` (default cbrill's)
- `libclean`: **libft**'s `clean`, if possible.
- `libfclean`: **libft**'s `fclean`, if possible.
- `just`: `make re && make clean`, convenience for a tidy rebuild.
- `do`: `make just && ./fillit $(TARGET)`, to quickly demo **fillit** (*Makefile*'s `$(TARGET)`, default *tet.txt*)
