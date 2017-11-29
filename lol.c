# include <stdio.h>

typedef union		s_mdr
{
	unsigned int	color;
	struct
	{
		char		a;
		char		r;
		char		g;
		char		b;
	}c;
}					t_color;

typedef struct		s_lol
{
	int		a;
	char	b;
	double	c;
	char	d[4];
	struct
	{
		int		a;
		int		b;
	} r;
}					t_lol;

void	ft_multiputs(char **lol)
{
	for (int i = 0; lol[i]; i++)
		printf("%s\n", lol[i]);
}

void	fuck_the_norm(t_lol *m)
{
	printf("%d %c %lf %s", m->a, m->b, m->c, m->d);
}

int		main()
{
	t_lol	mdr;
	t_lol	*s;
	t_color	c;

	mdr = (t_lol){.a = 12};
	c = (t_color){.c.a = 0xE0};
	printf("%08X\n", c.color);
	s = &mdr;
	*s = (t_lol){};
	ft_multiputs((char *[]){"lol", "mdr", "keskonsmar", NULL});
	fuck_the_norm(&(t_lol){16, 'a', 7.8923, {'a', 'b', 'c', '\0'}, {}});

}
