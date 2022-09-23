# Name: Caitlin Lopez
# Date: September 22, 2022 (Thursday 2:15)
# Title: Lab 1 - Part 1&2
# Description: This program checks that the correct user is logged in and
# calculates the area of a rectangle given height and width
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

#only allows user to calculate the rectangle area if the correct user is logged in
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
        area=`expr $height \* $width`
        echo "The area of the rectangle is $area"

        echo "Would you like to repeat for another rectangle [Yes/No]?"
        read response
done
