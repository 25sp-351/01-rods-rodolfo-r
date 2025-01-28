#include <stdio.h>

int main() {
    int rod_length; //lets say 4
    int piece_length;
    int value;

    printf("Enter Size of Rod: ");
    scanf("%d", &rod_length);
    
    int prices[rod_length + 1];
    for (int i = 0; i <= rod_length; i++){
        prices[i] = 0; //set everything to zero
    }

    printf("Enter ( piece length, value )");
    // Had to change this to a while loop because when reading the piece length
    // and value,
    // we should keep on reading until we reach the end of file

    while (scanf("%d %d", &piece_length, &value) == 2) 
    {
        if(piece_length > rod_length)
        {
            printf("Cuts made:\n");
            printf("%d @ %d = %d\n", 0, 0, 0);
            printf("Remainder: %d\n", rod_length);
            printf("Value: %d\n", 0);

        }
        if(piece_length <= rod_length){
            prices[piece_length] = value;
        }
    }//we set the length [i] equal to its corrisponding price

    int max[rod_length + 1]; //we include the +1 for account for the zero based indexing 
    int cuts[rod_length + 1];
    for (int i = 0; i <= rod_length; i++) 
    {
        max[i] = 0;
        cuts[i] = 0;
    }//we set the whole array = 0, max[0, 0, 0, 0, 0, 0, 0, 0]
    
    for (int i = 1; i <= rod_length; i++)
    {   
        int curr = 0;
        for(int j = 1; j <= i; j++)
        {
            if(curr < prices[i] + max[i - j]){
                curr = prices[j] + max[i - j];
                cuts[i] = j;
            }
            //curr = (curr > prices[j] + max[ i - j]) ? curr : prices[j] + max[i - j]; 
            //This is checking if the current best revenue stroed in curr is greater than the new posible revenue ( prices[j] + max[i - j] )
            //Ternary Operator
            // ? value_if_tru : value_if_false
            // if curr is greater than new revenue = unchanged
            //if the condition is false, updates curr
        }
        max[i] = curr;
    }

    printf("Cuts made:\n");
    int total = max[rod_length];
    int remainder = rod_length;

    while(remainder > 0)
    {
        int cut_length = cuts[remainder];
        int num_pieces = remainder / cut_length;
        int cut_value = num_pieces * prices[cut_length];

        printf("%d @ %d = %d\n", num_pieces, cut_length, cut_value);

        remainder -= cut_length * num_pieces;
    }

    printf("Remainder: %d\n", remainder);

    printf("Value: %d\n", total);

    return 0;
}

