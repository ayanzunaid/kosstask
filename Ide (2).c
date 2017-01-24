#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.14159

typedef struct com
{  float r,im;
    
    
} comp;

void enter (comp *a)
 {printf("ENTER REAL AND IMAG PART:\n");
    scanf("%f %f",&(a->r),&(a->im));

      }
      
 void mul (comp x,comp y )
 {printf("answer:\n");
     printf("%f + %fi\n",(x.r*y.r) - (x.im*y.im),x.r*y.im + x.im*y.r);
 
     
     
 }
 
 void pol(comp a)
  {float r,theta;
  if (a.r==0 && a.im ==0)
  {
    printf("INVALID INPUT");}
    else
    {
      r = sqrt(pow(a.r,2) + pow(a.im,2));
      if (a.r==0)
       {if (a.im>0)
             theta = 90.0;
             else
             theta = -90.0;
            }
           else if (a.im==0)
            {if (a.r>0)
                theta = 0.0;
                  else
                   theta = 180.0;
             }
            else
            {theta = atan(fabs(a.im/a.r));
               
               
               if (a.r<0 && a.im>0)
                { theta = pi - theta;}
                if (a.r>0 && a.im<0)
                  {theta = -1*theta;}
                  if (a.r<0 && a.im <0)
                     {theta = (-1*pi) + theta;}
                
                theta = (theta*180)/pi;
                
                
            }
             
             
            
      printf("THE POLAR FORM: (angle is in degrees)\n");
      printf("%f ANGLE%f",r,theta);
    }
     
     
      
      
  }
 
 void divide (comp x, comp y)
 {
    comp z;
    
       if (y.r==0 && y.im==0)
        {printf("CANT DIVIDE BY ZERO\n");}
        else
         {z.r = (x.r*y.r + x.im*y.im)/(sqrt(pow(y.r,2) + pow (y.im,2)));
          z.im = (x.im*y.r - x.r*y.im)/sqrt(pow(y.r,2) + pow(y.im,2));   
           printf("answer:\n %f + %fi",z.r,z.im);
         }
     
 }
      
      
long int fact (long int num)
{     if (num>1)
    { return num*fact(num -1 );}
    else 
    return 1;
     
    
    
}
void basiccal()
{   int cho;
       float a,b;
       int x; long int num;
       
    printf("CHOOSE OPERATION : 1. + 2. - 3. * 4./ 5.^ 6.! \n");
    scanf("%d",&cho);
    printf("\n");
    switch (cho)
    
    {case 1:printf("ENTER a & b:\n");
              scanf("%f %f",&a,&b);
              printf("%f",a+b);
             break;
      case 2:printf("ENTER a & b:   (a-b)\n");
              scanf("%f %f",&a,&b);
              printf("%f",a-b);
             break;  
             case 3:printf("ENTER a & b:\n");
              scanf("%f %f",&a,&b);
              printf("%f",a*b);
              break;
              case 4:printf("ENTER a & b:   (a/b)\n");
              scanf("%f %f",&a,&b);
              
              if (b!=0)
              {printf("%f",a/b);}
              else
                {printf("DIVISION BY ZERO\n");}
             break;
             case 5:printf("ENTER a & x:  (a^x) x is INTEGER\n");
              scanf("%f %d",&a,&x);
              
              if ((x==0 && a==0 ) || (x<0 && a==0))
              {printf("INVALID INPUT\n");}
             
              else
              {
              printf("%f",pow(a,x));}
             break;
             case 6:printf("ENTER number:\n");
              scanf("%ld",&num);
              if (num<=0)
              {printf("INVALID INPUT\n");}
              else
              {
              printf("%ld",fact(num));}
             break;
             
             
      default:printf("INVALID SELECTION\n");  
    }
    
    
}

void complexcal()
{int cho;
 comp a,b;
    printf("1. MULTIPLY 2.DIVIDE 3.POLAR FORM\n");
    scanf("%d",&cho);
    switch (cho)
      {case 1:enter(&a);enter(&b);
                  mul (a,b);
                break;
                 case 2:enter(&a);enter(&b);
                    divide(a,b);
                 break;
                 case 3:enter(&a);
                      pol(a);
                 break;
                  default: printf("INVALID SELECTION");
          
      }
}

void eqn()
{   int cho; float a,b,c,d,e,f,x,y,D;comp x1,x2;
    printf("1.LINEAR IN TWO VARIABLES 2.QUADRATIC SOLVER\n");
     scanf("%d",&cho);
    if (cho == 1)
    {
        
        printf("ax + by = c\ndx + ey = f   (all non zero)\n");
        printf("ENTER a,b,c:\n");
         scanf("%f %f %f",&a,&b,&c);
          printf("ENTER d,e,f:\n");
         scanf("%f %f %f",&d,&e,&f);
      
        if (a*e == b*d)
        {if (b*f != c*e)
           printf("NO SOLUTION");
            else
             printf("INFINITE ");
            
        }
        
        else
        
        {x = (c*e - b*f)/(a*e - b*d);
         y= (a*f - c*d)/(a*e - b*d);
         printf("X = %f Y = %f",x,y);
            
            
        }
        
        
      
    }
    else if (cho==2)
    {printf("ax2 + bx +c\n");
       printf("ENTER a,b,c:\n);
         scanf("%f %f %f",&a,&b,&c);
         D = b*b - 4*a*c;
         if (D>=0)
           {
               x1.r = (-b + sqrt(D))/(2*a);
            x2.r =  (-b - sqrt(D))/(2*a);
        
           x1.im = x2.im =0;    
           }
           
           else  
           
           { x1.r = x2.r = -b/(2*a);
               x1.im = sqrt(-D)/(2*a);
               x2.im = -x1.im;
               
               
           }
        
       printf("X1 = %f + %fi\nX2 = %f + %fi\n",x1.r,x1.im,x2.r,x2.im); 
    }
     else
      {printf("INVALID SELECTION\n");}
}


int main(void) {
    
    int cho;
    char ch = 'y';

	do
	{	printf("MENU:\n1.BASIC CALC\n 2.COMPLEX\n 3.EQN SOLVER\n\n ENTER CHOICE:\n");
	    scanf("%d",&cho);
	    switch(cho)
	    {    case 1:   basiccal();
	                 break;
	         case 2:   complexcal();
	           break;
	            case 3:  eqn();
	               break;
	        
	        default:printf("INVALID CHOICE\n");
	    }
	    
	   printf("USE AGAIN?(y/n)\n");
	   scanf("%c",&ch);
	}while(ch=='y' || ch == 'Y');
	return 0;
}

