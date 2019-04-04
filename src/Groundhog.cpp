/*
** EPITECH PROJECT, 2019
** CNA_groundhog_2018
** File description:
** Groundhog
*/

#include "Groundhog.hpp"

Groundhog::Groundhog()
{
    this->_switches = 0;
}

Groundhog::~Groundhog()
{
}

void Groundhog::calculateTemperatureIncreaseAverage(unsigned int period)
{
    if (this->_queue.size() <= period)
        return;
    this->_g = 0;
    for (size_t counter = this->_queue.size() - period; counter != this->_queue.size(); counter++) {
        double tmp = this->_queue[counter] - this->_queue[counter-1];
        this->_g += (tmp > 0 ? tmp : 0);
    }
    this->_g /= period;
}

void Groundhog::calculateRelativeTemperatureEvolution(unsigned int period)
{
    if (this->_queue.size() <= period)
        return ;
    this->_lastr = this->_r;
    double value1 = this->_queue[this->_queue.size() - period - 1];
    double value2 = this->_queue.back();
    this->_r =  (int)(round((value2-value1)/value1*100));
}


void Groundhog::calculateStandardDeviation(int period)
{
    double value1 = 0;
    double value2 = 0;

    for (auto iteration = this->_queue.end() - period; iteration != this->_queue.end(); iteration++) {
        value1 += *iteration;
        value2 += (*iteration * *iteration);
    }
    this->_s = sqrt(value2/period-(value1/period)*(value1/period));
}

void Groundhog::process(int period)
{
    this->calculateTemperatureIncreaseAverage(period);
    this->calculateRelativeTemperatureEvolution(period);
    this->calculateStandardDeviation(period);
}

void Groundhog::display(unsigned int period)
{
    std::cout << std::setprecision(2) << std::fixed << "g=";
    if (this->_queue.size() <= period)
        std::cout << "nan";
    else
        std::cout << this->_g;
    std::cout << "\tr=";
    if (this->_queue.size() <= period)
        std::cout << "nan";
    else
        std::cout << this->_r;
    std::cout << "%\ts=";
    if (this->_queue.size() < period)
        std::cout << "nan";
    else
        std::cout << this->_s;
    if (((this->_lastr < 0 && this->_r >= 0) || (this->_lastr >= 0 && this->_r < 0)) && this->_lastr) {
        ++this->_switches;
        std::cout << "\ta switch occurs";
    }
    std::cout << std::endl;
}

int Groundhog::core(int period)
{
    while (1337) {
        std::scanf("%s", this->_input);
        if (std::strcmp("STOP", this->_input) == 0)
            break;
        if (std::atof(this->_input) != 0) {
            this->_queue.push_back(std::atof(this->_input));
            this->process(period);
            this->display(period);
        }
    }
    std::cout << "Global tendency switched " << this->_switches << " times" << std::endl;
    return (0);
}
