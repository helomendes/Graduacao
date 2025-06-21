#!/bin/sh

#SBATCH --job-name=test
#SBATCH --nodes=2
#SBATCH --ntasks=2
#SBATCH --cpus-per-task=1
#SBATCH --output=output.out
#SBATCH --error=errors.err

if [ "$#" -ne 2 ]
then
	echo "Error: Requires two arguments"
	echo "Run: sbatch run.sbatch sequential.c parallel.c"
	exit
fi

SEQ=$1
PAR=$2

echo
echo "Compiling sequential file ${SEQ}"
gcc ${SEQ} -o seq
echo "Compiling parallel file ${PAR}"
mpicc -fopenmp ${PAR} -o par

echo

echo "Running on: $(hostname)"
echo "SLURM_JOB_ID: $SLURM_JOB_ID"
echo "Working directory: $PWD"
echo "Starting job..."
echo
echo "##########################################"
echo

set -x

echo "Executing sequential algorithm"
./seq
echo
echo "------------------------------------------"
echo
echo "Executing parallel algorithm"
mpirun -np 2 --map-by ppr:1:node ./par 2

echo
echo "##########################################"
echo
echo "Job finished."
