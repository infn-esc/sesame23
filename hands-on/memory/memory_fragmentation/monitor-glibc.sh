#!/bin/bash

./heap-fragmentor &
PID=$!

while [ -d /proc/$PID/ ]; do
  VSS=$(grep '^VmSize:' /proc/$PID/status | awk '{print $2}')
  RSS=$(grep '^VmRSS:' /proc/$PID/status | awk '{print $2}')
  printf "  VSS: %10d kB, RSS: %10d kB\n" $VSS $RSS
  #PSS=$(grep '^Pss:' /proc/$PID/smaps_rollup | awk '{print $2}')
  #printf "  VSS: %10d kB, RSS: %10d kB, PSS: %10d kB\n" $VSS $RSS $PSS
  sleep 0.1s
done
