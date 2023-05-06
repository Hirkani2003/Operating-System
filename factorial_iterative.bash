echo "Enter a number : "
read num
factorial=1
for (( i=2; i<=$num; ++i ))
do
factorial=$((factorial*i))
done
echo "$factorial is the factorial of number $num"