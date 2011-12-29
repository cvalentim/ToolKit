#// gnuplot script for ploting the data
#// taken from http://www.tophatstuff.co.uk/

# sets the chart title
set title "Time taken to access a two-dimensional array of size w^2 bytes"

# sets x and y labels
set xlabel "X LABEL"
set ylabel "Y LABEL"

# not sure what it does
set autoscale

# output as a png image file, uses font arial 12 
# and sets the image size to 600 x 600
set terminal png enhanced font 'arial,12' size 600, 600

# output file name
set output "plot.png"

# divides the x-axis at tics of 256
# and the y-axis at tics of 0.5
set xtic 256
set ytic  0.5

# sets the size of x and y axis
set xrange [0:2600]
set yrange [0:8.5]

# show the chart as grid
set grid xtics ytics

set key left top
set key spacing 2.5

set style line 1 lt 1 lw 1 linecolor rgb "black"
set style line 2 lt 3
set style line 3 lt 3
set key box linestyle 1


xfirst_fit(x) = k0 * (x**2)
fit xfirst_fit(x) "xfirst_char.txt" using 1:3 via k0

plot \
    "xfirst_char.txt" using 1:3 \ # plot using first column as x-axis and third as y-axis
        title "Access by x, then by y" with lines linewidth 2, \ 
    "yfirst_char.txt" using 1:3 \
        title "Access by y, then by x" with lines linewidth 2, \
    xfirst_fit(x) title "Best Fit: by x, then by y" with lines linewidth 2
    



