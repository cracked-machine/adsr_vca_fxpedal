#include "ADSR.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>

using namespace std::chrono_literals;


// create ADSR env
ADSR *env = new ADSR();

// normally this would be called everytime the ADC DMA new data flag was set
// but for simulation purpose we run it in a loop
void adc_dma_callback(int samplerate)
{
    std::ofstream f_data("data.txt");

    std::cout << "Starting gate thread\n";
    for(int i = 0; i < samplerate; i++)
    {
        std::this_thread::sleep_for(2ms);
        f_data << env->process() << std::endl;
    }
}

int main()
{
    
    float sampleRate = 160;

    // initialize settings
    env->setAttackRate(.1 * sampleRate);  // .1 second
    env->setDecayRate(.25 * sampleRate);
    env->setReleaseRate(1 * sampleRate);
    env->setSustainLevel(.6);
    
    std::thread t1(adc_dma_callback, sampleRate);

    std::this_thread::sleep_for(20ms);
    std::cout << "gate on\n";
    env->gate(true);

    std::this_thread::sleep_for(120ms);
    std::cout << "gate off\n";
    env->gate(false);


    std::this_thread::sleep_for(2000ms);    

    t1.join();
    
    return 0;
}