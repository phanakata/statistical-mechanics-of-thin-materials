#!/bin/bash
#SBATCH -J smHOOMD_%j
#SBATCH -o smHOOMD_%j.out  # File to which STDOUT will be written, %j inserts jobid
#SBATCH -e smHOOMD_%j.err  # File to which STDERR will be written, %j inserts jobid
#SBATCH --mail-type=ALL
#SBATCH -p gpu
#SBATCH --gres=gpu:1
#SBATCH -t 0-00:20
#SBATCH -N 1
#SBATCH -n 1
#SBATCH --mem=4000

# Singularity command line options
singularity exec --nv /n/home03/phanakata/software.simg python3 ribbon_clamped.py
