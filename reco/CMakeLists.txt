# Create a library called "libATReco" which includes the source files given in the array .

set(INCLUDE_DIRECTORIES
${ROOT_INCLUDE_DIR}
${Boost_INCLUDE_DIRS}
${BASE_INCLUDE_DIRECTORIES}
# Add all the folders having header files you used in the code.
#${CMAKE_SOURCE_DIR}/mcstack
${CMAKE_SOURCE_DIR}/AtMap
${CMAKE_SOURCE_DIR}/par
${CMAKE_SOURCE_DIR}/reco
${CMAKE_SOURCE_DIR}/reco/GETDecoder
${CMAKE_SOURCE_DIR}/reco/ATDecoder
${CMAKE_SOURCE_DIR}/reco/ATPulseAnalyzer
${CMAKE_SOURCE_DIR}/reco/HoughTransformation
${CMAKE_SOURCE_DIR}/reco/ATProtoPhiReco

)

include_directories(${INCLUDE_DIRECTORIES})

set(LINK_DIRECTORIES
${ROOT_LIBRARY_DIR}
${FAIRROOT_LIBRARY_DIR}
) 

link_directories(${LINK_DIRECTORIES})

set(SRCS
# Add all the source files below this line. Those must have cc for their extension.
GETDecoder/GETDecoder.cc
GETDecoder/GETFrame.cc
GETDecoder/GETMath.cc
GETDecoder/GETPlot.cc

ATDecoder/ATCore.cc
ATDecoder/ATPad.cc
ATDecoder/ATRawEvent.cc
ATDecoder/ATHit.cc
ATDecoder/ATEvent.cc
ATDecoder/ATProtoEvent.cc
ATDecoder/ATProtoQuadrant.cc

ATPulseAnalyzer/ATPSA.cc
ATPulseAnalyzer/ATPSASimple.cc
ATPulseAnalyzer/ATPSASimple2.cc
ATPulseAnalyzer/ATPSAProto.cc
#ATPulseAnalyzer/STPSALayer.cc

HoughTransformation/ATHoughSpace.cc
HoughTransformation/ATHoughSpaceLine.cc

ATProtoPhiReco/ATPhiReco.cc
ATProtoPhiReco/ATPhiRecoSimple.cc
ATProtoPhiReco/ATPhiRecoTriple.cc

ATDecoderTask.cc
ATPSATask.cc
ATPhiRecoTask.cc
ATHoughTask.cc

)

CHANGE_FILE_EXTENSION(*.cc *.hh HEADERS "${SRCS}")

Set(LINKDEF ATTPCRecoLinkDef.h)
Set(LIBRARY_NAME ATTPCReco)
Set(DEPENDENCIES
    Base
    MCStack
    XMLParser   
# Add all library names your code depending on.
# Basically those are the libraries in the header files' directory.
    AtTpcMap
    ATPar
    Spectrum
   
)

GENERATE_LIBRARY()
