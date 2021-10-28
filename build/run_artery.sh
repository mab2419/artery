#!/bin/bash
OPP_RUNALL=/home/bauder/omnetpp-5.6.2/bin/opp_runall
OPP_RUN=/home/bauder/omnetpp-5.6.2/bin/opp_run_dbg
NED_FOLDERS="/home/bauder/artery/src/artery:/home/bauder/artery/src/traci:/home/bauder/artery/extern/veins/examples/veins:/home/bauder/artery/extern/veins/src/veins:/home/bauder/artery/extern/inet/src:/home/bauder/artery/extern/inet/examples:/home/bauder/artery/extern/inet/tutorials:/home/bauder/artery/extern/inet/showcases"
LIBRARIES="-l/home/bauder/artery/build/src/artery/libartery_core.so -l/home/bauder/artery/build/src/traci/libtraci.so -l/home/bauder/artery/build/extern/libveins.so -l/home/bauder/artery/build/extern/libINET.so -l/home/bauder/artery/build/src/artery/storyboard/libartery_storyboard.so -l/home/bauder/artery/build/src/artery/envmod/libartery_envmod.so"

RUNALL=false
for arg do
    shift
    [[ "$arg" == -j* ]] && RUNALL=true && J=$arg && continue
    [[ "$arg" == -b* ]] && RUNALL=true && B=$arg && continue
    # run opp_runall with default values for -j* and -b* options by just specifying '--all'
    [[ "$arg" == "--all" ]] && RUNALL=true && continue
    set -- "$@" "$arg"
done

if [ "$RUNALL" = true ] ; then
    $OPP_RUNALL $J $B $OPP_RUN -n $NED_FOLDERS $LIBRARIES $@
else
    $OPP_RUN -n $NED_FOLDERS $LIBRARIES $@
fi
