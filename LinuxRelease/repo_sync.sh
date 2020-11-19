#!/bin/bash   

# export REPO_URL='https://mirrors.tuna.tsinghua.edu.cn/git/git-repo'

repo sync   -j1 --fail-fast
while [ $? = 1 ]; do   
		echo "================sync failed, re-sync again ====="   
	sleep 3   
	repo sync   -j1 --fail-fast
done
