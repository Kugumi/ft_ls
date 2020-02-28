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
|          |        |
| ------   | ------ |
| -l | Lists in long format. |
| -R | Recursively lists subdirectories encountered. |
| -a | Lists all entries, including those that begin with a dot (.), which are normally not listed. |
| -r | Reverses the order of sort to get reverse alphabetic, oldest first, or smallest file size first as appropriate. |
| -t | Sorts by time stamp (latest first) instead of by name. The default is the last modification time. |
| -A | Lists all entries, including those that begin with a dot (.), with the exception of the working directory (.) and the parent directory (..). |

### Options
|        |        |
| ------ | ------ |
| -l | Returns true if file is "block-special". |
| -R | Recursively lists subdirectories encountered. |
| -a | Lists all entries, including those that begin with a dot (.), which are normally not listed. |
| -r | Returns true if file exists. |
| -t | Returns true if file exists, and is a regular file. |
| -A | Returns true if file has the setgid bit set. |


