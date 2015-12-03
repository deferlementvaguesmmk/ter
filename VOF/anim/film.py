#!/usr/bin/env python 
""" Module for reading output files, and displaying them """

import pylab
import os

def film1D(base, ext, debut, fin, vmin, vmax, dt = 0):
  """ displays the evolution in time of a 1-D solution
  Usage : film1D(base, ext, debut, fin, vmin, vmax)
          film1D(base, ext, debut, fin, vmin, vmax, dt)

  base : root of output files
  ext : extension of output files
  debut : start index
  fin : final index
  vmin, vmax : y-range
  
  Example : film1D("Un", ".dat", 0, 20, -0.1, 1.1)
         will display frames contained in Un0.dat, Un1.dat, ...
         until Un19.dat with y in [-0.1, 1.1]
  
  Put a dt different from 0, if the animation is too fast, so that the system
  will wait dt seconds between each display """
  V = pylab.loadtxt(base + str(debut) + ext)
  line, = pylab.plot(V[:,0], V[:,1]);
  pylab.axis(pylab.array([V[0, 0], V[V.shape[0]-1,0], vmin, vmax]));
  os.system('sleep ' +str(dt))
  for i in range(debut+1, fin):
    V = pylab.loadtxt(base + str(i) + ext)
    line.set_ydata(V[:,1])
    pylab.draw()
    os.system('sleep ' +str(dt))

def film1D_twice(base, base2, ext, debut, fin, vmin, vmax, dt = 0):
  """ displays the evolution in time of a two 1-D solutions
  Usage : film1D_twice(base, base2, ext, debut, fin, vmin, vmax)
          film1D_twice(base, base2, ext, debut, fin, vmin, vmax, dt)

  base : root of output files (first family
  base2 : root of output files (second family)
  ext : extension of output files
  debut : start index
  fin : final index
  vmin, vmax : y-range
  
  Example : film1D_twice("Un", "UnExacte", ".dat", 0, 20, -0.1, 1.1)
         will display frames contained in Un0.dat, Un1.dat, ...
         until Un19.dat with y in [-0.1, 1.1], UnExacte0.dat, ...,
         UnExacte19.dat are also displayed
  
  Put a dt different from 0, if the animation is too fast, so that the system
  will wait dt seconds between each display """
  V = pylab.loadtxt(base + str(debut) + ext)
  V2 = pylab.loadtxt(base2 + str(debut) + ext)
  line, = pylab.plot(V[:,0], V[:,1]);
  line2, = pylab.plot(V2[:,0], V2[:,1], 'r');
  pylab.axis(pylab.array([V[0, 0], V[V.shape[0]-1,0], vmin, vmax]));
  os.system('sleep ' +str(dt))
  for i in range(debut+1, fin):
    V = pylab.loadtxt(base + str(i) + ext)
    line.set_ydata(V[:,1])
    V2 = pylab.loadtxt(base2 + str(i) + ext)
    line2.set_ydata(V2[:,1])
    pylab.draw()
    os.system('sleep ' +str(dt))

