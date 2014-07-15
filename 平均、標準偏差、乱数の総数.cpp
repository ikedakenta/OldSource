/**************************************************/
/*                    normal1_ans.c               */
/* Usage: a.out $BJ?6Q(B $BI8=`JP:9(B $BMp?t$NAm?t(B $BMp?t$N<o(B */
/**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void error1(char *);

int main(int argc,char *argv[])
{
  double heikin;          /* $BJ?6Q(B */
  double hensa;           /* $BI8=`JP:9(B */
  long num_ransuu;        /* $BH/@8$5$;$k5?;wMp?t$NAm?t(B */
  unsigned int ranseed;   /* $BMp?t$N<o(B */

  /***** $B%Q%i%a!<%?BeF~(B *****/
  if(argc >= 5)
  {
    heikin=atof(argv[argc-4]);        /* $BJ?6Q(B */
    hensa=atof(argv[argc-3]);         /* $BI8=`JP:9(B */
    num_ransuu=atoi(argv[argc-2]);    /* $BH/@8$5$;$k5?;wMp?t$NAm?t(B */
    ranseed=atoi(argv[argc-1]);       /* $BMp?t$N<o(B */
    if(num_ransuu <= 0)
    {
      printf("1 <= num_ransuu\n");
      exit(1);
    }
    if(hensa <= 0.0)
    {
      printf("hensa > 0.0\n");
      exit(1);
    }
  }
  else
  {
    printf("usage: %s heikin hensa num_ransuu seed\n",argv[0]);
    exit(1);
  }

  printf("heikin=%g hensa=%g num_ransuu=%d\n",heikin,hensa,num_ransuu);

  srandom(ranseed);/* $BMp?t$N<o$r@_Dj(B($BCM$,F1$8$J$iF1$8Mp?t7ONs$H$J$k(B) */

  /* $BMp?t$r@8@.$5$;$J$,$i%G!<%?$N3d9g$r;;=P(B */    
  {
    double dist;          /* $B&R$G5,3J2=$7$?J?6Q$+$i$N5wN%(B */
    int hist[3]={0,0,0};  /* $B3d9g$r;;=P$9$k$?$a$N%+%&%s%?(B */
    double ran1,ran2;     /* $BMp?t(B */


#ifdef METHOD_A  /* $B%\%C%/%9!&%^%i!<K!(B */    
    {
      int i;
      double pai2=8.0*atan(1.0);  /* 2$B&P(B */
      double x1,x2,a,b;

      num_ransuu=(num_ransuu/2)*2; /* METHOD_A$B$N>l9g$OMp?tAm?t$r6v?t$KJQ99(B */
      for(i=0;i<num_ransuu/2;i++)
      {
	x1=((double)random()+1.0)/((double)(RAND_MAX)+1.0);
	x2=((double)random()+1.0)/((double)(RAND_MAX)+1.0);
	a=pai2*x2;
	b=sqrt(-2.0*log(x1));
	ran1=sin(a)*b*hensa+heikin;    /* $BMp?t(B1 */
	ran2=cos(a)*b*hensa+heikin;    /* $BMp?t(B2 */

	dist=fabs(ran1-heikin)/hensa;  /* $B&R$G5,3J2=$7$?J?6Q$+$i$N5wN%(B */
	if(dist <= 1.0)
	  hist[0]++;
	if(dist <= 2.0)
	  hist[1]++;
	if(dist <= 3.0)
	  hist[2]++;

	dist=fabs(ran2-heikin)/hensa;
	if(dist <= 1.0)
	  hist[0]++;
	if(dist <= 2.0)
	  hist[1]++;
	if(dist <= 3.0)
	  hist[2]++;
      }
    }
#endif
#ifdef METHOD_B  /* $B0lMMMp?tJ?6Q(B */
    {
      int i,j;
      double sum;
      for(i=0;i<num_ransuu;i++)
      {
	sum=0.0;
	for(j=0;j<12;j++)
	  sum += (double)random()/(double)RAND_MAX;
	ran1=(sum-6.0)*hensa+heikin;    /* $BMp?t(B */

	dist=fabs(ran1-heikin)/hensa;  /* $B&R$G5,3J2=$7$?J?6Q$+$i$N5wN%(B */
	if(dist <= 1.0)
	  hist[0]++;
	if(dist <= 2.0)
	  hist[1]++;
	if(dist <= 3.0)
	  hist[2]++;
      }
    }
#endif

    /* $B;;=P$7$?3d9g$NI=<((B */    
    printf("$B!^(B1$B&R(B:%7.5f $B!^(B2$B&R(B:%7.5f $B!^(B3$B&R(B:%7.5f\n",(double)hist[0]/(double)num_ransuu,(double)hist[1]/(double)num_ransuu,(double)hist[2]/(double)num_ransuu);
  }
}

/* $B%(%i!<;~$N=hM}(B */
void error1(char *message)
{
  printf("%s\n",message);
  exit(1);
}
