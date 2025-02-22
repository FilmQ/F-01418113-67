#include <stdio.h>


struct complex {
    float real_part;
    float imaginary_part;
};

// struct complex add_complex(struct complex * C, struct complex * D);
// struct complex multiply_complex(struct complex * C, struct complex * D);
// void print_complex(struct complex * added_complex, struct complex * multiplied_complex);

struct complex add_complex(struct complex C, struct complex D)
{
    struct complex added_complex;

    added_complex.real_part      = C.real_part + D.real_part;
    added_complex.imaginary_part = C.imaginary_part + D.imaginary_part;

    return added_complex;
}

struct complex multiply_complex(struct complex C, struct complex D)
{
    struct complex multiplied_complex ;

    multiplied_complex.real_part      = (C.real_part * D.real_part -
                                         C.imaginary_part * D.imaginary_part);

    multiplied_complex.imaginary_part = (C.real_part  * D.imaginary_part -
                                        (-1)*(C.imaginary_part * D.real_part));

    return multiplied_complex;
}

void print_complex(const char * str, struct complex eval_complex)
{
    // printf("%s %.1f + %.1fi\n", str, eval_complex.real_part, eval_complex.imaginary_part);

    if(eval_complex.real_part != 0 && eval_complex.imaginary_part > 0)
        printf("%s%.1f + %.1fi\n", str, eval_complex.real_part, eval_complex.imaginary_part);

    else if(eval_complex.real_part == 0 && eval_complex.imaginary_part == 0)
        printf("%s%.1f\n", str, eval_complex.real_part);

    else if(eval_complex.imaginary_part != 0 && eval_complex.real_part < 0)
        printf("%s%.1f - %.1fi\n", str, eval_complex.real_part, -eval_complex.imaginary_part);

    else if(eval_complex.real_part == 0 && eval_complex.imaginary_part != 0)
        printf("%s%.1fi\n", str, eval_complex.imaginary_part);

    else if(eval_complex.real_part != 0 && eval_complex.imaginary_part == 0)
        printf("%s%.1f\n", str, eval_complex.real_part);

    else if(eval_complex.real_part > 0 && eval_complex.imaginary_part < 0)
        printf("%s%.1f - %.1fi\n", str, eval_complex.real_part, -eval_complex.imaginary_part);

}



int main()
{
    struct complex C, D;
    struct complex E, F;


  printf("Enter C: ");
  scanf("%f %f", &C.real_part, &C.imaginary_part);

  printf("Enter D: ");
  scanf("%f %f", &D.real_part, &D.imaginary_part);
  

  E = add_complex(C, D);
  F = multiply_complex(C, D);

  print_complex("C + D = ", E);
  print_complex("C x D = ", F);

  return 0;
}