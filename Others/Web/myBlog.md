wiki blog
=====

整理wiki blog的方法

	jekyll
	hexo
	docsify
	mdwiki
	gitbook

gitbook
----------

gitbook 

npm install -g cnpm

cnpm install -g  gitbook-cli


docker start gitbook
------

docker search -s 3 gitbook
docker pull fellah/gitbook


docker run -v /home/m/gitbook/my:/srv/gitbook -v /home/m/gitbook/my/html:/srv/html fellah/gitbook gitbook build . /srv/html

docker search -s 3 nginx
docker pull nginx

docker run --name my-nginx -v /home/m/gitbook/my/html:/usr/share/nginx/html -d -p 8080:80 nginx

So open IP:8080 to start a Web page .

How to make pdf 

[make pdf]()


