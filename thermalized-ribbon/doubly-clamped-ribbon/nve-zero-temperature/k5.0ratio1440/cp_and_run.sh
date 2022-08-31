#!/bin/ksh
for file1 in 30 40 50 60  
do 
echo $file1
mkdir  $file1
cd $file1
for file2 in 1  
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

