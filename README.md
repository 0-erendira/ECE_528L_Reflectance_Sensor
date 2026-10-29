# ECE 528/L - Robotics and Embedded Systems with Lab

**CSU Northridge**

**Department of Electrical and Computer Engineering**

## Reflectance Sensor Lab

The Reflectance Sensor lab interfaces with the following:

* User LEDs of the TI MSP432 LaunchPad
* 8-Channel QTRX Sensor Array - [Product Link](https://www.pololu.com/product/3672)



\# PreLab Questions 

\## Erendira Miranda



1\. What does a reflectant sensor consist of? How many reflectance sensors are on the Reflectance Sensor Array? What is its operating voltage?<br>



There are eight reflectance sensors that each have a dimmable IR emmitter coupled with a photortansistor. The operating voltabe being 2.9V to 5.5V.<br>

<br>

2\. Which control pins on the QTRX Reflectance Sensor Array are responsible for enabling the reflectance sensors? What is their default value after powering on the Sensor Array? List the pin names and the pin numbers used to connect the two control pins.<br>

CTRL ODD and CTRL EVEN are responsible for enabling the reflectance sensors as well as P5.3 and P9.2 and their default value after powering on is logic high.<br>

<br>

3\. Write a void function named P5\_0\_and\_P9\_7\_Init that takes no arguments and configures the P5.0 and P9.7 pins as output GPIO pins. Initialize the value of the P5.0 and P9.7 pins to zero.<br>

```c

void P5\_0\_and\_P9\_7\_Init(void)

{

&#x20; //initializes P5.0

&#x20; P5->SEL0 \&= \~0x01;

&#x20; P5->SEL1 \&= \~0x01;

&#x20; P5->Dir  |=  0x01;

&#x20; P5->OUT  \&= \~0x01;



&#x20; //initializes P9.7

&#x20; P9->SEL0 \&= \~0x80;

&#x20; P9->SEL1 \&= \~0x80;

&#x20; P9->Dir  |=  0x80;

&#x20; P9->OUT  \&= \~0x80;

}

```

<br>

4\. Write a void function named Print\_Binary that has an input parameter called value\_to\_convert of type uint8\_t. Your function must print an unsigned 8-bit integer in binary representation with an underscore (\_) seperatorafter the 4th bit. If the input value is 0, it should print "Binary: 0000\_0000" and return. Include your name in the author section of the documentation. If you've used references, cite them below.<br>



```c

/\*\*

&#x20;\* @file print\_binary.c  

&#x20;\*

&#x20;\* @brief Main source code for Print\_Binary program. 

&#x20;\*

&#x20;\* This file contains the main entry \[oint and the implementation

&#x20;\* of the Print\_Binary function that takes in a uint8\_t value and

&#x20;\* of the Print\_Binary function that takes in a uint8\_t value and

&#x20;\* prints the value in binary format.

&#x20;\*

&#x20;\* @author Aaron Nanas

&#x20;\* @author Erendira Miranda

\*/



\#include <stdio.h>

\#include <stdint.h>



void Print\_Binary(uint8\_t value\_to\_convert);



Int main()

{

&#x09;uint8\_t value\_to\_convert = 170;



&#x09;printf(“Decimal: %d\\n”, value\_to\_convert);

&#x09;Print\_Binary(value\_to\_convert);



&#x09;return 0;

}



void Print\_Binary(uint8\_t value\_to\_convert)

{

&#x09;if(value\_to\_convert == 0)

&#x09;{

&#x09;printf(“Binary: 0000\_0000\\n”);

&#x09;return;

}



printf(“Binary: ”);



for(int bit = 7; bit >= 0; bit --)

{

&#x09;printf(“%d”, (value\_to\_convert >> bit) \& 1)

&#x09;

&#x09;if(bit == 4)

&#x09;{

&#x09;printf(“\_”);

}

}

printf(“\\n”)

}



``` 





