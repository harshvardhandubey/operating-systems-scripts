echo "Enter the two nos : "
read a
read b
echo "Menu 1.Add 2.Sub 3.Mult 4.Div"
read ch
if [ $ch -eq 1 ]
then
c=$(( $a+$b ))
elif [ $ch -eq 2 ]
then
c=$(( $a-$b ))
elif [ $ch -eq 3 ]
then
c=$(( $a*$b ))
elif [ $ch -eq 4 ]
then
c=$(( $a/$b ))
fi
echo "The result is :"
echo -n
echo $c
