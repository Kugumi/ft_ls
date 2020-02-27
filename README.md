# ft_ls

To Recode ls and some of its options allow to find out **how to interact with
the file system using C.**

### Installation

```
$ git clone https://github.com/Kugumi/ft_ls.git
$ cd ft_ls
$ make
```

### Syntax

```
./ft_ls [-l] [-R] [-a] [-r] [-t] [-A] arg
```

### Options
|        |        |
| ------ | ------ |
| -l | Returns true if file is "block-special". |
| -R | Returns true if file is "character-special." |
| -a | Returns true if file is a directory. |
| -r | Returns true if file exists. |
| -t | Returns true if file exists, and is a regular file. |
| -A | Returns true if file has the setgid bit set. |
