//
// 4-2. Extend atof to handle scientific notation of the form 123.45e-6
// where a floating-point number may be followed by e or E and an optionally signed exponent.
//

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX_LENGTH 100

double stringToDouble(char input[]);

int main() {
    
    char line[MAX_LENGTH] = "10.5E1";
    
    double result = stringToDouble(line);
    printf("%f \n", result);
    
    return 0;
}

double stringToDouble(char input[]) {
    
    double ans = 0.0;
    int sign = input[0] == '-' ? -1 : 0;
    
    int i = 0;
    for (ans = 0.0; isdigit(input[i]); ++i)
        ans = ans * 10 + (input[i] - '0');
    
    if (input[i] == '.')
        i++;
    
    double power;
    for (power = 1.0; isdigit(input[i]); ++i){
        ans = ans * 10 + (input[i] - '0');
        power *= 10.0;
    }
    ans = ans / power;
    
    if (input[i] == 'e' || input[i] == 'E') {
        int exponentSign = input[++i] == '-' ? -1 : 0;
        if (exponentSign == -1)
            i++;
        
        double exponent = input[i] - '0';
        for (i += 1;isdigit(input[i]); ++i)
            exponent = exponent * 10 + (input[i] - '0');
        
        if (exponentSign == -1)
            ans = pow(ans, -1 * exponent);
        else
            ans = pow(ans, exponent);
    }
    
    if (sign == -1)
        ans *= -1;
    
    return ans;
}
