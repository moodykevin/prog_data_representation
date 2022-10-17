#!/bin/bash

# Get dictionary and grid files
read filename
read gridname

#Run 5 times, storing the last value (time) as a variable)
TIME1=`./a.out $filename $gridname | tail -1`
TIME2=`./a.out $filename $gridname | tail -1`
TIME3=`./a.out $filename $gridname | tail -1`
TIME4=`./a.out $filename $gridname | tail -1`
TIME5=`./a.out $filename $gridname | tail -1`

#Making sure all values are integers (found code for how to convert to int online)
TIME1=${TIME1%.*}
TIME2=${TIME2%.*}
TIME3=${TIME3%.*}
TIME4=${TIME4%.*}
TIME5=${TIME5%.*}

#Divide by 5 and return
AVGTIME=$(($TIME1+$TIME2+$TIME3+$TIME4+$TIME5))
echo $(( $AVGTIME / 5 ))
