add_artery_feature(police2 ClearLaneService2.cc PoliceService2.cc)
generate_opp_message(PoliceClearLane2.msg TARGET police2 DIRECTORY police2_msgs)
add_opp_run(highway_police2 NED_FOLDERS ${CMAKE_CURRENT_SOURCE_DIR})

if(WITH_STORYBOARD)
    target_sources(police2 PUBLIC PoliceServiceStoryboard2.cc)
endif()

#Hinzufügen, um richtigen PoliceService auszuwählen
if(WITH_ENVMOD)
    target_sources(police2 PUBLIC PoliceServiceEnvmod2.cc)
    target_link_libraries(police2 PUBLIC envmod)
endif()
