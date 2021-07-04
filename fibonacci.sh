echo "Fibonacci  series"
echo -n
a=0
b=1
echo "Enter the no of terms :"
read n
echo "Fibonacci series is :"
echo $a
echo $b
for ((i=n;i>2;i--))
do
c=$(( $a+$b ))
echo $c
a=$b
b=$c
done
 
