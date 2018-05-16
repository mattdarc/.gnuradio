# Introduction

gr-dip is a digital image processing library developed for GNU Radio using
OpenCV (C++). Currently, the blocks that are implemented are:

* Image Source
* Image Save
* Image Sink
* Image Throttle
* Gaussian Filter
* Median Filter

# Dependencies

* GNU Radio development packages and their dependencies
* OpenCV 3.4.1

# Installation

	   $ cd gr-dip
       $ mkdir build
       $ cd ./build && cmake ..
       $ make
       $ sudo make install
