#include <stdio.h>
#include <cs50.h>

int get_cents(void);
int calculate_quarters(int n);
int calculate_dimes(int n);
int calculate_nickels(int n);
int calculate_pennies(int n);

int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;

int quarters_amount = 0;
int dimes_amount = 0;
int nickels_amount = 0;
int pennies_amount = 0;

int total_coins;

int main(void)
{
    int change_owed = get_cents();
    int remainder = change_owed;

  
        remainder -= calculate_quarters(remainder);
   
        remainder -= calculate_dimes(remainder);
   
        remainder -= calculate_nickels(remainder);

                    calculate_pennies(remainder);

    total_coins = (quarters_amount + dimes_amount + nickels_amount + pennies_amount);

    string quarter = (quarters_amount > 1 || quarters_amount == 0) ? "quarters" : "quarter";
    string dime = (dimes_amount > 1 || dimes_amount == 0) ? "dimes" : "dime";
    string nickel = (nickels_amount > 1 || nickels_amount == 0) ? "nickels" : "nickel";
    string penny = (pennies_amount > 1 || pennies_amount == 0) ? "pennies" : "penny";

    return printf(" %i %s, %i %s, %i %s, %i %s\n Total coins: %i\n", quarters_amount, quarter, dimes_amount, dime, nickels_amount, nickel, pennies_amount, penny, total_coins);
}

int get_cents(void)
{
    int cents;

    do
    {
        cents = get_int("Change owed: ");

    } while (cents < 0);

    return cents;
}

int calculate_quarters(int n)
{
    quarters_amount = n / quarter;
    
    return quarters_amount * quarter;
}

int calculate_dimes(int n)
{
    dimes_amount = n / dime;

    if (n == dime)
    {
        dimes_amount = 1;
        return dimes_amount;
    }

    return dimes_amount * dime;
}
    


int calculate_nickels(int n)
{
    nickels_amount = n / nickel;

    return nickels_amount * nickel;
}
    


int calculate_pennies(int n)
{
    pennies_amount = n / penny;
 
    return pennies_amount;
}
