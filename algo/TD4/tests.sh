EXE=./td4
for i in test*.in 
do
   echo "Testing $i..."
   res=`$EXE <$i | diff -q - "$(basename $i .in).out"`
   if [ ! -z "$res" ] 
   then 
      echo "-> Test failed see diff file" 
      $EXE <$i | diff -y - "$(basename $i .in).out" | cat >"$(basename $i .in).diff"
   else  
      echo "-> Test passed"
   fi   
done
   
