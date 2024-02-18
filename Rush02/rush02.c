#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "helper_functions.c"
#include "build_arrays.c"

int     handle_block(int atoi_num, char **zero_to_nineteen, char **tens)
{
    if (atoi_num == 0)
        return (1);
    if (atoi_num >= 100)
    {
        ft_putstr(zero_to_nineteen[atoi_num / 100]);
        write(1, " ", 1);
        ft_putstr(tens[10]);
        if (atoi_num % 100 == 0)
            return (0);
        write(1, " and ", 5);
        atoi_num = atoi_num % 100;
    }
    if (atoi_num < 20)
        ft_putstr(zero_to_nineteen[atoi_num]);
    else
    {
        ft_putstr(tens[atoi_num / 10]);
        if (atoi_num % 10 == 0)
            return (0);
        write(1, "-", 1);
        ft_putstr(zero_to_nineteen[atoi_num % 10]);
    }
    return (0);
}

void    print_number(char *number, char **zero_to_nineteen, char **tens, char **big_boys)
{
    int   i;
    int   c;
    int   atoi_block;
    int   skip_intermezzo;

    i = 0;
    skip_intermezzo = 1;
    c = ft_strlen(number) / 3 - 1;
    while (i < ft_strlen(number) - 2)
    {
        if (!skip_intermezzo) {
            write(1, ", ", 2);
        }
        atoi_block = ft_atoi(ft_strslice(number, i, i + 2));
        skip_intermezzo = handle_block(atoi_block, zero_to_nineteen, tens);
        if (!skip_intermezzo && c != 0)
        {
            write(1, " ", 1);
            ft_putstr(big_boys[c]);
        }
        c--;
        i += 3;
    }
    write(1, "\n", 1);
}

char    *pad_number(char *number)
{
    if (ft_strlen(number) % 3 == 1)
        return (ft_strcat("00", number));
    else if (ft_strlen(number) % 3 == 2)
        return (ft_strcat("0", number));
    return number;
}

int     check_arguments(int argc, char *argv[])
{
    if (argc < 2 || argv[1][0] == '-')
    {
        write(1, "Error\n", 6);
        return (0);
    }
    if (argc == 2 && ft_strlen(argv[1]) >= 40)
    {
        write(1, "Dict Error\n", 12);
        return (0);
    }
    return (1);
}

void    cleanup(char **zero_to_nineteen, char **tens, char **big_boys)
{
    int j;

    j = 0;
    while (j < 20)
    {
        free(zero_to_nineteen[j]);
        j++;
    }
    j = 2;
    while (j < 11)
    {
        free(tens[j]);
        j++;
    }
    j = 1;
    while (j < 13)
    {
        free(big_boys[j]);
        j++;
    }
}

int main(int argc, char *argv[])
{
    int     fd;
    char    *number;
    char    *tens[11];
    char    *zero_to_nineteen[20];
    char    *big_boys[13];

    if (!check_arguments(argc, argv))
        return (0);
    if (argc == 3)
    {
        fd = open(argv[1], O_RDONLY);
        number = argv[2];
    }
    else
    {
        fd = open("numbers.dict", O_RDONLY);
        number = argv[1];
    }
    read_dictionary(fd, tens, zero_to_nineteen, big_boys);
    close(fd);
    print_number(pad_number(number), zero_to_nineteen, tens, big_boys);
    cleanup(zero_to_nineteen, tens, big_boys);
    return (0);
}