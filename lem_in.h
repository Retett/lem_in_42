/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:51:43 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/19 13:51:44 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft_42/libft.h"
# include "get_next_line.h"
# define STEP 1
# define PATH 1
# define EMPTY 0
# define CLOSE 1
# define OPEN 		0
# define START 		1
# define END 		2
# define NOTHING 	0
# define LINKS 		3
# define STOP_IT 	-1
# define ROOMS 		4
# define GREY 		1
# define BLACK 		2
# define DEAD_END 	-1
# define MAX_INT	2147483647
# define MIN_INT	-2147483648
# define START_STR	"##start"
# define END_STR	"##end"

# define CHECK(x) !(x) ? exit(1) : 1

typedef struct s_room			t_room;
typedef struct s_lem_in			t_lem_in;
typedef	struct s_join			t_join;
typedef	struct s_path			t_path;
typedef	struct s_mark			t_mark;
typedef struct s_print_sol		t_print_sol;

struct							s_mark
{
	t_room			*room;
	struct s_mark	*next;
};

struct							s_print_sol
{
	char				**name;
	int					end;
	struct s_print_sol	*next;
};

struct							s_join
{
	t_room			*room;
	struct s_join	*next;
};

struct							s_room
{
	int				x;
	int				y;
	char			*name;
	int				empty;
	int				pos;
	int				see;
	int				door;
	int				step;
	t_join			*join;
	struct s_room	*next;
};

struct							s_path
{
	struct s_path	*next;
	int				road;
	int				wait;
	int				check;
	t_mark			*room;
	t_print_sol		*print;
	char			**name;
};

struct							s_lem_in
{
	int			ants;
	char		*str;
	t_room		*start;
	t_room		*end;
	int			room_flag;
	int			link_flag;
	t_room		*room;
	t_path		*path;
};

void							parse_lem_data(t_lem_in *lem);
void							parse_hash(t_lem_in *lem, char	**str, int pos);
void							parse_links(t_lem_in *lem, char	**str);
void							parse_rooms(t_lem_in *lem, char	**str);
void							ft_push_room(t_lem_in *lem, t_room *room);
void							ft_push_hash(t_lem_in *lem, t_room *room);
void							ft_push_links(t_room *tmp, t_room *tmp_2);
void							ft_exit(char *error);
void							ft_arr_free(char **str);
void							search_length(t_lem_in *lem);
void							print_move_ants(t_lem_in *lem);
void							search_short_path(t_lem_in *lem);
void							path_count(t_path *lem);
void							parse_ants(t_lem_in *lem);
void							parse_link(t_lem_in *lem, char *line);
int								parse_room(t_lem_in *lem, char *str, int parse);
void							add_short_path(t_path *path, t_room *add);
void							print_add(t_path *path, int name);
void							free_all_unusing(t_lem_in *lem);
void							init_wait(t_path *path);

t_path							*add_move(t_path *path, t_path *add);
t_path							*start_search(t_room *tmp_2, t_path *path);

char							*ft_next(char *s1, char *s2);
int								get_next_line(const int fd, char **line);
int								ft_check(t_room *lem, char *str);
int								move_ants(t_lem_in *lem);

void							debug_mod_activated(t_lem_in *lem,
								int ac, char **av);
int								check_rooms(char **str);
int								check_link(t_lem_in *lem, char **str);
int								len_path(t_lem_in *lem);
void							add_line_to_line(t_lem_in *lem, char *line);
char							*ignor_comment(t_lem_in *lem);
#endif
