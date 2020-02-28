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
./ft_ls [-l] [-R] [-a] [-r] [-t] [-A] args
```

### Options
|        |        |
| ------ | ------ |
| -l | Lists in long format, giving mode, number of links, owner, group, size in bytes, and time of last modification for each file (see above). If the file is a special file, the size field instead contains the major and minor device numbers. If the time of last modification is greater than six months ago, it is shown in the format `month date year' for the POSIX locale |
| -R | Returns true if file is "character-special." |
| -a | Returns true if file is a directory. |
| -r | Returns true if file exists. |
| -t | Returns true if file exists, and is a regular file. |
| -A | Returns true if file has the setgid bit set. |
