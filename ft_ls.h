/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijerde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 00:32:16 by jijerde           #+#    #+#             */
/*   Updated: 2019/10/06 18:04:13 by jijerde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

#define NAME_MAX 14
//#define S_IFMT 0160000 /* тип файла */
#define S_IFDIR 0040000 /* каталог */
#define S_IFCHR 0020000 /* символьно-ориентированный */
#define S_IFBLK 0060000 /* блочно-ориентированный */
#define S_IFREG 0100000 /* обычный */

#define EDOM
#define EILSEQ
#define ERANGE
extern int errno;

typedef struct	s_flags
{
	int t;
	int r;
	int l;
	int rec;
	int a;
	int	tdr;
	int tds;
	int ter;
	int terd;
	int tfr;
	int fir;
	int reci;
}				t_flags;

typedef	struct	s_f
{
	char		*fname;
	struct s_f	*right;
	struct s_f	*left;
}				t_ree_files;

typedef	struct	s_e
{
	char		*name;
	char		*s;
	struct s_e	*right;
	struct s_e	*left;
}				t_ree_errors;

typedef	struct	s_d
{
	int fft;
	struct s_d		*fofreetd;
	struct s_d		*fofreetdr;
	char			*path;
	char			*dname;
	char			*s;         //for strerror
	struct s_d		*right;
	struct s_d		*left;
}				t_ree_dir;

typedef	struct	s_u
{
	int fftu;
	t_ree_dir	tr_dir;
	char		*tdname;
	struct s_u	*right;
	struct s_u	*left;
}				t_ree_trdirs;

typedef struct	s_dirs
{
	char			*name;
	struct s_dirs	*next;
}				t_dirs;

typedef	struct	s_uv
{
    t_ree_errors    *te;
    t_ree_files		*tf;
    t_dirs			*dirs;
    t_dirs			*first;
    t_dirs			*firstforfree;
    t_ree_trdirs	*fofreetu;
	t_ree_trdirs	*tr_tdroot;
	t_ree_trdirs	*tr_td;
}				t_trpointers;

void			treeprint(t_ree_dir *td, t_flags *fl);
t_dirs			*ft_lstsort(t_dirs *dirs);
t_ree_dir		*filltd(t_ree_dir *td, char *name, char *p);
//t_ree_dir		filltdr(t_ree_dir *td, char *name);
//t_ree_trdirs	filltur(t_ree_trdirs *tu, char *name, t_flags *fl);
t_ree_trdirs	*filltu(t_ree_trdirs *tu, char *name, t_flags *fl);
void			ft_treedirs(char *name, t_flags *fl, t_trpointers *tp);
void			ft_fillfl(t_flags *fl);
void			ft_filldirs(t_dirs	*dirs);
void			findtree(t_ree_trdirs *tua, t_flags *fl, int argc);
t_ree_dir		ft_dir(char *name, t_flags *fl, struct	s_d	*tr_trees);
void			ft_r(t_ree_trdirs *tua, t_flags *fl, t_trpointers *tp);
char			*ft_strjoinp(char *s1, char const *s2);
t_ree_errors	*fillte(t_ree_errors *te, char *name, char *s);
void            ft_err(t_trpointers *tp, char *name, char *s, t_flags *fl);
void			ft_files(t_trpointers *tp, char *name, t_flags *fl);
void            errprint(t_ree_errors *te);
void			filesprint(t_ree_files *tf);
t_ree_dir		*ft_errd(t_ree_dir *td, char *s, char *name, t_flags *fl);
char			*ft_name(char *name);
t_ree_dir		*fillemp(t_ree_dir *td);
t_ree_files		*filltf(t_ree_files *tf, char *name);
//void			ft_trfree(t_ree_trdirs *tua);
void			freemem(t_ree_trdirs *tua, t_flags *fl);
void			freedirs(t_dirs *dirs);
void			freememerr(t_ree_errors	*te, t_flags *fl);
void			freememfiles(t_ree_files *tf, t_flags *fl);
/*  typedef struct
{
	long ino; //номер inode
	char name[NAME_MAX + 1];
}	Dirent;

typedef struct
{
	int fd; //fd каталога
	Dirent d; //элемент каталога
}	DIR;*/

//DIR		*opendir(char *dirname);
//struct dirent	*readdir(DIR *dfd);
//void	closedir(DIR *dfd);
//int		stat(const char *file_name, struct stat *buf);
