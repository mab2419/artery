# CMake generated Testfile for 
# Source directory: /home/bauder/artery/scenarios/gemv2
# Build directory: /home/bauder/artery/build/scenarios/gemv2
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(gemv2-LOS "/home/bauder/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/bauder/artery/src/artery:/home/bauder/artery/src/traci:/home/bauder/artery/extern/veins/examples/veins:/home/bauder/artery/extern/veins/src/veins:/home/bauder/artery/extern/inet/src:/home/bauder/artery/extern/inet/examples:/home/bauder/artery/extern/inet/tutorials:/home/bauder/artery/extern/inet/showcases" "-l" "/home/bauder/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/bauder/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/bauder/artery/build/extern/libINET.so" "-l" "/home/bauder/artery/build/extern/libveins.so" "-l" "/home/bauder/artery/build/src/traci/libtraci.so" "-l" "/home/bauder/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cLOS_mediumAntennas" "--sim-time-limit=10s")
set_tests_properties(gemv2-LOS PROPERTIES  WORKING_DIRECTORY "/home/bauder/artery/scenarios/gemv2" _BACKTRACE_TRIPLES "/home/bauder/artery/cmake/AddOppRun.cmake;169;add_test;/home/bauder/artery/scenarios/gemv2/CMakeLists.txt;3;add_opp_test;/home/bauder/artery/scenarios/gemv2/CMakeLists.txt;0;")
add_test(gemv2-NLOSv "/home/bauder/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/bauder/artery/src/artery:/home/bauder/artery/src/traci:/home/bauder/artery/extern/veins/examples/veins:/home/bauder/artery/extern/veins/src/veins:/home/bauder/artery/extern/inet/src:/home/bauder/artery/extern/inet/examples:/home/bauder/artery/extern/inet/tutorials:/home/bauder/artery/extern/inet/showcases" "-l" "/home/bauder/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/bauder/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/bauder/artery/build/extern/libINET.so" "-l" "/home/bauder/artery/build/extern/libveins.so" "-l" "/home/bauder/artery/build/src/traci/libtraci.so" "-l" "/home/bauder/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cNLOSv" "--sim-time-limit=10s")
set_tests_properties(gemv2-NLOSv PROPERTIES  WORKING_DIRECTORY "/home/bauder/artery/scenarios/gemv2" _BACKTRACE_TRIPLES "/home/bauder/artery/cmake/AddOppRun.cmake;169;add_test;/home/bauder/artery/scenarios/gemv2/CMakeLists.txt;4;add_opp_test;/home/bauder/artery/scenarios/gemv2/CMakeLists.txt;0;")
add_test(gemv2-NLOSbLogDist "/home/bauder/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/bauder/artery/src/artery:/home/bauder/artery/src/traci:/home/bauder/artery/extern/veins/examples/veins:/home/bauder/artery/extern/veins/src/veins:/home/bauder/artery/extern/inet/src:/home/bauder/artery/extern/inet/examples:/home/bauder/artery/extern/inet/tutorials:/home/bauder/artery/extern/inet/showcases" "-l" "/home/bauder/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/bauder/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/bauder/artery/build/extern/libINET.so" "-l" "/home/bauder/artery/build/extern/libveins.so" "-l" "/home/bauder/artery/build/src/traci/libtraci.so" "-l" "/home/bauder/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cNLOSb1" "--sim-time-limit=10s")
set_tests_properties(gemv2-NLOSbLogDist PROPERTIES  WORKING_DIRECTORY "/home/bauder/artery/scenarios/gemv2" _BACKTRACE_TRIPLES "/home/bauder/artery/cmake/AddOppRun.cmake;169;add_test;/home/bauder/artery/scenarios/gemv2/CMakeLists.txt;5;add_opp_test;/home/bauder/artery/scenarios/gemv2/CMakeLists.txt;0;")
add_test(gemv2-NLOSbDifRefl "/home/bauder/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/bauder/artery/src/artery:/home/bauder/artery/src/traci:/home/bauder/artery/extern/veins/examples/veins:/home/bauder/artery/extern/veins/src/veins:/home/bauder/artery/extern/inet/src:/home/bauder/artery/extern/inet/examples:/home/bauder/artery/extern/inet/tutorials:/home/bauder/artery/extern/inet/showcases" "-l" "/home/bauder/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/bauder/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/bauder/artery/build/extern/libINET.so" "-l" "/home/bauder/artery/build/extern/libveins.so" "-l" "/home/bauder/artery/build/src/traci/libtraci.so" "-l" "/home/bauder/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cNLOSb1_diffractionReflection" "--sim-time-limit=10s")
set_tests_properties(gemv2-NLOSbDifRefl PROPERTIES  WORKING_DIRECTORY "/home/bauder/artery/scenarios/gemv2" _BACKTRACE_TRIPLES "/home/bauder/artery/cmake/AddOppRun.cmake;169;add_test;/home/bauder/artery/scenarios/gemv2/CMakeLists.txt;6;add_opp_test;/home/bauder/artery/scenarios/gemv2/CMakeLists.txt;0;")
add_test(gemv2-NLOSbSmallScale "/home/bauder/omnetpp-5.6.2/bin/opp_run_dbg" "-n" "/home/bauder/artery/src/artery:/home/bauder/artery/src/traci:/home/bauder/artery/extern/veins/examples/veins:/home/bauder/artery/extern/veins/src/veins:/home/bauder/artery/extern/inet/src:/home/bauder/artery/extern/inet/examples:/home/bauder/artery/extern/inet/tutorials:/home/bauder/artery/extern/inet/showcases" "-l" "/home/bauder/artery/build/src/artery/envmod/libartery_envmod.so" "-l" "/home/bauder/artery/build/src/artery/storyboard/libartery_storyboard.so" "-l" "/home/bauder/artery/build/extern/libINET.so" "-l" "/home/bauder/artery/build/extern/libveins.so" "-l" "/home/bauder/artery/build/src/traci/libtraci.so" "-l" "/home/bauder/artery/build/src/artery/libartery_core.so" "omnetpp.ini" "-uCmdenv" "-cNLOSb1_smallScaleVariations" "--sim-time-limit=10s")
set_tests_properties(gemv2-NLOSbSmallScale PROPERTIES  WORKING_DIRECTORY "/home/bauder/artery/scenarios/gemv2" _BACKTRACE_TRIPLES "/home/bauder/artery/cmake/AddOppRun.cmake;169;add_test;/home/bauder/artery/scenarios/gemv2/CMakeLists.txt;7;add_opp_test;/home/bauder/artery/scenarios/gemv2/CMakeLists.txt;0;")