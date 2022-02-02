#ifndef FT_DLIST_H
# define FT_DLIST_H
# include "libft.h"

typedef struct s_double_list
{
	void			*content;
	struct s_double_list	*next;
	struct s_double_list	*last;
}	t_dlist;

t_dlist	*ft_dlstnew(void *content);
void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new);
int		ft_dlstsize(t_dlist *dlst);
t_dlist	*ft_dlstlast(t_dlist *dlst);
void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new);
void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *));
void	ft_dlstclear(t_dlist **dlst, void (*del)(void *));
void	ft_dlstiter(t_dlist *dlst, void (*f)(void *));
t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *));

#endif
