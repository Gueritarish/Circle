gcc circle.c -lm -o circle

This will generate a binary that you can simply execute to display the circle you want.
To change the size of the circle you want to create you need to change the value of the RADIUS defined in the file.
If you want to change the way the distance of Minkowski is calculated, change the value of POWER to something else, default 2 to circle.

POWER :
1 is a diamond
2 is a perfect circle
above 2 will tend to be a square, depending on the RADIUS, it will simply be a square with rounded angle.
under 1 will tend to be a cross
0.5 is a perfect 4 branch star.

Be carefull as 0 won't display anything, it won't crash but will shown a warning on compilation due to the power root of ( 1 / 0 ).
