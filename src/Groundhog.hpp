/*
** EPITECH PROJECT, 2019
** CNA_groundhog_2018
** File description:
** Groundhog
*/

#ifndef GROUNDHOG_HPP_
    #define GROUNDHOG_HPP_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

class Groundhog {
    public:
        Groundhog(void);
        ~Groundhog(void);
        int core(int);
        void process(int);
        void calculateTemperatureIncreaseAverage(unsigned int);
        void calculateRelativeTemperatureEvolution(unsigned int);
        void calculateStandardDeviation(int);
        void display(unsigned int);
    protected:
    private:
        char _input[100];
        std::vector<double> _queue;
        double _g;
        int _lastr;
        int _r;
        double _s;
        int _switches;
};

#endif /* !GROUNDHOG_HPP_ */
