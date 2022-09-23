# Name: Caitlin Lopez
# Date: September 22, 2022 (Thursday 2:15)
# Title: Lab1 - Part 3
# Description: This program checks that the correct user is logged in and
# calculates the areas of a rectangle and a circle, with height, width, and
# radius input by the user
#!/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."

#only allows user to calculate the rectangle and circle areas if the correct
#user is logged in
if [ $user = "cjlopez" ]
then
        echo "Now you can proceed!"
else
        echo "Check who logged in!"
        exit 1
fi

response="Yes"
while [ $response != "No" ]
do
        echo "Enter height of rectangle: "
        read height
        echo "Enter width of rectangle: "
        read width
        echo "Enter radius of circle: "
        read radius
        area=`expr $height \* $width`
        echo "The area of the rectangle is $area and the area of the circle is "
        #need to use calculator to be able to use float number (pi)
        echo "scale = 5; $radius * $radius * 3.14159" | bc -l
        echo "Would you like to repeat for another rectangle and circle [Yes/No]?"
        read response
done
