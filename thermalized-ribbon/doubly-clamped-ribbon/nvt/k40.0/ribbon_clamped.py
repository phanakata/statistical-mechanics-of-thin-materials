r!/usr/bin/python
from __future__ import print_function
import numpy as np
import hoomd
from hoomd import md, deprecated, data, group, init
#import gsd.hoomd
import sys
import random

k=40.0 #kappa bending 
e=1440.000*k/2 #k spring constant
strain=0 #strain 
frac=1.000 #initial configuration, frac=1.0 means undeformed 
nx=100 #LX ribbon length (#nodes along x) 
ny=25  #LY ribbon width  (#nodes along y)
Run=1
print ("Kappa = ",k,"Epsilon = ",e)
obser_file = 'obser_clamped.log'
print ("Observable data is dumped in file: ",obser_file)
traj_file = 'traj_clamped.gsd'
init_strip = '../../../../lattice-configurations/init_L100W25_f1.000.gsd0'
print ("Init_strip.gsd file : ",init_strip)


hoomd.context.initialize()
s = hoomd.init.read_gsd(init_strip)

count = 0
for p in s.particles:
    if (p.type == 'A' or p.type=='E'):
        x, y, z = p.position
        z += random.uniform(-0.01,0.01)
        p.position = (x,y,z)
        count = count + 1
print("count A:", count)

#compression 
count = 0
for p in s.particles:
        x, y, z = p.position
        x = frac*(1-strain/10000.)*x
        p.position = (x,y,z)
        count = count +1
        
print ("count all:", count)

harmonic = md.bond.harmonic()
dih = md.dihedral.harmonic()

dih.dihedral_coeff.set('A', k=k, d=1, n=1)
dih.dihedral_coeff.set('D', k=k, d=1, n=1)
dih.dihedral_coeff.set('E', k=k, d=1, n=1)

harmonic.bond_coeff.set('A', k=e, r0=1.0)
harmonic.bond_coeff.set('D', k=e, r0=1.0)
harmonic.bond_coeff.set('E', k=e, r0=1.0)

#hoomd.analyze.log(filename=obser_file, quantities=["temperature", "potential_energy","bond_harmonic_energy","kinetic_energy","dihedral_harmonic_energy", "lx", "ly", "lz", "pressure_xx"], period=10000, header_prefix="#", overwrite=True)

md.integrate.mode_standard(dt=0.0010)

group1 = hoomd.group.type(name='group1', type='A') # intermediate  
group2 = hoomd.group.type(name='group2', type='D') # right/left
group3 = hoomd.group.type(name='group3', type='E') # midle 
groupB = hoomd.group.type(name='groupB', type='B') # right/left
groupC = hoomd.group.type(name='groupC', type='C') # none 


#group12 = hoomd.group.union(name='group12',a=group1,b=group2)
group13 = hoomd.group.union(name='group13',a=group1,b=group3)
#group123 = hoomd.group.union(name='group123',a=group12,b=group3)
#md.constrain.oneD(group=group2, constraint_vector=[1,0,0])
#hoomd.compute.thermo(group=group13)
hoomd.analyze.log(filename=obser_file, quantities=["temperature_group13", "potential_energy", "potential_energy_group13","bond_harmonic_energy","kinetic_energy_group13","dihedral_harmonic_energy", "lx", "ly", "lz", "pressure_xx_group13", "pressure_xx"], period=10000, header_prefix="#", overwrite=True)
hoomd.dump.gsd(filename=traj_file, group=group.all(), period=10000, overwrite=True)
md.integrate.nvt(group=group13,kT=1.0, tau=0.2)
hoomd.run(1.000001e7)
