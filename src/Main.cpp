/*
** EPITECH PROJECT, 2019
** CNA_groundhog_2018
** File description:
** main
*/

#include "Main.hpp"

int print_help(int return_value)
{
    std::cout << "SYNOPSIS\n\t./groundhog period\nDESCRIPTION\n\tperiod the number of days defining a period" << std::endl;
    return (return_value);
}

int main (int argc, char **argv)
{
    Groundhog program;

    if (argc != 2)
        return (print_help(84));
    if (!std::strcmp("-h", argv[1]))
        return (print_help(0));
    if (std::atoi(argv[1]) < 1)
        return (print_help(84));
    return (program.core(std::atoi(argv[1])));
}