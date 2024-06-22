cmake_minimum_required( VERSION 3.5 )
project( lab8 VERSION 0.1.0 LANGUAGES C CXX )

find_package( OpenSSL REQUIRED )
include_directories( ${OPENSSL_INCLUDE_DIR} )

find_package( OpenCV REQUIRED )
add_executable( lab8 main.cpp hash_summ.cpp )
target_link_libraries( lab8 ${OpenCV_LIBS} )
target_link_libraries( lab8 ${OPENSSL_LIBRARIES} )