set title "Taux de présence"

set xlabel "Width"
set ylabel "Height"

set palette model RGB
set palette model RGB defined (0 "white", 1 "blue")

set view map
set grid
splot 'TableVOF.dat' matrix with image

