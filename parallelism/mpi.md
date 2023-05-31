---
title:  Introduction to MPI
layout: main
section: parallelism
---

Check that your environment is correctly configured to compile and run MPI code.

```shell
$ module load compilers/gcc-12.2_sl7 compilers/openmpi-4-1-4_gcc12.2
$ mpic++ -v
g++ (GCC) 12.2.1 20221004
Copyright (C) 2022 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

$ which mpirun
/shared/software/compilers/openmpi-4.1.4_gcc12.2/bin/mpirun
```

Note that for MPI we will use the `gcc` v. 12 compiler.

We have to be sure that the .bashrc is sourced at login. We have to create in your $HOME the following .bash_profile if does not exist.

```shell
$ cd 
$ cat .bash_profile

# Get the aliases and functions
if [ -f ~/.bashrc ]; then
        . ~/.bashrc
fi
```
Moreover replace the lines in your .bashrc so that it appears like the following

```shell
$ cat .bash_profile

# Source global definitions
if [ -f /etc/bashrc ]; then
        . /etc/bashrc
fi

module load compilers/gcc-12.2_sl7
module load compilers/openmpi-4-1-4_gcc12.2
```
Then logout and login.

After login:
```shell
Last login: Wed May 31 16:16:14 CEST 2023 on pts/0
[student89@hpc-200-06-17 ~]$
[student89@hpc-200-06-17 ~]$ module list
Currently Loaded Modulefiles:
  1) /compilers/gcc-12.2_sl7            2) /compilers/openmpi-4-1-4_gcc12.2
[student89@hpc-200-06-17 ~]$

```
Examples and exercises are available in the
[`hands-on/mpi`]({{site.exercises_repo}}/hands-on/mpi) directory. Follow the
instructions included in the presentation.


To compile an MPI executable and execute it, in example: 

```shell
mpic++ -o  NoBloc_PingPong.out NoBloc_PingPong.cpp
mpirun --mca btl_openib_allow_ib 1 --machinefile machinefile.txt -np 2 NoBloc_PingPong.out
```
