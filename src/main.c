#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<getopt.h>

#define EXIT_ERROR -1
#define EXIT_OK     0

int main(int argc,char* argv[])
{
    double temperature;
    int option;
    opterr = 0;
    
    while(( option = getopt(argc,argv,"c:f:k:h")) != -1 )
    {
        switch(option)
        {
            case 'c': temperature = strtod(optarg,NULL);
                      printf("\n| %.2lf degree Celcius |  %.2lf degree Fahrenheit  | %.2lf degree Kelvin |\n", temperature , (temperature * 9/5) + 32 , temperature + 273.15);
                      return EXIT_OK;
            case 'f': temperature = strtod(optarg,NULL);
                      printf("\n| %.2lf degree Fahrenheit |  %.2lf degree Celcius  | %.2lf degree Kelvin |\n", temperature , (temperature-32) * 5/9 , ((temperature-32) * 5/9) + 273.15);
                      return EXIT_OK;
            case 'k': temperature = strtod(optarg,NULL);
                      printf("\n| %.2lf degree Kelvin |  %.2lf degree Fahrenheit  | %.2lf degree Celcius |\n", temperature , ((temperature - 273.15) * 9/5) + 32 , temperature - 273.15);
                      return EXIT_OK;
            case 'h': printf("\nUsage: %s [ -c value | -f value | -k value ]\n",argv[0]);
                      return EXIT_OK;
            default : printf("\nFailed to parse input\n");
                      printf("Usage: %s [ -c value | -f value | -k value ]\n",argv[0]);
                      return EXIT_ERROR;
        }
    }

    return EXIT_OK;
}
