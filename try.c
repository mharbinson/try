#include <stdio.h>
#include <math.h>

int main() {
    int num;
    const double pi = 3.14159265359;
    double R;
    double ha;
    double hb;
    double a;
    double b;
    double h;
    double topSurfaceArea;
    double bottomSurfaceArea;
    double lateralSurfaceArea;
    double totalSurfaceArea;
    double volume;
    double averageSurfaceArea =0;
    double averageVolume = 0;
    int result = 0;
    int validR = 1;
    int validha = 1;
    int validhb = 1;

    while(1){
        printf("How many spherical segments you want to evaluate [2-10]?");
        result = scanf("%d", &num);      
        if( num >= 2 && num <= 10 && result == 1){
            for(int i = 1;i <= num; i++){
                printf("%s","Obtaining data for spherical segment number ");
                printf("%d\n", i);
                printf("%s", "What is the radius of the sphere (R)? ");
                if(scanf("%lf", &R) != 1){
                    while (getchar() != '\n');
                    validR = 0;
                };
                printf("%s","What is the height of the top area of the spherical segment (ha)?"); 
                if(scanf("%lf", &ha) != 1){
                    while (getchar() != '\n');
                    validha = 0;
                };
                printf("%s","What is the height of the bottom area of the spherical segment (hb)?"); 
                if(scanf("%lf", &hb) != 1){
                    while (getchar() != '\n');
                    validhb = 0;
                };
                printf("%s", "Entered data: R=");
                printf("%.2lf", R);
                printf("%s", " ha = ");
                printf("%.2lf", ha);
                printf("%s", " hb = ");
                printf("%.2lf", hb);
                printf("\n");
                if(!validR || !validha || !validhb){
                    printf("Invalid Input: a number needs to be entered.");
                    i-= 1;
                }else if(ha < hb){
                    printf("invalid Input: ");
                    printf("%s", " ha = ");
                    printf("%.2lf", ha);
                    printf("%s", " hb = ");
                    printf("%.2lf", hb);
                    printf("ha must be greater than or equal to hb.");
                    printf("\n");
                    i-= 1;
                }else if(ha > R){
                    printf("invalid Input: ");
                    printf("%s", " ha = ");
                    printf("%.2lf", ha);
                    printf("%s", " r = ");
                    printf("%.2lf", R);
                    printf("\n");
                    printf("r must be greater than ha.");
                    printf("\n");
                    i-= 1;
                }else if(hb > R){
                    printf("invalid Input: ");
                    printf("%s", " ha = ");
                    printf("%.2lf", ha);
                    printf("%s", " r = ");
                    printf("%.2lf", R);
                    printf("\n");
                    printf("r must be greater than hb.");
                    printf("\n");
                    i-= 1;
                }else{
                    a = sqrt((R * R) - (ha * ha));
                    b = sqrt((R * R) - (hb * hb));
                    h = ha - hb;
                    topSurfaceArea = pi * (a * a);
                    bottomSurfaceArea = pi * (b * b);
                    lateralSurfaceArea = 2 * pi * R * h;
                    totalSurfaceArea = topSurfaceArea + bottomSurfaceArea + lateralSurfaceArea;
                    volume = ((pi * h)/6) * ((3 * (a * a)) + (3 *(b * b)) + (h * h));
                    printf("Total Surface Area = ");
                    printf("%.2lf", totalSurfaceArea);
                    printf(" Volume = ");
                    printf("%.2lf", volume);
                    printf(".");
                    printf("\n");
                    averageSurfaceArea += totalSurfaceArea;
                    averageVolume += volume;
                }

            }
            printf("Total average results:");
            printf("\n");
            printf("Average Surface Area = ");
            printf("%.2lf", averageSurfaceArea/num);
            printf(" Average Volume = ");
            printf("%.2lf", averageVolume/num);
            printf("\n");

            
        }else{
            while (getchar() != '\n');
        }
        break;
        
    }
    return 0;
}