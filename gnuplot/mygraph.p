# Gnuplot script for plotting experimental data.
# The input is a csv file, this script does a scatter graph
# based on the data first column (x-axis) and second column (y-axis).
# It also sets the best-fit-line for the points
 
set autoscale
unset log
unset label

#set xtic auto
#set ytic auto

set title "Char Tittle"
set xlabel "X axis label"
set ylabel "Y axis label"

set style fill solid 0.5

# sets output as a postscript file, with colors, use font Times-Roman of size 20
set terminal postscript eps enhanced color solid lw 2 "Times-Roman" 20

# sets output name
set out 'plot.ps'

# find the best fit line 
y(x) = m*x + b
fit y(x) "input.csv" via m, b


plot "input.csv" using 1:2 with points title 'Graph', \
     y(x) title 'best-fit-line', \
set term pop
