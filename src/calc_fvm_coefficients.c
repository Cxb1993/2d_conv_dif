#include <stdio.h>
#include "struct_list.h"
#define max(X,Y) (((X) > (Y)) ? (X) : (Y))

void calc_fvm_coefficients(struct block *grid_data, struct coeff *fvm_coeff, struct properties *phys_prop)
{
   int ii;

   for(ii = 0; ii < grid_data->np; ii++)
   {
      fvm_coeff[ii].a_W = phys_prop->Difx*phys_prop->Aw + max(0,  phys_prop->Fx*phys_prop->Aw);
      fvm_coeff[ii].a_E = phys_prop->Difx*phys_prop->Ae + max(0, -phys_prop->Fx*phys_prop->Ae);
      fvm_coeff[ii].a_S = phys_prop->Dify*phys_prop->As + max(0,  phys_prop->Fy*phys_prop->As);
      fvm_coeff[ii].a_N = phys_prop->Dify*phys_prop->An + max(0, -phys_prop->Fy*phys_prop->An);

      fvm_coeff[ii].S_u = 0.0;
      fvm_coeff[ii].S_p = 0.0;
   }
}
