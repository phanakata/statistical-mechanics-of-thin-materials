#!/bin/ksh
#strain level 
for file1 in 150 200 250 
do 
echo $file1
mkdir  $file1
cd $file1
#number of runs
for file2 in 1 2 3 4 5 6 7 8 9 10 
do
echo $file2
mkdir r$file2
cd r$file2  
cp ../../ribbon_clamped.py .
sed -i 's/Run=1/Run='$file2'/g' ribbon_clamped.py
sed -i 's/strain=0/strain='$file1'/g' ribbon_clamped.py
sbatch ../../singularity_hoomd.sh
cd ..
done
cd ..
done

