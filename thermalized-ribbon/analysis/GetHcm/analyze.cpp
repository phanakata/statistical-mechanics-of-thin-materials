#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include "stdint.h"
#include "variables.h"
#include "analyze.h"

/*	average position	*/
double avg_pos()
{
   double pos=0, min=1000, max=-1000, xx=0;
   int n_node=0;
   for(int i=0;i<N;i++)
   {   	
	xx=position[3*i];
	if(particleID[i]==0)
	{	
		pos+=position[3*i+2];
		n_node++;
	        //find max/min positions of nodes to measure L
		if (xx>max)
		{
			max =xx;
		}
	
		if (xx<min)
		{
			min =xx;
		}
	
	}
   }
   printf ("%lf\t", max-min);
   return (pos/n_node);
}

