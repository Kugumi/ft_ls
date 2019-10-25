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
#include <grp.h>
#include <pwd.h>
#include <time.h>
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

typedef struct  s_lc
{
	int			c2;
	size_t		c3;
	size_t		c4;
	int			cmajor;
	int			cminor;
	int			c5;
	long long	total;
	int			gg2;
}               t_lc;

typedef struct	s_signs
{
	int t;
	int r;
	int l;
	int rec;
	int a;
	int abig;
	int	tdr;
	int tds;
	int ter;
	int terd;
	int tfr;
	int fir;
	int reci;
	int ac;
}				t_signs;

typedef	struct	s_f
{
	int 			nl;
	int				major;
	int				minor;
	long long		size;
	long long			sec;
	char			*fname;
	char			*time;
	char 			*rwx;
	char			*buff;
	char			*uid;
	char			*gid;
	struct s_f		*right;
	struct s_f		*left;
}				t_ree_files;

typedef	struct	s_e
{
	char		*name;
	char		*s;
	struct s_e	*right;
	struct s_e	*left;
}				t_ree_errors;

typedef	struct	s_ree_dir
{
	int 					nl;
	int						major;
	int						minor;
	long long				size;
	long long				sec;
	char					*time;
	char 					*rwx;
	char					*buff;
	char					*uid;
	char					*gid;
	int						fft;
	struct s_ree_dir		*fofreetd;
	struct s_ree_dir		*fofreetdr;
	char					*path;
	char					*dname;
	int 					gg;
	char					*s;         //for strerror
	struct s_ree_dir		*right;
	struct s_ree_dir		*left;
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

typedef struct	s_alldirs
{
	char				*name;
	struct s_alldirs	*next;
}				t_alldirs;

typedef	struct	s_uv
{
	int 			gg;
	int				l;
	int 			t;
	t_lc			lenc;
    t_ree_errors	*teroot;
	t_ree_errors    *te;
	t_ree_files		*tfroot;
    t_ree_files		*tf;
    t_dirs			*dirs;
    t_dirs			*first;
    t_dirs			*firstforfree;
	t_ree_trdirs	*tr_tdroot;
	t_ree_trdirs	*tr_td;
	long long		tsec;
	char			*tmp;
}				t_trpointers;

void			treeprint(t_ree_dir *td, t_signs *fl, t_trpointers *tp);
void			treeprintr(t_ree_dir *td, t_signs *fl);
t_dirs			*ft_lstsort(t_dirs *dirs);
t_dirs			*ft_lstsortr(t_dirs *dirs);
t_ree_dir		*filltd(t_ree_dir *td, char *name, char *p, t_trpointers *tp);
//t_ree_dir		filltdr(t_ree_dir *td, char *name);
//t_ree_trdirs	filltur(t_ree_trdirs *tu, char *name, t_signs *fl);
t_ree_trdirs	*filltu(t_ree_trdirs *tu, char *name, t_signs *fl);
t_ree_dir		*ft_treedirs(char *name, t_signs *fl, t_trpointers *tp);
void			ft_treedirsr(char *name, t_signs *fl, t_trpointers *tp);
void			ft_fillfl(t_signs *fl, t_trpointers	*tp);
void			ft_filldirs(t_dirs	*dirs);
void			findtree(t_ree_trdirs *tua, t_signs *fl, int argc);
void			findtreer(t_ree_trdirs *tua, t_signs *fl, int argc);
t_ree_dir		*ft_dir(char *name, t_signs *fl, t_ree_dir	*tr_trees, t_trpointers *tp);
t_ree_dir		*ft_dirt(char *name, t_signs *fl, t_ree_dir	*tr_trees, t_trpointers *tp);
t_ree_dir		*ft_dirr(char *name, t_signs *fl, t_ree_dir	*tr_trees, t_trpointers *tp);
t_ree_dir		*ft_dirrt(char *name, t_signs *fl, t_ree_dir	*tr_trees, t_trpointers *tp);
void			ft_r(t_ree_dir *t, t_signs *fl, t_trpointers *tp);
void			ft_r1(t_ree_trdirs *tua, t_signs *fl, t_trpointers *tp);
char			*ft_strjoinp(char *s1, char const *s2);
t_ree_errors	*fillte(t_ree_errors *te, char *name, char *s);
void            ft_err(t_trpointers *tp, char *name, char *s, t_signs *fl);
void			ft_files(t_trpointers *tp, char *name, t_signs *fl);
void			ft_filesr(t_trpointers *tp, char *name, t_signs *fl);
void            errprint(t_ree_errors *te);
void			filesprint(t_ree_files *tf, t_signs *fl, t_trpointers *tp);
t_ree_dir		*ft_errd(t_ree_dir *td, char *s, char *name, t_signs *fl);
char			*ft_name(char *name);
t_ree_dir		*fillemp(t_ree_dir *td);
t_ree_files		*filltf(t_ree_files *tf, char *name, t_signs *fl, t_trpointers *tp);
//void			ft_trfree(t_ree_trdirs *tua);
void			freemem(t_ree_trdirs *tua, t_signs *fl);
void			freedirs(t_dirs *dirs);
void			freememdir(t_ree_dir *td, t_signs *fl, t_trpointers *tp);
void			freememerr(t_ree_errors	*te, t_signs *fl);
void			freememfiles(t_ree_files *tf, t_signs *fl);
char			*drwx(int mode);
void			chtime(char *time);
t_lc			total(char *name, t_lc len, t_trpointers *tp);
t_lc			zerostruct(t_lc	len);
long long		totaltotal(char *name, t_trpointers *tp, t_signs *fl);

int	ft_lenlst(t_dirs *forlen);
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
