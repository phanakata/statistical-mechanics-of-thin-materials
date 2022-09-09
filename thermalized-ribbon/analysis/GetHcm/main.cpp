/*
 *  Paul Hanakata 2020-2022 - Harvard University 
 *  C++ code to calculate average height, ribbon length, and Binder cummulants
 *  Codes are adapted from https://github.com/souravbhabesh
 */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "stdint.h"
#include "gsd.h"
#include "variables.h"
#include "gsd_read.h"
#include "analyze.h"

int NX,NY, START, RUN;
double KAPPA, DISCARD;
int STEPS,FRAMES,CLONE;

int main(int argc, char **argv)
{
  FILE *therm,*lat, *bc;
  char init_strip[256],trajectory_file[256],thermalpos_file[256],lattice_file[256];
  int frame_cnt=0;
  double hcm=0, average_hcm=0, average_hcm2=0, average_hcm4=0;
  
  /*      Character array for directory pathname and filename     */
  char filepath[256];
  switch (argc){
     case 5:
       sscanf(argv[1],"%d",&NX); //number of nodes along x    
       sscanf(argv[2],"%d",&NY); //number of nodes along y 
       sscanf(argv[3],"%lf",&DISCARD); //percentage of data to be discarded for equilibration
       sscanf(argv[4],"%d",&STEPS); //total steps 
       break;
  default:
    print_and_exit("Usage: %s NX NY DISCARD TOTALSTEPS\n",
		   argv[0]);
  }
  FRAMES=STEPS/PERIOD; //convert NTOTAL steps to snapshots (FRAMES) 
  START=int((double)FRAMES*DISCARD);
  sprintf(trajectory_file,"traj_clamped.gsd");
  frame_cnt=0;
      for(int frames=START;frames<FRAMES;frames++)
	{
	  load_gsd(trajectory_file,frames);
	  hcm=avg_pos();
	  average_hcm += hcm;
	  average_hcm2 += hcm*hcm; 
	  average_hcm4 += hcm*hcm*hcm*hcm;
	  
	  printf("%d\t%lf\n", frames, hcm);
	  frame_cnt++;
	}
  average_hcm/=frame_cnt;
  sprintf(filepath,"./binderCumulant");
  bc = fopen(filepath, "w");
  fprintf(bc,"%lf\t%lf", average_hcm2/frame_cnt, average_hcm4/frame_cnt);
  fclose(bc);
  return 0;
}
