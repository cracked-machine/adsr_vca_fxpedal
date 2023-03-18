# adsr_vca_fxpedal
MCU generated ADSR envelope into a LM13700 OTA VCA

## Block diagram

ADSR waveform is generated via [MCU DAC](docs/datasheet/stm32l432kb_datasheet.pdf) using software.

Input signal is ADSR-modulated using the [LM13700](docs/datasheet/lm13700.pdf) OTA chip in a `voltage controlled amplifier` confguration.

Note, ADSR values can be selected and then adjusted using the switched rotary encoder. I.e. you depress the encoder shaft to toggle between attack, decay, sustain and release attributes. 

An OLED display will show the current ADSR envelope shape as it is adjusted.

ADSR envelope signal also available as buffered output.

ADSR generation is triggered by input signal peak detection or by manual 3.3v logic signal.

![](https://lucid.app/publicSegments/view/f9110502-4c70-44df-a120-1ce2ebbae0e5/image.png)

## Power Supply Scheme

This supports both guitar applications (9VDC) and modular synth (+/-12V) by switching the jumpers.

![](https://lucid.app/publicSegments/view/5046d51e-e26f-4106-ab1e-7b260f3f4b0d/image.png)

Implementation can be seen on the schematic page

![](docs/schematic/adsr_vca_fx-PowerSupply.svg)

