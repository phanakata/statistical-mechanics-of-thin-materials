## Overview 
This project's directory structure is as follows:
* ```lattice-configurations/```: contains initial lattice configurations 
* ```doubly-clamped-ribbon/```: NVT and NVE simulations for doubly clamped ribbon
* ```analysis/```: contains analysis codes (C++ and python) 


## To download 
git clone https://github.com/phanakata/statistical-mechanics-of-thin-materials/

## Technical 
* Molecular Dynamics Simulations 
  * HOOMD-blue 2.8.1 CUDA (10.1) DOUBLE HPMC_MIXED TBB SSE SSE2 
  * HOOMD run either on CPU or Tesla V100-PCIE-32GB  80 SM_7.0 @ 1.38 GHz, 32510 MiB DRAM, MNG


## Authors
Paul Hanakata

## Citation

If you use this package/code/dataset, build on  or find our research is useful for your work please cite 
```
@article{hanakata2021thermal,
  title={Thermal buckling and symmetry breaking in thin ribbons under compression},
  author={Hanakata, Paul Z and Bhabesh, Sourav S and Bowick, Mark J and Nelson, David R and Yllanes, David},
  journal={Extreme Mechanics Letters},
  volume={44},
  pages={101270},
  year={2021},
  publisher={Elsevier}
}
```


## References
* <a href="https://www.sciencedirect.com/science/article/pii/S2352431621000602?casa_token=reJKwD1SuVkAAAAA:pr92erUDodYfs9T-B0acZRQbZidhoVUp7qdzhssqd5HXizYCM_WbOXzCUwC7NsEXCAGD9eo7g_Y" style="color:#268cd7
"> **Paul Z. Hanakata**,  S. S.  Bhabesh, M. J. Bowick, D. R. Nelson, D. Yllanes, "*Thermal buckling and symmetry breaking in thin ribbons under compression*", Extreme Mechanics Letters, 44, 101270 (2021).</a>

## Acknowledgments
* Some of the analysis codes are adapted from https://github.com/souravbhabesh

