echo "Enter a number : "
read n
num=0
while (($n>0))
do
    k=$(( n%10 ))
    num=$(( num*10 + k))
    n=$(( n/10 ))
done
echo "$num is the reverse number."