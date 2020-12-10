commit_msg=`date`


git add .

git status

sleep 2s

echo "####### git add done #######"

git commit -m "$commit_msg"

echo "####### commit start######"

sleep 2s

echo "####### commit done, start git push #######"


git push -u origin master

set timeout 3

expect "Username for 'https://github.com':"

send "QuectelWB\n"

set timeout 1

send "wangbees09\n"

#QuectelWB

echo "####### git push done #######"
