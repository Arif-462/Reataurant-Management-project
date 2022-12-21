#include<stdio.h>
#include<stdbool.h>//code link: https://github.com/Asif-102/foodzoo/commit/7593a2dc27a976dc1faf3639ef9afc2cc91ccea9

struct Food{
    char name[100];
    double price;
    float tax;
    int f_code;

};

struct Food input_foods()
{
   struct Food single_food;
   printf("Enter food_name, Price, food_code: ");
   scanf(" %s %lf %d",single_food.name, &single_food.price, &single_food.f_code);
   single_food.tax = single_food.price * 0.05;
   return single_food;
}

void display_foods(struct Food f[],int size)
{
    printf("\n-------------------------------\n");
     for(int i=0; i<size; i++)
    {
        printf("\n-------------------------------\n");
        printf("Food name: %s\n",f[i].name);
        printf("Food price: %.2lf\n",f[i].price);
        printf("Food tax: %0.2lf\n",f[i].tax);
        printf("Food code: %d\n",f[i].f_code);
        printf("\n-------------------------------\n");

    }
     printf("\n-------------------------------\n");

}

bool check_food_code(struct Food f[], int size, int code)
{
    bool chk = false;
    for(int i=0; i<size; i++)
    {
        if(f[i].f_code == code)
        {
            chk = true;
            break;
        }
    }
    return chk;

}

void display_ordered_food(struct Food f[], int size, int ordered_food[], int order_size)
{
    double total_price = 0;
    for(int i=0; i<order_size; i++)
    {
        int food_code = ordered_food[i];
        struct Food food;
        for(int k=0; k<size; k++)
        {
            if(f[k].f_code == food_code)
            {
                food = f[k];
            }
        }
        printf("food name = %s food price = %0.2lf\n",food.name, food.price);
        total_price += food.price;
    }
     printf("-------------------------------\n");
     printf("Total price = %0.2lf\n", total_price);

}

int main(void)
{
    printf("Enter your manue quantity : ");
    int n;
    scanf("%d",&n);
    struct Food food_items[n];
    for(int i=0; i<n; i++)
    {
        food_items[i] = input_foods();
    }

     display_foods(food_items, n);

     int ordered_food[100];
     int index = 0;

     printf("Order your food by food code or enter 0 for exite: ");

     int food_code;
    while( scanf("%d", &food_code))
    {
        if(food_code == 0)
            break;
         display_foods(food_items, n);

        while(check_food_code(food_items, n, food_code) == false)
        {
            printf("Invalid food code try again \n");
            printf("order your food by enter food code or 0 for exite: ");
            scanf("%d", &food_code);

            if(food_code == 0)
            break;
        }
        if(food_code == 0)
            break;

        if(check_food_code(food_items, n, food_code)== true)
        {
            ordered_food[index] = food_code;
            index++;
        }
        printf("Order your food by food code or enter 0 for exite: ");

    }
    display_ordered_food(food_items, n, ordered_food, index);

    return 0;
}
